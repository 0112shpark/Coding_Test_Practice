#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;
int n, k;
int visited[100010];
int visited_before[100010];
queue<int> q;
stack<int> st;

void bfs(int a) {
	visited[a] = 1;
	visited_before[a] = a;
	q.push(a);
	while (!q.empty()) {
		int x = q.front();
		
		if (x == k) {
			break;
		}
		q.pop();

		int mov_x = x - 1;
		if (x - 1 >= 0 && visited[x - 1] == 0) {
			q.push(x - 1);
			visited[x - 1] = visited[x] + 1;
			visited_before[x - 1] = x;
		}
		
		mov_x = x + 1;
		if (x + 1 <= 100000 && visited[x + 1] == 0) {
			q.push(x + 1);
			visited[x + 1] = visited[x] + 1;
			visited_before[x + 1] = x;
		}
		mov_x = x * 2;
		if (x * 2 <=100000 && visited[x*2] == 0) {
			q.push(x*2);
			visited[x*2] = visited[x] + 1;
			visited_before[x*2] = x;
		}
	}
}


int main() {
	
	cin >> n >> k;

	bfs(n);
	cout << visited[k] - 1 << endl;
	int i = k;
	st.push(k);
	while (i!=n) {
		st.push(visited_before[i]);
		i = visited_before[i];
	}
	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}
	
}