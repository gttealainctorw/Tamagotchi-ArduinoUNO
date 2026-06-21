# Tamagotchi-ArduinoUNO

<img width="1080" height="1616" alt="_DSC1495" src="https://github.com/user-attachments/assets/ad05e28c-5a70-400e-9bd9-89bb235d90aa" />

# Requirements

Before getting started, make sure you have the following components and tools.

## Hardware

- Arduino Uno
- 0.96" I2C OLED Display (SSD1306)
- Piezo Buzzer
- 3 Push Buttons
- Mini Breadboard
- Male-to-Male Jumper Wires
- USB Type-A to Type-B Cable

## Software

- Arduino IDE

## Required Libraries

This repository already includes all the main project files required for the Tamagotchi to run. However, you may need to install a few additional libraries to compile the project successfully.

### Recommended Libraries

- Adafruit GFX Library
- Adafruit SSD1306
- CuteBuzzerSounds

These libraries can be installed through:

```text
Sketch → Include Library → Manage Libraries
```

Depending on your Arduino IDE version or library availability, you may need to download some libraries directly from GitHub and install them manually.

---

# Installation

## 1. Download the Repository

### Option A: Download ZIP

1. Click **Code**
2. Select **Download ZIP**
3. Extract the ZIP file to a folder of your choice

---

## 2. Install the Required Libraries

Open Arduino IDE and navigate to:

```text
Sketch → Include Library → Manage Libraries
```

Search for and install:

- Adafruit GFX Library
- Adafruit SSD1306
- CuteBuzzerSounds

If any library is not available in the Library Manager, download it from its GitHub repository and install it manually using:

```text
Sketch → Include Library → Add .ZIP Library
```

---

## 3. Open the Project

1. Open Arduino IDE
2. Select:

```text
File → Open
```

3. Navigate to the repository folder
4. Open:

```text
Code.ino
```

---

## 4. Configure the Board

Select:

```text
Tools → Board → Arduino Uno
```

Then choose the correct COM port:

```text
Tools → Port
```

---

## 5. Connect the Arduino

Connect the Arduino Uno to your computer using the USB Type-A to Type-B cable.

---

## 6. Compile the Project

Click:

```text
Verify ✓
```

If all required libraries are installed correctly, the project should compile without errors.

---

## 7. Upload the Program

Click:

```text
Upload →
```

Wait until the upload process is complete.

---

# Hardware Connections

<img width="1616" height="1080" alt="_DSC1506" src="https://github.com/user-attachments/assets/0fa4bf8a-b8d0-4291-bff3-8235094552b1" />

<img width="1227" height="847" alt="image" src="https://github.com/user-attachments/assets/347606c8-ce48-4f38-9028-dd1e37617774" />

## I2C OLED Display

| OLED | Arduino Uno |
|--------|--------|
| VCC | 5V |
| GND | GND |
| SDA | A4 |
| SCL | A5 |

---

## Buzzer

| Buzzer | Arduino Uno |
|---------|---------|
| Positive (+) | D5 |
| Negative (-) | GND |

---

## Left Button

| Button | Arduino Uno |
|---------|---------|
| Terminal 1 | D11 |
| Terminal 2 | GND |

---

## Select Button

| Button | Arduino Uno |
|---------|---------|
| Terminal 1 | D12 |
| Terminal 2 | GND |

---

## Right Button

| Button | Arduino Uno |
|---------|---------|
| Terminal 1 | D10 |
| Terminal 2 | GND |

---

## Additional Jumper

| Arduino Uno | Connection |
|------------|------------|
| D2 | GND |

---

## Pin Summary

| Function | Arduino Pin |
|----------|------------|
| OLED SDA | A4 |
| OLED SCL | A5 |
| Buzzer | D5 |
| Left Button | D11 |
| Select Button | D12 |
| Right Button | D10 |
| Jumper to GND | D2 |

> The buttons use the `INPUT_PULLUP` configuration, so each button must be connected between its corresponding pin and GND. No external resistors are required.
---
### CuteBuzzerSounds

This project uses the **CuteBuzzerSounds** library for sound effects and melodies.

GitHub repository:

https://github.com/evertonramires/CuteBuzzerSounds

If the library is not available through the Arduino IDE Library Manager, download it from GitHub and install it manually using:

```text
Sketch → Include Library → Add .ZIP Library
```
---
# Expected Result

Once the program is uploaded, the OLED display will show the virtual pet and you will be able to interact with it using the three buttons. The buzzer will play sounds, and the Tamagotchi will run autonomously on the Arduino Uno.
