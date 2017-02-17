#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	istream_iterator<int> ifs(cin), eof;
	vector<int> vei;
	copy(ifs, eof, back_inserter(vei));
	sort(vei.begin(), vei.end());
	copy(vei.begin(), vei.end(), 
		ostream_iterator<int>(cout, " "));
	return 0;
}