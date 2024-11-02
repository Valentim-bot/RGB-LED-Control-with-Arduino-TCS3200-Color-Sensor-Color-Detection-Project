
// Define color sensor pins
#define RedLED 9
#define GreenLED 10
#define BlueLED 11

#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8

// Calibration Values
// Get these from Calibration Sketch

int redMin = 90; // Red minimum value
int redMax = 285; // Red maximum value
int greenMin = 95; // Green minimum value
int greenMax = 295; // Green maximum value
int blueMin = 75; // Blue minimum value
int blueMax = 235; // Blue maximum value

// Variables for Color Pulse Width Measurements

int redPW = 0;
int greenPW = 0;
int bluePW = 0;

// Variables for final Color values

int redValue;
int greenValue;
int blueValue;

void setup() {

  // Set S0 - S3 as outputs
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);

  pinMode(RedLED, OUTPUT);
  pinMode(BlueLED, OUTPUT);
  pinMode(GreenLED, OUTPUT);
  
  // Set Sensor output as input
  pinMode(sensorOut, INPUT);
  
  // Set Frequency scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  
  // Setup Serial Monitor
  Serial.begin(9600);
}

void loop() {
  
  // Read Red value
  redPW = getRedPW();
  // Map to value from 0-255
  redValue = map(redPW, redMin,redMax,255,0);
  // Delay to stabilize sensor
  delay(200);
  
  // Read Green value
  greenPW = getGreenPW();
  // Map to value from 0-255
  greenValue = map(greenPW, greenMin,greenMax,255,0);
  // Delay to stabilize sensor
  delay(200);
  
  // Read Blue value
  bluePW = getBluePW();
  // Map to value from 0-255
  blueValue = map(bluePW, blueMin,blueMax,255,0);
  // Delay to stabilize sensor
  delay(200);
  
  // Print output to Serial Monitor
  /*Serial.print("Red = ");
  Serial.print(redValue);
  Serial.print(" - Green = ");
  Serial.print(greenValue);
  Serial.print(" - Blue = ");
  Serial.println(blueValue);*/
  // Assuming variables red, green, and blue hold the current color readings

// Assuming variables red, green, and blue hold the current RGB readings

// Assuming redValue, greenValue, and blueValue hold the current RGB readings

// Check for Green
if (redValue>235 && redValue<265 && greenValue>240 && greenValue<265 && blueValue>235 && blueValue<265) {
    // This is WHITE

    Serial.println("This is White");
}



if (redValue>128 && redValue<150 && greenValue>215 && greenValue<245 && blueValue>238 && blueValue<260) {
    // This is BLUE

   Serial.println("This is blue");
   digitalWrite(BlueLED, 1);
   digitalWrite(GreenLED, 0);
   digitalWrite(RedLED, 0);
}

if (redValue>180 && redValue<215 && greenValue>215 && greenValue<245 && blueValue>170 && blueValue<185) {
    // This is GREEN

   Serial.println("This is green");
   digitalWrite(BlueLED, 0);
   digitalWrite(GreenLED, 1);
   digitalWrite(RedLED, 0);
}

if (redValue>190 && redValue<220 && greenValue>20 && greenValue<50 && blueValue>20 && blueValue<48) {
    // This is RED

   Serial.println("This is red");
    digitalWrite(BlueLED, 0);
   digitalWrite(GreenLED, 0);
   digitalWrite(RedLED, 1);
}


if (redValue>40 && redValue<65 && greenValue>-40 && greenValue<-18 && blueValue>-60 && blueValue<-30) {
    // This is BLACK

   Serial.println("This is black");
  
}
else if(redValue>250 && redValue<285 && greenValue>250 && greenValue<275 && blueValue>190 && blueValue<215){

  Serial.println("Color: YELLOW");
 
    digitalWrite(BlueLED, 0);
   digitalWrite(GreenLED, 0);
   digitalWrite(RedLED, 0);
  

}


  // Print output to Serial Monitor
  Serial.print("Red = ");
  Serial.print(redValue);
  Serial.print(" - Green = ");
  Serial.print(greenValue);
  Serial.print(" - Blue = ");
  Serial.println(blueValue);
  
}


// Function to read Red Pulse Widths
int getRedPW() {

  // Set sensor to read Red only
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Define integer to represent Pulse Width
  int PW;
  // Read the output Pulse Width
  PW = pulseIn(sensorOut, LOW);
  // Return the value
  return PW;

}

// Function to read Green Pulse Widths
int getGreenPW() {

  // Set sensor to read Green only
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Define integer to represent Pulse Width
  int PW;
  // Read the output Pulse Width
  PW = pulseIn(sensorOut, LOW);
  // Return the value
  return PW;

}

// Function to read Blue Pulse Widths
int getBluePW() {

  // Set sensor to read Blue only
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  // Define integer to represent Pulse Width
  int PW;
  // Read the output Pulse Width
  PW = pulseIn(sensorOut, LOW);
  // Return the value
  return PW;

}