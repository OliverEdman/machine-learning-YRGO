#pragma once

#include "ml/lin_reg/interface.h"
#include "ml/types.h"

#include <cstddef>
#include <cstdint>

namespace ml::lin_reg
{
    class Fixed final : public Interface 
    {
    public:
        explicit Fixed(const Matrix1d& trainInput, const Matrix1d& trainOutput) noexcept;
        ~Fixed() noexcept override = default;

        Fixed() = delete;
        Fixed(const Fixed&) = delete;
        Fixed(Fixed&&) = delete;
        Fixed& operator=(const Fixed&) = delete;
        Fixed& operator=(Fixed&&) = delete;

        [[nodiscard]] double predict(double input) const noexcept override;
        bool train(std::size_t epochCount, double learningRate = 0.01) noexcept;

    private:
        void optimize(double input, double output, double learningRate) noexcept;

        const Matrix1d& myTrainInput;
        const Matrix1d& myTrainOutput;
        double myBias{0.0};
        double myWeight{0.0};
        const std::size_t mySetCount;
    };
} // namespace ml::lin_reg
