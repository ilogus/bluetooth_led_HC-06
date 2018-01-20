/* 
 *  Bluetooh : LED ON/OFF
 *  Coder - IloGus
 *  Website - https://www.ilogus.fr
 *  Docs - https://docs.ilogus.fr/bluetooth-led
 *  Download the App : Arduino bluetooth controller
 *  https://play.google.com/store/apps/details?id=com.giumig.apps.bluetoothserialmonitor
 *  
 *  Libraries : https://www.arduino.cc/en/Reference/SoftwareSerial
 *  
 *  Material :
 *  - Arduino UNO
 *  - Bluetooth module HC-06
 *  - LED
 *  - x1 resistor 1KΩ
 *  - x1 resistor 2,2 KΩ
 *  - (be careful with the other pin than 13 !)
 */

#define LED 13 // affectation de la pin13 sur la variable LED
#define RX 2   // affectation de la pin2 sur la variable RX
#define TX 3   // affectation de la pin3 sur la variable TX
#include <SoftwareSerial.h>      // appel de la bibliothèque SoftwareSerial
SoftwareSerial bluetooth(RX,TX); // configuration du RX TX sur l' objet bluetooth

word received; // variable code ASCII reçu

void setup() {
  Serial.begin(9600);     // initialisation liaison série à 9600 bauds (HyperTexte)
  bluetooth.begin(9600);  // initialisation connexion série à 9600 bauds (Bluetooth)
  pinMode(LED,OUTPUT) ;   // utilisation de la LED en sortie
}

void loop() {
  getBluetooth(); // appel de la fonction getBluetooth
  
  if (received==49){ // si octet reçu est 49 = 1 en ASCII
    Serial.println("Led allumee"); // on affiche led allumée dans l'HyperText
    digitalWrite(LED,HIGH);        // on met au niveau bas la LED
  }    

  if (received==48){ // si octet reçu est 49 = 0 en ASCII
    Serial.println("Led eteinte"); // on affiche led eteinte dans l'HyperText
    digitalWrite(LED,LOW);         // on met au niveau bas la LED
  }

  delay(200); // pause de 0.2 secondes
}

//fonction qui récupère les trames Bluetooth
void getBluetooth(){
    if (bluetooth.available()) { // si le bluetooth est disponible
      received=bluetooth.read(); // alors on regarde ce qu'il s'y passe
    }
}
