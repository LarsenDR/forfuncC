/*  The is the header file for ForFuncC */

#include <stdio.h>
#include <string.h>

float acornwt(float dbh, char* species);
float basalarea( float dia[], float wt[], char unittype[]);
float cubicvolume( float sdia, float ldia, float length, char* equationtype, char* unittype, bool sameunits);
float density(float sg, float mc, float wdensity);
float mesavage( float dbh, float mht, char* voltype, float girard);
float parameters(char* group );
float qmd( float ba, float tpa);
float Qmd(float ba, float tpa, char* unittype);
float sdi( float tpa, float qmd, char* unittype);

