#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int arr[10];
priority_queue<vector<int>, vector<vector<int>>>pq;
vector<vector<int>> ans;

void dfs(int idx,int cnt, vector<int> temp) {

	
	if (cnt == m) {
		sort(temp.begin(), temp.end());
		ans.push_back(temp);
		return;
	}
	if (idx == n) {
		return;
	}
	for (int i = idx; i < n; i++) {
		temp.push_back(arr[i]);
		dfs(i , cnt+1,temp);
		temp.pop_back();

	}
}

int main() {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<int> temp;
	dfs(0,0, temp);
	ans.erase(unique(ans.begin(),ans.end()), ans.end());
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}

}