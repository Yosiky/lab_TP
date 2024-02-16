#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>

template <class T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &v) {
	for (const T &i : v) {
		out << std::hex << "0x" << i << ' ';
	}
	return (out);
}

int main(void) {
	// const uint16_t start_point = 0x3145;
	const uint16_t start_point = 0;
	std::vector<uint16_t> v(20);
	std::random_device rd;
    std::mt19937 g(rd());

	std::iota(v.begin(), v.end(), start_point);
	std::cout << "Start view: " << v << std::endl;
	std::shuffle(v.begin(), v.end(), g);
	std::cout << "Random shuffle: " << v << std::endl;
	std::sort(v.begin(), v.end());
	std::cout << "Sort view: " << v << std::endl;
	return (0);
}
