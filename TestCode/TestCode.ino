/* Test Code for Modular IN2 Nixie Display.
 * 
 * Revision 0.1 19 April 2018
 */

unsigned long ul_Count = 0;

const byte clkPin = 2;
const byte clrPin = 3;
const byte datPin = 4;

void setup() {
  Serial.begin(9600);
  pinMode(clkPin, OUTPUT);
  pinMode(clrPin, OUTPUT);
  pinMode(datPin, OUTPUT);

  digitalWrite(clkPin, LOW);
  digitalWrite(clrPin, HIGH); // Clear is active low, so set to high for now.
  digitalWrite(datPin, LOW);
}

void loop() {
  digitalWrite(datPin, LOW);  // Start with the data pin low
  /*while(Serial.available()>0){
    ul_Count = long(Serial.parseInt());
    //Serial.println();
    processOutput(ul_Count);
    if(Serial.read() == '\n'){
      Serial.println("");
    }
  }*/
  for(int i = 0; i<=99; i++)
  {
    delay(250);
    processOutput(i);
    delay(250);
  }
}

void processOutput(unsigned long ulTest){
  int x = 0;
  
  do{
      byte bDisplay[4] = {0, 0, 0, 0};  // Array to hold the 4 bytes that will be shifted out.
      byte bHabyte[2] = {0, 0};         // Array to hold 2 digits before being placed into the display array.
      Serial.println(ulTest);           // Feedback to the serial monitor the data that should be displayed on the tubes.
      // Grab the 2 least significant digits, and put them into the array.
      for(int i=0;i<2;i++){
        bHabyte[i] = ulTest % 10;       // Set the first half byte to the LSD of the number.
        ulTest = ulTest / 10;           // Trim off the LSD.
        if(i==0){
          bHabyte[i] = bHabyte[i] << 4; // Shift the bits over by 4 
        }
        if(i==1){
          bDisplay[x] = bHabyte[i] | bHabyte[i-1]; // OR the bytes together.
        }
      }
      Serial.println(bDisplay[x], BIN); // Display the byte we are shifting out in binary
      digitalWrite(clkPin, LOW);        // Ensure the clock pin is low
      shiftOut(datPin, clkPin, MSBFIRST, bDisplay[x]);
      x++;
    }while(ulTest > 0);
}

