#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <limits>

int main(void) {
	std::string str = ", Hel,,,,  , lo, world!";

	std::cout << "Count point: " << std::count(str.begin(), str.end(), ',') + 1 << std::endl;
	std::string::iterator start = str.begin();
	std::string::iterator finish;
	long range = std::numeric_limits<long>::max();

	while (start != str.end() && (*start == ' ' || *start == ',')) {
		start = std::next(start);
	}
	finish = std::find(start, str.end(), ',');

	while (start != str.end()) {
		if (start == finish) 
			range = 0;
		else {
			std::string::iterator i;

			while (start != str.end() && *start == ' ')
				start = std::next(start);
			while (start != finish) {
				i = std::find(start, finish, ' ');
				range = std::min(range, std::distance(start, i));
				start = i;
			}
		}
		start = finish;
		if (finish != str.end())
			start = std::next(start);
		finish = std::find(start, str.end(), ',');
	}
	std::cout << "Min word lenght: " << range << std::endl;

	return (0);
}
