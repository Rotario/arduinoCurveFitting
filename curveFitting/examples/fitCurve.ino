#include "curveFitting.h"

void setup(){
  Serial.begin(9600);
  while(!Serial);
  Serial.println("Starting");
  
  int xpower = 3;
  int order = 3;
  Serial.printf("Fitting curve of order %i to data of power %i...\n", order, xpower);
  
  double x[26];
  double t[26];
  for (int i = 0; i < sizeof(x)/sizeof(double); i++){
    t[i] = i;
    x[i] = power(i, xpower);
  }
  
  double coeffs[order+1];
  int ret = fitCurve(order, sizeof(x)/sizeof(double), t, x, sizeof(coeffs)/sizeof(double), coeffs);
  
  if (ret == 0){ //Returned value is 0 if no error
    uint8_t c = 'a';
    Serial.println("Coefficients are");
    for (int i = 0; i < sizeof(coeffs)/sizeof(double); i++){
      Serial.printf("%c=%f\t ",c++, coeffs[i]);
    }
  }
}

void loop(){
}

