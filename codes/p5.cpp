#include <iostream>
#include <string>
using namespace std;
void solve() {
	string s;
	cin >> s;	
	int x = 0, y = 0;
	for(auto c : s) {
		switch(c) {
			case 'A':
				++x;
				break;
			case 'B':
				++x;
				++y;
				break;
			case 'C':
				++y;
				break;
			case 'D':
				--x;
				break;
			case 'E':
				--x;
				--y;
				break;
			case 'F':
				--y;
				break;
		}
	}
	if(x * y > 0) cout << max(abs(x), abs(y)) << '\n';
	else cout << abs(x) + abs(y) << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);	
	solve();
}
