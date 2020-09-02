const int RED_LED = 2; 
const int YEL_LED = 8;
boolean flag_direction = true;
const int RED_BUTTON_RUN = 3;
boolean rotate_read = 0;
const int WHITE_BUTTON_DIRECTION = 6;

bool rotate_direction = true;
void setup() {
  // put your setup code here, to run once:
  pinMode(RED_LED ,OUTPUT); 
  pinMode(YEL_LED,OUTPUT);
  pinMode(RED_BUTTON_RUN, INPUT_PULLUP);
  pinMode(WHITE_BUTTON_DIRECTION, INPUT_PULLUP);
  
}

void loop() {

rotate_read = !digitalRead(WHITE_BUTTON_DIRECTION);

if( rotate_read == HIGH && flag_direction == 0)      
    {                                              
      rotate_direction = !rotate_direction;
      flag_direction = 1;
    }

 if(rotate_read == LOW && flag_direction == 1)
    {
      flag_direction = 0;
    }  
    
 int  run_state = digitalRead(RED_BUTTON_RUN);
 
  if (run_state == false){
    if (rotate_direction == true){
      for(int x = 0; x < 1000; x++) {
      
      digitalWrite(YEL_LED,HIGH); 
      delayMicroseconds(100); 
      digitalWrite(YEL_LED,LOW); 
      }
    }
    else {
      for(int x = 0; x < 1000; x++) {      
      digitalWrite(RED_LED,HIGH); 
      delayMicroseconds(100); 
      digitalWrite(RED_LED,LOW); 
    }
    }
}
} 
