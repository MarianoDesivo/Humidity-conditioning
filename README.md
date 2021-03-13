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

## Installing MarianoTV

To install MarianoTV, follow these steps:

* Download MarianoTV.py
* Move it to the folder where you have all your videos (remember it includes all subfolders).
* By default, in MarianoTV.py, VLC.exe path is set to C:\Program Files (x86)\VideoLAN\VLC\vlc.exe". You may have to edit that line:
```python
    vlc = r"C:\Program Files (x86)\VideoLAN\VLC\vlc.exe" #Path of VLC.exe
```

## Wiring diagram

* Just double click on MarianoTV.py (I recommend creating a desktop shortcut). It will open a console window that will start playing random videos.
* To correctly close this program, Alt+Tab to console and press Enter (if closed other way it may corrupt the registry).

### Other functions

* There is a watched videos counter. If it reaches 300 it will reset the watched list.
```python
    if contador > 300: #If we have watched more than 300 videos 
      f = open('CapitulosVistos.txt', 'w')    #Reset the list to start again

```
* There is a 10% chance you get a repeated video
```python
    if random.randint(1,10) == 1: #There is a 10% chance to watch a video you have already seen
```

## Contact

If you want to contact me you can reach me at Mariano_Desivo@hotmail.com.

## License

This project uses the following license: [MIT License](https://github.com/MarianoDesivo/MarianoTV/blob/main/LICENSE).
