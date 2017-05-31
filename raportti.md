##Alarm proto

30.5. kokeiltiin sensoreita

http://firstbot.ipdisk.co.kr/publist/HDD1/Link/Manual/41in1Sensor.pdf

löytyi ohje jossa hyvät kaaviot ja esimerkkikoodeja

kokeilimme piezoa jolla olisi tarkoitus saada hälytys kuulumaan.

Sovelsimme ohjeessa ollutta koodia ja laitoimme hälytyksen tapahtumaan kun tärinäsensorin tila muuttuu.

int buzzer = 12;
int Led=13;
int vib=7;
int val;
void setup()
{
 Serial.begin (9600);
 pinMode(buzzer, OUTPUT);
 pinMode(Led,OUTPUT);
 pinMode(vib,INPUT);

}

void loop()
{
 val=digitalRead(vib);
   if(val==HIGH) // 진동 없음( NO Connect )
   {
     digitalWrite(buzzer, HIGH);
        delay(2);
        digitalWrite(buzzer, LOW);
        delay(2);

    digitalWrite(Led,LOW); // LED OFF
   }
   else // 진동 감지 ( Connect )
   {
       for (int i = 0; i < 100; i++)
       {




Jatkoimme sensorikokeiluja PIR sensorilla jonka toimintaansaattamisessa oli onglelmia katsoimme neuvoa https://learn.adafruit.com/pir-passive-infrared-proximity-motion-sensor/testing-a-pir
sivustolta aluksi laitoimme sensorin kiinni mutta se ei tuntunut toimivan. Siirtelimme jumperia ja säätelimme säätöruuveja saimme kuitenkin lopulta aikaan toimivan version.





































