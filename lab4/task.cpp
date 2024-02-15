#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>

template <class T>
class Compare {
	int parametr;
public:
	void set_parametr(int k) {
		parametr = k;
	}

	T operator()(const T &val) {
		int sqrt_val = sqrt((double)val);

		if (sqrt_val * sqrt_val == val) {
			return (val * parametr);
		}
		return (val);
	}
};

int main(void) {
	std::vector<int> arr = {2, 4, 8, 9};

	Compare<int> op;
	op.set_parametr(10);
	std::transform(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, " "), op);
	return (0);
}

