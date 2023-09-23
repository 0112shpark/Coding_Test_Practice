#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>
#include <queue>


using namespace std;

int main() {
	priority_queue<int, vector<int>, greater<int>> pq;
	int N;
	vector<int> ans;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int val;
		cin >> val;
		if (val == 0 ) {
			if(pq.empty()){
				ans.push_back(0);
			}
			else {
				ans.push_back(pq.top());
				pq.pop();
			}
		}
		else {
			pq.push(val);
		}
		
	}
	for (int i = 0; i<ans.size(); i++) {
		cout << ans[i] << '\n';
	}
}