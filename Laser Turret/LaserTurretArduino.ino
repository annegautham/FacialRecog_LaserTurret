#include<Servo.h>

Servo x, y;
int width = 640, height = 480;  // total resolution of the video
int xpos = 120, ypos = 140;  // initial positions of both Servos
int laserPin = 11;
int buzzerPin = 8;
void setup() {

  Serial.begin(9600);
  x.write(xpos);
  y.write(ypos);
  x.attach(9);
  y.attach(10);
  pinMode(laserPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);


}
const int angle = 3;   // degree of increment or decrement

void loop() {
  if (Serial.available() > 0)
  {
    int x_mid, y_mid;
    if (Serial.read() == 'X')
    {
      x_mid = Serial.parseInt();  // read center x-coordinate
      if (Serial.read() == 'Y')
        y_mid = Serial.parseInt(); // read center y-coordinate
    }
  // Adjusting Servo
    if (x_mid > width / 2 + 30)
      xpos += angle;
    if (x_mid < width / 2 - 30)
      xpos -= angle;
    if (y_mid < height / 2 + 30)
      ypos -= angle;
    if (y_mid > height / 2 - 30)
      ypos += angle;


    // if the servo degree is outside its range
    if (xpos >= 180)
      xpos = 180;
    else if (xpos <= 0)
      xpos = 0;
    if (ypos >= 180)
      ypos = 180;
    else if (ypos <= 0)
      ypos = 0;

    x.write(xpos);
    y.write(ypos);
    fire();
    }

}
void fire(){
    digitalWrite(laserPin, HIGH);
    tone(buzzerPin,2200);
    tone(buzzerPin,1000);
    tone(buzzerPin,500);
    tone(buzzerPin,200);
    tone(buzzerPin,500);
    delayMicroseconds(10000);
    noTone(buzzerPin);
    delayMicroseconds(10000);
    tone(buzzerPin,2200); 
    tone(buzzerPin,1000);
    delayMicroseconds(10000);
    noTone(buzzerPin);
    delayMicroseconds(10000);
    tone(buzzerPin,100); 
    delayMicroseconds(10000);
    noTone(buzzerPin);
    delayMicroseconds(10000);
    tone(buzzerPin,100); 
    delayMicroseconds(10000);
    noTone(buzzerPin);
    delayMicroseconds(10000);
}
