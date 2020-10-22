const int steppin1 = 10;
const int dirpin1 = 12;
const int steppin2 = 8;
const int dirpin2 = 7;
const float tiempo = 10;//Usar 5 para ir rapido (velocidad maxima) y 10 para pruebas y poder coger el coche

const int fronthit = 4;// sensores final de carrena
const int righthit = 6;
const int lefthit = 9;

unsigned long time1=0;

#define diameter 0.064 //diameter of the wheels, in meters
#define steps 200
#define width 0.205   //width of the robot, including the wheels, in meters.
//In my case it is between 0.2 and 0.24

void setup() {
pinMode(steppin1,OUTPUT);
pinMode(dirpin1,OUTPUT);
pinMode(steppin2,OUTPUT);
pinMode(dirpin2,OUTPUT);
pinMode(fronthit,INPUT);
pinMode(lefthit,INPUT);
pinMode(righthit,INPUT);
Serial.begin(9600);
}



void loop() {
  int c = 1;
  float distance = 0.5;
  float alfa = 360;
  delay(2000);
  while(1){
    //delay(5000);
    if((c * (Serial.read()-'0'))==0){
      right_without_faces(90);  
      //if(digitalRead(fronthit)==0 && digitalRead(righthit)==0){
      //  backward(0.1);
      //  left(180);
      }else if(digitalRead(righthit)==0){
        left_without_faces(180);
      }   
    }else{
      fordward(1);
      if(digitalRead(fronthit)==0){
        backward(0.1);
        right(60);
        if(digitalRead(righthit)==0){
          left(90);
          if(digitalRead(lefthit)==0){
            backward(0.1);
            right(195);
          }
        }
      }
    }
  }
}


///////////////////////////FUNCIONES DE MOVIMIENTO//////////////////////////////

void right(float alfa){
  int c = 1;
  int r = 0;
  float alfa1 = radians(alfa);
  digitalWrite(dirpin1,HIGH);
  digitalWrite(dirpin2,LOW);
  float distance = alfa1 * width/2;
  float totalofsteps= distance * steps/(diameter*3.14);
  //Serial.println(totalofsteps);
  for(int x =0;x<totalofsteps;x++){
    if (digitalRead(fronthit)==0 || digitalRead(lefthit)==0 || digitalRead(righthit)==0){break;}//exit if it hit something
    if(Serial.available()){//From RPi to Arduino
      r = c * (Serial.read()-'0');//conveting the value of chars to integer
      if(r==0){break;}}//exit if the is a face
    digitalWrite(steppin1,HIGH);
    digitalWrite(steppin2,HIGH);
    delay(tiempo);
    digitalWrite(steppin1,LOW);
    digitalWrite(steppin2,LOW);  
    delay(tiempo);
  }
}

void left(float alfa){
  int c = 1;
  int r = 0;
  alfa = radians(alfa);
  digitalWrite(dirpin2,HIGH);
  digitalWrite(dirpin1,LOW);
  float distance = alfa * width/2;
  float totalofsteps= distance * steps/(diameter*3.14);
  //Serial.println(totalofsteps);
  for(int x =0;x<totalofsteps;x++){
    if (digitalRead(fronthit)==0 || digitalRead(lefthit)==0 || digitalRead(righthit)==0){break;}//exit if it hit something
    if(Serial.available()){//From RPi to Arduino
      r = c * (Serial.read()-'0');//conveting the value of chars to integer
      if(r==0){break;}}//exit if the is a face
    digitalWrite(steppin1,HIGH);
    digitalWrite(steppin2,HIGH);
    delay(tiempo);
    digitalWrite(steppin1,LOW);
    digitalWrite(steppin2,LOW);  
    delay(tiempo);
  }
}

void fordward(float distance){
  int c = 1;
  int r = 0;
  digitalWrite(dirpin1,LOW);
  digitalWrite(dirpin2,LOW);
  float totalofsteps= distance * steps/(diameter*3.14);
  for(int x =0;x<totalofsteps;x++){
    if (digitalRead(fronthit)==0 || digitalRead(lefthit)==0 || digitalRead(righthit)==0){break;}//exit if it hit something
    if(Serial.available()){//From RPi to Arduino
      r = c * (Serial.read()-'0');//conveting the value of chars to integer
      if(r==0){break;}}//exit if the is a face    
    digitalWrite(steppin1,HIGH);
    digitalWrite(steppin2,HIGH);
    delay(tiempo);
    digitalWrite(steppin1,LOW);
    digitalWrite(steppin2,LOW);  
    delay(tiempo);
  }
}
void backward(float distance){
  int c = 1;
  int r = 0;
  digitalWrite(dirpin1,HIGH);
  digitalWrite(dirpin2,HIGH);
  float totalofsteps= distance * steps/(diameter*3.14);
  for(int x =0;x<totalofsteps;x++){   
    digitalWrite(steppin1,HIGH);
    digitalWrite(steppin2,HIGH);
    delay(tiempo);
    digitalWrite(steppin1,LOW);
    digitalWrite(steppin2,LOW);  
    delay(tiempo);
  }
 }

 void right_without_faces(float alfa){
  float alfa1 = radians(alfa);
  digitalWrite(dirpin1,HIGH);
  digitalWrite(dirpin2,LOW);
  float distance = alfa1 * width/2;
  float totalofsteps= distance * steps/(diameter*3.14);
  //Serial.println(totalofsteps);
  for(int x =0;x<totalofsteps;x++){
    digitalWrite(steppin1,HIGH);
    digitalWrite(steppin2,HIGH);
    delay(tiempo);
    digitalWrite(steppin1,LOW);
    digitalWrite(steppin2,LOW);  
    delay(tiempo);
  }
}

void left_without_faces(float alfa){
  alfa = radians(alfa);
  digitalWrite(dirpin2,HIGH);
  digitalWrite(dirpin1,LOW);
  float distance = alfa * width/2;
  float totalofsteps= distance * steps/(diameter*3.14);
  //Serial.println(totalofsteps);
  for(int x =0;x<totalofsteps;x++){
    digitalWrite(steppin1,HIGH);
    digitalWrite(steppin2,HIGH);
    delay(tiempo);
    digitalWrite(steppin1,LOW);
    digitalWrite(steppin2,LOW);  
    delay(tiempo);
  }
}
