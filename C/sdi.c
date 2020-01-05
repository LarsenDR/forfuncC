#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "forfuncC.h"

// Function to calculate stand density index 
// from quadratic mean diameter and tree per acre
// by David R. Larsen, January 5, 2020


float sdi( float tpa, float qmd, char* unittype){
    float value = 0.0;
    if (!strcmp(unittype, "imperial")){
        value = tpa * pow(( qmd/ 10.0), 1.605);
    }else if ( !strcmp(unittype, "metric")){
        value = tpa * pow(( qmd/ 25.4), 1.605);
    }
    return value;
}



//Test main function
void main() {
  fprintf( stdout, "\n");
  fprintf( stdout, "sdi, tpa=100.0, qmd=12.3, sdi= %f\n", sdi( 200.0, 12.3, "imperial") );
  fprintf( stdout, "sdi, tpa=450.0, qmd=31.0, sdi= %f\n", sdi( 494.1, 31.0, "metric") );
  fprintf( stdout, "sdi, tpa=100.0, qmd=1.0, sdi= %f\n", sdi( 200.0, 1.0, "cunits") );
}
