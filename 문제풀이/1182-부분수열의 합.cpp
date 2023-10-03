#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[25];
int ans = 0;
vector<int> aa;
int n;
int s;

void dfs(int idx,int sum) {

	if (sum == s&& idx>0) {
		
		ans++;
		
	}

	if (idx == n) {
		return;
	}

	
	for (int i = idx; i < n; i++) {
		
		dfs(i+1, sum + arr[i]);
		
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	dfs(0,0);
	cout << ans;
}