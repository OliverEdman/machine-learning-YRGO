/**
 * @file Dense layer stub.
 */
#pragma once

#include <cstddef>
#include <cstdio>
#include <exception>

#include "interface.h"
#include "ml/types.h"

namespace ml::dense_layer
{

class Stub final : public Interface
{
public:

    explicit Stub(const std::size_t nodeCount, const std::size_t weightCount,
                  const double outputValue = 0.5) noexcept
        : myWeights{}
        , myOutput{}
        , myError{}
        , myFeedforwardCount{}
    {
        if (0U == nodeCount)
        {
            std::fprintf(stderr, "Node count cannot be 0!\n");
            std::terminate();
        }
        if (0U == weightCount)
        {
            std::fprintf(stderr, "Weight count cannot be 0!\n");
            std::terminate();
        }
        myOutput.resize(nodeCount, outputValue);
        myError.resize(nodeCount);
        myWeights.resize(nodeCount, Matrix1d(weightCount));
    }


    ~Stub() noexcept override = default;


    [[nodiscard]] const Matrix1d& output() const noexcept override { return myOutput; }


    [[nodiscard]] const Matrix1d& error() const noexcept override { return myError; }

    [[nodiscard]] const Matrix2d& weights() const noexcept override { return myWeights; }


    [[nodiscard]] std::size_t nodeCount() const noexcept override { return myOutput.size(); }


    [[nodiscard]] std::size_t weightCount() const noexcept override { return myWeights[0U].size(); }


    bool feedforward(const Matrix1d& input) noexcept override
    {
        ++myFeedforwardCount;
        return input.size() == weightCount();
    }

    bool backpropagate(const Matrix1d& reference) noexcept override
    {
        return reference.size() == nodeCount();
    }


    bool backpropagate(const Interface& nextLayer) noexcept override
    {
        return nextLayer.weightCount() == nodeCount();
    }

    bool optimize(const Matrix1d& input, const double learningRate) noexcept override
    {
        const bool lrValid{(0.0 < learningRate) && (1.0 > learningRate)};
        return lrValid && (input.size() == weightCount());
    }

    void setOutput(const double outputValue) noexcept
    {
        for (auto& value : myOutput)
        {
            value = outputValue;
        }
    }


    [[nodiscard]] std::size_t feedforwardCount() const noexcept { return myFeedforwardCount; }

    void clearFeedforwardCount() noexcept { myFeedforwardCount = 0U; }

    Stub()                       = delete; // No default constructor.
    Stub(const Stub&)            = delete; // No copy constructor.
    Stub(Stub&&)                 = delete; // No move constructor.
    Stub& operator=(const Stub&) = delete; // No copy assignment.
    Stub& operator=(Stub&&)      = delete; // No move assignment.

private:
  
    Matrix2d myWeights;

    Matrix1d myOutput;

    Matrix1d myError;

    std::size_t myFeedforwardCount;
};
} // namespace ml::dense_layer