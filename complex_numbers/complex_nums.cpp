//
//  complex_nums.cpp
//  complex_numbers
//
//  Created by Richard Derryberry on 1/3/23.
//

#include <cmath>
#include <iostream>
#include "assert.h"
#include "complex_nums.h"

Complex::Complex ()
{
    cartesian = false;
    polar = false;
}

Complex::Complex (double r, double i)
{
    real = r;
    imag = i;
    
    cartesian = true;
    polar = false;
}

void Complex::calculateCartesian()
{
    assert(polar);
    real = mag * cos(theta);
    imag = mag * sin(theta);
    cartesian = true;
}

void Complex::calculatePolar()
{
    assert(cartesian);
    mag = sqrt( pow(real, 2.0) + pow(imag, 2.0) );
    theta = atan(imag / real);
    polar = true;
}

// Getter/setter Functions

double Complex::getReal()
{
    if (cartesian == false) calculateCartesian();
    return real;
}

double Complex::getImag()
{
    if (cartesian == false) calculateCartesian();
    return imag;
}

double Complex::getMag()
{
    if (polar == false) calculatePolar();
    return mag;
}

double Complex::getTheta()
{
    if (polar == false) calculatePolar();
    return theta;
}

void Complex::setCartesian(double r, double i)
{
    real = r;
    imag = i;
    cartesian = true;
    polar = false;
}

void Complex::setPolar(double m, double t)
{
    mag = m;
    theta = t;
    cartesian = false;
    polar = true;
}

// Display Functions

void Complex::printCartesian()
{
    std::cout << getReal() << " + " << getImag() << "i" << '\n';
}

void Complex::printPolar()
{
    std::cout << getMag() << " e^ " << getTheta() << "i" << '\n';
}

// Functions on complex numbers

Complex add (Complex &a, Complex &b)
{
    double real = a.getReal() + b.getReal();
    double imag = a.getImag() + b.getImag();
    Complex sum (real, imag);
    return sum;
}

Complex mult (Complex &a, Complex &b)
{
    double mag = a.getMag() * b.getMag();
    double theta = a.getTheta() + b.getTheta();
    Complex product;
    product.setPolar(mag, theta);
    return product;
}
