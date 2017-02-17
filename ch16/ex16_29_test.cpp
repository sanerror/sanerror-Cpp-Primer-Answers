#include "ex16_29_Blob.share_point.h"
#include <string>

using namespace std;

// a simple test
int main() {
	Blob<string> bs;
	bs.push_back("hello");
	bs.push_back("world");
	
	for (int i = 0; i != bs.size(); ++i)
		cout << bs[i] << " ";
	return 0;
}