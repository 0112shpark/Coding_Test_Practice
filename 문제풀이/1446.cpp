#include <stdio.h>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

struct load {
	int from;
	int to;
	int weight;
};

int main() {

	ios_base::sync_with_stdio(false);

	cin.tie(NULL);
	cout.tie(NULL);

	vector<load> way;
	int dist[10001];
	int n, d;
	cin >> n >> d;

	for (int i = 0; i < n; i++) {
		load temp;
		
		cin >> temp.from >> temp.to >> temp.weight;
		if (temp.weight > temp.to - temp.from) {
			continue;
		}
		else {
			way.push_back(temp);
		}
		
	}
	for (int i = 0; i < 10001; i++) {
		dist[i] = i;
	}

	for (int i = 1; i <= d; i++) {

		for (int j = 0; j < way.size(); j++) {
			if (dist[way[j].from] + way[j].weight < dist[way[j].to]) {
				dist[way[j].to] = dist[way[j].from] + way[j].weight;
			}
		}
		dist[i] = min(dist[i], dist[i - 1] + 1);
	}
	
	cout << dist[d];
	
	
}