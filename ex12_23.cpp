#include <iostream>
#include <string>
#include <cstring>
#include <memory>

int main(){
	char *chs = new char[255]();
	strcat_s(chs, 255, "hello ");
	strcat_s(chs, 255, "world");
	std::cout << chs << std::endl;
	delete[] chs;

	std::unique_ptr<std::string[]> up(new std::string[2]);
	up[0] = "hello ";
	up[1] = "world!";
	for (size_t i = 0; i != 2; ++i)
		std::cout << up[i] << std::endl;
	return 0;
}
