#include <stdio.h>
#include <stdlib.h>

int main() {

	int n, score, p;

	scanf("%d %d %d", &n, &score, &p);
	int rank = 1;
	int ans = 0;

	if (n > 0) {
		int* arr = (int*)malloc(sizeof(int) * n);

		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}
		
		
		
			for (int i = 0; i < n; i++) {

				if (score < arr[i]) {
					rank++;
				}
				else if (score >= arr[i]) {
					ans = rank;
					if (score == arr[i] && i + 1 == p) {
						ans = -1;
					}
					break;
				}
				
			}
		
		free(arr);
		
	}
	else {
		ans = 1;
	}
	printf("%d", ans);
}