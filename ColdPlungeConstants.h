/*

A nice place to keep all of the constants being used in this sketch

*/
#ifndef ColdPlungeConstants_h
#define ColdPlungeConstants_h


const bool DEV_MODE = 1;


// The relay shield uses pins 4-7
const int[] RELAYPINS = {4,5,6,7}
const int RELAY_PIN_UNUSED = 4;
const int RELAY_PIN_PUMP = 5;
const int RELAY_PIN_OZONE = 6;
const int RELAY_PIN_CHILLER = 7;


const int CURRENT_PIN_CHILLER = A0;    // Analog input pin for current sensor

const int TIME_ACCELERATOR = (DEV_MODE ? 60 : 1);   // Set to 1 for production, but for testing we can decrease all periods by 60 so one minute becomes 1 second 

const int MINS = 1000*60;          // One minute is 60000 ms
const int HRS = MINS * 60;         // One hour is 60 mins

// Lucid Chart is here: https://lucid.app/lucidchart/1e63e848-da89-4b3a-9d73-76b039f0eef8/edit?invitationId=inv_ef632815-1f97-4c4f-9197-4ef0d59d3a5f


const unsigned long OFFSET_MAIN = round(1 * MINS / TIME_ACCELERATOR);   // Wait one minute after each programming to start the pump
const unsigned long PERIOD_MAIN = round(60 * MINS / TIME_ACCELERATOR);  //  Cycle every hour 
const unsigned long PERIOD_OZONE = round(24 * HRS / TIME_ACCELERATOR);  // Ozone Cycle every 24 hours
const unsigned long OFFSET_OZONE = round(12 * HRS / TIME_ACCELERATOR);  // Wait 12 hours before starting ozone after reprogramming


const unsigned long PERIOD_CHILLER = round(30 * MINS / TIME_ACCELERATOR); // Run Chiller for up to 30 minutes




#endif
