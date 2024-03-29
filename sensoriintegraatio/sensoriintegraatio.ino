int buzzer = 12;
int Led = 13;
int vib = 7;
int val;
int buzala;
int pirala;
int pirsensor = 8;
int vibala;
int redpin = 10; // red LED
int greenpin = 11; // green LED
float x = -8888;
float num= 0.7465; 
String numero;
void setup()

{
  Serial.begin (115200);
  pinMode(buzzer, OUTPUT);
  pinMode(Led, OUTPUT);
  pinMode(vib, INPUT);
  pinMode(pirsensor, INPUT);
  pinMode (redpin, OUTPUT);
  pinMode (greenpin, OUTPUT);
}
void red()
{ analogWrite (greenpin, 0);
  analogWrite (redpin, 255);
}
String serialHttpGet(String url) {
  Serial.print("GET ");
  Serial.println(url);
  return Serial.readStringUntil('\n');
}

float serialHttpGetFloat(String url) {
  String s = serialHttpGet(url);
  return s.toFloat();
}
float numGet() {
    x = serialHttpGetFloat("http://one.api.botbook.com/last/RbXY29EudyF");
    return x;
}

void numSend(String numero)
{
  x = serialHttpGetFloat("http://one.api.botbook.com/add/10P3Em4hjKa/?x=" + numero);
}

void green()
{
  analogWrite (greenpin, 255);
  analogWrite (redpin, 0);
}
void buzzerAlarm(int x)
{
  int a = 1;
  
  if (x == 1)
  {
    red();
    for (a = 1 ; a < 50; a++)
    {
      int a = 1;
      tone(buzzer, 10, 10000);
      delay(50);
      tone(buzzer, 12, 100);
    }
  }
  if (x == 2) {
    for (a = 1; a < 50; a++)
    {
      red();
      int a = 1;
      tone(buzzer, 5, 10000);
      delay(50);
      tone(buzzer, 20, 100);
    }
  }
}
void loop()
{
  vibala = digitalRead(vib);
  pirala = digitalRead(pirsensor);
  num = numGet();
  delay(10);
 
  if (vibala == HIGH)
  {
    Serial.println("Vibration alarm!");
    num = numGet();
    numSend("9");
    buzzerAlarm(1);
    analogWrite (greenpin, 255);
    analogWrite (redpin, 0);
    digitalWrite(Led, LOW);
    delay(1000);
  }

  
  else if (pirala == HIGH)
  {
    Serial.println("Motion detected!");
    numSend("8");
    analogWrite (greenpin, 255);
    analogWrite (redpin, 0);
    buzzerAlarm(2);
    num = numGet();
    delay(1000);
  }
  else if (vibala == LOW && num == 9)
  {
    Serial.println("Continue vibration alarm!");
    buzzerAlarm(1);
    num = numGet();
    delay(1000);
  }
  else if (pirala == LOW && num == 8)
  {
    Serial.println("Continue motion alarm!");
    buzzerAlarm(2);
    num = numGet();
    delay(1000);
  }
  else
  {
    green();
    Serial.println("All nominal");
    digitalWrite(Led, LOW);
    delay(1000);
  }

}
