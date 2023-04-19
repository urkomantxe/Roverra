#include <Traktorinoa.h>
#include <UltraDistSensor.h>
#include <Servo.h>

Traktorinoa niretraktorinoa;
UltraDistSensor mysensor;
Servo pintza; // Serbo objetua sortzen du
Servo engranaia; // Serbo objetua sortzen du
float reading;

void setup()
{
  Serial.begin(9600);
  mysensor.attach(7, 8); //Trigger pin , Echo pin
  engranaia.attach(9); // Serboa  Arduinoko 6. Pin-era
  engranaia.write(100);  // goian 180    behean 50
  pintza.attach(6);
  pintza.write(90);     //  itxita 120  irekita 90
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
      case 's': engranaia.write(180); break; // goian 180    behean 50
      case 'i': engranaia.write(70); break; // goian 180    behean 50
      case 'e': pintza.write(90); break;  //  itxita 120  irekita 90
      case 'g': pintza.write(120); break; //  itxita 120  irekita 90
      default : break;
    }
  }
  delay(50);

  reading = mysensor.distanceInCm();
  /* while (reading >1 && reading <40){
     niretraktorinoa.geratu();
     nireSerboa.write(90);
     delay (5000);
     niretraktorinoa.atzera();
     reading = mysensor.distanceInCm();
     }
  */
}
