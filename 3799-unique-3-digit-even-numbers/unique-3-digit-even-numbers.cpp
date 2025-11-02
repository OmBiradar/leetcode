#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int totalNumbers(vector<int>& digits) {
		vector<int> cnt(10, 0);
		for (int d : digits) cnt[d]++;
		int ans = 0;
		for (int c = 0; c <= 9; c++) {
			if (c % 2 == 1 || cnt[c] == 0) continue;
			cnt[c]--;
			for (int h = 1; h <= 9; h++) {
				if (cnt[h] == 0) continue;
				cnt[h]--;
				for (int t = 0; t <= 9; t++) {
					if (cnt[t] > 0) ans++;
				}
				cnt[h]++;
			}
			cnt[c]++;
		}
		return ans;
	}
};