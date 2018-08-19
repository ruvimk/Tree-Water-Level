#define DEBUG 0 

#define TREE_PIN A2 
#define NONLOW_LEVELS 3 
#define SIGNAL_LOW 0.6f // Volts 
#define SIGNAL_HIGH 1.0f // Volts 
#define LEVEL_LOW 0 

// LED pins to use (in the code, we assume that they are contiguous; this makes code simple): 
#define PIN_LED_LOW 2 
#define PIN_LED_L1 3 
#define PIN_LED_L2 4 
#define PIN_LED_L3 5 

void setup() {
  // put your setup code here, to run once:
  pinMode (TREE_PIN, INPUT); 
  pinMode (PIN_LED_LOW, OUTPUT); 
  pinMode (PIN_LED_L1, OUTPUT); 
  pinMode (PIN_LED_L2, OUTPUT); 
  pinMode (PIN_LED_L3, OUTPUT); 
#if DEBUG 
  Serial.begin (9600); 
#endif 
}

void loop() {
  // put your main code here, to run repeatedly:
  float value = (float) analogRead (TREE_PIN) * 5.0f / 1023.0f; 
  int level = value >= SIGNAL_LOW ? (int) round ((value - SIGNAL_LOW) * NONLOW_LEVELS / (SIGNAL_HIGH - SIGNAL_LOW)) : LEVEL_LOW; 
  digitalWrite (PIN_LED_LOW, level == 0); 
  digitalWrite (PIN_LED_L1, level == 1); 
  digitalWrite (PIN_LED_L2, level == 2); 
  digitalWrite (PIN_LED_L3, level >= 3); 
#if DEBUG 
  Serial.print ("Input: "); 
  Serial.print ((float) value * 5.0f / 1023.0f); 
  Serial.println (" V"); 
#endif 
}
