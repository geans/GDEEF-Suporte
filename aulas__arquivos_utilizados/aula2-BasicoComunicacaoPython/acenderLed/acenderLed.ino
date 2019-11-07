void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    if (Serial.read() == '1') {
      digitalWrite(13, HIGH);
      Serial.println("Número 1 encontrado");
    }
    else {
      digitalWrite(13, LOW);
      Serial.println("Número 1 não encontrado");
    }
  }
}
