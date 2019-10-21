#include <bits/stdc++.h>
#include "IP.h"
using namespace std;

IP::IP(string p) {
	s = p;
	int cont, i;
	cont = 0; i = 0;
	while(cont <= 2) {
		if(s[i] == '.') cont++;
		i++;
	}
	lastIndex = i;
}

int IP::getLast() {
	string srt = "";
	int n, j;
	for(int i = lastIndex; i < s.size(); i++) 
		srt += s[i];
    stringstream num(srt);  
    num >> n; 
	return n;
}

string IP::getFirst() {
	int cont = 0;
	string srt = ""; 
	for(int i = 0; i < lastIndex; i++)
		srt += s[i];
	return srt;
}