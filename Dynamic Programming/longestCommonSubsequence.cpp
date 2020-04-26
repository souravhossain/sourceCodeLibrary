/**
 *  Name: Longest Common Subsequence
 *  Author Name: Sourab Hossain
 */

#include "bits/stdc++.h"

using namespace std;

int lcm(string str1, string str2) {
    int m = str1.size(), n = str2.size();
	int dp[m + 1][n + 1];

	for(int i = 0; i <= m; i++) {
		dp[i][0] = 0;
	}

	for(int i = 0; i <= n; i++) {
		dp[0][i] = 0;
	}

	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			if(str1[i - 1] == str2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			} else {
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}

	return dp[m][n];
}

int main(int argc, char const *argv[])
{
	string text1 = "abcde", text2 = "ace";
	
	cout << lcm(text1, text2) << endl;

	return 0;
}