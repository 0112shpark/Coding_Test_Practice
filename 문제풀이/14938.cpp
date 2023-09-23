#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, r;
int item[110];
int cost[110];
int ans = 0;
vector<pair<int,int>> node[110]; // cost, to
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

int dij(int start) {

	int cnt = 0;
	for (int i = 1; i <=n; i++) {
		cost[i] = 50;
	}

	cost[start] = 0;
	q.push({0,start});

	while (!q.empty()) {
		int val = q.top().first;
		int to = q.top().second;
		q.pop();
		for (int i = 0; i < node[to].size(); i++) {
			int value = node[to][i].first;
			int to1 = node[to][i].second;

			if (cost[to] + value < cost[to1]) {
				cost[to1] = cost[to] + value;
				q.push({ cost[to1],to1 });
			}
			
		}

	}
	for (int i = 1; i <=n; i++) {
		if (cost[i] <= m) {
			cnt += item[i];
		}
		
	}
	return cnt;
}

int main() {

	ios_base::sync_with_stdio(false);

	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> r;

	for (int i = 1; i <= n; i++) {
		cin >> item[i];
	}
	for (int i = 0; i < r; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		node[a].push_back({ l,b });
		node[b].push_back({ l,a });
	
		
	}
	
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dij(i));
	}

	cout << ans;
}