#include <iostream>
#include <algorithm>
#include <vector>

void ee_transform(std::vector<char> &arr) {
	for (auto i = std::begin(arr); i != std::end(arr); 
		 i = std::find(i, std::end(arr), 'e'))
		*i = 'g';
}

std::ostream &operator<<(std::ostream &out, const std::vector<char> &arr) {
	for (const auto &i : arr)
		out << i << ' ';
	return (out);
}

int main(void) {
	// std::vector<char> a1 = "";
	std::vector<char> a1;
	const int n = 10;

	a1.resize(n, 'e');
	ee_transform(a1);
	std::cout << a1 << std::endl;

	return (0);
}
