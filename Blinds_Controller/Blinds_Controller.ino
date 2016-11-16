#include <ESP8266WiFi.h>
#include <Adafruit_PWMServoDriver.h>
#include <Wire.h>

#define servomin 150
#define servomax 600
int max = 680;
int min = 0;
Adafruit_PWMServoDriver driver = Adafruit_PWMServoDriver();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println();

  WiFi.begin{Guest);
  Wire.begin(12, 13);
  driver.begin();
  driver.setPWMFreq(60);
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
    driver.setPWM(0, 0, 560);
    Serial.println("560");
    delay(2000);
    driver.setPWM(0,0,1);
    Serial.println("1");
    delay(2000);
}
