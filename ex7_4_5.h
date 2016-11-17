#ifndef ex7_4_h
#define ex7_4_h

#include <string>

class Person {
	std::string name;
	std::string address;
public:
	const std::string& name() const { return name; };
	const std::string& addr() const { return address; };
};


#endif
//Yes,these function may not write to the data members of 
//the objects on which it;s called;