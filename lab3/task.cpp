#include <iostream>

#define PI 3.14f

class Shape {
protected:
	float a, b, c;

public:

	void set_attributes(float a, float b, float c) {
		this->a = a;
		this->b = b;
		this->c = c;
	}

	virtual const std::string name(void) const = 0;
	virtual const float getVolume(void) const = 0;

};

class Sphere: public Shape {

public:

	const std::string name(void) const override {
		return ("Sphere");
	}

	const float getVolume(void) const override {
		return (4.0f / 3 * PI * a * a * a);
	}
};

class Elipsoid: public Shape {
public:

	const std::string name(void) const override {
		return ("Elipsoid");

	}

	const float getVolume(void) const override {
		return (4.0f / 3 * PI * a * b * c);
	}
};

class Cylinder: public Shape {
public:

	const std::string name(void) const override {
		return ("Cylinder");
	}

	const float getVolume(void) const override {
		return (PI * a * a * b);
	}
};

Shape *get_random_obj(void) {
	static int i = 0; 
	Shape *pointer;

	switch (i) {
	case (0): 
		pointer = new Sphere;
		break ;
	case (1):
		pointer = new Elipsoid;
		break ;
	case (2):
		pointer = new Cylinder;
		break ;
	}
	i = (i + 1) % 3;
	return (pointer);
}

int detect_type(Shape *ptr) {
	if (dynamic_cast<Sphere *>(ptr) != NULL) {
		return (1);
	}
	if (dynamic_cast<Elipsoid *>(ptr) != NULL) {
		return (2);
	}
	if (dynamic_cast<Cylinder *>(ptr) != NULL) {
		return (3);
	}
	return (4);
}

int main(void) {

	for (int i = 0; i < 3; ++i) {
		Shape *pointer = get_random_obj();

		pointer->set_attributes(1, 2, 3);

		std::cout << "If next value == 1 it's Sphere\n\tvalue == 2 it's Elipsoid\n\tvalue == 3 it's Cylinder\nif value == 4 then type is not inherents Shpae" << std::endl;
		std::cout << detect_type(pointer) << std::endl;

		std::cout << "Name of shape is " << pointer->name() << std::endl;
		std::cout << "Figure's volume is " << pointer->getVolume() << std::endl;
		std::cout << "============================================" << std::endl;
	}
	return (0);
}
