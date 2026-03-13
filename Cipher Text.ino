String inputString = "";
bool stringComplete = false;
int xorKey = 0x5A;  // Your secret key (you can change this)

void setup() {
  Serial.begin(9600);
  Serial.println("=== Hardware Cipher Machine ===");
  Serial.println("Commands:");
  Serial.println("  E:yourtext  → Encrypts the text");
  Serial.println("  D:yourtext  → Decrypts the text");
  Serial.println("================================");
}

void loop() {
  if (stringComplete) {
    inputString.trim();

    if (inputString.startsWith("E:")) {
      String message = inputString.substring(2);
      Serial.print("Original:  ");
      Serial.println(message);
      Serial.print("Encrypted: ");
      Serial.println(xorEncrypt(message));

    } else if (inputString.startsWith("D:")) {
      String message = inputString.substring(2);
      Serial.print("Encrypted: ");
      Serial.println(message);
      Serial.print("Decrypted: ");
      Serial.println(xorEncrypt(message)); // XOR is symmetric!

    } else {
      Serial.println("Unknown command. Use E: or D:");
    }

    inputString = "";
    stringComplete = false;
  }
}

// XOR Encryption Function
String xorEncrypt(String text) {
  String result = "";
  for (int i = 0; i < text.length(); i++) {
    char encryptedChar = text[i] ^ xorKey;
    result += encryptedChar;
  }
  return result;
}

// Serial Event - reads input
void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    if (inChar == '\n') {
      stringComplete = true;
    } else {
      inputString += inChar;
    }
  }
}