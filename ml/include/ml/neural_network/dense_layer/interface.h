#pragma once
#include <cstddef>

#include <ml/types.h>

namespace ml::dense::layer
{
class Interface
{

    virtual ~Interface() noexcept = default;

    [[nodiscard]] virtual std::size_t nodeCount() const noexcept = 0;

    [[nodiscard]] virtual std::size_t weightCount() const noexcept = 0;

    [[nodiscard]] virtual const ml::Matrix1d& output() const noexcept = 0;

    [[nodiscard]] virtual const ml::Matrix1d& error() const noexcept = 0;

    [[nodiscard]] virtual const ml::Matrix2d& weights() const noexcept = 0;

    bool virtual feedforward(const ml::Matrix1d& input) noexcept = 0;

    bool virtual backpropagate(const ml::Matrix1d& reference) noexcept = 0;

    bool virtual backpropagate(const Interface& nextLayer) noexcept = 0;

    bool virtual optimize (const ml::Matrix1d& input, double learningRate) noexcept = 0;

};
} // namespace ml::dense::layer