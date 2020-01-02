#include <stdlib.h>
#include <string.h>
#include "forfuncC.h"

// Function to calculate mean acorn weight (in lb) from dbh and species and trees per acre.
float acornwt(float dbh, char* species)
{
  float acnwt;
  if( (!strcmp(species, "black") && (dbh > 9.9) && (dbh < 36.1) )){
    acnwt = -1.9065 + 0.2973 * dbh;
  }else if((!strcmp(species, "chestnut") && (dbh > 9.9) && (dbh < 36.1))){
    acnwt = 0.0008271 * (dbh * dbh * dbh) - 0.08157 * (dbh * dbh) + 2.692 * dbh - 18.85;
  }else if(!strcmp(species, "red") && dbh > 9.9 && dbh < 36.1) {
    acnwt = 0.0004016 * (dbh * dbh * dbh * dbh) - 0.0349937 * (dbh * dbh * dbh) + 0.9864357 * (dbh * dbh) - 9.5233885 * dbh + 27.32720516;
  }else if(!strcmp(species, "scarlet") && dbh > 9.9 && dbh < 36.1) {
    acnwt = 0.0005975 * (dbh * dbh * dbh * dbh) - 0.05325 * (dbh * dbh * dbh) + 1.651 * (dbh * dbh) - 19.97 * dbh + 84.71;
  }else if(!strcmp(species, "white") && dbh > 9.9 && dbh < 36.1){
    acnwt = 0.0001987 * (dbh * dbh * dbh * dbh) - 0.02027 * (dbh * dbh * dbh) + 0.694 * (dbh * dbh) - 8.768 * dbh + 37.36;
  }else{
    acnwt = 0.0;
  };
  return( acnwt );
};

//Test main function
void main() {
	fprintf( stdout, "acornwt, black oak, imperial = %f\n", acornwt( 14.3, "black") );
	fprintf( stdout, "acornwt, white oak, imperial = %f\n", acornwt( 22.6, "white") );
	fprintf( stdout, "acornwt, scalet oak, imperial = %f\n", acornwt( 18.9, "scarlet") );
}