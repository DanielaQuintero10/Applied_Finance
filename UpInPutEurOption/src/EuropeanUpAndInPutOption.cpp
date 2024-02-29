#include<iostream>
#include<cmath>
#include"getOneGaussianByBoxMueller.h"
#include"EuropeanUpAndInPutOption.h"

//definition of constructor
EuropeanUpAndInPutOption::EuropeanUpAndInPutOption(
  int nInt_,
  double strike_,
  double spot_,
  double vol_,
  double r_,
  double expiry_,
  double br_){
  nInt = nInt_;
  strike = strike_;
  spot = spot_;
  vol = vol_;
  r = r_;
  expiry = expiry_;
  br = br_;
  generatePath();
}

void EuropeanUpAndInPutOption::generatePath() {
  double thisDrift = (r * expiry - 0.5 * vol * vol * expiry) / double(nInt);
  double cumShocks = 0;
  thisPath.clear();

  for(int i = 0; i < nInt; i++){
    cumShocks += (thisDrift + vol * sqrt(expiry / double(nInt)) * getOneGaussianByBoxMueller());
    thisPath.push_back(spot * exp(cumShocks));
  }
}

double EuropeanUpAndInPutOption::getPriceForEuropeanUpAndInPut(int nReps) {
  double rollingSum = 0.0;

  for (int i = 0; i < nReps; i++) {
    generatePath();
    bool isActivated = false;
    for (double price : thisPath) {
      if (price > br) {
        isActivated = true;
        break;
      }
    }
    if (isActivated) {
      double finalPrice = thisPath.back();  // Get the final price if the option is activated
      rollingSum += (finalPrice < strike) ? (strike - finalPrice) : 0;
    }
  }
  return exp(-r * expiry) * rollingSum / nReps;
}
