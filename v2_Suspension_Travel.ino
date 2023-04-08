/*
Wire Color Code

Red = power
Black = ground
Green/Blue = Output

*/


//these pins are reading in Magnetic Flux Density
//sensor outputs voltage proportional to magnetic strength
//analog read in
const int pinSIN = A0; 
const int pinCOS = A1;

//ATAN2() outputs radians
const float R2D = 180.0/PI;
const float D2R = PI/180.0;

void setup() {

  pinMode(pinSIN, INPUT);
  pinMode(pinCOS, INPUT);

  Serial.begin(9600);
  
}

void loop() {
  //all trig function parameters are in radians > convert if needed
  //recall By = @sin(x) & Bx = @cos(x) where B = output, @ = max MFD
  // MFD is in mA units  
  long vltSIN = analogRead(pinSIN);
  long vltCOS = analogRead(pinCOS);

  long R_vltSIN = vltSIN * D2R;
  long R_vltCOS = vltCOS * D2R;
  
  float angle = atan2(R_vltSIN,R_vltCOS) * R2D;

  Serial.println(vltSIN);
  Serial.print(" ");
  Serial.println(vltCOS);
  Serial.println(" ");
  Serial.println(angle);
  delay(100);

}

//ignore this pls... we might need it
/*
void interruptName(){
  count++;
  // Interrupt Service Route over
}
*/