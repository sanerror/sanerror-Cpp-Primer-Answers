#include <iostream>
#include <vector>
#include <memory>

using namespace std;

shared_ptr<vector<int>> make(){
	auto a = make_shared<vector<int>>();
	return a;
}

void read(shared_ptr<vector<int>> vi){
	int temp;
	cout << "Enter something" << endl;
	while (cin >> temp)
		vi->push_back(temp);
}

void write(shared_ptr<vector<int>> vi){
	for (const auto& ele : *vi)
		cout << ele << " ";
	cout << endl;
}

int main(){
	auto p = make();
	read(p);
	write(p);
	return 0;
}