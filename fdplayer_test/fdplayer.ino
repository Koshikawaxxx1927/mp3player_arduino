#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

SoftwareSerial mySoftwareSerial(10, 11);
DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_y type, int value);

void setup()
{
    
}