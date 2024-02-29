#include<vector>

class EuropeanUpAndInPutOption {
public:

  EuropeanUpAndInPutOption(
    int nInt_,
    double strike_,
    double spot_,
    double vol_,
    double r_,
    double expiry_,
    double br_
  );

  ~EuropeanUpAndInPutOption() {}
  void generatePath();
  double getPriceForEuropeanUpAndInPut(int nReps);
  double operator()(char char1, char char2, int nReps);

  std::vector<double> thisPath;
  int nInt;
  double strike;
  double spot;
  double vol;
  double r;
  double expiry;
  double br;
};

