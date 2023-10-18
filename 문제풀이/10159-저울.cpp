#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
//from->to
vector<vector<int>> map(110);
vector<vector<int>> rev_map(110);
int visited[110];
int ans = 0;

void dfs(int a) {
	visited[a] = 1;
	ans++;
	for (int i = 0; i < map[a].size(); i++) {
		if (visited[map[a][i]] == 0) {
			//cout << a;
			dfs(map[a][i]);
			
		}
	}
}
void rev_dfs(int a) {
	
	visited[a] = 1;
	ans++;
	for (int i = 0; i < rev_map[a].size(); i++) {
		if (visited[rev_map[a][i]] == 0) {
		
			rev_dfs(rev_map[a][i]);

		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		
		int from, to;
		cin >> from >> to;
		map[from].push_back(to);
		rev_map[to].push_back(from);

	}

	vector<int> answer;
	
		for (int i = 1; i <= n; i++) {
			ans = 0;
			for (int j = 0; j <= n; j++) {
				visited[j] = 0;
			}
			dfs(i);
			ans--;
			rev_dfs(i);
			ans--;
			ans = n - ans - 1;
			answer.push_back(ans);
		}
		for(int i = 0; i<answer.size();i++){
			cout << answer[i] << endl;
		}
		
	

}