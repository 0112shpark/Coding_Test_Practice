#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
int arr[110];
int selected[110];
int init_val = 0;
vector<int> ans;
int cnt = 0;
vector<int> same;

void dfs(int a, vector<int> &b) {
	//cout << a << endl;
	if (selected[a]) {
		init_val = a;
		return;
	}
	b.push_back(a);
	selected[a] = 1;
	dfs(arr[a], b);
	
}

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		
		cin >> arr[i];
		
		
	}
	for (int i = 1; i <=n; i++) {
		vector<int> temp;
		init_val = -1;
		for (int i = 0; i < 110; i++) {
			selected[i] = 0;
		}
		dfs(i, temp);
		if (init_val == i) {

			for (int j = 0; j < temp.size(); j++) {
				ans.push_back(temp[j]);
			}
			
		}
	}
	
	
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(),ans.end()), ans.end());
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
	
}