#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

std::ostream &operator<<(std::ostream &out, const std::vector<uint8_t> v) {
	for (const auto &i: v) {
		out << (int)i << ' ';
	}
	return (out);
}

int main(void) {
	const int n = 10;
	std::vector<uint8_t> v(n);
	std::srand(std::time(nullptr));
	int max_count = 1;
	int count = 0;
	int last = v[0] + 1;

	// std::generate(v.begin(), v.end(), [](void) { return (rand() % 256); });
	std::fill(v.begin(), v.end(), 1);
	v[0] = 0;
	v[9] = 0;
	v[5] = 0;
	std::for_each(v.begin(), v.end(), 
		[&max_count, &last, &count](uint8_t value) {
			if (last != value)
			   count = 1;
			else
				++count;
			max_count = std::max(max_count, count);
			last = value;
		});
	std::cout << "Vector: " << v << std::endl;
	std::cout << "Answer: " << max_count << std::endl;

	return (0);
}
