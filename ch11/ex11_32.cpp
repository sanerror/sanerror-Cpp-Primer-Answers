#include <iostream>
#include <map>
#include <string>
#include <set>

using namespace std;

int main(){
	multimap<string, string> authors{
		{ "J.K", "Harry Potter" },
		{ "Tolkien", "Ring" },
		{ "lewis", "Naenia" },
		{ "Tolkien", "Hobbit" },
		{ "J.K", "Fantasy Animals" }
};
	map<string, multiset<string>> order_authors;
	for (const auto& author : authors)
		order_authors[author.first].insert(author.second);
	for (const auto& author : order_authors) {
		cout << author.first << ": ";
		for (const auto& work : author.second) cout << work << " ";
		cout << std::endl;
	}
	return 0;
}