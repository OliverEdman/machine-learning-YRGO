#include "ml/lin_reg/fixed.h"

namespace ml::lin_reg
{
    Fixed::Fixed(const Matrix1d& trainInput, const Matrix1d& trainOutput) noexcept
        : myTrainInput(trainInput),
          myTrainOutput(trainOutput),
          myBias(0.0),
          myWeight(0.0),
          mySetCount(trainInput.size())
    {
    }

    double Fixed::predict(const double input) const noexcept
    {
        return (input * myWeight) + myBias;
    }

    bool Fixed::train(std::size_t epochCount, double learningRate) noexcept
    {
        if (epochCount == 0 || 
            mySetCount == 0 || 
            myTrainInput.size() != myTrainOutput.size() || 
            learningRate <= 0.0 || 
            learningRate >= 1.0)
        {
            return false;
        }

        for (std::size_t epoch = 0; epoch < epochCount; ++epoch)
        {
            for (std::size_t i = 0; i < mySetCount; ++i)
            {
                const auto input = myTrainInput[i];
                const auto output = myTrainOutput[i];
                optimize(input, output, learningRate);
            }
        }

        return true;
    }

    void Fixed::optimize(double input, double output, double learningRate) noexcept 
    {
        // yp = kx+m
        const auto prediction = predict(input);

        // e = yref -yp
        const auto error = output - prediction ;

        // k = k + e * LR * x
        myWeight += error * learningRate * input;

        // m = m + e * LR
        myBias += error * learningRate;
    }
} // namespace ml::lin_reg
