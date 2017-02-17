#include <iostream>

class checkEqual {
public:
	bool operator()(int a, int b) {
		return (a == b);
	}
};