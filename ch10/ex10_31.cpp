#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	istream_iterator<int> ifs(cin), eof;
	vector<int> vei, ves;
	copy(ifs, eof, back_inserter(vei));
	sort(vei.begin(), vei.end());
	ves.resize(vei.size());
	auto end_unique = unique_copy(vei.cbegin(), vei.cend(), ves.begin());
	ves.erase(end_unique, ves.end());
	copy(ves.begin(), ves.end(),
		ostream_iterator<int>(cout, " "));
	return 0;
}