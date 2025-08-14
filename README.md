# Arduino-based Palm Hand Rehabilitation Device

This repository contains the source code and documentation for my final year project for the Bachelor of Science in Systems Engineering at Al-Nahrain University. The project, which was recognized by my supervisor as patent-worthy and achieved a grade of 94%, is a device designed to assist individuals with nerve injuries in regaining strength and dexterity in their hands.

## 🎯 Project Overview

This project presents the design and implementation of a rehabilitation system for driving DC motors to help people recovering from a stroke or nerve damage achieve the best possible hand function, allowing them to return to their daily activities.

The device provides a variety of adjustable resistance levels to accommodate different strengths and abilities, helping to improve grip strength, finger flexibility, and coordination. By enabling patients to perform exercises at home, it aims to reduce the need for frequent hospital visits, thus lowering the overall healthcare burden.

## 🛠️ Technologies Used

* **Microcontroller:** Arduino Mega 2560
* **Actuators:** 5x DC Motors
* **Drivers:** L298N Motor Driver
* **Interface:** 20x4 LCD Display with I2C Module, 4x4 Keypad
* **Sensors:** Limit Switches for position control
* **Programming:** Arduino IDE (C++)
* **3D Modeling:** Solidworks

## 🚀 Key Features

* **Individual Finger Control:** The device allows for the selection and control of five separate DC motors, one for each finger. [cite: 20]
* **Adjustable Resistance Levels:** Users can select different resistance levels via the keypad to match their specific rehabilitation needs. [cite: 19, 41]
* **Position Control System:** Utilizes limit switches to define the endpoints of motor travel, preventing derailment and ensuring safety. [cite: 94, 95, 255]
* **User Feedback:** An LCD screen displays the current motor and level selection, providing clear feedback to the user. [cite: 20, 178]

* **/src:** Contains all source code for the project.
    * `Rehab_Device_Main.ino`: The main Arduino sketch.
    * `Robojax_L298N_DC_motor.h`: Header file for the motor driver library.
    * `Robojax_L298N_DC_motor.cpp`: Implementation file for the motor driver library.
* **/diagrams:** Contains the block diagram and flowchart for the project's hardware and software implementation.
