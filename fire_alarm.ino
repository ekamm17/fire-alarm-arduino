const int lm35_pin = A1; 
#define red_1 11
#define red_2 12
#define red_3 13
#define buzz 8
#define green 7

void setup() {
  Serial.begin(9600); //Initialize serial communication at a baud rate = 9600
  // Setting the pin modes for the LEDs and buzzer
  pinMode(red_1,OUTPUT);
  pinMode(red_2,OUTPUT);
  pinMode(red_3,OUTPUT);
  pinMode(buzz,OUTPUT);
  pinMode(green,OUTPUT);
}

void loop() {
  int temp_adc_val;
  float temp_val;
  int nval ;
  temp_adc_val = analogRead(lm35_pin); //Read analog value from LM35 sensor

  // The LM35 outputs 10 mV per degree Celsius, and the ADC of Arduino has a resolution of 4.88 mV per step
  temp_val = (temp_adc_val * 4.88); 
  temp_val = (temp_val/10); 

  //Displaying temperatue on the serial monitor
  Serial.print("Temperature = ");
  Serial.print(temp_val);
  Serial.print(" Degree Celsius\n");

  if(temp_val>32){
    //Alarm condition: turn on buzzer and red LEDs
    digitalWrite(buzz,HIGH);
    digitalWrite(green,LOW);
    digitalWrite(red_1,HIGH);
    digitalWrite(red_2,LOW);
    digitalWrite(red_3,LOW);
    delay(100);
    digitalWrite(red_1,LOW);
    digitalWrite(red_2,HIGH);
    digitalWrite(red_3,LOW);
    delay(100);
    digitalWrite(red_1,LOW);
    digitalWrite(red_2,LOW);
    digitalWrite(red_3,HIGH);   
  }
  else{
    //Normal condition: turn off red LEDs and turn on green LEDs
    digitalWrite(red_1,LOW);
    digitalWrite(red_2,LOW);
    digitalWrite(red_3,LOW);
    digitalWrite(buzz,LOW);
    digitalWrite(green,HIGH);
    delay(1000);
    digitalWrite(green,LOW);
    delay(900);
  }
  delay(100);
}
