#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//end,start
vector<pair<int, int>> arr;
vector<int> ans;

int main() {

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		pair<int, int> temp;
		cin >> temp.second >> temp.first;
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end());
	int end_time = 0;
	int start_time = 0;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i].second >= end_time) {
			end_time = arr[i].first;
			ans.push_back(i);
		}
	}
	cout << ans.size();
}