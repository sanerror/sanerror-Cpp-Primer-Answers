#include "ex15_30.h"

using namespace std;

int main() {
	Basket bsk;
	for (int i = 0; i < 10; ++i)
		bsk.add_item(Bulk_quote("JNU110", 45, 10, 0.1));
	for (int i = 0; i < 20; ++i)
		bsk.add_item(Bulk_quote("SYSU110", 50, 10, 0.1));
	bsk.total_receipt(cout);
	return 0;
}