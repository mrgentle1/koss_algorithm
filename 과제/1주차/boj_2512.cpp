#include <bits/stdc++.h>

#define INF 987654321

using namespace std;

void solution(){
	int n;
	cin >> n;
	
	vector<int> v(n);
	int maxVal = 0;
	for(auto& i:v){
		cin >> i;
		maxVal = max(maxVal, i);
	}
	
	int m;
	cin >> m;
	
	int low = 0, high = maxVal;
	int result;
	while(low <= high){
		int mid = (low+high) / 2;
		long long sum = 0;
		for(int i : v)
			sum += min(i, mid);
		if(sum <= m){
			result = mid;
			low = mid + 1;
		}
		else{
			high = mid - 1;
		}
	}
	cout << result << '\n';
	return;
}

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solution();
	
	return 0;
}
