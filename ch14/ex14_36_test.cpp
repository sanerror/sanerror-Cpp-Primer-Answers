#include "ex14_35.h"
#include <vector>

using namespace std;

int main() {
	PrintSth ps;
	vector<string> vs;
	while (1) {
		string str = ps();
		if (!str.empty())
			vs.push_back(str);
		else 
			break;
	}
	for (auto ele : vs)
		cout << ele << " ";
	cout << endl;
	return 0;
}