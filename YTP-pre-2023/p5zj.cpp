#pragma GCC optimize("Ofast")
#include<iostream>
#include<vector>
#include<functional>
#define endl '\n'
using namespace std;
template<typename T>
struct segment {
	int size;
	struct node {
		T v; node *l, *r;
		node() {l = r = nullptr;}
		node(T x): v(x) {l = r = nullptr;}
	}*root;
	operator bool() {return size;}
	node* build(const vector<T>& arr, int l, int r) {
		if (l == r) {return new node(arr[l - 1]);}
		node* ret = new node;
		int m = (l + r) >> 1;
		ret->l = build(arr, l    , m);
		ret->r = build(arr, m + 1, r);
		return ret;
	}
	void build(const vector<T>& arr) {root = build(arr, 1, size);}
	node* update(int i, T k, int l, int r, node* pre) {
		if (r < i || i < l) return pre;
		if (l == r) return new node(k);
		node* ret = new node;
		int m = (l + r) >> 1;
		ret->l = update(i, k, l    , m, pre->l);
		ret->r = update(i, k, m + 1, r, pre->r);
		return ret;
	}
	void update(int i, T k) {
		root = update(i, k, 1, size, root);
	}
	T at(int i, int l, int r, node* cur) {
		if (l == r) return cur->v;
		int m = (l + r) >> 1;
		if (i <= m) return at(i, l, m, cur->l);
		else return at(i, m + 1, r, cur->r);
	}
	T at(int i) {return at(i, 1, size, root);}
	segment(const vector<T>& arr): size(arr.size()) {build(arr);}
	segment(int s): size(s), root(nullptr) {}
};

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	int n, m; cin >> n >> m;
	vector<segment<pair<int, int>>> v(m + 1, n);
	vector<pair<int, int>> tmp(n);

	for (int i = 0; i != n; i++)
		tmp[i] = {i + 1, 1};

	v[0].build(tmp);
	function<pair<int, int>(int, segment<pair<int, int>>&)> find = [&find](int i, segment<pair<int, int>>& cur) {
		pair<int, int> tmp = cur.at(i);
		return i == tmp.first ? tmp : find(tmp.first, cur);
	};
	function<void(int, int, segment<pair<int, int>>&)> join = [&find](int a, int b, segment<pair<int, int>>& cur) {
		auto x = find(a, cur), y = find(b, cur);
		auto cmp = [](pair<int, int> a, pair<int, int> b) {return a.second < b.second || (a.second == b.second && a.first < b.first);};
		auto maxn = max(x, y, cmp), minn = min(x, y, cmp);
		cur.update(minn.first, {maxn.first, minn.second});
		cur.update(maxn.first, {maxn.first, maxn.second + minn.second});
	};

	for (int i = 1, op, x, y; i <= m; i++) {
		cin >> op;
//		cout << "op: " << op << endl;
		switch (op) {
		case 1:
			cin >> x >> y;
//			cout << "xy: " << x << ' ' << y << endl;
			v[i] = v[i - 1];
			join(x, y, v[i]);
			break;
		case 2:
			v[i] = v[i-1];
			int k;
			cin >> k;
			vector<int> asks;
			for (int j = 0; j < k; ++j) {
				int a; cin >> a;
				asks.push_back(a);
			}

			int ma = find(asks[0], v[i]).first;
			bool ns = 0;
			for (auto &j : asks) {
				if (ma != find(j, v[i]).first){
					ns = 1;
					break;
				}
			}
			if (ns) {
				cout << -1 << endl;
				continue;
			} 

			int l = 0, r = i;
			while (l < r) {
				int mid = (l + r) / 2;
				bool ns = 1;
				int ra = find(asks[0], v[mid]).first;
				for (auto &j : asks) {
					if (ra != find(j, v[mid]).first){
						ns = 0;
						break;
					}
				}
				if (ns) {
					r = mid;
				} else {
					l = mid + 1;
				}
			}
			cout << l << endl;
// 			cin >> x >> y;
// //			cout << "xy: " << x << ' ' << y << endl;
// 			v[i] = v[i - 1];
// 			auto a = find(x, v[i]), b = find(y, v[i]);
// //			cout << "a: " << a.first << ' ' << a.second << endl;
// //			cout << "b: " << b.first << ' ' << b.second << endl;
// 			int ans = (a.first == b.first);
// 			cout << ans << endl;
			break;
		}
	}
	return 0;
}
