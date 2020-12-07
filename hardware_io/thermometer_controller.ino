/* This Arduino app uses a photoresistor to read a light level, 
 * then activates an external switch by sending a LOW command 
 * through one of the output pins. The potentiometer allows for
 * adjustment through hardware of the photodiode's read value.
 *
 * PIN MAP:
 * POT        PHOTORESISTOR     THERMOMETER     LED     ARDUINO     
 * Out        Leg1              -                       A0
 * 5V In      Leg2                                      5V 
 * GND                          Button GND      -       GND
 *                                              +       D2
 *                              Trigger 5V              D5    // 5V = open, 0V = closes 
 * Note: LED '-' goes through 440-ohm resistor to ground, 
 * as seen in the circuit diagram.
 */

// Pin definitions
const int LED_PIN = 2 ; 
const int TRIGGER_PIN = 5 ;
const int PHOTORESISTOR = A0 ;

char commandInput ;
int lightLevel = 0 ; 
int lightThreshold = 500 ; 

// the setup function runs once when you press reset or power the board
void setup() {

  // Initialize serial interface
  Serial.begin(9600); 
  delay(1000);
  
  // Initialize hardware pins
  pinMode(LED_PIN, OUTPUT);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode ( PHOTORESISTOR, INPUT ) ;
  digitalWrite (TRIGGER_PIN, HIGH ) ;

  Serial.println("Ready for interface");
}

// Main program loop
void loop() {

  // Read and report photoresistor level (0 to 1024 from analog pin)
  lightLevel = analogRead ( PHOTORESISTOR ) ;
  Serial.print (" Light level detected: ");
  Serial.println (lightLevel) ;
 
  // Check if photoresistor level over threshold
  if ( lightLevel >= lightThreshold ) {
    Serial.println ("LED Detected, triggering thermometer"); 
    
    // Blink confirmation LED
    digitalWrite(LED_BUILTIN, HIGH);  
    delay(500);                       
    digitalWrite(LED_BUILTIN, LOW);   

    // Send trigger signal to thermometer
    digitalWrite(TRIGGER_PIN , LOW);
    delay(1000) ;
    digitalWrite(TRIGGER_PIN, HIGH) ;

  }
  
}
