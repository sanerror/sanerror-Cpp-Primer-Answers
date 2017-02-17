#pragma once
#include <string>
#include <iostream>

template <unsigned H, unsigned W> class Screen;
template <unsigned H, unsigned W>
std::ostream & operator<<(std::ostream &os, Screen<H, W> &s);
template <unsigned H, unsigned W>
std::istream & operator>>(std::istream &os, Screen<H, W> &s);

template <unsigned H, unsigned W>
class Screen {
	friend std::ostream & operator<< <H, W> (std::ostream &os, Screen<H, W> &s);
	friend std::istream & operator>> <H, W> (std::istream &os, Screen<H, W> &s);
public:
	Screen() : contents(H*W, ' ')  {}
	Screen(char c) : contents(H*W, c) {}
	char get() const { return contents[cursor]; }
	inline char get(int, int) const;
	Screen &clear(char c = bkground); // refresh?
public:
	Screen &move(int r, int c);
	Screen &set(char);
	Screen &set(int, int, char);
	Screen &display(std::ostream &os)
		{ do_display(os); return *this; }
	const Screen &display(std::ostream &os) const
		{ do_display(os); return *this; }
private:
	static const char bkground = ' ';
	// which actually do display works.
	void do_display(std::ostream &os) const { os << contents; }
	int cursor = 0;
	std::string contents;
};

template <unsigned H, unsigned W>
Screen<H, W> &Screen<H, W>::clear(char c = bkground) {
	contents = std::string(H*W, c);
	return *this;
}

template <unsigned H, unsigned W>
inline char Screen<H, W>::get(int r, int c) const {
	return contents[r*W + c];
}

template <unsigned H, unsigned W>
inline Screen<H, W> &Screen<H, W>::move(int r, int c) {
	int row = r * W;
	cursor = row + c;
	return *this;
}

template <unsigned H, unsigned W>
inline Screen<H, W> &Screen<H, W>::set(char c) {
	contents[cursor] = c;
	return *this;
}

template <unsigned H, unsigned W>
inline Screen<H, W> &Screen<H, W>::set(int r, int col, char ch) {
	contents[r*W + col] = ch;
	return *this;
}



template <unsigned H, unsigned W>
std::ostream & operator<<(std::ostream &os, Screen<H, W> &s) {
	os << s.contents;
	return os;
}

template <unsigned H, unsigned W>
std::istream & operator>>(std::istream &is, Screen<H, W> &s) {
	std::string t;
	is >> t;
	s.contents = t.substr(0, H*W);
	return is;
}