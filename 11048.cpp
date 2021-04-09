#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int N, M;
int candymap[1001][10001];
int dp[1001][1001];

void inputs() {//기본셋팅
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> candymap[i][j];
			dp[i][j] = -1; //dp테이블은 -1로 초기화
		}
	}
	dp[1][1] = candymap[1][1];
	for (int i = 2; i <= N; i++) { //한방향뿐
		dp[i][1] = dp[i - 1][1] + candymap[i][1];
	}
	for (int j = 2; j <= N; j++) {
		dp[1][j] = dp[1][j - 1] + candymap[1][j];
	}
}
int maxthree(int num1, int num2, int num3) {
	return max(max(num1, num2), num3);
}
int getdp(int x, int y) {
	if (dp[x][y] != -1) return dp[x][y];
	else {
		dp[x][y] = maxthree(getdp(x - 1, y), getdp(x, y - 1), getdp(x - 1, y - 1)) + candymap[x][y]; //x-1,y-1 쪽만 봐도 됨
		return dp[x][y];
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	inputs();
	cout << getdp(N, M) << "\n";

	return 0;
}