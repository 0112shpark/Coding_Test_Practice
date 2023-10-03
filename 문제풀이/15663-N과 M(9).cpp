#include<iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[10];
int select1[10];
int n, m;
vector<vector<int>> ans;

void dfs(int cnt, vector<int> temp) {
	if (cnt == m) {
		ans.push_back(temp);
		return;
	}
	

	for (int i = 0; i < n; i++) {
		if (select1[i] == 1) {
			continue;
		}
		temp.push_back(arr[i]);
		select1[i] = 1;
		dfs(cnt + 1, temp);
		select1[i] = 0;
		temp.pop_back();
	}
}


int main() {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		
	}

	vector<int>temp;
	dfs( 0, temp);

	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	
	for (int i = 0; i < ans.size(); i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}

