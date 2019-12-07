#include <stdlib.h>
#include <string.h>
#include "forfuncC.h"

int arrayLength = 7;

// Basalarea function to basalarea per unit area for a list of trees.
float basalarea(float dia[], float wt[], char* unittype) {
	float cst, ba;
	cst = 0.005454154;
	if (!strcmp(unittype, "metric")) {
		cst = 0.00007856;
	}

	for( int i = 0; i < arrayLength; i++ ){
		ba = ba + cst*dia[i]*dia[i]*wt[i];
	}
	return( ba );
}

//Test main function
void main() {
	float dia[] = {8, 6, 8, 5, 4, 6, 7};
	float wt[] = {10, 10, 10, 10, 10, 10, 10};
	float wt2[] = {25, 25, 25, 25, 25, 25, 25};
	float BAi = basalarea(dia, wt, "imperial");
	float BAm = basalarea(dia, wt2, "metric");
	fprintf( stdout, "basalarea imperial = %f\n", BAi );
	fprintf( stdout, "basalarea metric = %f\n", BAm );
}
