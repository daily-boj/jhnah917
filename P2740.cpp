#include <bits/stdc++.h>
using namespace std;

int a[111][111];
int b[111][111];
int c[111][111];

int n, m, k;

int main(){
	cin >> n >> m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++) cin >> a[i][j];
	}
	cin >> m >> k;
	for(int i=0; i<m; i++){
		for(int j=0; j<k; j++) cin >> b[i][j];
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<k; j++){
			for(int s=0; s<m; s++){
				c[i][j] += a[i][s] * b[s][j];
			}
		}
	}
	
	for(int i=0; i<n; i++){
		for(int j=0; j<k; j++){
			cout << c[i][j] << " ";
		}
		cout << "\n";
	}
}