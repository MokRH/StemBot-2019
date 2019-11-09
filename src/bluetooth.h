//****************** BT Setting ******************//
#include <SoftwareSerial.h>
const int8_t rx = 7, tx = 8, key = 6;
SoftwareSerial BT(rx, tx); // RX, TX
//****************** BT Setting ******************//

char get_bt = ' ';
char BT_receiver() {
  if (BT.available() > 0) {
    get_bt = BT.read();
  }
  return (get_bt);
}

void rename_bt(String btname) {
  BT.print("AT+NAME");
  BT.print(btname);
  BT.print("\r\n");
  delay(500);
  BT.println("AT+RESET\r\n");
  delay(500);
}

void bt_setup(){
  //****************** BT setup ******************//
  pinMode(key, OUTPUT); digitalWrite(key, LOW);
  BT.begin(9600);
  //****************** BT setup ******************//
}