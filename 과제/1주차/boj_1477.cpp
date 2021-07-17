#include <bits/stdc++.h>

using namespace std;

void solution(){
	int n, m, l;
	int ans;
	cin >> n >> m >> l;
	
	vector<int> v(n);
	for(auto& i : v)
		cin >> i;
	
	v.push_back(0);
	v.push_back(l);
	sort(v.begin(), v.end());
	
	int low = 0;
	int high = l;
	
	while (low <= high){
		int cnt = 0;
		int mid = (low+high)/2;
		for(int i = 1; i < v.size(); i++){
			int interval = v[i] - v[i-1];
			if(interval > mid)
				cnt += (interval-1) / mid;
		}
		if(cnt <= m){
			ans = mid;
			high = mid-1;
		}
		else{
			low = mid+1;
		}
	}
	cout << ans << '\n';
}

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	solution();
	
	return 0;
}
