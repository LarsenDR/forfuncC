#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "forfuncC.h"

// Forestry Functions in C
// A set of cubic foot log volume functions.  They each need small end diameter outside bark n centimeters or inches 
// and log length in meters or feet.
// Copyright David R. Larsen, January 4, 2020
// 

float cubicvolume( float sdia, float ldia, float length, char* equationtype, char* unittype, bool sameunits){
    float As, Al, value;

    if (!strcmp(unittype, "imperial")){
      if (sameunits == true) {
        As = M_PI * pow(sdia, 2.0);
        Al = M_PI * pow(ldia, 2.0);
      } else {
        As = M_PI / (4.0 * 144.0) * pow((sdia), 2.0);
        Al = M_PI / (4.0 * 144.0) * pow((ldia), 2.0);
      }

      if (!strcmp(equationtype, "smalian")){
        value = length / 2.0 * (As + Al);
      } else if (!strcmp(equationtype, "cone")){
        value = length / 3.0 * (As + sqrt(As*Al) + Al);
      } else if (!strcmp(equationtype, "neiloid")){
        value = length / 4.0 * (As + cbrt(pow(As, 2.0)*Al) + cbrt(As*pow(Al, 2.0)) + Al);
      }

    }else if (!strcmp(unittype, "metric")){
      if (sameunits == true) {
        As = M_PI * pow(sdia, 2.0);
        Al = M_PI * pow(ldia, 2.0);
      } else {
        As = M_PI / (4.0 * 10000.0) * pow((sdia), 2.0);
        Al = M_PI / (4.0 * 10000.0) * pow((ldia), 2.0);
      }

      if (!strcmp(equationtype, "smalian")){
        value = length / 2.0 * (As + Al);
      } else if (!strcmp(equationtype, "cone")){
        value = length / 3.0 * (As + sqrt(As*Al) + Al);
      } else if (!strcmp(equationtype, "neiloid")){
        value = length / 4.0 * (As + cbrt(pow(As, 2.0)*Al) + cbrt(As*pow(Al, 2.0)) + Al);
      }
    }else{
      value = 0.0;
      fprintf( stdout, "\tUnknown unittype, %s options are imperial or metric.\n", unittype);   
    }
    return value;
}



//Test main function
void main() {
  fprintf( stdout, "\n");
	fprintf( stdout, "cubicvolume, smalian, imperial = %f\n", cubicvolume( 10.0, 12.0, 16.0, "smalian", "imperial", false) );
	fprintf( stdout, "cubicvolume, smalian, metric = %f\n", cubicvolume( 10.0, 12.0, 16.0, "smalian", "metric", false) );
	fprintf( stdout, "cubicvolume, smalian, cunit = %f\n", cubicvolume( 10.0, 12.0, 16.0, "smalian", "cunit", false) );
	fprintf( stdout, "cubicvolume, cone, imperial = %f\n", cubicvolume( 10.0, 12.0, 16.0, "cone", "imperial", false) );
	fprintf( stdout, "cubicvolume, cone, metric = %f\n", cubicvolume( 10.0, 12.0, 16.0, "cone", "metric", false) );
	fprintf( stdout, "cubicvolume, cone, cunit = %f\n", cubicvolume( 10.0, 12.0, 16.0, "cone", "cunit", false) );
	fprintf( stdout, "cubicvolume, neiloid, imperial = %f\n", cubicvolume( 10.0, 12.0, 16.0, "neiloid", "imperial", false) );
	fprintf( stdout, "cubicvolume, neiloid, metric = %f\n", cubicvolume( 10.0, 12.0, 16.0, "neiloid", "metric", false) );
	fprintf( stdout, "cubicvolume, neiloid, cunit = %f\n", cubicvolume( 10.0, 12.0, 16.0, "neiloid", "cunit", false) );
}