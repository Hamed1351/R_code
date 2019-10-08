#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
List sqrt_approx_2(double value, int n, double threshold) {
  double x = 1.0;
  double previous = x;
  bool is_good_enough = false;
  int i;
  for(i = 0; i < n; i++) {
    previous = x;
    x = (x + value / x) / 2.0;
    is_good_enough = fabs(previous - x) < threshold;
    
    // If the solution is good enough, then "break"
    if(is_good_enough > threshold) break;
  }
  return List::create(_["i"] = i , _["x"] = x);
}

/*** R
sqrt_approx_2(2, 1000, 0.1)
*/