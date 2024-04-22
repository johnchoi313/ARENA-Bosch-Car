
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal_I2C lcd(0x27,16,2); // set the LCD address to 0x27 for a 16 chars and 2 line display

int LCD_delay = 500;
int LCD_timer = 0;

int num = 0;

//Photo Resistors (PR)
#define HOOD_PR_PIN A1
#define ENGINE_PR_PIN A0
#define WHEEL_PR_L_PIN A3
#define WHEEL_PR_R_PIN A2
//Limit Switches (LS)
#define HEADLIGHT_LS_L_PIN 12
#define HEADLIGHT_LS_R_PIN 11


void setup()
{
  lcd.init();
  lcd.backlight();

  pinMode(HOOD_PR_PIN, INPUT);
  pinMode(ENGINE_PR_PIN, INPUT);

  pinMode(WHEEL_PR_L_PIN, INPUT);
  pinMode(WHEEL_PR_R_PIN, INPUT);

  pinMode(HEADLIGHT_LS_L_PIN, INPUT_PULLUP);
  pinMode(HEADLIGHT_LS_R_PIN, INPUT_PULLUP);

  Serial.begin( 9600 ); //Enable the serial comunication
}


void printLCD() {
  
}

void loop()
{

  int a = digitalRead(HOOD_PR_PIN);
  int b = digitalRead(ENGINE_PR_PIN);

  int c = digitalRead(WHEEL_PR_L_PIN);
  int d = digitalRead(WHEEL_PR_R_PIN);

  int e = digitalRead(HEADLIGHT_LS_L_PIN);
  int f = digitalRead(HEADLIGHT_LS_R_PIN);

  lcd.setCursor(0, 0);
  lcd.print("HO=");
  lcd.setCursor(0+3, 0);
  lcd.print(a);
  
  lcd.setCursor(0, 1);
  lcd.print("EN=");
  lcd.setCursor(0+3, 1);
  lcd.print(b);

  lcd.setCursor(6, 0);
  lcd.print("WL=");
  lcd.setCursor(6+3, 0);
  lcd.print(c);

  lcd.setCursor(6, 1);
  lcd.print("WR=");
  lcd.setCursor(6+3, 1);
  lcd.print(d);

  lcd.setCursor(12, 0);
  lcd.print("HL=");
  lcd.setCursor(12+3, 0);
  lcd.print(e);
 
  lcd.setCursor(12, 1);
  lcd.print("HR=");
  lcd.setCursor(12+3, 1);
  lcd.print(f);
  
  delay(50);
}
