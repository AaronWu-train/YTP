#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
using namespace std;
const int MAXN = 15;
const double EPS = 1e-4;
int deg, arr[MAXN];
struct Poly {
	int deg;
	long long int coef[MAXN];
   	double operator() (const double& x) const {
		double ret = 0;
		for(int i = deg; i >= 0; --i) {
			ret *= x;	
			ret += coef[i];
		}	
		return ret;
	}
} f, fp;
void solve() {
	string line;
	getline(cin, line);
	stringstream ss;
	ss << line;
	int buf;
	while(ss >> buf) {	
		arr[deg++] = buf;
	}
	--deg;	
	f.deg = deg;
	for(int i = 0; i <= deg; ++i) {
		f.coef[i] = arr[deg - i];	
	}
	fp.deg = deg - 1;
	for(int i = 0; i <= deg - 1; ++i) {	
		fp.coef[i] = f.coef[i + 1] * (i + 1);	
	}
	double x = 0;
	for(int i = 1; i <= 100; ++i) {
		double iter = f(x)/fp(x);
		if(fabs(iter) <= EPS) break; 
		x = x - iter;	
	}
	cout << setprecision(2) << fixed << x << '\n';
	return;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();	
}
