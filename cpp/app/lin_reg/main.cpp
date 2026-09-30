/**
 * @brief Linear regression demonstration.
 */
#include <cstdint>
#include <cstdio>

#include "ml/lin_reg/fixed.h"
#include "ml/types.h"

namespace
{
/**
 * @brief Predict with the given linear regression model.
 *
 * @param[in] linReg Linear regression model to predict with.
 * @param[in] inputData Input data to predict with.
 */
void predict(const ml::lin_reg::Interface& linReg, const ml::Matrix1d& inputData) noexcept
{
    // Check the number of input sets, terminate if missing.
    if (inputData.empty())
    {
        std::printf("No input data!\n");
        return;
    }

    // Perform prediction with each input set, print the result in the terminal.
    std::printf("--------------------------------------------------------------------------------\n");
    for (const auto& input : inputData)
    {
        const auto prediction = linReg.predict(input);
       std::printf("Input: %g, predicted output: %g\n", input, prediction);
    }
    std::printf("--------------------------------------------------------------------------------\n\n");
}
} // namespace

/**
 * @brief Train and predict with a linear regression model.
 *
 * @return 0 on success, or -1 on failure.
 */
int main()
{
    constexpr std::uint32_t epochCount{52U};
    constexpr double learningRate{0.2};

    // Create linear regression model to predict y = 2x + 2.
    const ml::Matrix1d trainInput{0.0, 1.0, 2.0, 3.0, 4.0};
    const ml::Matrix1d trainOutput{2.0, 4.0, 6.0, 8.0, 10.0};
    ml::lin_reg::Fixed linReg{trainInput, trainOutput};

    // Train the model, terminate on failure.
    if (!linReg.train(epochCount, learningRate))
    {
        std::printf("Training failed!\n");
        return -1;
    }

    // Perform prediction with all input sets.
    predict(linReg, trainInput);
    return 0;
}
