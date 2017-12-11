#include <Servo.h>

Servo tilt;
Servo pan;

const int SOFT_POT_PIN_PAN = A0; // pan
const int SOFT_POT_PIN_TILT = A1; // tilt

const int DEPL=4;


void setup(){
  tilt.attach(11, 500, 2500);
  pan.attach(10, 500 , 2500);
  
  Serial.begin(9600);
  
  pinMode(SOFT_POT_PIN_PAN, INPUT);

}

void loop(){
  
  //with_slider();
  serial_read();
    
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
    switch(c){
      case 'z' :
        if(tilt.read() < 170)
          tilt.write(tilt.read() + DEPL);
        break;
      case 's' :
        if(tilt.read() > 10)
          tilt.write(tilt.read() -DEPL);
        break;
      case 'q' :
        if (pan.read() > 10)
          pan.write(pan.read() - DEPL);
        break;
      case 'd' : 
        if (pan.read() < 170)
           pan.write(pan.read() + DEPL);
        break;
      case ' ':
        pan.write(pan.read());
        tilt.write(tilt.read());
        break;
      case 'm' :
        pan.write(90);
        tilt.write(90); 
        delay(100); 
        break;
      default :
        Serial.print("Error : character unrecognize -> ");
        Serial.println(c);
    }  
  }
    
}
