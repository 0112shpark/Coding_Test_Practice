#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int u, v;
int n, e;
//to, cost
vector<pair<int, int>> map[810];
int cost_arr[810];
//cost, to
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void dij(int start) {
	for (int i = 0; i < 810; i++) {
		cost_arr[i] = 999999999;
	}

	cost_arr[start] = 0;
	pq.push({ 0,start });
	while (!pq.empty()) {
		int node = pq.top().second;
		int cost = pq.top().first;
		pq.pop();

		for (int i = 0; i < map[node].size(); i++) {
			int node_to = map[node][i].first;
			int cost_to = map[node][i].second;
			if (cost_to + cost < cost_arr[node_to]) {
				cost_arr[node_to] = cost_to + cost;
				pq.push({ cost_arr[node_to],node_to });
			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> e;

	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		map[a].push_back({ b,c });
		map[b].push_back({ a,c });
	}
	cin >> u >> v;

	// dij(u) 하면 u부터 1, n, v까지의 최단 경로가 나옴
	// dij(v) 하면 v부터 1,n,u까지의 최단 경로가 나옴
	// 1->u->v->n 혹은 1->v->u->n중 최소값이 ans.
	dij(u);
	long long  one_to_u = cost_arr[1];
	long long  u_to_v = cost_arr[v];
	long long u_to_n = cost_arr[n];
	dij(v);
	long long one_to_v = cost_arr[1];
	long long v_to_n = cost_arr[n];
	//1->u->v->n
	long long first_way = one_to_u + u_to_v + v_to_n;
	//1->v->u->n
	long long second_way = one_to_v + u_to_v + u_to_n;

	long long ans = min(second_way, first_way);

	if (ans >= 999999999) {
		cout << -1;
	}
	else { cout << ans; }
}