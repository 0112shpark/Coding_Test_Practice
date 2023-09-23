#include <stdio.h>
#include <vector>
#include<stdlib.h>
#include <iostream>
#include <queue>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);

	cin.tie(NULL);

	cout.tie(NULL);

	priority_queue<int, vector<int>,greater<int>> pq;

	int N;
	int val;
	cin >> N;
	
		for (int j = 0; j < N*N; j++) {
			
			cin >> val;
			pq.push(val);
			if (pq.size() > N) {
				pq.pop();
			}
		}
	
	cout << pq.top();
}
