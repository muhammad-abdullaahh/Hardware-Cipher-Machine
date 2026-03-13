# 🔐 Hardware Cipher Machine
### Built with Arduino Uno

A hardware-based encryption/decryption device that runs on an Arduino Uno. Type a message via the Serial Monitor and the Arduino encrypts it using XOR cipher in real time. Type the ciphertext back to decrypt it.

---

## 📋 Table of Contents
- [About](#about)
- [Hardware Required](#hardware-required)
- [How It Works](#how-it-works)
- [Setup & Installation](#setup--installation)
- [Usage](#usage)
- [Example Output](#example-output)
- [What You Learn](#what-you-learn)
- [Future Improvements](#future-improvements)
- [Disclaimer](#disclaimer)

---

## About

This project turns an Arduino Uno into a hardware cipher machine using **XOR encryption** — the same fundamental technique used in real-world malware obfuscation, stream ciphers, and hardware security modules (HSMs).

It communicates with your laptop over USB via the **Serial Monitor** in the Arduino IDE.

---

## Hardware Required

| Component | Details |
|-----------|---------|
| Arduino Uno R3 | Any revision works |
| USB Cable | Type-A to Type-B |
| Laptop/PC | With Arduino IDE installed |

No extra components needed — just the Uno and a USB cable!

---

## How It Works

XOR (Exclusive OR) encryption works by applying a secret key to each character in the message:

```
Encrypt:  character XOR key = ciphertext
Decrypt:  ciphertext XOR key = character  (XOR is symmetric!)
```

Example with key `0x5A`:
```
'H' (72) XOR 90 = 18  → encrypted
 18      XOR 90 = 72  → back to 'H'
```

The secret key is stored directly on the Arduino hardware — making it a true hardware security device.

---

## Setup & Installation

### Step 1 — Install Arduino IDE
Download from [arduino.cc/en/software](https://www.arduino.cc/en/software)

### Step 2 — Connect Arduino
Plug your Arduino Uno into your laptop via USB.

### Step 3 — Select Board & Port
- Go to **Tools → Board → Arduino AVR Boards → Arduino Uno**
- Go to **Tools → Port → COM3** (or `/dev/ttyACM0` on Linux)

### Step 4 — Upload the Code
Open `cipher_machine.ino`, then press **Ctrl + U** to upload.

Expected output after upload:
```
Sketch uses 4278 bytes (13%) of program storage space.
Global variables use 422 bytes (20%) of dynamic memory.
Done uploading.
```

---

## Usage

1. Open **Serial Monitor** → `Ctrl + Shift + M`
2. Set baud rate to **9600**
3. Set line ending to **New Line**

### Commands

| Command | Description |
|---------|-------------|
| `E:yourtext` | Encrypts the message |
| `D:ciphertext` | Decrypts the message |

---

## Example Output

```
=== Hardware Cipher Machine ===
Commands:
  E:yourtext  → Encrypts the text
  D:yourtext  → Decrypts the text
================================

> E:HelloWorld
Original:  HelloWorld
Encrypted: 2/..395..,

> D:2/..395..,
Encrypted: 2/..395..,
Decrypted: HelloWorld
```

---

## What You Learn

| Concept | Real-World Application |
|---------|----------------------|
| XOR Encryption | Used in malware string obfuscation |
| Symmetric Keys | Foundation of AES, stream ciphers |
| Hardware Crypto | How HSMs (Hardware Security Modules) work |
| Serial Protocol | How embedded devices communicate with a host |
| Arduino C++ | Embedded systems programming |

---

## Future Improvements

- [ ] Add Caesar cipher mode alongside XOR
- [ ] Brute force key cracker (try all 255 possible keys)
- [ ] Change key via Serial command at runtime
- [ ] Store encrypted messages on EEPROM
- [ ] Add LED blink feedback on encrypt/decrypt
- [ ] Port to ESP8266 for wireless encrypted messaging

---

## Project Structure

```
hardware-cipher-machine/
│
├── cipher_machine.ino     ← Main Arduino sketch
└── README.md              ← This file
```

---

## Disclaimer

This project is built for **educational purposes** to understand how encryption and hardware security work. Use responsibly and ethically.

---

## Author

**Abdullah**
BSE Student | Cybersecurity Enthusiast
GitHub • LinkedIn

> *"Security is not a product, but a process."* — Bruce Schneier
