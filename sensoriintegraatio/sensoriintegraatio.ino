int buzzer = 12;
int Led=13;   
int vib=7;  
int val;
int buzala;
int pirala;
int pirsensor = 8;
int vibala;
void setup() 

{
 Serial.begin (9600); 
 pinMode(buzzer, OUTPUT); 
 pinMode(Led,OUTPUT);  
 pinMode(vib,INPUT);
 pinMode(pirsensor,INPUT);
} 

void loop()  
{  
 vibala=digitalRead(vib);
 pirala=digitalRead(pirsensor);
 
   if(vibala==HIGH) 
   {  
     digitalWrite(buzzer, HIGH); 
        delayMicroseconds(100);  
        digitalWrite(buzzer, LOW); 
        delayMicroseconds(100);
     
    digitalWrite(Led,LOW); 
   }
   if(pirala == HIGH) 
   {
   Serial.println("Motion detected!");
       
        digitalWrite(buzzer, HIGH); 
        delay(10);  
        digitalWrite(buzzer, LOW); 
        delay(10); 
   }  
   else 
   { 
        
         Serial.println("Motion ended!");
         digitalWrite(Led,LOW); 
        delay(10);
       
    
    
  } 

} 
