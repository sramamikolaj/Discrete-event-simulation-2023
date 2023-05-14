
#include "Generator.h"
#include <cmath>

Generator::Generator(int kernel): kernel_(kernel)
{
  // empty
}

Generator::~Generator()
{

}

double Generator::rand()
{
   int h = kernel_/kQ;
   kernel_ = kA*(kernel_-kQ*h)-kR*h;
   if (kernel_ < 0)
      kernel_ = kernel_ + static_cast<int>(kM);
   return kernel_/kM;
}
double Generator::rand(int min, int max)
{
   return rand()*(max-min)+min;
}
double Generator::randLog(double lambda)
{
   int h = kernel_/kQ;
   kernel_ = kA*(kernel_-kQ*h)-kR*h;
   if (kernel_ < 0)
      kernel_ = kernel_ + static_cast<int>(kM);
   double k = kernel_/kM;
   return -1*(1/lambda)*log(k);
}

double Generator::generateGaussian(double mu, double sigma) {
   int h = kernel_/kQ;
   kernel_ = kA*(kernel_-kQ*h)-kR*h;
   if (kernel_ < 0)
      kernel_ = kernel_ + static_cast<int>(kM);
   double k = kernel_/kM;
   return mu + sigma * sqrt(-2.0 * log(k));
}