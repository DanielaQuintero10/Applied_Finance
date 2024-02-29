#include<Rcpp.h>
#include<vector>
#include<ctime>
#include<cstdlib>
#include"EuropeanUpAndInPutOption.h"
#include"getVecMean.h"
#include"getVecStdDev.h"

using namespace Rcpp;
using std::vector;


// [[Rcpp::export]]
double getPriceForEuropeanUpAndInPut(
    int nInt,
    double Strike,
    double Spot,
    double Vol,
    double Rfr,
    double Expiry,
    double br,
    int nReps = 1000
){

  srand( time(NULL) );
  EuropeanUpAndInPutOption InOutOption(nInt, Strike, Spot, Vol, Rfr, Expiry,br);
  return InOutOption.getPriceForEuropeanUpAndInPut(nReps);
}
