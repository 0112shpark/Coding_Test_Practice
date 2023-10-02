#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int credit;
int n;
int ans = 0;
vector<pair<int, pair<int, int>>> arr;

//[요일][시간]
int tim[6][11];

int cal_credit(int a, int b) {
	return b - a + 1;
}

void dfs(int idx, int crd) {
	
	if (crd >= credit) {
		if (crd == credit) {
			ans++;
		}
		return;
	}
	if (idx == arr.size()) {
		//cout << credit;
		return;
	}
	for (int k = idx; k < arr.size(); k++) {
		int flag = 0;
		
			for (int i = arr[k].second.first; i <= arr[k].second.second; i++) {
				if (tim[arr[k].first][i] == 1) {
					flag = 1;
					break;
				}
			}

			if (flag==0) {
			
				for (int i = arr[k].second.first; i <= arr[k].second.second; i++) {

					tim[arr[k].first][i] = 1;

				}
				cout << arr[k].second.first << arr[k].second.second << endl;

				dfs(k+ 1, crd + cal_credit(arr[k].second.first, arr[k].second.second));

				for (int i = arr[k].second.first; i <= arr[k].second.second; i++) {
					tim[arr[k].first][i] = 0;
				}
			
			}
		
	}
	

}

int main() {


	cin >> n >> credit;

	for (int i = 0; i < n; i++) {
		int day;
		int start;
		int end;
		cin >> day >> start >> end;
		if (day != 5) {
			
			arr.push_back({ day,{start,end} });
		}
	}
	
		dfs(0, 0);
	
	
	cout << ans;
}