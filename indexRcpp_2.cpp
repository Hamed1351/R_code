#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
double sum_cpp(NumericVector x) {
  // The size of x
  int n = x.size();
  // Initialize the result
  double result = 0;
  // Complete the loop specification
  for(int i = 0; i < n; i++) {
    // Add the next value
    result = result + x[i];
  }
  return result;
}

/*** R
set.seed(42)
x <- rnorm(1e6)
sum_cpp(x)
# Does the function give the same answer as R's sum() function?
all.equal(sum_cpp(x), sum(x))
*/