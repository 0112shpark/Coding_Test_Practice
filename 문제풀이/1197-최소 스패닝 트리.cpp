#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int v, e;
int ans = 0;
//to, cost;
vector < pair<int, int>> node[10010];
priority_queue < pair<int, int>, vector<pair<int, int>>, greater<>> pq;
int visited[10010];
void prim(int a) {

	visited[a] = 1;
	for (int i = 0; i < node[a].size(); i++) {
		pq.push({ node[a][i].second,node[a][i].first });
	}
	while (!pq.empty()) {
		
		int cost = pq.top().first;
		int to = pq.top().second;
		pq.pop();
		if (visited[to]) {
			continue;
		}

		visited[to] = 1;
		
		ans += cost;
		for (int i = 0; i < node[to].size(); i++) {
			pq.push({ node[to][i].second,node[to][i].first });
		}
	}
}

int main() {

	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		node[from].push_back({ to,cost });
		node[to].push_back({ from,cost });
	}

	prim(1);
	cout << ans;
}