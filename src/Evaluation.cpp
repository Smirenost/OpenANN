#include <OpenANN/Evaluation.h>
#include <OpenANN/Learner.h>
#include <OpenANN/io/DataSet.h>
#include <OpenANN/io/Logger.h>
#include <OpenANN/optimization/Optimizer.h>
#include <cmath>

namespace OpenANN {

double sse(Learner& learner, DataSet& dataSet)
{
  const int N = dataSet.samples();
  double sse = 0.0;
  for(int n = 0; n < N; n++)
    sse += (learner(dataSet.getInstance(n)) - dataSet.getTarget(n)).squaredNorm();
  return sse;
}

double mse(Learner& learner, DataSet& dataSet)
{
  return sse(learner, dataSet) / (double) dataSet.samples();
}

double rmse(Learner& learner, DataSet& dataSet)
{
  return std::sqrt(mse(learner, dataSet));
}

double ce(Learner& learner, DataSet& dataSet)
{
  const int N = dataSet.samples();
  double ce = 0.0;
  for(int n = 0; n < N; n++)
    ce -= (dataSet.getTarget(n).array() *
        (learner(dataSet.getInstance(n)).array().log())).sum();
  return ce;
}


double accuracy(Learner& learner, DataSet& dataSet)
{
  // TODO implement
}

Eigen::MatrixXd confusionMatrix(Learner& learner, DataSet& dataSet)
{
  // TODO implement
}


int oneOfCDecoding(const Eigen::VectorXd& target)
{
  int i;
  target.maxCoeff(&i);
  return i;
}


void crossValidation(int folds, Learner& learner, DataSet& dataSet, Optimizer& opt)
{

}


}
