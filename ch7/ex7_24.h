#ifndef ex7_24_h
#define ex7_24_h

#include <iostream>
#include <string>

class Screen {
public:
	using pos = std::string::size_type;

	Screen() = default;
	Screen(pos ht, pos wd) :height(ht), width(wd), contents(ht*wd, ' ')
	{};
	Screen(pos ht, pos wd, char c) :height(ht), width(wd), contents(ht*wd, c)
	{};

	char get() const { return contents[cursor]; }
	char get(pos r, pos c) const { return contents[r*width + c]; }

private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
};

#endif 
