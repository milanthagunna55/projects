// Pin definitions for Traffic Lights
#define RED_LANE1 4
#define GREEN_LANE1 3
#define YELLOW_LANE1 2

#define RED_LANE2 10
#define GREEN_LANE2 8
#define YELLOW_LANE2 9

#define RED_LANE3 11
#define GREEN_LANE3 12
#define YELLOW_LANE3 13

#define RED_LANE4 5
#define GREEN_LANE4 6
#define YELLOW_LANE4 7

// Pin definitions for Sensors
#define SENSOR_LANE1 14  // Sensor for Lane 1
#define SENSOR_LANE2 15  // Sensor for Lane 2
#define SENSOR_LANE3 16  // Sensor for Lane 3
#define SENSOR_LANE4 17  // Sensor for Lane 4

void setup() {
  // Set traffic light pins as output
  pinMode(GREEN_LANE1, OUTPUT);
  pinMode(YELLOW_LANE1, OUTPUT);
  pinMode(RED_LANE1, OUTPUT);

  pinMode(GREEN_LANE2, OUTPUT);
  pinMode(YELLOW_LANE2, OUTPUT);
  pinMode(RED_LANE2, OUTPUT);

  pinMode(GREEN_LANE3, OUTPUT);
  pinMode(YELLOW_LANE3, OUTPUT);
  pinMode(RED_LANE3, OUTPUT);

  pinMode(GREEN_LANE4, OUTPUT);
  pinMode(YELLOW_LANE4, OUTPUT);
  pinMode(RED_LANE4, OUTPUT);

  // Set sensor pins as input
  pinMode(SENSOR_LANE1, INPUT);
  pinMode(SENSOR_LANE2, INPUT);
  pinMode(SENSOR_LANE3, INPUT);
  pinMode(SENSOR_LANE4, INPUT);

  // Initialize all traffic lights to red (initial state)
  digitalWrite(RED_LANE1, HIGH);
  digitalWrite(RED_LANE2, HIGH);
  digitalWrite(RED_LANE3, HIGH);
  digitalWrite(RED_LANE4, HIGH);

  digitalWrite(GREEN_LANE1, LOW);
  digitalWrite(GREEN_LANE2, LOW);
  digitalWrite(GREEN_LANE3, LOW);
  digitalWrite(GREEN_LANE4, LOW);

  digitalWrite(YELLOW_LANE1, LOW);
  digitalWrite(YELLOW_LANE2, LOW);
  digitalWrite(YELLOW_LANE3, LOW);
  digitalWrite(YELLOW_LANE4, LOW);
  
  delay(200); // Initial small delay to ensure setup completion
}

void loop() {
  // Check if a vehicle is detected in any lane using the sensors
  bool vehicleInLane1 = digitalRead(SENSOR_LANE1) == HIGH;
  bool vehicleInLane2 = digitalRead(SENSOR_LANE2) == HIGH;
  bool vehicleInLane3 = digitalRead(SENSOR_LANE3) == HIGH;
  bool vehicleInLane4 = digitalRead(SENSOR_LANE4) == HIGH;

  // Lane 1: Green if vehicle detected, otherwise Red
  if (vehicleInLane1) {
    digitalWrite(GREEN_LANE1, HIGH);
    digitalWrite(RED_LANE1, LOW);
    digitalWrite(YELLOW_LANE1, LOW);
  } else {
    digitalWrite(GREEN_LANE1, LOW);
    digitalWrite(RED_LANE1, HIGH);
    digitalWrite(YELLOW_LANE1, LOW);
  }

  // Lane 2: Green if vehicle detected, otherwise Red
  if (vehicleInLane2) {
    digitalWrite(GREEN_LANE2, HIGH);
    digitalWrite(RED_LANE2, LOW);
    digitalWrite(YELLOW_LANE2, LOW);
  } else {
    digitalWrite(GREEN_LANE2, LOW);
    digitalWrite(RED_LANE2, HIGH);
    digitalWrite(YELLOW_LANE2, LOW);
  }

  // Lane 3: Green if vehicle detected, otherwise Red
  if (vehicleInLane3) {
    digitalWrite(GREEN_LANE3, HIGH);
    digitalWrite(RED_LANE3, LOW);
    digitalWrite(YELLOW_LANE3, LOW);
  } else {
    digitalWrite(GREEN_LANE3, LOW);
    digitalWrite(RED_LANE3, HIGH);
    digitalWrite(YELLOW_LANE3, LOW);
  }

  // Lane 4: Green if vehicle detected, otherwise Red
  if (vehicleInLane4) {
    digitalWrite(GREEN_LANE4, HIGH);
    digitalWrite(RED_LANE4, LOW);
    digitalWrite(YELLOW_LANE4, LOW);
  } else {
    digitalWrite(GREEN_LANE4, LOW);
    digitalWrite(RED_LANE4, HIGH);
    digitalWrite(YELLOW_LANE4, LOW);
  }

  // Sequence for all lanes (assuming lane 1 has priority, for example)
  if (vehicleInLane1) {
    delay(5000); // Lane 1 stays green for 5 seconds if a vehicle is detected
  }

  if (vehicleInLane2) {
    delay(5000); // Lane 2 stays green for 5 seconds if a vehicle is detected
  }

  if (vehicleInLane3) {
    delay(5000); // Lane 3 stays green for 5 seconds if a vehicle is detected
  }

  if (vehicleInLane4) {
    delay(5000); // Lane 4 stays green for 5 seconds if a vehicle is detected
  }

  // If no vehicle is detected, all lanes should be red
  if (!vehicleInLane1 && !vehicleInLane2 && !vehicleInLane3 && !vehicleInLane4) {
    digitalWrite(RED_LANE1, HIGH);
    digitalWrite(RED_LANE2, HIGH);
    digitalWrite(RED_LANE3, HIGH);
    digitalWrite(RED_LANE4, HIGH);
    digitalWrite(GREEN_LANE1, LOW);
    digitalWrite(GREEN_LANE2, LOW);
    digitalWrite(GREEN_LANE3, LOW);
    digitalWrite(GREEN_LANE4, LOW);
    delay(2000); // Red light stays on for all lanes for 2 seconds
  }
}
