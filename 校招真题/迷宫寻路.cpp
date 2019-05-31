#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
	int shortestpath(vector<vector<int>> v)
	{
		int row = v.size(), col = v[0].size();
		vector<vector<int>> dp(row, vector<int>(col, -1));




	}

};



int main()
{
	int row, col;
	vector<vector<int>> v(row, vector<int>(col, 0));
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
			cin >> v[i][j];
	}
	
	Solution n;
	cout << n.shortestpath(v) << endl;

	return 0;
}












#include<stdio.h>
#include<queue>
#include<string.h>
#include<vector>
using namespace std;
char G[105][105];
int book[105][105][1200], N, M;
int Next[4][2] = { 0,1,0,-1,1,0,-1,0 };
int bfs(int, int);
struct node {
	int x, y, k, step;
	node(int x, int y, int k, int step) :x(x), y(y), k(k), step(step) {}
};
int main() {
	int i, j;
	//freopen("input.txt","r",stdin);
	while (scanf("%d%d", &N, &M) != EOF) {
		for (i = 0; i<N; i++) scanf("%s", G[i]);
		memset(book, 0, sizeof(book));
		int flag = 0;
		for (i = 0; i<N; i++) {
			if (flag == 1) break;
			for (j = 0; j<M; j++)
				if (G[i][j] == '2') {
					flag = 1;
					book[i][j][0] = 1;
					printf("%d\n", bfs(i, j));
					break;
				}
		}
	}
}
int bfs(int startX, int startY) {
	queue<node> Q;
	Q.push(node(startX, startY, 0, 0));
	while (!Q.empty()) {
		node head = Q.front(); Q.pop();
		if (G[head.x][head.y] == '3') return head.step;
		for (int i = 0; i<4; i++) {
			int nx = head.x + Next[i][0], ny = head.y + Next[i][1];
			if (nx >= N || nx<0 || ny >= M || ny<0 || G[nx][ny] == '0') continue;
			int key = head.k;
			if ('a' <= G[nx][ny] && G[nx][ny] <= 'z') key = key | (1 << (G[nx][ny] - 'a'));
			if ('A' <= G[nx][ny] && G[nx][ny] <= 'Z' && (key&(1 << (G[nx][ny] - 'A'))) == 0) continue;
			if (!book[nx][ny][key]) {
				book[nx][ny][key] = 1;
				Q.push(node(nx, ny, key, head.step + 1));
			}
		}
	}
	return 0;
}//这题就是普通的bfs多了‘钥匙’这个状态
 //所以book[x][y][key]的意义就是 横坐标为x,纵坐标为y,钥匙状态为key的点是否访问过
 //钥匙的状态 就用二进制数表示 最多10 把钥匙 那就是1024
 //比如我现在有第二把钥匙和第四把钥匙  那么我的钥匙状态就是 0101000000 也就是 320