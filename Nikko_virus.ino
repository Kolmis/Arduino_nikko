/*
Nikon controllit:
1 = alas+vasen
2 = alas
3 = alas+oikea
4 = vasen
5 = pysähdy
6 = oikea
7 = ylös, vasen 
8 = ylös
9 = ylös,oikea
*/
//char incomingByte;  // incoming data
int  LED = 8;      // LED pin
int  GND = 7;
int  LEFT = 11;
int  RIGHT = 10;
int  FORWARD = 6;
int  BACKWARD = 9;
char bytex;
char bytey;
String movement;
String L;
String F;
String R;
String B;

void setup() {
  Serial.begin(9600); // initialization
  pinMode(LED, OUTPUT);
  pinMode(GND, OUTPUT);
  pinMode(LEFT, OUTPUT);
  pinMode(RIGHT, OUTPUT);
  pinMode(FORWARD, OUTPUT);
  pinMode(BACKWARD, OUTPUT);
  digitalWrite(GND, LOW);
  Serial.println("Initialized");
}
 
void loop() {
  if (Serial.available() > 0) {  // if the data came
    Serial.println("uliuli");
    //bytex = Serial.read();
    movement=Serial.readString();
    Serial.println(movement);
    
    L="";
    F="";
    R="";
    B="";
    
    L+=movement[0];
    L+=movement[1];
    L+=movement[2];
    
    F+=movement[3];
    F+=movement[4];
    F+=movement[5];
    
    R+=movement[6];
    R+=movement[7];
    R+=movement[8];
    
    B+=movement[9];
    B+=movement[10];
    B+=movement[11];
    
    Serial.println(L);
    Serial.println(F);
    Serial.println(R);
    Serial.println(B);
    drive(L.toInt(),F.toInt(),R.toInt(),B.toInt());
  }
}
void drive(int L, int F, int R, int B){
  analogWrite(FORWARD, F);
  analogWrite(BACKWARD, B);
  analogWrite(LEFT, L);
  analogWrite(RIGHT, R);
}
