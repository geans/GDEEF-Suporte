void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
}

void loop() {
  String buffer;
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    buffer = Serial.readString();
    if (buffer == "arduino?") {
      Serial.print("Sim, sou eu");
    }
    else if (buffer == "acender") {
      digitalWrite(13, HIGH);
      Serial.print("Acendi");
    }
    else if (buffer == "apagar") {
      digitalWrite(13, LOW);
      Serial.print("Apaguei");
    }
  }
}
