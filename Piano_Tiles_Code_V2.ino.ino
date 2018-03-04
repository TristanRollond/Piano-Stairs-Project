



const int piezo = 8;
const int trigger1 = 9;
const int trigger2 = 7;

const int echo_one = 10;
const int echo_two = 11;

long echo_one_duration;
long echo_two_duration;

int echo_one_distance;
int echo_two_distance;

void setup() {
  pinMode(piezo, OUTPUT);
  pinMode(trigger1, OUTPUT);  
  pinMode(trigger2, OUTPUT);  
  pinMode(echo_one, INPUT); 
  pinMode(echo_two, INPUT);
  Serial.begin(9600); 
}

void loop() {
  digitalWrite(trigger1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger1, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigger1, LOW);
  
  echo_one_duration = pulseIn(echo_one, HIGH);
  echo_one_distance = echo_one_duration*0.034/2;

  
  digitalWrite(trigger2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger2, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigger2, LOW);

  echo_two_duration = pulseIn(echo_two, HIGH);
  echo_two_distance = echo_two_duration*0.034/2;

  Serial.println (echo_one_distance);
  Serial.println (echo_two_distance);
  
  if (echo_one_distance < 35) {
    tone(piezo, 1000, 500);
    Serial.println("step 1");
  } else {
    noTone(piezo);
  }
  
  if (echo_two_distance < 35) {
    tone(piezo, 2000, 500);
    Serial.println("step 2");
  } else {
    noTone(piezo);
  }
}
