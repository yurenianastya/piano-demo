#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

const int buzzer = 12;
const byte rows = 4;
const byte columns = 4;

char keys[rows][columns] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[rows] = {2, 3, 4, 5};
byte columnPins[columns] = {6, 7, 8, 9};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, columnPins, rows, columns);


void setup() {
  pinMode(12, OUTPUT);
  //wiipiano();

}

void sound(int frequency, int time) {
  tone(buzzer, frequency);
  delay(time);
  noTone(buzzer);
}

void wiipiano() {
  sound(2793, 500);
  sound(3500, 300);
  sound(4186, 500);
  sound(3500, 500);
  sound(2793, 300);
  sound(2350, 250);
  sound(2350, 250);
  sound(2350, 250);
  delay(1000);
  sound(2100, 250);
  sound(2350, 250);
  delay(50);
  sound(2793, 300);
  sound(3500, 300);
  sound(4186, 500);
  sound(3500, 500);
  sound(2793, 300);
  sound(5274, 750);
  sound(4978, 300);
  sound(4698, 300);
}

void loop() {
  char key = keypad.getKey();
  if(key)  // Check for a valid key.
  {
    switch (key)
    {
      case '1':
      //low la
        sound(1760, 150);
        break;
      case '2':
      // low si
        sound(1975, 150);
        break;
      case '3':
      // low do
        sound(2050, 150);
        break;
      case '4':
      // low re
        sound(2350, 150);
        break;
      case '5':
      // low mi
        sound(2637, 150);
        break;
      case '6':
      // fa
        sound(2793, 150);
        break;
      case '7':
      // sol
        sound(3135, 150);
        break;
      case '8':
      // la
        sound(3500, 150);
        break;
      case '9':
      // si
        sound(3951, 150);
        break;
      case '0':
      //high pitched do
        sound(4186, 150);
        break;
      case '#':
      //high pitched re
        sound(5274, 150);
        break;
      case '*':
      //high pitched mi
        sound(4698, 150);
        break;
       
      default:
        Serial.println(key);
    }
  }
}
