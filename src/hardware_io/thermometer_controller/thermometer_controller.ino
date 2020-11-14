/*  PIN MAP:
 *   POT        PHOTORESISTOR     THERMOMETER     ARDUINO     
 *   Out        Leg1              -               A1
 *   5V In      Leg2                              5V 
 *   GND                          Button GND      GND
 *                                Trigger 5V      7         // 5V = open switch, 0V = close switch
 */




const int TRIGGER_PIN = 7 ;
const int PHOTORESISTOR = A1 ;

char commandInput ;
int lightLevel = 0; 

// the setup function runs once when you press reset or power the board
void setup() {

  Serial.begin(9600); 
  delay(1000);
  
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(TRIGGER_PIN, OUTPUT);

  Serial.println("Ready for command");
  digitalWrite (TRIGGER_PIN, HIGH ) ;

  pinMode ( PHOTORESISTOR, INPUT ) ;
  
}

void loop() {

  lightLevel = analogRead ( PHOTORESISTOR ) ;
  Serial.print (" Light level detected: ");
  Serial.println (lightLevel) ;
 
  if ( lightLevel >= 500 ) {
    Serial.println ("LED Detected, triggering thermometer"); 
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(500);                       // wait for a second
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW

//    digitalWrite(TRIGGER_PIN , LOW);
//    delay(1000) ;
//    digitalWrite(TRIGGER_PIN, HIGH) ;
    
  }
  
}



// the loop function runs over and over again forever
//void loop() {
//
//  if ( Serial.available() ) {
//    input = Serial.read();
//    Serial.println ( commandInput ) ;
//    if ( commandInput == 't' || commandInput == 'T' ) {
//      Serial.println ("Triggering thermometer"); 
//      digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
//      delay(500);                       // wait for a second
//      digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
//
//      digitalWrite(TRIGGER_PIN , LOW);
//      delay(1000) ;
//      digitalWrite(TRIGGER_PIN, HIGH) ;
//      
//    }
//  }
//}
