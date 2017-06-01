int buzzer = 12;
int Led=13;   
int vib=7;  
int val;
int buzala;
int pirala;
int pirsensor = 8;
int vibala;
int redpin = 10; // red LED 
int greenpin = 11; // green LED 
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
void red()
{       analogWrite (greenpin, 0);
        analogWrite (redpin, 255);
  }
  void green()
{       analogWrite (greenpin, 255);
        analogWrite (redpin, 0);
  }
 void buzzerAlarm(int x)
  {
    int a = 1;
   
    if (x==1)
    {
      red();
      for (a=1 ;a<50;a++)
    {
      int a = 1;
      tone(buzzer,10,10000);
      delay(50);
      tone(buzzer,12,100);
      }}
     if (x==2){for (a=1;a<50;a++)
     {
      red();
      int a = 1;
      tone(buzzer,5,10000);
      delay(50);
      tone(buzzer,20,100);
      }}
    }
void loop()  
{  
 vibala=digitalRead(vib);
 pirala=digitalRead(pirsensor);
 
   if(vibala == HIGH) 
   { 
 
        buzzerAlarm(1);
        analogWrite (greenpin, 255);
        analogWrite (redpin, 0);
     
    digitalWrite(Led,LOW); 
   }
   else if(pirala == HIGH) 
   {
   Serial.println("Motion detected!");

        analogWrite (greenpin, 255);
        analogWrite (redpin, 0);
        buzzerAlarm(2);
        delay(10);
   }  
   else 
   { 
        green();
        Serial.println("Motion ended!");
        digitalWrite(Led,LOW); 
         delay(10);
        } 

}
