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

int k, n;
string s;
set<int> one;
set<int> cnt;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// get input
    cin >> k >> s >> n;

	// return res
	for (int w = 0; w < n; w++) {
        string word;
        cin >> word;
        size_t idx = 0;
        idx = s.find(word, idx);
        while (idx != string::npos) {
			//cout << "found " << word << " at " << idx << endl;
            for (int i = idx; i < idx + word.size(); i++) {
                if (one.count(i)) {
                    cnt.insert(i);
					//cout << "added " << i << endl;
                } else {
                    one.insert(i);
                }
            }
            idx++;
            idx = s.find(word, idx);
        }
    }
	cout << fixed << cnt.size() << endl;
	return 0;
}