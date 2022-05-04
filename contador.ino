int latas = 0;
int botellas = 0;

void setup() {
  pinMode(latas, INPUT);
  pinMode(botellas, INPUT);
}

void loop() {
  if (latas == HIGH){
    reg_latas++;
  }
  if (botellas == HIGH){
    reg_botellas++;
  }
}
