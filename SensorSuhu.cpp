#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN 10
#define LEDPIN 13
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHT22);
LiquidCrystal_I2C lcd(0x27,20,4);

int chk;
float hum;
float temp;

void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("Syahrul Bagas H");
  lcd.setCursor(4,1);
  lcd.print("Green House");
  delay(3000);
  lcd.clear();
  pinMode(LEDPIN, OUTPUT);
}

void loop() {
  hum = dht.readHumidity();
  temp = dht.readTemperature();
  
  lcd.init();
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("Papan Informasi");
  lcd.setCursor(5,1);
  lcd.print("Green House");
  
  // menampilkan suhu
  lcd.setCursor(0,2);
  lcd.print("Suhu       :");
  lcd.setCursor(13,2);
  lcd.print(temp);
  lcd.setCursor(19,2);
  lcd.print("C");
  
  // menampilkan kelembaban
  lcd.setCursor(0,3);
  lcd.print("Kelembaban :");
  lcd.setCursor(13,3);
  lcd.print(hum);
  lcd.setCursor(19,3);
  lcd.print("%");
  
  // menyalakan LED jika suhu di atas 25 derajat Celsius
   if (temp > 25) {
    digitalWrite(LEDPIN, HIGH);
    delay(500); // menunggu selama 0,5 detik (500 ms)
    digitalWrite(LEDPIN, LOW);
    delay(100); // menunggu selama 0,5 detik (100 ms)
  } else {
    digitalWrite(LEDPIN, LOW);
  }
  
  // delay(500);
  // lcd.clear();
}
