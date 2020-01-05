#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "forfuncC.h"

// Function to calculate percent stocking
// from Basal area and trees per acre
// by David R. Larsen, January 5, 2020

// percentstocking is only for imperial units.

float parameters(char* group ){
    float value[3] = {-0.00507, 0.01698, 0.00307};
    if ( !strcmp( group, "northern.red.oak")){
        value[] = {-0.00507, 0.01698, 0.00307};
    }
    return value;
}

// Function to calculate a quadratic mean diameter from basla area and trees per acre
float qmd( float ba, float tpa){
    float value = sqrt(((ba / tpa) / 0.005454154));
    return value;
}

// percentStocking is a function that retruns the percent stocking
// using a gringrich style tree area equation.
float percentStocking(float ba, float tpa, char* group){
    float percent, dia, amd;
    float b[3];
    dia = qmd( ba, tpa);
    amd = -0.259 + 0.973 * dia;
    b[3] = parameters( group );
    percent = (b[0] + b[1] * amd + b[2] * pow(dia, 2.0)) * tpa;
    if (percent < 0.0 ){
        percent = 0.0;
    }
    return percent;
}

//Test main function
void main() {
  fprintf( stdout, "\n");
  fprintf( stdout, "percentStocking, ba=55, tpa=100 = %f\n", percentStocking( 55.0, 100.0, " ") );
}
