#include <iostream>
#include <string>
#include <list>

using std::list;
using std::string;

void elimDups(list<string>& words){
	words.sort();
	words.unique();
}

int main(){
	list<string> lst{ "aa", "aa", "aa", "aab", "aass", "aa" };
	elimDups(lst);
	for (const auto& it : lst)
		std::cout << it << " ";
	std::cout << std::endl;
	system("pause");
	return 0;
}