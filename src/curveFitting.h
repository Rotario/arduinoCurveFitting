/*
  curveFitting.h - Library for fitting curves to given
  points using Least Squares method, with Cramer's rule
  used to solve the linear equation. Max polynomial order 20.
  Created by Rowan Easter-Robinson, August 23, 2018.
  Released into the public domain.
*/

#ifndef curveFit_h
#define curveFit_h

#include <Arduino.h>
#define MAX_ORDER 20

#ifndef CURVE_FIT_DEBUG
#define CURVE_FIT_DEBUG 0
#endif

/* Enum for error messages */
enum curveFitERROR{
	ORDER_AND_NCOEFFS_DO_NOT_MATCH = -1,
	ORDER_INCORRECT = -2,
	NPOINTS_INCORRECT = -3
};

/* Matrix Helper Functions */
void printMat(const char *s, double*m, int n);
void showmat(const char *s, double **m, int n);
void cpyArray(double *src, double*dest, int n);
void subCol(double *mat, double* sub, uint8_t coln, uint8_t n);
double curveFitPower(double base, int exponent);

/* Determinant matrix functions */
int trianglize(double **m, int n);
double det(double *in, int n, uint8_t prnt);

/* Curve fitting functions */
int fitCurve (int order, int nPoints, double py[], int nCoeffs, double *coeffs);
int fitCurve (int order, int nPoints, double px[], double py[], int nCoeffs, double *coeffs);
#endif
