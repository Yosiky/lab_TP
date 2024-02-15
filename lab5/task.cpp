#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>

int main(void) {
	std::vector<int> arr = {2, 4, 8, 9};
	int parametr = 10;
	int bound = 5;

	std::function<int (const int)> lambda = [parametr, bound](int val) {
		if (val < bound)
			return (val * parametr);
		return (val);
	};
	std::transform(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, " "), lambda);
	return (0);
}

