#include <DFPlayer_Mini_Mp3.h>
#include <SoftwareSerial.h>
const int trigPin = 8; //pin trigger
const int echoPin = 9; //pin echo
long duration;
int distance;

void setup() {
  Serial.begin (9600);
  pinMode (trigPin, OUTPUT);
  pinMode (echoPin, INPUT);
  
  mp3_set_serial (Serial);
  mp3_set_volume (20); //volume 0-30
}

void loop() {
// Clears pin trigger
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

//set pin trigger selama 10 microsecond
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

//membaca jarak yang dihasilkan
  duration = pulseIn(echoPin, HIGH);

//memperkirakan jarak
  distance= (duration*0.034)/2;

//tampilkan diserial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println("cm");

//Jika jarak kurang atau sama dengan 50 cm
  if (distance <= 50){
  //putar lagu
  mp3_play();
  delay (3000); //durasi disesuaikan dengan durasi musik
  mp3_stop();
}

  //jika tidak
  else {
  //matikan lagu
  mp3_stop();
  }
}
