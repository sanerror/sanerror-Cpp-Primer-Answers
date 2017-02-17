#include <iostream>
#include <vector>

using namespace std;

vector<int>* make(){
	auto a = new vector<int>();
	return a;
}

void read(vector<int>* vi){
	int temp;
	cout << "Enter something" << endl;
	while (cin >> temp)
		vi->push_back(temp);
}

void write(vector<int>* vi){
	for (const auto& ele : *vi)
		cout << ele << " ";
	cout << endl;
}

int main(){
	auto p = make();
	read(p);
	write(p);
	delete p;
	return 0;
}