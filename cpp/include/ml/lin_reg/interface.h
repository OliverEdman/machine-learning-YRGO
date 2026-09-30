#pragma once

namespace ml::lin_reg 
{

	class Interface 
	{
	public:
		//Destruktor
		virtual ~Interface() noexcept = default;

		[[nodiscard]] virtual double predict(double input) const noexcept = 0;
	};
}// namespace ml::lin_reg
