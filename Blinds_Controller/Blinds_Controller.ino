/* For this code to work you 
 *  need to add a file called api.h
 *  using the specific template in the github repository.
 *  Add your Blynk API Key to the variable. 
 *  The reason for this is because if it was right in the file, anyone
 *  could access the key and mess with your project. The file api.h is
 *  already set up in .gitignore so it will not sync with github. 
 */


#include <BlynkSimpleEsp8266.h>
#include <ESP8266WiFi.h>
#include <Adafruit_PWMServoDriver.h>
#include <Wire.h>
#include "Api.h"


int servoMax = 645;
int servoMin = 0;
Adafruit_PWMServoDriver driver = Adafruit_PWMServoDriver();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
 /* Serial.println("");
  WiFi.begin("Guest");
  Serial.println("Connecting to Wifi");
  delay(500);
  while (WiFi.status() !=WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi Connected");
  Serial.println("IP Address: ");
  Serial.println(WiFi.localIP());*/
  Serial.println(key);
  Blynk.begin(key, "Guest", "hh");
  Wire.begin(12, 13);
  Serial.println("I2C ready");
  driver.begin();
  driver.setPWMFreq(60);
  Serial.println("Servo Driver Ready");
  Serial.println(WiFi.localIP());
  bool result = Blynk.connected();
  Serial.println(result);

  
}

BLYNK_WRITE(V1){
  int angle = param.asInt();
  int len = map(angle, 0, 160, 0, 153);
  len = map(angle, 0, 153, servoMin, servoMax);
  Serial.println("angle" + angle);
  Serial.println("len" + len);
  driver.setPWM(0, 0, len);
}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
 /*   driver.setPWM(0, 0, 560);
    Serial.println("560");
    delay(2000);
    driver.setPWM(0,0,1);
    Serial.println("1");
    delay(2000);*/
}
