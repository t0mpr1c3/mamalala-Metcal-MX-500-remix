#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 9, 8, 7); // LiquidCrystal(rs, enable, d4, d5, d6, d7)

int TIP_DET_PIN           = 3;          // Digital PIN 0-13
int RF_EN_PIN             = 4;          // Digital PIN 0-13
int VLIM_PIN              = 5;          // Digital PIN 0-13
int BOOST_PIN             = 2;          // Digital PIN 0-13
int REG_PIN               = A0;         // Analog PIN A0-A5
int VF_PIN                = A1;         // Analog PIN A0-A5
int VR_PIN                = A2;         // Analog PIN A0-A5
int BACKLIGHT_PIN         = 6;          // PWM PIN 3, 5, 6, 9, 10, or 11

float VF, VR, REG, VSWR;

int SAMPLES               = 16;
int NO_TIP_BACKLIGHT_VAL  = 50;         // 0-255
int POWER_BACKLIGHT_VAL   = 255;        // 0-255
int BOOST_BACKLIGHT_VAL   = 255;        // 0-255
int READY_BACKLIGHT_VAL   = 255;        // 0-255
int ECO_BACKLIGHT_VAL     = 50;         // 0-255
int STANDBY_BACKLIGHT_VAL = 0;          // 0-255

int VSWR_MAX              = 1000;
int READY_VAL             = 10;         // 0-99
    
long ECO_TIME             = 5000;       // ms
long STANDBY_TIME         = 10000;      // ms
  
unsigned long LASTMILLIS;
int PERCENT, LASTPERCENT, STATE, LASTSTATE;

byte r0[8] = {
  B00000, 
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
}; // 0 / 5
byte r1[8] = {
  B10000, 
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000
}; // 1 / 5
byte r2[8] = {
  B11000, 
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000
}; // 2 / 5 
byte r3[8] = {
  B11100, 
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
  B11100
}; // 3 / 5
byte r4[8] = {
  B11110, 
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110,
  B11110
}; // 4 / 5
byte r5[8] = {
  B11111, 
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
}; // 5 / 5

void draw_state(int State) {
  
  if (State == 0){
      lcd.setCursor(4, 0);
      lcd.print("STANDBY");
      digitalWrite(RF_EN_PIN, LOW);
      analogWrite(BACKLIGHT_PIN, STANDBY_BACKLIGHT_VAL);}
      
  if (State == 1){
      lcd.setCursor(4, 0);
      lcd.print("  ECO  ");
      pinMode(VLIM_PIN, OUTPUT);
      digitalWrite(VLIM_PIN, HIGH);
      analogWrite(BACKLIGHT_PIN, ECO_BACKLIGHT_VAL);}
      
  if (State == 2){
      lcd.setCursor(4, 0);
      lcd.print(" READY ");
      pinMode(VLIM_PIN, INPUT);
      analogWrite(BACKLIGHT_PIN, READY_BACKLIGHT_VAL);}
      
  if (State == 3){
      lcd.setCursor(4, 0);
      lcd.print(" POWER ");
      pinMode(VLIM_PIN, INPUT);
      analogWrite(BACKLIGHT_PIN, POWER_BACKLIGHT_VAL);}
      
  if (State == 4){
      lcd.setCursor(4, 0);
      lcd.print(" BOOST ");
      digitalWrite(RF_EN_PIN, HIGH);
      pinMode(VLIM_PIN, OUTPUT);
      digitalWrite(VLIM_PIN, LOW);
      analogWrite(BACKLIGHT_PIN, BOOST_BACKLIGHT_VAL);}
      
  if (State == 5){
      lcd.setCursor(4, 0);
      lcd.print("NO  TIP");
      digitalWrite(RF_EN_PIN, LOW);
      analogWrite(BACKLIGHT_PIN, NO_TIP_BACKLIGHT_VAL);}
  
}

void draw_bargraph(int percent) {
  int i, cp, cl;

  if (percent < READY_VAL){
      lcd.setCursor(14, 1);
      lcd.print("0");
      lcd.print(percent);}
  else { 
      lcd.setCursor(14, 1);
      lcd.print(percent);}

  lcd.setCursor(0, 1);
  
  percent = map(percent, 0, 99, 0, 70);
  cp = percent / 5;
  cl = percent % 5;
  
  for(i = 0; i < cp; ++i)
    lcd.write(5);
  if(cl != 0)
    lcd.write(cl);

  for(i = 0; i < 14 - (cp + (cl ? 1 : 0)); ++i)
    lcd.write((uint8_t)0);
}

void setup(){
  
  Serial.begin(9600);
  pinMode(TIP_DET_PIN, INPUT);
  digitalWrite(TIP_DET_PIN, HIGH);
  pinMode(BOOST_PIN, INPUT);
  digitalWrite(BOOST_PIN, HIGH);
  pinMode(RF_EN_PIN, OUTPUT);
  pinMode(BACKLIGHT_PIN, OUTPUT);
  analogWrite(BACKLIGHT_PIN, BOOST_BACKLIGHT_VAL);
   
  lcd.createChar(0, r0);
  lcd.createChar(1, r1);
  lcd.createChar(2, r2);
  lcd.createChar(3, r3);
  lcd.createChar(4, r4);
  lcd.createChar(5, r5);

  lcd.begin(16, 2); 
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" RF-GEN MX-5000 ");
  lcd.setCursor(0, 1);
  lcd.print("   Ver:  2.01   ");
  delay(3000);
  lcd.clear();
  
  PERCENT = 0;
  STATE = 4;
  draw_state(STATE);
  LASTSTATE = STATE;
  draw_bargraph(PERCENT);
  LASTPERCENT = PERCENT;
}

void loop(){
  
REG = 0;
VF  = 0;
VR  = 0;

for (int i = 0; i < SAMPLES; i++){
     REG = REG + analogRead(REG_PIN);
     VF  = VF + analogRead(VF_PIN);
     VR  = VR + analogRead(VR_PIN);
     delay(1);}
     
REG = REG / SAMPLES;
VF  = VF / SAMPLES;
VR  = VR / SAMPLES;

VSWR = (1 + sqrt(VR / VF)) / (1 - sqrt(VR / VF));
PERCENT = map(constrain(VSWR, 0, VSWR_MAX), 0, VSWR_MAX, 99, 0);

Serial.print("REG = ");
Serial.print(REG);
Serial.print("\tVF = ");
Serial.print(VF);
Serial.print("\tVR = ");
Serial.print(VR);
Serial.print("\tVSWR = ");
Serial.print(VSWR);
Serial.print("\tPERCENT = ");
Serial.println(PERCENT);

if (digitalRead(TIP_DET_PIN) == LOW) STATE = 5;                                                     //NO TIP 

else{  
  
if (digitalRead(BOOST_PIN) == LOW) STATE = 4;
  
else {
  
if (LASTPERCENT > PERCENT && LASTSTATE == 4 || PERCENT > READY_VAL && LASTSTATE != 4)  STATE = 3;   //POWER
if (PERCENT > READY_VAL && LASTSTATE == 1 || LASTSTATE == 5)                           STATE = 4;   //BOOST
if (PERCENT < READY_VAL && LASTSTATE != 1 && LASTSTATE != 4 && LASTSTATE != 5)         STATE = 2;   //READY
if (millis() - LASTMILLIS > ECO_TIME)                                                  STATE = 1;   //ECO
if (millis() - LASTMILLIS > STANDBY_TIME)                                              STATE = 0;   //STANDBY
}
}

if (PERCENT > READY_VAL || STATE == 4 || STATE == 5) LASTMILLIS = millis();

if (STATE != LASTSTATE){
    draw_state(STATE);
    LASTSTATE = STATE;}
  
if (PERCENT != LASTPERCENT){
    draw_bargraph(PERCENT);
    LASTPERCENT = PERCENT;}
  
delay(100);
}
