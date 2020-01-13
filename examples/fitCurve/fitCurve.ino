#include <curveFitting.h>

void setup(){
  Serial.begin(9600);
  while(!Serial);
  Serial.println("Starting");
  
  char buf[100];
  int xpower = 3;
  int order = 3;
  snprintf(buf, 100, "Fitting curve of order %i to data of power %i...\n", order, xpower);
  Serial.print(buf);
  
  double x[26];
  double t[26];
  for (int i = 0; i < sizeof(x)/sizeof(double); i++){
    t[i] = i;
    x[i] = pow(i, xpower);
  }
  
  double coeffs[order+1];
  int ret = fitCurve(order, sizeof(x)/sizeof(double), t, x, sizeof(coeffs)/sizeof(double), coeffs);
  
  if (ret == 0){ //Returned value is 0 if no error
    uint8_t c = 'a';
    Serial.println("Coefficients are");
    for (int i = 0; i < sizeof(coeffs)/sizeof(double); i++){
      snprintf(buf, 100, "%c=",c++);
      Serial.print(buf);
      Serial.print(coeffs[i]);
      Serial.print('\t');
    }
  }
}

void loop(){
}
