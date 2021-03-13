#include <Arduino.h>
#include <TM1637Display.h>
#include <IRremote.h>

//Set display pins
#define CLK 4
#define DIO 5

TM1637Display display(CLK, DIO); //display object

#include <Adafruit_Sensor.h>
#include <DHT.h>
// Set DHT pin:
#define DHTPIN 2
// Set DHT type: DHT22 (the other type is DHT11)
#define DHTTYPE DHT22  
// Initialize DHT sensor for normal 16mhz Arduino:
DHT dht = DHT(DHTPIN, DHTTYPE);

void setup() {
  IrSender.begin(true);
  // Begin serial communication at a baud rate of 9600:
  Serial.begin(9600);
  // Setup sensor:
  dht.begin();
  display.setBrightness(0x00); //Set brightness to minimum level
}

void loop() {
  const uint8_t celsius[] = {
  SEG_A | SEG_B | SEG_F | SEG_G,  // Circle for temperature celsius degrees
};
const uint8_t H[] = {
  
  SEG_B | SEG_C | SEG_E | SEG_F | SEG_G  // "H" for Humidity
};

//IR address code from the air conditioner and command to turn it OFF
uint16_t sAddress = 0x10;
uint8_t sCommand = 0x00;


float h = dht.readHumidity(); //read humidity from sensor
int humedad = h*10; //convert to int (the display only works with ints)
int decimales;
decimales=humedad%10; //obtain the digit after the coma
float t = dht.readTemperature(); //read temperature from sensor
int temperatura = t*10; //convert to int
int decimales2; 
decimales2=temperatura%10; //obtain the digit after the coma

//show humidity on the display
display.showNumberDec(humedad,true,3,0);
display.setSegments(H, 1, 2);
display.showNumberDec(decimales,true,1,3);

//wait for 1 second
delay(1000);

//show temperature on the display
display.showNumberDec(temperatura,true,3,0);
display.setSegments(celsius, 1, 2);
display.showNumberDec(decimales2,true,1,3);

//wait another second
delay(1000);

//print thermal sensation
Serial.print("Sensación térmica: ");
Serial.println(dht.computeHeatIndex(t, h, false));

if (h < 40) //if humidity is below 40%
  IrSender.sendNEC(sAddress, sCommand, 0); //turn off th air conditioner

}
