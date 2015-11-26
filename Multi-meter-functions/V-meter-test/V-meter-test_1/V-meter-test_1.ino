// V-metere-test_1

float Value = 0.0;
float V = 0.0;
float voltage =0.0;

float R1 = 100000;
float R2 = 10000;
void setup(){

pinMode(A1,INPUT);
Serial.begin(115200);
}



void loop(){

Value = analogRead(A1);
V = (Value * 5.0) / 1024.0;
voltage = V / (R2/(R1+R2));

// if (voltage <0.9){
// voltage = 0.0;
// }

Serial.println("voltage out is ");
Serial.print(voltage);

}

