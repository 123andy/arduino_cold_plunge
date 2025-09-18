#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>
#include <Arduino_NetworkConfigurator.h>
#include "configuratorAgents/agents/BLEAgent.h"
#include "configuratorAgents/agents/SerialAgent.h"
void onTempSetpointChange();
void onChillerOnChange();
void onFlowFailDetectedChange();
void onOzoneEligibleChange();
void onOzoneOnChange();
void onPumpOnChange();

String next_cycle;
String next_ozone;
float chiller_current;
float flow_rate;
float temp_current;
int temp_setpoint;
bool chiller_on;
bool flow_fail_detected;
bool ozone_eligible;
bool ozone_on;
bool pump_on;

KVStore kvStore;
BLEAgentClass BLEAgent;
SerialAgentClass SerialAgent;
WiFiConnectionHandler ArduinoIoTPreferredConnection; 
NetworkConfiguratorClass NetworkConfigurator(ArduinoIoTPreferredConnection);

void initProperties(){
  NetworkConfigurator.addAgent(BLEAgent);
  NetworkConfigurator.addAgent(SerialAgent);
  NetworkConfigurator.setStorage(kvStore);
  // For changing the default reset pin uncomment and set your preferred pin. Use DISABLE_PIN for disabling the reset procedure.
  //NetworkConfigurator.setReconfigurePin(your_pin);
  ArduinoCloud.setConfigurator(NetworkConfigurator);

  ArduinoCloud.addProperty(next_cycle, READ, 10 * SECONDS, NULL);
  ArduinoCloud.addProperty(next_ozone, READ, 10 * SECONDS, NULL);
  ArduinoCloud.addProperty(chiller_current, READ, ON_CHANGE, NULL);
  ArduinoCloud.addProperty(flow_rate, READ, ON_CHANGE, NULL);
  ArduinoCloud.addProperty(temp_current, READ, ON_CHANGE, NULL);
  ArduinoCloud.addProperty(temp_setpoint, READWRITE, ON_CHANGE, onTempSetpointChange);
  ArduinoCloud.addProperty(chiller_on, READWRITE, ON_CHANGE, onChillerOnChange);
  ArduinoCloud.addProperty(flow_fail_detected, READWRITE, ON_CHANGE, onFlowFailDetectedChange);
  ArduinoCloud.addProperty(ozone_eligible, READWRITE, ON_CHANGE, onOzoneEligibleChange);
  ArduinoCloud.addProperty(ozone_on, READWRITE, ON_CHANGE, onOzoneOnChange);
  ArduinoCloud.addProperty(pump_on, READWRITE, ON_CHANGE, onPumpOnChange);

}
