#include<iostream>
using namespace std;
const double g = 9.8;
int main() {
    double t, result;
    cin >> t;
    result = 0.5 * g * t * t; 
    cout << result << endl; 
}