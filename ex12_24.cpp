#include <iostream>

int main(){
	char* input = new char[5]();
	std::cin >> input;
	std::cout << input;
	//delete[] input;
	return 0;
}