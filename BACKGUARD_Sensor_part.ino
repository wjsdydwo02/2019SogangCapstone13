#include <HX711.h>
#include <SoftwareSerial.h>
//핀 설정
#define PS1 33
#define PS2 34 //압력센서들

#define LD1 17
#define LS1 16 //로드셀 1
#define LD2 22
#define LS2 21 //로드셀 2

//상수(?)
#define CF1 1  
#define CF2 1
#define T1 1
#define T2 1 //조율용 값
HX711 L1;
HX711 L2;

SoftwareSerial mySerial(2,0);

void setup() {
  Serial.begin(9600);
  L1.begin(LD1,LS1);
  L2.begin(LD2,LS2);
  
  L1.set_scale(CF1);
  L2.set_scale(CF2);
  L1.tare(T1);
  L2.tare(T2); //로드셀 조율
  // put your setup code here, to run once:
  mySerial.begin(9600);
}

void loop() {
  long milis = millis();
  int ps1 = analogRead(PS1);
  int ps2 = analogRead(PS2);

  int w1 = L1.read_average(2);
  int w2 = L2.read_average(2);
  //Serial.println(String(ps1)+","+String(ps2));
  String datas  = String(milis)+","+String(ps1)+","+String(ps2)+","+String(w1)+","+String(w2);
  Serial.println(datas);
  mySerial.print(datas+"\n");
  //delay(0);
  // put your main code here, to run repeatedly:

}
