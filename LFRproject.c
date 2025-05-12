#define enA 10
#define in1 9
#define in2 8
#define in3 7
#define in4 6
#define enB 5

#define left_IR A0
#define right_IR A1

void setup() {
  Serial.begin(9600);
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(left_IR, INPUT);
  pinMode(right_IR, INPUT);

  analogWrite(enA, 120);
  analogWrite(enB, 140);
}

void loop() {
  int left_value = digitalRead(left_IR);
  int right_value = digitalRead(right_IR);

  if (left_value == 1 && right_value == 0) {
    right();
  } else if (right_value == 1 && left_value == 0) {
    left();
  } else if (right_value == 0 && left_value == 0) {
    forward();
  } else if (right_value == 1 && left_value == 1) {
    STOP();
  } else {
    STOP();
  }
}

void right() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void left() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void STOP() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void forward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}





