#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int T;

struct info {
	int prob[110] = { 0 };
	int num = 0;
	int sum = 0;
	int cnt=0;
	int time=0;
};


int main() {
	int n, k, t, m;
	cin >> T;
	for (int i = 0; i < T; i++) {
		info team[110];
		cin >> n >> k >> t >> m;
		for (int j = 0; j < m; j++) {
			int a, b, c;
			cin >> a >> b >> c;
			team[a].num = a;
			team[a].cnt++;
			if (team[a].prob[b] < c) {
				team[a].sum += (c - team[a].prob[b]);
				team[a].prob[b] = c;
			}
			team[a].time = j;

		}
		sort(team, team + n + 1, [](const info& a, const info& b) {
			if (a.sum == b.sum) {
				if (a.cnt == b.cnt) {
					return a.time < b.time;
				}
				return a.cnt < b.cnt;
			}
		return a.sum > b.sum;
			});
		for (int i = 0; i <= n; i++) {
			if (team[i].num == t) {
				cout << i + 1<<endl;
			}
		}
	}
}
