# Vesc_WIFI
Simple VESC WIFI brdige [At tcp hub]
+ Optimized and good for RT Data.
+ Lag fixed and unused codes deleted.
+ WIFI with password to much better BLE without password!
+ Easy install with Arduino IDE
+ IOS Supported [Another codes not work with ios and you receive update firmware error code!]



Installtion method:
- [Download arduino ide](https://www.arduino.cc/en/software)
- Put CircularBuffer folder to your arduino ide library folder [C:\Users\PC user name\Documents\Arduino\libraries]
- [Install and do this instructions for support esp32 at arduino ino](https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/)
- Modify config your SSID name and Password at line 9 - 10.
- Modify config rx-tx pin outs line 6 - 7 .
- And in line 11 if you want custom port you can change but default port easier to connect.
- After editing all configs you can upload source code to esp32 :)
- Click to upload button and wait if you receive error you must hold the EN / RESET button until the upload is finished.
- Connect your VESC RX to ESP32 TX and VESC TX to ESP32 RX and connect VIN - 5V pin to vesc.
- Optional: I recommend you to use 10µF capacitor between V+ and G pin to prevent unstable voltage and send data without lag.
- Your vesc wifi ready to use :)

Also if you want install compiled and ready version with this [instrucation](https://www.aranacorp.com/en/generating-and-uploading-bin-files-for-esp32/) you can upload vesc_wifi.bin.
Compiled version:
SSID Name : Elshan_VESC
SSID Password : jjeRNVkQC1eoQrz
Vesc Port : 65102
VESC_RX : D15
VESC_TX : D13

Tested with ESP32 DEVKIT V1 and VESC 5.02 - 5.03 - 6 - 6.2.
Warning : You can use it to monitor and change settings or profiles, but do not use it to upload firmware.
It is possible to upload the incomplete firmware!
