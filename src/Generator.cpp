
#include "Generator.h"
#include <cmath>
#include <iostream>
#include <random>
Generator::Generator(int kernel): kernel_(kernel), lambda_(0)
{
}

Generator::Generator(int kernel, double lambda): kernel_(kernel), lambda_(lambda)
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

double Generator::randLog()
{
   int h = kernel_/kQ;
   kernel_ = kA*(kernel_-kQ*h)-kR*h;
   if (kernel_ < 0)
      kernel_ = kernel_ + static_cast<int>(kM);
   double k = kernel_/kM;
   double returnable = (-1*(1/lambda_)*log(k));
   return returnable;
}

double Generator::randGaussian(double mu, double sigma) 
{
   int h = kernel_/kQ;
   kernel_ = kA*(kernel_-kQ*h)-kR*h;
   if (kernel_ < 0)
      kernel_ = kernel_ + static_cast<int>(kM);
   double k = kernel_/kM;
   h = kernel_/kQ;
   kernel_ = kA*(kernel_-kQ*h)-kR*h;
   if (kernel_ < 0)
      kernel_ = kernel_ + static_cast<int>(kM);
   double k2 = kernel_;
   return mu + sigma * std::sqrt(-2.0 * std::log(k)) * std::cos(2.0 * 3.14 * k2);
}