#ifndef EX13_18_H
#define EX13_18_H

#include <iostream>
#include <string>

class Employee {
public:
	Employee() { id = s_increment++; };
	Employee(const std::string& na) {
		name = na;
		id = s_increment++;
	}
	Employee(Employee &s) { 
		name = s.name;
		id = s_increment++;
	}
	Employee& operator=(Employee &rhs) {
		name = rhs.name;
		id = s_increment++;
		return *this;
	}
private:
	std::string name;
	unsigned id;
	static unsigned s_increment;
};

int Employee::s_increment = 0;

#endif