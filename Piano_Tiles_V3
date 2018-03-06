const int piezo = 8;
const int trigger1 = 9;
const int trigger2 = 7;

const int echo1 = 10;
const int echo1 = 11;

void setup() {
  pinMode(piezo, OUTPUT);
  pinMode(trigger1, OUTPUT);  
  pinMode(trigger2, OUTPUT);  
  pinMode(echo1, INPUT); 
  pinMode(echo2, INPUT);
  Serial.begin(9600); 
}

void loop() {
  detectStep(trigger1, echo1, 1000)
  detectStep(trigger2, echo2, 2000)
}

void detectStep (trigger, echo, frequency) {
  long duration;
  int distance;
  
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigger, LOW);

  duration = pulseIn(echo, HIGH);
  distance = duration*0.034/2;

  Serial.println (distance);

  if (distance < 35) {
    tone(piezo, frequency, 500);
    Serial.println("step 1");
  } else {
    noTone(piezo);
  }
}
