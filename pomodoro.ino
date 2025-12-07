
// POMODORO TIMER
//author : John Vincent Ballangca
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


int buttonPin = 7;
int GREEN_PIN = 10;
int RED_PIN = 9;
int BLUE_PIN = 6;

const int WORK_TIME = 25 * 60;
const int BREAK_TIME = 5 * 60;

bool running = false;
bool inWork = true;  

unsigned long startTime = 0;
int remaining = 0;


bool lastButtonState = HIGH;


void setColor(int r, int g, int b) {
  analogWrite(RED_PIN, r);
  analogWrite(GREEN_PIN, g);
  analogWrite(BLUE_PIN, b);
}

void setup() {
  lcd.begin(16, 2);
  pinMode(buttonPin, INPUT_PULLUP);

  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Pomodoro Timer");
  lcd.setCursor(0, 1);
  lcd.print("Press Start");

  setColor(0, 0, 255);
}

void loop() {
  bool buttonState = digitalRead(buttonPin);


  if (buttonState == LOW && lastButtonState == HIGH) {

    if (!running) {

      running = true;
      startTime = millis();
      remaining = inWork ? WORK_TIME : BREAK_TIME;

    } else {
    
      running = false;
      inWork = true;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Pomodoro Timer");
      lcd.setCursor(0, 1);
      lcd.print("Press Start");
      setColor(0, 0, 255);
      delay(300);
    }

    delay(200);
  }

  lastButtonState = buttonState;

  if (!running) return;


  unsigned long elapsed = (millis() - startTime) / 1000;
  int newRemaining = (inWork ? WORK_TIME : BREAK_TIME) - elapsed;

  if (newRemaining != remaining) {
    remaining = newRemaining;


    if (inWork) setColor(255, 0, 0);  
    else setColor(0, 255, 0);        

    int mins = remaining / 60;
    int secs = remaining % 60;

    lcd.setCursor(0, 0);
    lcd.print(inWork ? "Work Time      " : "Break Time     ");

    lcd.setCursor(0, 1);
    lcd.print(mins);
    lcd.print(":");
    if (secs < 10) lcd.print("0");
    lcd.print(secs);
    lcd.print("         ");

   
    if (remaining <= 0) {
      running = false;
      inWork = !inWork;

      lcd.clear();
      if (!inWork) {
        lcd.print("Work Finished!");
      } else {
        lcd.print("Break Finished!");
      }
      setColor(0, 0, 255); 
      delay(2000);

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Press Start...");
    }
  }
}
