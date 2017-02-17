#include <iostream>

class if_then_else {
public:
	int operator()(bool a, int b, int c) {
		if (a)
			return b;
		else
			return c;
	}
};