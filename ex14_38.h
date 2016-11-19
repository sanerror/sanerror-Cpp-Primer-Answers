#include <iostream>

class checkLength {
public:
	checkLength(std::size_t low, std::size_t up) : lowb(low), upb(up) {}
	bool operator()(const std::string& cst) {
		return (cst.size() <= upb && cst.size() >= lowb);
	}
private:
	std::size_t lowb;
	std::size_t upb;
};