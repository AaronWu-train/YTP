#include <iostream>
using namespace std;
const int MAXN = 1e6 + 5;
int arr[MAXN], dp[MAXN];
void solve() {
	int N;
	cin >> N;
	for(int i = 1; i <= N; ++i) {
		cin >> arr[i];
	}	
	int mx = 0;
	for(int i = 1; i <= N; ++i) {
		dp[i] = min(dp[i - 1] + 1, arr[i]);
		mx = max(dp[i], mx);
	}
	cout << mx << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();	
}
