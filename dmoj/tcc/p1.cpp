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
string s;
queue<int> no;
int cnt = 0;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// get input
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'N') {
            no.push(i + 1);
        } else {
            cnt++;
        }
    }

	// return res
	string res = "YES";
    while (cnt <= n/2) {
        if (no.front() > cnt) {
            res = "NO";
            break;
        }
        no.pop();
        cnt++;
    }

	cout << fixed << res << endl;
	return 0;
}