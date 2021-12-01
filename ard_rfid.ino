#include <SPI.h>
#include <MFRC522.h> //Ihk


const int pinRST = 9; // pin RST du module RC522
const int pinSDA = 10; // pin SDA du module RC522
MFRC522 rfid(pinSDA, pinRST);
void setup()
{
SPI.begin();
rfid.PCD_Init();
Serial.begin(9600);
}
void loop()
{
if (rfid.PICC_IsNewCardPresent()) // on a dédecté un tag
{
if (rfid.PICC_ReadCardSerial()) // on a lu avec succès son contenu
{
Serial.println("Voici l'UID de ce tag en decimal :");
Serial.print("const byte bonUID[");
Serial.print(rfid.uid.size);
Serial.print("] = {");
for (byte i = 0; i < rfid.uid.size; i++)
{
Serial.print(rfid.uid.uidByte[i]);
if (i < rfid.uid.size - 1)
{
Serial.print(", ");
}
else
Serial.println("};");
}
Serial.println();
delay (2000);
}
}
}
