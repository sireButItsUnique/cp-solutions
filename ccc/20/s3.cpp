#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;

/*
zzzzzzz
zzzzzzzz
*/

vector<ll> rolling_hash(string s, int window_size, int base = 131,
						int mod = 1e12 + 7) {
	int n = s.length();
	vector<ll> power(window_size, 1);
	vector<ll> hash_values(n - window_size + 1);

	// Precompute the powers of the base modulo the mod
	for (int i = power.size() - 2; i >= 0; i--) {
		// power[i] = (power[i + 1] * base) % mod;
		power[i] = (power[i + 1] * base);
	}

	// Compute the hash value of the first window
	unsigned ll current_hash = 0;
	for (int i = 0; i < window_size; i++) {
		// current_hash += (power[i] * (s[i])) % mod;
		// current_hash %= mod;
		current_hash += (power[i] * (s[i]));
	}
	hash_values[0] = current_hash;

	// Compute the hash values of the rest of the substrings
	for (int i = 1; i <= n - window_size; i++) {
		// Del first character
		// current_hash -= (power[0] * (s[i - 1])) % mod;
		// current_hash %= mod;
		current_hash -= (power[0] * (s[i - 1]));

		// Shift the window by one character
		current_hash *= base;
		// current_hash %= mod;

		// Add last character in window
		current_hash += (s[i + window_size - 1]);
		// current_hash %= mod;

		hash_values[i] = current_hash;
	}
	return hash_values;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// get input
	string n, h;
	cin >> n >> h;
	vector<int> cnt(26, 0);
	for (int i = 0; i < n.size(); i++) {
		cnt[n[i] - 'a']++;
	}
	if (n.size() > h.size()) {
		cout << 0;
		return 0;
	}
	vector<ll> hashes = rolling_hash(h, n.size());

	// slid thru haystack
	vector<int> perm(26, 0);
	set<ll> counted;
	for (int i = 0; i < n.size(); i++) {
		perm[h[i] - 'a']++;
	}
	// cout << h.substr(0, n.size()) << ": " << hashes[0] << endl;
	if (perm == cnt) {
		counted.insert(hashes[0]);
	}

	for (int i = n.size(); i < h.size(); i++) {
		perm[h[i - n.size()] - 'a']--;
		perm[h[i] - 'a']++;

		// cout << h.substr(i - n.size() + 1, n.size()) << ": "
		// 	 << hashes[i - n.size() + 1] << endl;
		if (perm == cnt) {
			counted.insert(hashes[i - n.size() + 1]);
		}
	}

	// return res
	cout << fixed << counted.size();
	return 0;
}