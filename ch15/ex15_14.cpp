#include <iostream>
#include <string>

using namespace std;

class base {
public:
	base() = default;
	base(const string& str) : basename(str) {}
	string name() { return basename; }
	virtual void print(ostream &os) { os << basename; }
private:
	string basename;
};

class derived : public base {
public:
	derived() = default;
	derived(const string& str, int j) : base(str), i(j) {}
	void print(ostream &os) { base::print(os); os << " " << i << endl; }
private:
	int i;
};

int main() {
	base bobj("hello"); base *bp1 = &bobj; base &br1 = bobj;
	derived dobj("hi", 1); base *bp2 = &dobj; base &br2 = dobj;

	bobj.print(cout);
	dobj.print(cout);
	bp1->name();
	bp2->name();
	br1.print(cout);
	br2.print(cout);

	return 0;
}