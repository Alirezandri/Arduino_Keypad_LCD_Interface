#include <Keypad.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// تعداد سطر و ستون Keypad
const byte ROWS = 4;
const byte COLS = 4;

// تعریف کلیدها
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

// پایه‌های سطرها
byte rowPins[ROWS] = {A0, A1, A2, A3};

// پایه‌های ستون‌ها
byte colPins[COLS] = {6, 7, 8, 9};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  lcd.begin(16,2);
  lcd.print("Press Key");
}

void loop() {

  char key = keypad.getKey();

  if (key) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("You Pressed:");
    lcd.setCursor(0,1);
    lcd.print(key);
  }

}
