#include "ex16_12_24.h"
#include <string>

using namespace std;

// a simple test
int main() {
	Blob<string> bs{ "pen", "pine", "apple", "applepen" };
	bs.push_back("hello");
	BlobPtr<string> bps(bs, 2);
	++bps;
	cout << *bps << endl;

	std::vector<string> vs{ "pen", "pine", "apple", "applepen" };
	Blob<string> b2(vs.begin(), vs.end());
	for (int i = 0; i != b2.size(); ++i)
		cout << b2[i] << " ";
	return 0;
}