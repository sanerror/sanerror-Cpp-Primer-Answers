#include <iostream>
#include <fstream>
#include "ex12_19.h"

int main(){
	std::ifstream ifs("../data/book.txt");
	StrBlob sb;
	string str;
	while (getline(ifs, str))
		sb.push_back(str);
	for (StrBlobPtr sbp = sb.begin(); sbp != sb.end(); sbp.incr())
		std::cout << sbp.deref() << std::endl;
	return 0;
}