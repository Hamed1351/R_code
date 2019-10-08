#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
double sqrt_approx(double value, int n) {
  // Initialize x to be one
  double x = 1.0;
  // Specify the for loop
  for(int i = 0; i < n; i++) {
    x = (x + value / x) / 2.0;
  }
  return x;
}




/*** R
sqrt_approx(2, 10)
*/