#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;
int n, m;
int dest[1010];
int visited[1010] = { 0 };
vector<vector<int>> map;
queue<int> q;

void bfs(int start) {

	while (!q.empty()) {
		int coord = q.front();
		q.pop();
		for (int i = 0; i < n; i++) {
			if (map[coord][i] == 1) {
				if (visited[i] == 0) {
					visited[i] = 1;
					q.push(i);
				}
			}
		}

	}

}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	

	cin >> n;
	cin >> m;
	for (int i = 0; i < n; i++) {
		vector<int> temp;
		for (int j = 0; j < n; j++) {
			
			int val;
			cin >> val;
			temp.push_back(val);
		}
		map.push_back(temp);
	}
	for (int i = 0; i < m; i++) {
		int des;
		cin >> des;
		dest[i] = des - 1;
	}
	visited[dest[0]] = 1;
	q.push(dest[0]);
	bfs(dest[0]);

	for (int i = 0; i < m; i++) {
		if (visited[dest[i]] == 0) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	
}