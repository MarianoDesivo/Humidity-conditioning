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

![IrHumedadMariano_´PS](https://user-images.githubusercontent.com/79780807/111042674-4e72da80-841d-11eb-8fe1-e626ae02e580.jpg)

## Code

To install MarianoTV, follow these steps:

* Download MarianoTV.py
* Move it to the folder where you have all your videos (remember it includes all subfolders).
* By default, in MarianoTV.py, VLC.exe path is set to C:\Program Files (x86)\VideoLAN\VLC\vlc.exe". You may have to edit that line:
```python
    vlc = r"C:\Program Files (x86)\VideoLAN\VLC\vlc.exe" #Path of VLC.exe
```
## Contact

If you want to contact me you can reach me at Mariano_Desivo@hotmail.com.

## License

This project uses the following license: [MIT License](https://github.com/MarianoDesivo/MarianoTV/blob/main/LICENSE).
