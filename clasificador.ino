void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
}

void loop() {
  if (Serial.available() > 0){
    option = Serial.read();
    //Alumninio
    if(option == 'y'){
      digitalWrite(led1, HIGH);       //Motor gira a bote alumninio
    }
    //Plastico
    if(option == 'n'){
      digitalWrite(led1, HIGH);
      delay(500);
      digitalWrite(led1, LOW);
    }
    //Error
        if(option == 'e'){
      digitalWrite(led1, HIGH);
      delay(500);
      digitalWrite(led1, LOW);
    }
  }
}
