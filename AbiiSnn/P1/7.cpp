#include<bits/stdc++.h>
using namespace std;

class Numero {
public:
	int numero;
	bool flag;
};
int main() {
	int n;
	cin >> n;
	vector<Numero> numbers(n+1);

	for(int i = 2; i <= n; i++) {
		numbers[i].numero = i;
		numbers[i].flag = true; 
	}
	for(int i = 2; i * i <= n; i++) {
		if(numbers[i].flag) {
			for(int j = i; j < (n / i); j++) {
				numbers[i * j].flag = false;
			}
		}
	}
	for(int i = 0; i < n; i++) {
		if(numbers[i].flag) {
			cout << numbers[i].numero << " ";
		}
	}
	cout << endl;
}