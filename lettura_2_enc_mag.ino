//lettura_2_enc_mag.ino
#define CSn1 A0
#define CSn2 A1

int posA=0;
int posB=0;

void setup() {
  Serial.begin(9600);

  pinMode(SCK, OUTPUT);
  pinMode(MISO, INPUT);
  pinMode(CSn1, OUTPUT);
  pinMode(CSn2, OUTPUT);
  digitalWrite(CSn1, HIGH);
  digitalWrite(CSn2, HIGH);
  
}

void loop() {
  posA = readEncoder(CSn1);
  int eposA=map(posA,0,16384,0,359); //mappatura sui 360°. Per mappatura elettrica 48*NP, NP = n. coppie polari (11)
  eposA=constrain(eposA,0,359);
  Serial.print("posA: ");
  Serial.print(eposA);

  posB = readEncoder(CSn2);
  int eposB=map(posB,0,16384,0,359);
  eposB=constrain(eposB,0,359);
  Serial.print(", posB: ");
  Serial.println(eposB);

delay(10); // aumentare o diminuire per rendere più veloce o meno i grafici sul plotter seriale
}

int readEncoder(int EncPin){
  digitalWrite(EncPin, LOW);
  byte d = shiftIn(MISO, SCK, MSBFIRST);
  byte d1= shiftIn(MISO, SCK, MSBFIRST);
  digitalWrite(EncPin, HIGH);
  d &=0b00111111;
  int posEnc = d << 8;
  posEnc = posEnc | d1;
  return posEnc;
}
