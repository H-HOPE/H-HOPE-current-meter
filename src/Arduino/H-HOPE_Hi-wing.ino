//Arduino 1.0.5 IDE

//include libraries for I2C and LCD display
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//LCD has i2c address 0x27 or 0x3F
LiquidCrystal_I2C lcd(0x27,16,2);

//counter
#define HALLpin 2

//variables
volatile unsigned long deltaT, deltaTold, InteruptTime=0;
float waterSpeed=0;


void setup(){
//Serial for debug
Serial.begin(19200);
//I2C begin
Wire.begin();
//LCD begin
lcd.init(); 
lcd.backlight();
lcd.setCursor(0, 0);
lcd.print("Water speed:");

//Interupt pin setup
pinMode(HALLpin, INPUT_PULLUP);
attachInterrupt(0, cnt, FALLING);
}



void loop(){ 
  
lcd.setCursor(0, 1);
//calculate water speed from frequency
waterSpeed=130.0/deltaT;  //y=130/x
//print water speed to LCD
lcd.print(waterSpeed,1);
lcd.print(" m/s");
//lcd.print(", ");
//lcd.print(deltaT);
//lcd.print(" ms   ");
//if no data from hall sensor set water speed to 0.
if(InteruptTime+1000<millis()){
  deltaT=9999;
}
//Serial print for debug
Serial.println(deltaT);
delay(200);
}


///////////////////////////////////////////////////////////////////////
//magnet detector - interrupt
void cnt() {
  deltaT=millis()-deltaTold;
  deltaTold=millis();
  InteruptTime=millis();
}
