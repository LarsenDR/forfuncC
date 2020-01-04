#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "forfuncC.h"

// Forestry Functions in C
// A set of board foot log volume functions.  They each need small end diameter outside bark in inches 
// and log length in feet.
// Copyright David R. Larsen, January 4, 2020
// 

float doyle( float sdia, float length ){
    float value;
    value = pow(((sdia-4.0)/4.0), 2.0) * length;
    return value;
}

float scribner( float sdia, float length ){
    float value;
    value = (0.79 * pow(sdia, 2.0) - 2.0 * sdia - 4.0 ) * (length / 16.0);
    return value;
}

float intvolume( float sdia, float length ){
    float value;

    if (length == 4.0){
        value = 0.22 * pow(sdia, 2.0) - 0.71 * sdia;   
    }else if (length == 8.0){
        value = 0.44 * pow(sdia, 2.0) - 1.20 * sdia - 0.30;   
    }else if (length == 12.0){
        value = 0.66 * pow(sdia, 2.0) - 1.47 * sdia - 0.79;   
    }else if (length == 16.0){
        value = 0.88 * pow(sdia, 2.0) - 1.52 * sdia - 1.36;   
    }else if (length == 20.0){
        value = 1.10 * pow(sdia, 2.0) - 1.35 * sdia - 1.90;   
    }else if (length == 24.0){
        value = 1.10 * pow(sdia, 2.0) - 1.35 * sdia - 1.90 + 0.22 * pow(sdia, 2.0) - 0.71 * sdia;   
    }else if (length == 28.0){
        value = 1.10 * pow(sdia, 2.0) - 1.35 * sdia - 1.90 + 0.44 * pow(sdia, 2.0) - 1.20 * sdia - 0.30;   
    }else if (length == 32.0){
        value = 1.10 * pow(sdia, 2.0) - 1.35 * sdia - 1.90 + 0.66 * pow(sdia, 2.0) - 1.47 * sdia - 0.79;   
    }else if (length == 36.0){
        value = 1.10 * pow(sdia, 2.0) - 1.35 * sdia - 1.90 + 0.88 * pow(sdia, 2.0) - 1.52 * sdia - 1.36;   
    }else if (length == 40.0){
        value = (1.10 * pow(sdia, 2.0) - 1.35 * sdia - 1.90) * 2.0;   

    }

    return value;
}

//Test main function
void main() {
	fprintf( stdout, "bflogvolume, doyle = %f\n", doyle( 10.0, 16.0) );
	fprintf( stdout, "bflogvolume, doyle = %f\n", doyle( 28.0, 16.0) );
	fprintf( stdout, "bflogvolume, scribner = %f\n", scribner( 10.0, 16.0) );
	fprintf( stdout, "bflogvolume, scribner = %f\n", scribner( 28.0, 16.0) );
	fprintf( stdout, "bflogvolume, Int 1/4 = %f\n", intvolume( 10.0, 16.0) );
	fprintf( stdout, "bflogvolume, Int 1/4 = %f\n", intvolume( 28.0, 16.0) );
	fprintf( stdout, "bflogvolume, Int 1/4 = %f\n", intvolume( 28.0, 36.0) );
}