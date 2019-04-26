
#define LED 8
#define RN_RESET 9

int cont = 0;
 char frame[50];

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  pinMode(RN_RESET, OUTPUT);
  digitalWrite(RN_RESET, LOW);
  pinMode(0, OUTPUT);
  digitalWrite(0, LOW);
  pinMode(1, OUTPUT);
  digitalWrite(1, LOW);
  Serial.begin(9600);
  Serial1.begin(57600);
  Serial5.begin(9600);

  digitalWrite(LED, HIGH);
  delay(10000);
  digitalWrite(LED, LOW);
  digitalWrite(RN_RESET, HIGH);

  Serial.println("Start");
  //Serial1.print("sys factoryRESET\r\n");
}

void loop() {
  // put your main code here, to run repeatedly:

    cont=0;
    while (Serial1.available())
//    	Serial.write(Serial1.read());
      frame[cont++] = (char)Serial1.read();
    for (int i=0; i<=cont-1; i++)
      Serial.print(frame[i]);

    cont=0;
    while (Serial.available())
//    	Serial1.write(Serial.read());
      frame[cont++] = (char)Serial.read();
    for (int i=0; i<=cont-1; i++)
    	Serial1.print(frame[i]);

}
