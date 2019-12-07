
#include "forfuncC.h"

int arlen = 7;

float basalarea(float dia[], float wt[], char unittype[]) {
	float cst, ba;
	cst = 0.005454154;
	if (unittype == "metric") {
		cst = 0.00007856;
	}

	for( int i = 0; i < arlen; i++ ){
		ba = ba + cst*dia[i]*dia[i]*wt[i];
	}
	return( ba );
}

void main() {
	float dia[] = {8, 6, 8, 5, 4, 6, 7};
	float wt[] = {10, 10, 10, 10, 10, 10, 10};
	float wt2[] = {25, 25, 25, 25, 25, 25, 25};
	float BAi = basalarea(dia, wt, "imperial");
	float BAm = basalarea(dia, wt2, "metric");
	fprintf( stdout, "basalarea imperial = %f\n", BAi );
	fprintf( stdout, "basalarea metric = %f\n", BAm );
}
