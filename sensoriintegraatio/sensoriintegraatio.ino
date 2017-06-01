int buzzer = 12;
int Led=13;   
int vib=7;  
int val;
int buzala;
int pirala;
int pirsensor = 8;
int vibala;
int redpin = 11; // red LED 
int greenpin = 10; // green LED 
void setup() 

{
 Serial.begin (9600); 
 pinMode(buzzer, OUTPUT); 
 pinMode(Led,OUTPUT);  
 pinMode(vib,INPUT);
 pinMode(pirsensor,INPUT);
 pinMode (redpin, OUTPUT); 
 pinMode (greenpin, OUTPUT); 
} 

void loop()  
{  
 vibala=digitalRead(vib);
 pirala=digitalRead(pirsensor);
 
   if(vibala==HIGH) 
   { 
 
     digitalWrite(buzzer, HIGH); 
        delayMicroseconds(1000);  
        digitalWrite(buzzer, LOW); 
        delayMicroseconds(1000);
        analogWrite (greenpin, 255);
        analogWrite (redpin, 0);
     
    digitalWrite(Led,LOW); 
   }
   else if(pirala == HIGH) 
   {
   Serial.println("Motion detected!");

        analogWrite (greenpin, 255);
        analogWrite (redpin, 0);
        digitalWrite(buzzer, HIGH); 
        delay(10);  
        digitalWrite(buzzer, LOW); 
        delay(10); 
   }  
   else 
   { 
         analogWrite (redpin, 255);
         analogWrite (greenpin, 0);
         Serial.println("Motion ended!");
         digitalWrite(Led,LOW); 
        delay(10);
       
    
    
  } 

}
