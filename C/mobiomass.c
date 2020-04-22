#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "forfuncC.h"

// Function to calculate tree biomass (in lb) from dbh, total height and species 
// by David R. Larsen, Copyright April 21, 2020
//
// Equations from Goerndt, M. E., D. R. Larsen, C. D. Keating. 2014. Evaluation of 
// aboveground biomass weight and merchantable biomass weight for four hardwood 
// species in Missouri.i In the proceedings of the Central Hardwood Conference 
// March 10-12, 2014, Carbondale Illinois, USDA Forest Service GTR-NRS-P-142. 
// Pages 234-250
// Creative Commons http://creativecommons.org/licenses/by-nc/3.0/us/


// Function to calculate a Mesavage board foot volume.
float mobiomass( float dbh, float mht, char* species){
{
  float mobio = 0;
  if ( mht > 0 ){
   if( species == "black" )  {
	mobio = 1.67079 + 0.04796 * pow(dbh,2) + 0.81549 * log((pow(dbh,2)*mht);
   } else if( species == "post" ) {
	mobio = -0.50714 + 0.01655 * pow(dbh,2) + 0.81549 * log(pow(dbh,2)*mht);
   } else if( species == "hickory" ) {
	mobio = 0.70177 + 0.05791 * pow(dbh,2) + 0.60755 * log(pow(dbh,2)*mht);
   } else if( species == "white" ) {
	mobio = 0.61557 + 0.00373 * pow(dbh,2) + 0.71159 * log(pow(dbh,2)*mht);
   } else {
	mobio = 0.0;
   }
  }
  return mobio;
}

//Test main function
void main() {
  fprintf( stdout, "\n");
  fprintf( stdout, "mobiomass, (lb) = %f\n", mobiomass( 24.0, 40.0, "black") );
}