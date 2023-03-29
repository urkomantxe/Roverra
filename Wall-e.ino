#include <Traktorinoa.h>
#include<UltraDistSensor.h>
#include <Servo.h>

Traktorinoa niretraktorinoa;
UltraDistSensor mysensor;
Servo nireSerboa; // Serbo objetua sortzen du
float reading;

void setup()
{
  Serial.begin(9600);
  mysensor.attach(7, 8); //Trigger pin , Echo pin
nireSerboa.attach(9); // Serboa  Arduinoko 6. Pin-era
nireSerboa.write(20);
}

void loop() {

  if (Serial.available() > 0) {
    char data = Serial.read(); // bluetooth modulutik datorren datua irakurri
    switch (data)
    {
      case 'a': niretraktorinoa.aurrera(); break; 
      case 'b': niretraktorinoa.atzera(); break; 
      case 'c': niretraktorinoa.ezkerrera(); break; 
      case 'd': niretraktorinoa.eskuinera(); break; 
      case 'p': niretraktorinoa.geratu(); break;  
      default : break;
    }
  }
  delay(50);
 
  reading = mysensor.distanceInCm();
  while (reading >1 && reading <40){
    niretraktorinoa.geratu();
    nireSerboa.write(90);
    delay (5000);
    niretraktorinoa.atzera();
    reading = mysensor.distanceInCm();
    } 
}
