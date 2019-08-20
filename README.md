# arduinoCurveFitting
Fit polynomial curves to given points using least squares regression. The max order of polynomial fitting is 20, this should be more than enough to fit most practical problems. All values are kept as double for precision, this works well on a Teensy due to its floating point unit and large (64 bit) double precision. the numbers required increase exponentially as the number of points or order increases.

This library solves the least squares problem using Cramer's rule and a small function to calculate the determinant of each matrix.

More explained in this article
https://medium.com/@rowaner111/fitting-curves-to-data-on-an-arduino-part-1-how-to-use-arduinocurvefitting-a3173c6dd4ef
