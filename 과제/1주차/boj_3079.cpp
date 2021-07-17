#include <bits/stdc++.h>

using namespace std;

void solution(){
	long long n, m;
	cin >> n >> m;
	
	vector<int> v(n);
	for(auto& i : v)
		cin >> i;
		
	sort(v.begin(), v.end());
	long long low = 0, high = m*v.back();
	long long ans = m * v.back();
	
	while(low <= high){
		long long mid = (low+high)/2;
		long long sum = 0;
		
		for(int i: v)
			sum += mid / i;
		
		if(sum >= m){
			ans = min(ans, mid);
			high = mid-1;
		}
		else
			low = mid+1;
	}
	
	cout << ans << '\n';
}

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solution();
	
	return 0;
}
