#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "forfuncC.h"

// Function to calculate the Beers, 1964 tree volume
// from diameter at breast height and merchantable height
// by David R. Larsen, January 5, 2020


float treeVolume(float dbh, float mht, char* volumeType ){
	float volume = 0.0, a, b, c;
	if (mht > 0.0 ){
		a = (pow(dbh, 2.0) * (dbh + 190.0)) / 100000.0;
		b = 1.0 / 100.0 * ((mht*(168.0-mht))/64.0 + (32.0 / mht));
		c = 475.0 + (3.0 * pow(mht, 2.0))/128.0;

		if (!strcmp(volumeType, "cords")) {
			volume = a * b;
		} else if (!strcmp(volumeType, "cubic")) {
			volume = 76.0 * a * b;
		} else if (!strcmp(volumeType,"cubicbark")) {
			volume = 92.0 * a * b;
		} else if (!strcmp(volumeType, "boardfeet")) {
			volume = a * b * c;
		} else {
			volume = 0.0;
		};
	}
	return volume;
}

void main() {
	fprintf( stdout, "treeVolume, Cords = %f\n", treeVolume(10, 26, "cords"));
	fprintf( stdout, "treeVolume, Cubic = %f\n", treeVolume(10, 26, "cubic"));
	fprintf( stdout, "treeVolume, Cubic with bark = %f\n", treeVolume(10, 26, "cubicbark"));
	fprintf( stdout, "treeVolume, International 1/4 boardfeet = %f\n", treeVolume(10, 26, "boardfeet"));
}