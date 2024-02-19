#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
using namespace std;

class Dsu {
public:
	vector<ll> parent;

	Dsu(int n) {
		n += 2;
		parent.resize(n);
		for (int i = 0; i < n; i++) {
			parent[i] = i;
		}
	}

	int get(int node) {
		if (parent[node] != node) {
			parent[node] = get(parent[node]);
		}
		return parent[node];
	}

	void join(int node1, int node2) {
		int group = get(node1);
		parent[group] = node2;
	}
};

int n;
map<int, int> cnt;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// get input
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		cnt[tmp]++;
	}

	// return res
	int high = 0;
	int count = 0;
	for (int height = 2; height <= 4000; height++) {
		int length = 0;
		if (height % 2 == 0) {
			length += cnt[height / 2] / 2;
		}
		for (int i = 1; i < ceil(height / 2.0); i++) {
			length += min(cnt[i], cnt[height - i]);
		}
		if (length == high) {
			count++;
		}
		if (length > high) {
			high = length;
			count = 1;
		}
	}
	cout << high << " " << count;
	return 0;
}