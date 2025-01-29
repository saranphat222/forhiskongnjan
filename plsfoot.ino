#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);


int pinSpeed_1 = 13;
int pinSpeed_2 = 12;
int pinSpeed_3 = 11;

int state_Speed_1 = 0;
int state_Speed_2 = 0;
int state_Speed_3 = 0;

int coin_10 = 0 ;
int coin_5 = 0 ;
int coin_1 = 0 ;

int oneClink_1 = 0;
int oneClink_2 = 0;
int oneClink_3 = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Coding by nongnuea 1/7");

  pinMode(pinSpeed_1, INPUT); 
  pinMode(pinSpeed_2, INPUT); 
  pinMode(pinSpeed_3, INPUT);



  lcd.print("Coding by nongnuea 1/7");
  lcd.setCursor(0, 1);
  lcd.print("Nina Is Zeeza's Mom");

  delay(5000);

  lcd.clear();

}

void loop() {
  state_Speed_1 = digitalRead(pinSpeed_1);
  state_Speed_2 = digitalRead(pinSpeed_2);
  state_Speed_3 = digitalRead(pinSpeed_3);

  if (state_Speed_1 == 1) {
    if (oneClink_1 == 0) {
      oneClink_1 = 1;
      coin_1 ++;
    }
  }
  else if (state_Speed_1 == 0 ) {
    oneClink_1 = 0;
  }



  if (state_Speed_2 == 1) {
    if (oneClink_2 == 0) {
      oneClink_2 = 1;
      coin_5++;
    }
  }
  else if (state_Speed_2 == 0 ) {
    oneClink_2 = 0;
  }



  if (state_Speed_3 == 1) {
    if (oneClink_3 == 0) {
      oneClink_3 = 1;
      coin_10 ++;
    }
  }
  else if (state_Speed_3 == 0 ) {
    oneClink_3 = 0;
  }


  lcd.setCursor(0, 0);
  lcd.print("c_1 :");
  lcd.print(coin_1);


  lcd.setCursor(9, 0);
  lcd.print("c_5 :");
  lcd.print(coin_5);

  lcd.setCursor(0, 1);
  lcd.print("c_10 :");
  lcd.print(coin_10);
  
}