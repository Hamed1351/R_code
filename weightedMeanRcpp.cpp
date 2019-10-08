#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
double weighted_mean_cpp(NumericVector x, NumericVector w) {
  // Initialize these to zero
  double total_w = 0;
  double total_xw = 0;
  
  // Set n to the size of x
  int n = x.size();
  
  // Specify the for loop arguments
  for(int i = 0; i < n; i++) {
    // Add ith weight
    total_w += w[i];
    // Add the ith data value times the ith weight
    total_xw += (x[i] * w[i]);
  }
  
  // Return the total product divided by the total weight
  return total_xw / total_w;
}

/*** R 
x <- c(0, 1, 3, 6, 2, 7, 13, 20, 12, 21, 11)
w <- 1 / seq_along(x)
weighted_mean_cpp(x, w)
# Does the function give the same results as R's weighted.mean() function?
all.equal(weighted_mean_cpp(x, w), weighted.mean(x, w))
*/
