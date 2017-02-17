#pragma once
#include <iostream>

struct Delete {
	template <typename P>
	void operator()(P* ptr) {
		delete ptr;
	}
};