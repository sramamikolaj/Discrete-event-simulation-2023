#ifndef RANDOM_GENERATOR_H_
#define RANDOM_GENERATOR_H_

#include <string>

class Generator
{
   public:
      Generator(int kernel);
      virtual ~Generator();

      // Draws number between <0,1>
      double rand();
      double rand(int min, int max);
      double randLog(double lambda);
      double generateGaussian(double mu, double sigma);

      int get_kernel() {return kernel_;};
   private:
      int kernel_;
      const double kM = 2147483647.0;
      static const int kA = 16807;
      static const int kQ = 127773;
      static const int kR = 2836;
};


#endif /* RANDOM_GENERATOR_H_ */