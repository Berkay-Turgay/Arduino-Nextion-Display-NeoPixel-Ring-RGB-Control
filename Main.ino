#include <Adafruit_NeoPixel.h>

#define PIN 14 // Data Pin
byte sayac[4], ID, pw, R, G, B;
boolean knt = false;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(12, PIN, NEO_GRB + NEO_KHZ800);

class Renkler {

  public:
    int R, G, B;

} x[12]; // 12 Adet LED olduğu için


void setup() {
  Serial.begin(115200);
  strip.begin();
  strip.setBrightness(30); //adjust brightness here
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  if (knt) {
    colorWipe(ID, strip.Color(x[ID].R, x[ID].G, x[ID].B), 50);

    if (pw == 1)
      cycle_mod();

    knt = false;
  }
}

void cycle_mod() {
  while (pw == 1) {
    clean();
    delay(250);
    for (int i = 0; i < 12; i++) {
      colorWipe(i, strip.Color(x[i].R, x[i].G, x[i].B), 50);
      delay(50);
    }
    veri_kontrol();
  }
}

void clean() {
  for (int i = 0; i < 12; i++) {
    strip.setPixelColor(i, strip.Color(0, 0, 0) );
    strip.show();
  }
}

void colorWipe(byte i, uint32_t c, uint8_t wait) {
  strip.setPixelColor(i, c);
  strip.show();
  delay(wait);
}

void serialEvent() {

  if (Serial.available() > 0) {

    delay(100);

    pw = Serial.read();
    for (int i = 0; i < 3; i++)
      sayac[i] = Serial.read();

    ID = Serial.read();
    for (int i = 0; i < 3; i++)
      sayac[i] = Serial.read();

    x[ID].R = Serial.read();
    for (int i = 0; i < 3; i++)
      sayac[i] = Serial.read();

    x[ID].G = Serial.read();
    for (int i = 0; i < 3; i++)
      sayac[i] = Serial.read();

    x[ID].B = Serial.read();
    for (int i = 0; i < 3; i++)
      sayac[i] = Serial.read();

    knt = true;
  }
}

void veri_kontrol(){

   if (Serial.available() > 0) {

    delay(100);

    pw = Serial.read();
    for (int i = 0; i < 3; i++)
      sayac[i] = Serial.read();

    ID = Serial.read();
    for (int i = 0; i < 3; i++)
      sayac[i] = Serial.read();

    x[ID].R = Serial.read();
    for (int i = 0; i < 3; i++)
      sayac[i] = Serial.read();

    x[ID].G = Serial.read();
    for (int i = 0; i < 3; i++)
      sayac[i] = Serial.read();

    x[ID].B = Serial.read();
    for (int i = 0; i < 3; i++)
      sayac[i] = Serial.read();
  }
}
