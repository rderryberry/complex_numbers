//
//  main.cpp
//  complex_numbers
//
//  Created by Richard Derryberry on 1/3/23.
//

#include <iostream>
#include "complex_nums.h"

int main() {
    Complex c1 (2.0, 3.0);
    Complex c2 (3.0, 4.0);
    Complex product = mult(c1, c2);
    product.printCartesian();
    return 0;
}
