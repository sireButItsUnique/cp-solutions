#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b) { return a[1] > b[1]; }
int main() {
	priority_queue<vector<int>, vector<vector<int>>, decltype(&cmp)> pq(cmp);
	pq.push({0, 1, 2});
	pq.push({0, 3, 2});
	pq.push({0, 2, 2});
	cout << pq.top()[1] << endl;
	pq.pop();
	cout << pq.top()[1] << endl;
	pq.pop();
	cout << pq.top()[1] << endl;
	return 0;
}