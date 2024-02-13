#include <cfenv>
#include <cmath>
#include <iostream>
#include <exception>
#include <limits>

double ee_mul(float a, float b) {
	std::feclearexcept(FE_ALL_EXCEPT);
	double res = a * b;

	if (std::fetestexcept(FE_OVERFLOW))
		throw std::overflow_error("FE_OVERFLOW");
	return (res);
}

int main(void) {
	try {
		// double ans = ee_mul(std::numeric_limits<float>::max(), 
							// std::numeric_limits<float>::max());
		double ans = ee_mul(1.0f, 2.0f);

		std::cout << ans << std::endl;
	} catch (std::exception &excp){
		std::cout << "ERROR: " << excp.what() << std::endl;
	}
	return (0);
}
