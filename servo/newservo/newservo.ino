#include <Servo.h>

Servo tilt;
Servo pan;

const int SOFT_POT_PIN_PAN = A0; // pan
const int SOFT_POT_PIN_TILT = A1; // tilt


void setup(){
  tilt.attach(11, 500, 2500);
  pan.attach(10, 500 , 2500);
  
  Serial.begin(9600);
  
  pinMode(SOFT_POT_PIN_PAN, INPUT);

}

void loop(){
  
  //with_slider();
  //serial_read();
  char car = 'C';  
  int value = int(car);
  int unite = value % 10;
  int dixaine = (value - unite) /10; 
  Serial.print(car);
  Serial.print(" - ");
  Serial.print(value);
  Serial.print(" - ");
  Serial.print(dixaine);
  Serial.print(" - ");
  Serial.println(unite);
}

void with_slider(){
  // Read in the soft pot's ADC value
  int softPotADCPAN = analogRead(SOFT_POT_PIN_PAN);
  int softPotADCTILT = analogRead(SOFT_POT_PIN_TILT);
  
  // Map the 0-1023 value to 0-40
  int positionPan = map(softPotADCPAN, 0, 1023, 0, 180);
  int positionTilt = map(softPotADCTILT, 0, 1023, 0, 180);

  pan.write(positionPan);
  tilt.write(positionTilt);
 
  delay(50);
}


void serial_read(){

  if(Serial.available()){
    char c = Serial.read();
    int value = int(c);
    int unite = value % 10;
    int dixaine = (value - unite) /10;
    
    int DEPL = 0;
    
    //aller à droite
    if(dixaine < 5){
      if (pan.read() < 170){
        if(dixaine = 1)
          DEPL = 4;
        if(dixaine = 2)
          DEPL = 3;
        if(dixaine = 3)
          DEPL = 2;
        if(dixaine = 4)
          DEPL = 1; 
        pan.write(pan.read() + DEPL);
      }
    }
    //aller à gauche
    else if(dixaine > 5){
      if (pan.read() > 10){
        if(dixaine = 9)
          DEPL = 4;
        if(dixaine = 8)
          DEPL = 3;
        if(dixaine = 7)
          DEPL = 2;
        if(dixaine = 6)
          DEPL = 1;    
        pan.write(pan.read() - DEPL);
      }  
    }
    //aller à en bas
    if(dixaine < 5){
      if(tilt.read() > 10){
        if(dixaine = 1)
          DEPL = 4;
        if(dixaine = 2)
          DEPL = 3;
        if(dixaine = 3)
          DEPL = 2;
        if(dixaine = 4)
          DEPL = 1 ;
        tilt.write(tilt.read() -DEPL);
      }
    }
    //aller en haut
    else if(dixaine > 5){
      if(tilt.read() < 170){
        if(dixaine = 9)
          DEPL = 4;
        if(dixaine = 8)
          DEPL = 3;
        if(dixaine = 7)
          DEPL = 2;
        if(dixaine = 6)
          DEPL = 1;    
        tilt.write(tilt.read() + DEPL);
      }  
    }
  }
    
}
