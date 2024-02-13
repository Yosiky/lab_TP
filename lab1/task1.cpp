#include <iostream>
#include <vector>
#include <algorithm>

template <class T>
typename std::vector<T>::const_iterator ee_find(const std::vector<T> &arr, const T &value) {
	return (std::find(std::begin(arr), std::end(arr), value));
}

int main(void) {
	std::vector<int> a1 = {0, 1, 2, 3};
	std::vector<float> a2 = {0.5, 1.5, 2.5, 3.5};

	std::cout << (ee_find(a1, 2) != std::end(a1)) << ' ' << 
				 (ee_find(a2, 2.5f) != std::end(a2)) << std::endl;
	return (0);
}


