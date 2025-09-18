/*

A nice place to keep all of the constants being used in this sketch

*/
#ifndef ColdPlungeConstants_h
#define ColdPlungeConstants_h


const bool DEV_MODE = 0;

// The relay shield uses pins 4-7
const int ARR_RELAYPINS[] = {4,5,6,7};
const int PIN_RELAY_UNUSED = 4;
const int PIN_RELAY_PUMP = 5;
const int PIN_RELAY_OZONE = 6;
const int PIN_RELAY_CHILLER = 7;

const int PIN_CURRENT_CHILLER = A1;   // Analog input pin for current sensor
const int PIN_TEMP_SENSOR = A0;        // Analog input pin for voltage of thermistor
const int PIN_FLOW_SENSOR = 3;        // Sensor for flow

const int TIME_ACCELERATOR = (DEV_MODE ? 120 : 1);   // Set to 1 for production, but for testing we can decrease all periods by 60 so one minute becomes 1 second 

const int MINS = 1000*60;          // One minute is 60000 ms
const int HRS = MINS * 60;         // One hour is 60 mins

// Lucid Chart is here: https://lucid.app/lucidchart/1e63e848-da89-4b3a-9d73-76b039f0eef8/edit?invitationId=inv_ef632815-1f97-4c4f-9197-4ef0d59d3a5f

const unsigned long MAIN_OFFSET       = round(5 * MINS / TIME_ACCELERATOR);   // Wait x minutes after each programming to start the main cycle...

// Not sure if I'm going to use period or gap to control scheduling for MAIN cycle?
// const unsigned long MAIN_PERIOD       = round(60 * MINS / TIME_ACCELERATOR);  //  Cycle every hour 
const unsigned long MAIN_GAP          = round(2 * HRS / TIME_ACCELERATOR);  //  GAP to wait after cycle before scheduling next cycle 

// const unsigned long MAIN_DURATION_MIN = round(10 * MINS / TIME_ACCELERATOR);  // Run for as little as 10 minutes
const unsigned long MAIN_DURATION_MAX = round(45 * MINS / TIME_ACCELERATOR);  // Run for as long as 45 minutes

const unsigned long OZONE_DURATION    = round(10 * MINS / TIME_ACCELERATOR);  // Ozone Cycle lasts 10 minutes
const unsigned long OZONE_PERIOD      = round(24 * HRS / TIME_ACCELERATOR);   // Ozone Cycle repeats after 24 hours
const unsigned long OZONE_OFFSET      = round(3  * HRS / TIME_ACCELERATOR);   // Wait 3 hours before starting ozone after reprogramming

const unsigned long FLOW_CHECK_OFFSET = round(2 * MINS / TIME_ACCELERATOR);   // After flow is started, wait 2 minutes for flow check to stabilize before enforcing
const unsigned long FLOW_CHECK_PERIOD = round(1 * MINS / TIME_ACCELERATOR);   // After re-check every minute to ensure flow is still working



// Thermistor Values
const float BETA      = 3950;   // 3974.0;
const float ROOM_TEMP = 298.15; // room temperature in Kelvin
const float Ro        = 10000.0;      // Resistance of the thermistor at roomTemp
const float R1        = 9880.0;       // Resistnce of the known resistor



const unsigned long PERIOD_CHILLER = round(30 * MINS / TIME_ACCELERATOR); // Run Chiller for up to 30 minutes


/*
// const int RELAY_BASE = 4;      // The first relay is connected to digital pin 4
// const int RELAY_NUM = 4;       // Total number of relays
// const int RELAY_DELAY = 4000;  // Total seconds between relay changes
// const int FLOW_PIN = 3;        // Pin for yellow flow meter
// const int ANALOG_CURRENT_PIN = A0;

// // EnergyMonitor emon1;
// const int numReadings = 30;      // number of samples for rolling average
// int readings[numReadings];       // array to store the readings
// int readIndex = 0;               // current index in the array
// long total = 0;                  // sum of readings
// int average = 0;

// // Method to return Freq for flow counter
// float getFrequency(int pin) {
//   unsigned long highTime = pulseIn(pin, HIGH);
//   unsigned long lowTime = pulseIn(pin, LOW);
//   unsigned long period = highTime + lowTime;  // total time in microseconds
//   if (period == 0) return 0;  // protect against divide by zero errors
//   return 1000000.0 / period;  // frequency in hertz
// }

// // Convert frequency counter to gallons per minute
// float getGalPerMin(float frequency) {
//   // According to specs, 1380 clicks corresponds to a gallon of water
//   return frequency / 1380 * 60;
// }

// float getCurrent(int pin) {
//   int sensorValue = analogRead(pin);
//   float voltage = sensorValue * (5.0/1023.0);  // Convert ADC value to voltage
//   float current = voltage / 0.185;              // Example adjustment
//   Serial.print("Sensor: ");
//   Serial.print(sensorValue); 
//   Serial.print(" / Voltage: ");
//   Serial.print(voltage);
//   Serial.print(" / Current: ");
//   Serial.print(current);
//   Serial.println(" A");
//   return current;
// }


  // float freq = getFrequency(FLOW_PIN);
  // flowRate = getGalPerMin(freq);
  // Serial.print("Frequency: ");
  // Serial.print(freq);
  // Serial.print(" Hz => ");
  // Serial.print(flowRate);
  // Serial.println(" Gal/Min");

  // // subtract the oldest reading
  // total -= readings[readIndex];
  // // read from the sensor
  // readings[readIndex] = analogRead(PIN_CURRENT_CHILLER);
  // // add the new reading
  // total += readings[readIndex];
  // // advance to the next position
  // readIndex = (readIndex + 1) % numReadings;
  // // calculate the average
  // average = total / numReadings;

  // Serial.print("Rolling average: ");
  // Serial.print(average);


  // float voltage = average * (5.0/1023.0);  // Convert ADC value to voltage
  // float current = voltage / 0.185;              // Example adjustment
  // Serial.print(" / Voltage: ");
  // Serial.print(voltage);
  // Serial.print(" / Current: ");
  // Serial.print(current);
  // Serial.println(" A");
  
  // delay(200);

  
  // float cur = getCurrent(ANALOG_CURRENT_PIN);

  // emon1.serialprint();
  
  // delay(100);
*/


#endif
