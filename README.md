# -Industrial-Fault-Indication-System-with-SMS-Alert
The Industrial Fault Indication System with SMS Alert is an ARM7 (LPC2148)-based monitoring and alerting system designed to detect critical industrial conditions such as abnormal temperature or humidity. The system continuously reads sensor values, logs data, and generates automatic SMS alerts through a GSM module when values exceed predefined safety thresholds. This ensures timely notification to operators, prevents equipment damage, and improves workplace safety.  
    This project demonstrates real-time embedded system design, sensor interfacing, communication protocols, and GSM-based remote alerting.

🟧 📌 Key Features
Real-time monitoring of temperature and humidity

Automatic SMS alert through GSM module during fault conditions

Sensor data display on LCD

EEPROM storage for configuration/threshold values

Menu-driven user interface using keypad

Fault logging capability

Microcontroller-based, low-cost, and power-efficient system

🟨 📌 Technologies & Components Used

ARM7 LPC2148 microcontroller

GSM module (SIM900/800) for SMS alerts

DHT11/LM35 sensor for temperature & humidity

24C256 EEPROM for data storage (via I2C)

16x2 LCD display

Keypad for user input

UART protocol for GSM communication

I2C protocol for EEPROM

Embedded C, Keil µVision, Flash Magic

🟪 📌 System Architecture (Short Explanation)

Sensors read environmental conditions

LPC2148 processes sensor data

Compares values with threshold stored in EEPROM

If abnormal → triggers GSM module via UART

Sends SMS to registered user

LCD continuously shows real-time status

Keypad allows updating threshold values

🟫 📌 What I Learned

Embedded C programming

ARM7 microcontroller interfacing

GSM AT commands & UART communication

Data logging using EEPROM (I2C)

Interrupts, timers, and embedded architecture

Real-time fault detection logic
