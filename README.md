 Line Follower Robot

An autonomous robot designed to detect and follow a black line on a white surface using infrared (IR) sensors. The robot operates without human intervention and makes real-time directional decisions using an Arduino UNO microcontroller.

📘 Overview

This project involves designing and building a Line Follower Robot that follows a predefined path by detecting a black line using IR sensors.
The robot continuously monitors its path and adjusts its direction — moving forward, left, or right based on the sensor readings.
It demonstrates the core concepts of automation, sensor integration, and embedded control systems.

⚙️ Components Used
No.	Component	Quantity
1	Arduino UNO	1
2	IR Sensor Modules (Left & Right)	2
3	L293D Motor Driver Module	1
4	DC Motors & Wheels	2
5	Robot Chassis	1
6	Jumper Wires	—
7	Battery Pack	1
8	USB Cable	1
✨ Features

Automatic Path Tracking – Follows a black line autonomously.

Cost-Effective Design – Built using affordable and readily available components.

Real-Time Sensor Response – IR sensors detect the line and adjust movement instantly.

🧠 Working Principle

The IR sensors detect the reflected infrared light:

When the sensor detects a white surface, it outputs HIGH (1).

When it detects a black line, it outputs LOW (0).

The Arduino reads these signals and controls the motors through the L293D driver module to:

Go forward when both sensors are LOW.

Turn right when the left sensor detects the line.

Turn left when the right sensor detects the line.

Stop when both sensors detect the black line (dead end).

🧩 Circuit Connections
Arduino Pin	Component	Description
A0	Left IR Sensor	Input
A1	Right IR Sensor	Input
10	ENA	Motor A speed control
5	ENB	Motor B speed control
9, 8	Motor A	Direction control
7, 6	Motor B	Direction control
🧾 Code
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
  analogWrite(enA, 120); // Set motor A speed
  analogWrite(enB, 140); // Set motor B speed
}

void loop() {
  int left_value = digitalRead(left_IR);
  int right_value = digitalRead(right_IR);

  if (left_value == 1 && right_value == 0) right(); 
  else if (right_value == 1 && left_value == 0) left();
  else if (right_value == 0 && left_value == 0) forward();
  else STOP();
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

🎥 Working Demonstration

👉 Watch Project Video

🧰 Materials Required

Arduino UNO Board

IR Sensor Module (2x)

L293D Motor Driver

Robot Chassis Kit

DC Motors & Wheels

Power Supply (Battery Pack)

Jumper Wires and USB Cable

📄 License

This project is open-source and available under the MIT License
.
