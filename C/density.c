#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "forfuncC.h"

// Function to calculate the density of a cubic unit of wood.
// waterdensity must in in the unit desired for output.
// by David R. Larsen, Copyright January 4, 2020
// Creative Commons http://creativecommons.org/licenses/by-nc/3.0/us/
//
// "Specific gravity G  is defined as the ratio of the density of a substance
// to the density of water pw at a specified reference temperature, typically
// 4 C (39 F), where pw  is 1.000 g cm-3(1,000 kg m-3 or 62.43 lb ft-3)." (Wood Handbook)
// Equation from Wood Handbook Chapter 4, page 10-12,  General Technical Report FPL-GTR 190

float density(float sg, float mc, float wdensity) {
    float value;
    value = wdensity * sg * (1.0 + (mc / 100.0));
    return value;
}

//Test main function
void main() {
  fprintf( stdout, "\n");
  fprintf( stdout, "density, imperial = %f\n", density( 0.4, 12.0, 62.43) );
  fprintf( stdout, "density, imperial = %f\n", density( 0.4, 12.0, 1000.0) );
}
