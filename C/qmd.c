#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "forfuncC.h"

// Function to calculate the quadratic mean diameter 
// from basal area and tree per acre
// by David R. Larsen, January 5, 2020

float Qmd(float ba, float tpa, char* unittype){
    float value = 0.0;
    if (!strcmp(unittype, "imperial")){
        value = sqrt((ba/tpa)/0.005454154);
    }else if (!strcmp(unittype, "metric")){
        value = sqrt((ba/tpa)/0.00007854);
    }
    return value;
}


//Test main function
void main() {
  fprintf( stdout, "\n");
  fprintf( stdout, "qmd, ba=55.0, tpa=100.0 qmd= %f\n", Qmd( 55.0, 100.0, "imperial") );
  fprintf( stdout, "qmd, ba=18.3, tpa=450.0 qmd= %f\n", Qmd( 18.3, 450.0, "metric") );
  fprintf( stdout, "qmd, ba=55.0, tpa=100.0 qmd= %f\n", Qmd( 55.0, 100.0, "cunits") );
  fprintf( stdout, "qmd, ba=95.0, tpa=180.0 qmd= %f\n", Qmd( 95.0, 180.0, "imperial") );
  fprintf( stdout, "qmd, ba=28.0, tpa=500.0 qmd= %f\n", Qmd( 28.0, 500.0, "metric") );
  fprintf( stdout, "qmd, ba=95.0, tpa=180.0 qmd= %f\n", Qmd( 95.0, 180.0, "cumits") );
}
