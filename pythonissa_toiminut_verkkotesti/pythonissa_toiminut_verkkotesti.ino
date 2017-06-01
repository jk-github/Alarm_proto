float x = -8888;
int fan = 8;

void setup() {
  Serial.begin(115200);
  pinMode(fan, OUTPUT);
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

void loop() {
  x = serialHttpGetFloat("http://one.api.botbook.com/add/10P3Em4hjKa/?x=15");
  Serial.println(x);

}
