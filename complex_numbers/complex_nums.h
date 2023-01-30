//
//  complex_nums.h
//  complex_numbers
//
//  Created by Richard Derryberry on 1/3/23.
//

#ifndef complex_nums_h
#define complex_nums_h

#include <stdio.h>

class Complex
{
    double real;
    double imag;
    
    double mag;
    double theta;
    
    bool cartesian;
    bool polar;
    
    void calculateCartesian ();
    void calculatePolar ();
    
public:
    Complex ();
    Complex (double r, double i);
    
    double getReal ();
    double getImag ();
    
    double getMag ();
    double getTheta ();
    
    void setCartesian(double r, double i);
    void setPolar (double m, double t);
    
    void printCartesian ();
    void printPolar ();
};

// Functions on complex numbers

Complex add (Complex &a, Complex &b);
Complex mult (Complex &a, Complex &b);

#endif /* complex_nums_h */
