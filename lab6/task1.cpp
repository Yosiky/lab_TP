#include <iostream>
#include <exception>
#include <memory>

template <class T>
struct List {
	std::shared_ptr<List>	next;
	std::shared_ptr<T>		data;
};

template <class T>
class Queue {
	
	using value_type = T;
	using value_pointer = T*;
	using smart_ptr = std::shared_ptr<value_type>;

	std::shared_ptr<List<value_type>> head;
	std::shared_ptr<List<value_type>> end;

public:

	void push_back(value_pointer value) {
		if (head == nullptr) {
			end.reset(new List<value_type>{nullptr, smart_ptr(value)});
			head = end;
		}
		else {
			end->next.reset(new List<value_type>{nullptr, smart_ptr(value)});
			end = end->next;
		}
	}

	void pop_front(void) {
		if (head == nullptr)
			throw (std::runtime_error("queue is empty"));
		else if (head == end) {
			head.reset();
			end.reset();
		} else
			head = head->next;
	}

	value_type &top(void) const {
		if (head != nullptr)
			return *head->data;
		else
			throw (std::runtime_error("queue is empty"));
	}

	void print(std::ostream &out, std::string sep=" ") const {
		std::shared_ptr<List<value_type>> first = head;
		bool first_elem = true;
		while (first != nullptr) {
			if (first_elem) {
				out << *first->data;
				first_elem = false;
			} else 
				out << sep << *first->data;

			first = first->next;
		}
	}
};

struct SpaceShip {

	int weight;
	int high;
	Queue<int> arr;

};

std::ostream &operator<<(std::ostream &out, const SpaceShip &obj) {
	out << "{ " << obj.weight << ' ' << obj.high << " ( ";
	obj.arr.print(out);
	out << " )" << " }";
	return (out);
}

int main(void) {
	Queue<int> queue;
	const int N = 10;

	for (int i = 0; i < N; ++i) 
		queue.push_back(new int(i));
	queue.print(std::cout);
	std::cout << std::endl;
	for (int i = 0; i < N; ++i)
		queue.pop_front();
	for (int i = 0; i < N; ++i) {
		queue.push_back(new int(i));
	}
	queue.print(std::cout);
	std::cout << std::endl;

	Queue<SpaceShip> ships_order;

	for (int k = 0; k < 10; ++k) {
		SpaceShip *pointer = new SpaceShip{rand() % 10, rand() % 10};
		for (int i = 0; i < rand() % 5 + 5; ++i) 
			pointer->arr.push_back(new int(i));
		ships_order.push_back(pointer);
	}
	std::cout << "Ships order: " << std::endl;
	ships_order.print(std::cout, "\n");
	return (0);
}
