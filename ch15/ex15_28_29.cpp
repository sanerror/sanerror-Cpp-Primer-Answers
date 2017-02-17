#include "ex15_27.h"
#include <vector>
#include <memory>

using namespace std;

int main() {
	vector<Quote> basket;
	basket.push_back(Bulk_quote("Jnu-110", 10, 20, 0.1));
	basket.push_back(Bulk_quote("Sysu-100", 10, 10, 0.2));
	double all = 0;
	for (auto ele : basket) {
		all += ele.net_price(20);
	}

	vector<shared_ptr<Quote>> basket2;
	basket2.push_back(make_shared<Bulk_quote>("Jnu-110", 10, 20, 0.1));
	basket2.push_back(make_shared<Bulk_quote>("Sysu-100", 10, 10, 0.2));
	all = 0;
	for (auto ele : basket2) {
		all += ele->net_price(20);
	}
	cout << all << endl;
	return 0;
}