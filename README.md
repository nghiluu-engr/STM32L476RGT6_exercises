# STM32L476RGT6_exercises

## 📌 Overview
This repository stores my exercises since I first started learning about microcontrollers until now. 
All projects and exercises are written in the **C language** and developed using 2 software tools:
* **STM32CubeMX**: For setting up pins and peripheral hardware.
* **Keil uVision (Keil C)**: For writing code and uploading it to the board.

All exercises are practiced on a complete development board that includes the **STM32L476RGT6** microcontroller and other onboard peripherals.

---

## 🛠️ Hardware
* **Microcontroller:** STM32L476RGT6 (ARM Cortex-M4 core).
* **Programmer:** ST-Link V2.
* **Onboard Peripherals:** * 1x ICM-20948 (IMU sensor).
  * 1x Buzzer.
  * 1x RGB LED.
  * 2x Push Buttons.

---

## 🚀 BLINK_LED_RGB

### 1. Main Code 
All the main code files are placed inside the `SourceCode` folder:
* **RGB LED Library (`blink_led_rgb.h` / `blink_led_rgb.c`):** Manages and controls 1 onboard RGB LED.

### 2. Requirements
* Make the RGB LED blink with basic timing control.

---

## 🚀 BUTTON

### 1. Main Code 
All the main code files are placed inside the `SourceCode` folder:
* **Button Library (`button.h` / `button.c`):** Manages and controls 1 push button.

### 2. Requirements
* Implement software debouncing to filter out noise from the button signal when pressed.

---

## 🚀 External_Interrupt

### 1. Main Code 
* All the main application logic and interrupt configurations are placed directly inside the `main.c` file.

### 2. Requirements
* Use an External Interrupt (EXTI) line to detect the button press signal instead of polling inside the main loop.

---

## 🚀 BUZZER

### 1. Main Code 
All the main code files are placed inside the `SourceCode` folder:
* **Buzzer Library (`buzzer.h` / `buzzer.c`):** Manages and controls 1 onboard buzzer.

### 2. Requirements
* Make the buzzer beep intermittently (similar to a "blink LED" effect but using sound).
* Use a Timer (PWM mode) to adjust the volume/loudness of the buzzer sound.

---

## 🚀 ADC

### 1. Main Code 
* All the main ADC reading and processing operations are placed inside the `main.c` file.

### 2. Requirements
* Measure the current voltage level of the battery using the Analog-to-Digital Converter (ADC) and debug the value.

---

## 🚀 TIMER, PWM

### 1. Main Code
* All the main configurations for the timer counter and PWM channels are placed inside the `main.c` file.

### 2. Requirements
* Use a Timer in PWM mode to change the duty cycle smoothly, making the LED gradually brighten up.
