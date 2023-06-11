#ifndef RANDOM_GENERATOR_H_
#define RANDOM_GENERATOR_H_
#include <string>

class Generator
{
   public:
      Generator(int kernel);
      Generator(int kernel, double lambda);

      double rand();
      double rand(int min, int max);
      double randLog();
      double randGaussian(double mu, double sigma);
      int    getKernel() {return kernel_;};
   private:
      const double lambda_;
      int kernel_;
      const double kM     = 2147483647.0;
      static const int kA = 16807;
      static const int kQ = 127773;
      static const int kR = 2836;
};


#endif