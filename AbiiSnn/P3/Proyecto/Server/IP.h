#ifndef IP_H_
#define IP_H_
#include <bits/stdc++.h>
using namespace std;
class IP {
	public:
		IP(string p);
		int getLast();
		string getFirst();
	private:
		string s;
		int lastIndex;
};
#endif
