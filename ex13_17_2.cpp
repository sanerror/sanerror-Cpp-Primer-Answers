#include <iostream>

using namespace std;

class numbered {
private:
	static int seq;
public:
	numbered() { mysn = seq++; }
	numbered(const numbered& a) : mysn(seq++) {}
	int mysn;
};

int numbered::seq = 0;

void f(numbered s)
{
	cout << s.mysn << endl;
}

int main() {
	numbered a, b = a, c = b; // call f() three times
	f(a);f(b);f(c); // call f() three times again

	return 0;
}