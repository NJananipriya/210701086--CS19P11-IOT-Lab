# Hand Gestures and Pulse Oximeter Project

This Arduino project utilizes a pulse oximeter sensor to monitor heart rate (HR) and SpO2 levels, and flex sensors to detect various hand gestures. The results are displayed on an I2C LCD screen and communicated via an HC-05 Bluetooth module to send alerts based on the detected gestures.

## Libraries Required

- `LiquidCrystal_I2C` library for the LCD display
- `MAX30100_PulseOximeter` library for the pulse oximeter
- `SoftwareSerial` library for Bluetooth communication

## Hardware Used
Arduino Uno: The main microcontroller board for the project.
Pulse Oximeter Sensor (MAX30100 or MAX30102): For measuring heart rate and blood oxygen saturation.
I2C LCD Display (16x2): For displaying heart rate and SpO2 readings.
Flex Sensors (3 sensors): For detecting hand gestures based on bending.
HC-05 Bluetooth Module: For wireless communication to send alerts.
Jumper Wires: For making connections between components.
Breadboard: For prototyping and assembling the circuit.
10k ohm Resistors: For pull-down configuration of the flex sensors.

## Software Used
Arduino IDE: The development environment for writing and uploading the code to the Arduino board.
LiquidCrystal_I2C Library: For controlling the I2C LCD display.
MAX30100_PulseOximeter Library: For interfacing with the pulse oximeter sensor.
SoftwareSerial Library: For enabling serial communication with the HC-05 Bluetooth module.

### Connections:

1. **Pulse Oximeter:**
   - Connect the pulse oximeter sensor to the I2C pins (SDA and SCL) on the Arduino.

2. **I2C LCD Display:**
   - Connect the LCD display to the I2C pins (SDA and SCL) on the Arduino.

3. **Flex Sensors:**
   - Connect one end of each flex sensor to analog pins A0, A1, and A2 on the Arduino.
   - Connect the other end of each flex sensor to GND through a 10k ohm pull-down resistor.

4. **HC-05 Bluetooth Module:**
   - Connect the TX pin of the HC-05 to digital pin 2 (SoftwareSerial RX) on the Arduino.
   - Connect the RX pin of the HC-05 to digital pin 3 (SoftwareSerial TX) on the Arduino.
   - 
