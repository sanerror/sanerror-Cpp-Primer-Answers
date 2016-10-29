#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
	multimap<string, string> authors{
		{ "J.K", "Harry Potter" },
		{ "Tolkien", "Ring"},
		{ "lewis", "Naenia" },
		{ "Tolkien", "Hobbit" },
		{ "J.K", "Fantasy Animals" }
};
	string author = "Tolkien", book = "Hobbit";
	auto range = authors.equal_range(author);
	while (range.first != range.second){
		if (range.first->second == book){
			authors.erase(range.first);
			break;// the container has been changed , the iterator is invalid.
		}
		++range.first;
	}
	for (const auto& ele : authors)
		cout << ele.first << " " << ele.second << endl;
	return 0;
}