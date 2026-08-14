# 🌡️ Automated Temperature-Controlled Fan System

An automated, closed-loop cooling system built with an Arduino microcontroller and a temperature sensor. The system dynamically monitors ambient temperature and regulates DC fan speed in real time using Pulse Width Modulation (PWM) to optimize cooling efficiency and conserve power.

---

## 🎥 Project Demonstration & Media

* 📺 **Video Demo:** [Watch the Hardware Demo in Action](https://drive.google.com/file/d/1vPGcn4jYVBXiDT5JXWfHWR9ZgAcGaG3f/view?usp=sharing).
* 📸 **Circuit & Hardware Photos:** *(<img width="768" height="1020" alt="photo_2026-08-14_04-42-48" src="https://github.com/user-attachments/assets/869c82a0-26ce-4c09-86d2-a8939205035f" />
)*

---

## ✨ Key Features

* **Real-Time Monitoring:** Continuously tracks ambient temperature readings.
* **Dynamic Speed Regulation:** Automatically scales fan speed via PWM based on preset temperature thresholds.
* **Energy Efficient:** Keeps the fan idle or at minimum speed when temperatures are within safe operating limits.
* **Hardware-Software Integration:** Built with C++ source code programmed directly to an Arduino board.

---

## 🛠️ Hardware & Components

* **Microcontroller:** Arduino Uno / Nano
* **Sensor:** Temperature Sensor (e.g., LM35 / DHT11 / DHT22)
* **Actuator:** 5V / 12V DC Cooling Fan
* **Driver Module:** Motor Driver (e.g., L298N) / Transistor Module (e.g., TIP120)
* **Power Supply:** External Battery Pack / USB Power Supply
* **Prototyping:** Solderless Breadboard & Jumper Wires

---

## ⚙️ How It Works

1. **Sensing:** The temperature sensor measures the current ambient temperature and feeds analog/digital signals to the Arduino.
2. **Processing:** The Arduino processes the input against predefined threshold limits.
3. **Actuation:** 
   * Below baseline threshold $\rightarrow$ Fan remains **OFF** or runs at minimal standby speed.
   * Above baseline threshold $\rightarrow$ Fan activates and increases speed proportionally as temperature rises.

---

## 💻 Installation & Setup

1. Clone or download this repository:
   ```bash
   git clone [https://github.com/Chigocal/temperature-controlled-fan.git](https://github.com/Chigocal/temperature-controlled-fan.git)
   ```
2. Open the `.ino` file in the **Arduino IDE**.
3. Connect your Arduino board via USB.
4. Select the correct **Board** and **Port** in `Tools` $\rightarrow$ `Board` / `Port`.
5. Click **Upload** to flash the code to the microcontroller.

---

## 👤 Author

* **GitHub:** [@Chigocal](https://github.com/Chigocal)
