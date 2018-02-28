const int piezo = 8;
const int trigger = 9;
const int echo_one = 10;
const int echo_two = 11;
const int echo_three = 12;

long echo_one_duration;
long echo_two_duration;
long echo_three_duration;

int echo_one_distance;
int echo_two_distance;
int echo_three_distance;

void setup() {
  pinMode(sound, OUTPUT);
  pinMode(tigger, OUTPUT);  
  pinMode(echo_one, INPUT); 
  pinMode(echo_two, INPUT);
  pinMode(echo_three, INPUT);
  Serial.begin(9600); 
}

void loop() {
  digitalWrite(trigger, LOW);
  
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  
  echo_one_duration = pulseIn(echo_one, HIGH);
  echo_one_distance = echo_one_duration*0.034/2;
  
  echo_two_duration = pulseIn(echo_two, HIGH);
  echo_two_distance = echo_two_duration*0.034/2;
  
  echo_three_duration = pulseIn(echo_three, HIGH);
  echo_three_distance = echo_three_duration*0.034/2;
  
  if (echo_one_distance < 35) {
    tone(piezo, NOTE_C4, 500);
  } else {
    noTone(sound);
  }
  
  if (echo_two_distance < 35) {
    tone(piezo, NOTE_D4, 500);
  } else {
    noTone(sound);
  }
  
  if (echo_three_distance < 35) {
    tone(piezo, NOTE_E4, 500);
  } else {
    noTone(sound);
  }
}
