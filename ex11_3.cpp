#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

void word_count_pro(map<string, int>& m){
	string word;
	while (cin >> word){
		for (auto& ch : word)
			ch = tolower(ch);

		word.erase(remove_if(word.begin(), word.end(), ispunct),
			word.end());
		++m[word];
	}
	for (const auto& ele : m)
		cout << ele.first << " : " << ele.second << endl;
}

int main(){
	map<string, int> m;
	word_count_pro(m);
	system("pause");
	return 0;
}