# Humidity conditioning

I used an Arduino UNO connected to a DHT22 sensor to measure humidity. When humidity goes too low, it sends an IR message to turn off the air conditioner with an IR led.

It also shows temperature and humidity on a 4 digit display.

## Supplies

* TM1637 4-digit 7-segment display
* Breadboard
* Arduino Uno
* DHT22 sensor
* 4,7k resistor
* 47 ohm resistor
* IR led

## Wiring diagram

* DHT22 will need a 4.7k to 10k pullup resistor (see [datasheet](https://www.makerguides.com/wp-content/uploads/2019/02/DHT22-AM2302-Datasheet.pdf) page 4)

![IrHumedadMariano_´PS](https://user-images.githubusercontent.com/79780807/111042674-4e72da80-841d-11eb-8fe1-e626ae02e580.jpg)

## Code

* You can download it from [here](https://github.com/MarianoDesivo/Humidity-conditioning/blob/main/HumidityConditioning.ino).
* If you don't know the IR code for your air conditioner you can get it with this [code](https://github.com/Arduino-IRremote/Arduino-IRremote/tree/master/examples/ReceiveDemo)
```ino
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
  IrSender.sendNEC(sAddress, sCommand, 0); //turn off the air conditioner

}
```
## Contact

If you want to contact me you can reach me at Mariano_Desivo@hotmail.com.

## License

This project uses the following license: [MIT License](https://github.com/MarianoDesivo/MarianoTV/blob/main/LICENSE).
