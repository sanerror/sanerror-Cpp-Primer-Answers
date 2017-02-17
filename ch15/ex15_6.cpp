#include "ex15_3_5.h"

using namespace std;

int main(){
	Quote item("XSC-001", 29.5);
	Bulk_Quote bulk("XSC-008", 29.5, 2, 0.2);
	print_total(cout, item, 3);
	print_total(cout, bulk, 3);
	return 0;
}