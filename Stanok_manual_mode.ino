const int stepPin = 5; 
const int dirPin = 2; 
const int enPin = 8;

const int PIN_BUTTON_RUN = 3;

const int PIN_BUTTON_DIRECTION = 6;

bool rotate_direction = true;
void setup() {
  // put your setup code here, to run once:
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  pinMode(PIN_BUTTON_RUN, INPUT_PULLUP);
  pinMode(PIN_BUTTON_DIRECTION, INPUT_PULLUP);
  pinMode(enPin,OUTPUT);
  digitalWrite(enPin,LOW);
  
}

void loop() {
  
bool temp_rotate = digitalRead(PIN_BUTTON_DIRECTION);
  if (temp_rotate == false){
    rotate_direction = !rotate_direction;
  }
  
 bool  run_state = digitalRead(PIN_BUTTON_RUN);
  if (run_state == false){
    digitalWrite(dirPin, rotate_direction);
    for(int x = 0; x < 1000; x++) {
      
      digitalWrite(stepPin,HIGH); 
      delayMicroseconds(300); 
      digitalWrite(stepPin,LOW); 
      delayMicroseconds(200); 
  }
 }

} 
