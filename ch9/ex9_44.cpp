#include <iostream>
#include <string>

using namespace std;

void replace(string& s, const string& oldVal, const string& newVal)
{
	int pos = 0;
	while (pos <= s.size() - oldVal.size())
	{
		if (oldVal == string(s, pos, oldVal.size()))
		{
			s.replace(pos, oldVal.size(), newVal);
			pos += newVal.size();
		}
		else
		{
			++pos;
		}
	}
}

int main()
{
	string s("To drive straight thru is a foolish, tho courageous act.");
	replace(s, "tho", "though");
	replace(s, "thru", "through");

	cout << s;
}