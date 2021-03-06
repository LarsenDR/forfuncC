#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "forfuncC.h"

// Function to calculate Mesavage and Girard tree Volumes
// from dbh and merchantable tree height, and Girard form class
// by David R. Larsen, January 4, 2020

// Function to calculate a Mesavage board foot volume.
float mesavage( float dbh, float mht, char* voltype, float girard){
    float L, correct;
    float v1, v2, v3, volume;
    float a[3], b[3], c[3];
    L = mht / 16.0;
    correct = (1.0 + ((girard - 78.0) * 0.03));

    if (!strcmp(voltype, "Int1/4")) {
        a[0] = -13.35212;
        a[1] = 9.58615;
        a[2] = 1.52968;
        b[0] = 1.79620;
        b[1] = -2.59995;
        b[2] = -0.27465;
        c[0] = 0.04482;
        c[1] = 0.45997;
        c[2] = -0.00961;
    } else if (!strcmp(voltype,"Scribner")) {
        a[0] = -22.50365;
        a[1] = 17.53508;
        a[2] = -0.59242;
        b[0] = 3.02888;
        b[1] = -4.34381;
        b[2] = -0.02302;
        c[0] = -0.01969;
        c[1] = 0.51593;
        c[2] = -0.02035;
    } else if (!strcmp(voltype, "Doyle")) {
        a[0] = -29.37337;
        a[1] = 41.51275;
        a[2] = 0.55743;
        b[0] = 2.78043;
        b[1] = -8.77272;
        b[2] = -0.04516;
        c[0] = 0.04177;
        c[1] = 0.59042;
        c[2] = -0.01578;
    };

    v1 = (a[0] + a[1]*L + a[2]*pow(L, 2));
    v2 = (b[0] + b[1]*L + b[2]*pow(L, 2)) * dbh;
    v3 = (c[0] + c[1]*L + c[2]*pow(L, 2)) * pow(dbh, 2);
    volume = (v1 + v2 + v3) * correct;
    
    return volume;
}



//Test main function
void main() {
  fprintf( stdout, "\n");
  fprintf( stdout, "mesavage, Int 1/4 (78) = %f\n", mesavage( 24.0, 40.0, "Int1/4", 78.0) );
  fprintf( stdout, "mesavage, Int 1/4 (82) = %f\n", mesavage( 24.0, 40.0, "Int1/4", 82.0) );
  fprintf( stdout, "mesavage, Scribner (78) = %f\n", mesavage( 24.0, 40.0, "Scribner", 78.0) );
  fprintf( stdout, "mesavage, Scribner (82) = %f\n", mesavage( 24.0, 40.0, "Scribner", 82.0) );
  fprintf( stdout, "mesavage, Doyle (78) = %f\n", mesavage( 24.0, 40.0, "Doyle", 78.0) );
  fprintf( stdout, "mesavage, Doyle (82) = %f\n", mesavage( 24.0, 40.0, "Doyle", 82.0) );
}