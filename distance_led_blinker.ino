#define trigPin 2
#define echoPin 3

#define ledPin 5

long duration;
int distance;
int blinkSpeed;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;

  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.println(" cm");

  blinkSpeed = map(distance, 0, 200, 50, 500);

  digitalWrite(ledPin, HIGH);
  delay(blinkSpeed);
  digitalWrite(ledPin, LOW);
  delay(blinkSpeed);
}
