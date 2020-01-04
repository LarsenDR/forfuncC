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

cubicvolume( float sdia, float ldia, float length, char* equationtype, char* unittype, bool sameunits){
    float As, Al, value;

    if (!strcmp(unittype, "imperial")){

    }else if (!strcmp(unittype, "metric")){

    }else{
      value = 0.0;
      fprintf( stdout, "Unknown unititype, ", unittype, " options are imperial or metric.");   
    }
    return value
}



//Test main function
void main() {
	fprintf( stdout, "cubicvolume, smalian, imperial = %f\n", cubicvolume( 10.0, 12.0, 16.0, "smalian", "imperial", false) );
}