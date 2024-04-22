
#include <Wire.h>
#include <SharpIR.h>
#include <LiquidCrystal_I2C.h>




int tim = 500; //the value of delay time
// initialize the library with the numbers of the interface pins
LiquidCrystal_I2C lcd(0x27,16,2); // set the LCD address to 0x27 for a 16 chars and 2 line display

int LCD_delay = 500;
int LCD_timer = 0;


int num = 0;

//IR Sensors
#define IR_PIN_L A0
#define IR_PIN_R A1

//SharpIR IR_SENSOR_L( SharpIR::GP2Y0A41SK0F, A0 );
SharpIR IR_SENSOR_R( SharpIR::GP2Y0A41SK0F, A1 );


//Hall Effect Sensors
#define HE_PIN_L A2
#define HE_PIN_R A3

//Photo Resistors
#define PR_PIN_L 11
#define PR_PIN_R 12





void setup()
{
  //lcd.init();
  //lcd.backlight();

  //pinMode(PR_PIN_L, INPUT);
  //pinMode(PR_PIN_R, INPUT);

  //pinMode(HE_PIN_L, INPUT);
  //pinMode(HE_PIN_R, INPUT);

  //pinMode(IR_PIN_L, INPUT);
  //pinMode(IR_PIN_R, INPUT);

  Serial.begin( 9600 ); //Enable the serial comunication


}



void loop()
{
  
  //int x = analogRead(IR_PIN_L);
  //int y = analogRead(IR_PIN_R);

  //int x = IR_SENSOR_L.getDistance(); //Calculate the distance in centimeters and store the value in a variable
  int y = IR_SENSOR_R.getDistance(); //Calculate the distance in centimeters and store the value in a variable

  Serial.println( y ); //Print the value to the serial monitor

  /*

  int a = digitalRead(PR_PIN_L);
  int b = digitalRead(PR_PIN_R);

  int c = digitalRead(HE_PIN_L);
  int d = digitalRead(HE_PIN_R);

  

  lcd.setCursor(0, 0);
  lcd.print(x);
  lcd.setCursor(0, 1);
  lcd.print(y);

  lcd.setCursor(5, 0);
  lcd.print(a);
  lcd.setCursor(5, 1);
  lcd.print(b);

  lcd.setCursor(10, 0);
  lcd.print(c);
  lcd.setCursor(10, 1);
  lcd.print(d);
  */

  delay(50);

}




