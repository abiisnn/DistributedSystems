#include<bits/stdc++.h>
using namespace std;

int main() {
	double x, r, t;
	cin >> x;
	r = x;
	t = 0; 
	while(abs(x - (r * r)) > 1e-4) {
		t = r;
		r = (0.5) * ((x / r) + r);
	}
	cout << fixed << setprecision(4) << r << endl;
}