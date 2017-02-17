#include <iostream>
#include <string>

using namespace std;

struct date {
private:
	unsigned day, month, year;

public:
	date(const string& s) {
		if (s.find_first_of(",") != string::npos) {
			convert1(s);
		}
		else if (s.find_first_of("/") != string::npos) {
			convert2(s);
		}
		else if (s.find_first_of(" ") != string::npos) {
			convert3(s);
		}
		else {
			year = 2000, month = 1, day = 1;
		}
	}
	void callout() {
		std::cout << year << "." << month << "." << day << endl;
	}

private:
	string numbers{ "0123456789" };
	void convert1(const string& s) {
		month = month_convert(s);
		day = stoi(s.substr(s.find_first_of(numbers), s.find_first_of(",")));
		year = stoi(string(s.end()-4,s.end()));
	}
	void convert2(const string& s) {
		month = stoi(s.substr(0, s.find_first_of("/")));
		day = stoi(s.substr(s.find_first_of("/")+1, s.find_last_of("/")));
		year = stoi(string(s.end() - 4, s.end()));
	}
	void convert3(const string& s) {
		month = month_convert(s);
		day = stoi(s.substr(s.find_first_of(numbers), s.find_last_of(" ")));
		year = stoi(string(s.end() - 4, s.end()));
	}
	int month_convert(const string& s) {
		int mon;
		if (s.find("Jan") < s.size()) mon = 1;
		if (s.find("Feb") < s.size()) mon = 2;
		if (s.find("Mar") < s.size()) mon = 3;
		if (s.find("Apr") < s.size()) mon = 4;
		if (s.find("May") < s.size()) mon = 5;
		if (s.find("Jun") < s.size()) mon = 6;
		if (s.find("Jul") < s.size()) mon = 7;
		if (s.find("Aug") < s.size()) mon = 8;
		if (s.find("Sep") < s.size()) mon = 9;
		if (s.find("Oct") < s.size()) mon = 10;
		if (s.find("Nov") < s.size()) mon = 11;
		if (s.find("Dec") < s.size()) mon = 12;
		return mon;
	}

};

int main() {
	date day1("May 3,2001");
	date day2("12/1/1900");
	date day3("Dec 3 1900");
	day1.callout();
	day2.callout();
	day3.callout();
	return 0;
}