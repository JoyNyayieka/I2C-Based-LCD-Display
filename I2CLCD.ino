#include <LiquidCrystal_I2C.h>
#include <Wire.h>

const int totalColumns = 16;
const int totalRows = 2;

LiquidCrystal_I2C lcd(0x27, totalColumns, totalRows);

String staticMessage = "Group 6 members";
String scrollingMessage[5] = {
  "Carol - Member",
  "Hope- Member",
  "Brain - Member",
  "Joy - Member",
  "Tole- Member"
};

void scrollMessage(int row, String message, int delayTime, int totalColumns) {
  for (int i = 0; i < totalColumns; i++) {
    message = " " + message;
  }
  message += " ";
  for (int position = 0; position < message.length() - totalColumns; position++) {
    lcd.setCursor(0, row);
    lcd.print(message.substring(position, position + totalColumns));
    delay(delayTime);
  }
}

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
  lcd.clear(); // Clear the display before printing
  lcd.setCursor(0, 0);
  lcd.print(staticMessage);
  for (int i = 0; i < 5; i++) {
    scrollMessage(1, scrollingMessage[i], 250, totalColumns);
    delay(1000); // Delay between displaying each member's name
  }
}

