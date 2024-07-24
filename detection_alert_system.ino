// Force sensor pins
#define FORCE_FRONT_PIN A0
#define FORCE_BACK_PIN A1
#define FORCE_LEFT_PIN A2
#define FORCE_RIGHT_PIN A3
#define FORCE_TOP_PIN A4

// Detection ranges
#define MIN_ANALOG_VAL 0
#define MAX_ANALOG_VAL 1023
#define MIN_FORCE 0
#define MAX_FORCE 50

// constant values
const int DELAY_MS = 1;
const int FORCE_THRESHOLD = 10; // Arbitrary value
const int ACCEL_THRESHOLD = 70;
const int ROTATION_THRESHOLD = 5582;

void setup() {
  Serial.begin(9600);
  while (!Serial)
    delay(10); // will pause until serial console opens
}

void loop() {
  // Get force readings
  int frontVal = analogRead(FORCE_FRONT_PIN);
  int backVal = analogRead(FORCE_BACK_PIN);
  int leftVal = analogRead(FORCE_LEFT_PIN);
  int rightVal = analogRead(FORCE_RIGHT_PIN);
  int topVal = analogRead(FORCE_TOP_PIN);

  // Convert analog values (0-1023) to force detection range (up to 50 N)
  int frontForce = map(frontVal, MIN_ANALOG_VAL, MAX_ANALOG_VAL, MIN_FORCE, MAX_FORCE);
  int backForce = map(backVal, MIN_ANALOG_VAL, MAX_ANALOG_VAL, MIN_FORCE, MAX_FORCE);
  int leftForce = map(leftVal, MIN_ANALOG_VAL, MAX_ANALOG_VAL, MIN_FORCE, MAX_FORCE);
  int rightForce = map(rightVal, MIN_ANALOG_VAL, MAX_ANALOG_VAL, MIN_FORCE, MAX_FORCE);
  int topForce = map(topVal, MIN_ANALOG_VAL, MAX_ANALOG_VAL, MIN_FORCE, MAX_FORCE);

  // Output force readings
  Serial.print("    Force (FRONT): ");
  Serial.print(frontVal);
  Serial.print("  ");
  Serial.print(frontForce);

  Serial.print("    Force (BACK): ");
  Serial.print(backVal);
  Serial.print("  ");
  Serial.print(backForce);

  Serial.print("    Force (LEFT): ");
  Serial.print(leftVal);
  Serial.print("  ");
  Serial.print(leftForce);

  Serial.print("    Force (RIGHT): ");
  Serial.print(rightVal);
  Serial.print("  ");
  Serial.print(rightForce);

  Serial.print("    Force (TOP): ");
  Serial.print(topVal);
  Serial.print("  ");
  Serial.println(topForce);

  // Determine if force is enough to likely result in a concussion
  if(frontForce > FORCE_THRESHOLD) {
    Serial.println();
    Serial.println("-------------FRONT FORCE EXCEEDED-------------");
    Serial.print("Force of ");
    Serial.print(frontForce);
    Serial.println(" N was detected on front sensor.");
    Serial.println("Consider seeking medical attention.");
    Serial.println();
  }
  else if(backForce > FORCE_THRESHOLD) {
    Serial.println();
    Serial.println("-------------BACK FORCE EXCEEDED-------------");
    Serial.print("Force of ");
    Serial.print(backForce);
    Serial.println(" N was detected on back sensor.");
    Serial.println("Consider seeking medical attention.");
    Serial.println();
  } 
  else if(leftForce > FORCE_THRESHOLD) {
    Serial.println();
    Serial.println("-------------LEFT FORCE EXCEEDED-------------");
    Serial.print("Force of ");
    Serial.print(leftForce);
    Serial.println(" N was detected on left sensor.");
    Serial.println("Consider seeking medical attention.");
    Serial.println();
  }
  else if(rightForce > FORCE_THRESHOLD) {
    Serial.println();
    Serial.println("-------------RIGHT FORCE EXCEEDED-------------");
    Serial.print("Force of ");
    Serial.print(rightForce);
    Serial.println(" N was detected on right sensor.");
    Serial.println("Consider seeking medical attention.");
    Serial.println();
  }
  else if(topForce > FORCE_THRESHOLD) {
    Serial.println();
    Serial.println("-------------TOP FORCE EXCEEDED-------------");
    Serial.print("Force of ");
    Serial.print(topForce);
    Serial.println(" N was detected on top sensor.");
    Serial.println("Consider seeking medical attention.");
    Serial.println();
  }
}
