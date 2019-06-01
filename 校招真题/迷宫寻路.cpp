#include<iostream>
#include<vector>
#include<queue>
#include<memory.h>

using namespace std;



int store[105][105][1030];
//比如我现在有第二把钥匙和第四把钥匙  那么我的钥匙状态就是 0101000000 也就是 320

class Solution
{
public:
	struct node
	{
		node(int x1, int y1, int k1, int step1) :x(x1), y(y1), k(k1), step(step1) {}
		int x, y, k, step;
	};

	int shortestpath(vector<vector<char> >& v)
	{
		memset(store, 0, sizeof(store));

		int row = v.size(), col = v[0].size();
		int starti = 0, startj = 0;
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				if (v[i][j] == '2')
				{
					starti = i;
					startj = j;
					break;
				}
			}
		}
		vector<pair<int, int>> nextroad = { {0,1} ,{0,-1} ,{1,0} ,{-1,0} };
		queue<node> q;
		node fnode(starti, startj, 0, 0);
		q.push(fnode);

		//store[fnode.x][fnode.y][fnode.k] = 1;
		// 这里不能加，因为取完钥匙后还要回去遍历

		while (!q.empty())
		{
			node cur = q.front(); q.pop();
			if (v[cur.x][cur.y] == '3')  return cur.step;
			for (int i = 0; i < 4; ++i)
			{
				int nx = cur.x + nextroad[i].first;
				int ny = cur.y + nextroad[i].second;
				if (nx < 0 || nx > row - 1 || ny < 0 || ny > col - 1
					|| v[nx][ny] == '0' || store[nx][ny][cur.k] == 1) continue;

				if (v[nx][ny] >= 'a' && v[nx][ny] <= 'z')
				{
					//cur.k = cur.k | (1 << (v[nx][ny] - 'a'));
					store[nx][ny][cur.k] = 1;
					q.push(node(nx, ny, cur.k | (1 << (v[nx][ny] - 'a')), cur.step + 1));
				}
				else if (v[nx][ny] >= 'A' && v[nx][ny] <= 'Z')
				{
					if (cur.k & (1 << (v[nx][ny] - 'A')))
					{
						store[nx][ny][cur.k] = 1;
						q.push(node(nx, ny, cur.k, cur.step + 1));
					}
				}
				else
				{
					store[nx][ny][cur.k] = 1;
					q.push(node(nx, ny, cur.k, cur.step + 1));
				}
			}
		}
		return 0;
	}

};

int main()
{
	int row, col;

	 cin >> row >> col;
	 vector<vector<char>> v(row, vector<char>(col, 0));
	 for (int i = 0; i < row; ++i)
	 {
	 	for (int j = 0; j < col; ++j)
	 		cin >> v[i][j];
	 }

	//row = 5, col = 5;
	//vector<vector<char> > v = {
	//	{'0','2','1','1','1'},
	//	{'0','0','a','0','1'},
	//	{'0','1','0','0','3'},
	//	{'0','1','0','0','1'},
	//	{'0','1','1','1','1'} };


	Solution n;
	cout << n.shortestpath(v) << endl;

	return 0;
}








//
//
//#include<stdio.h>
//#include<queue>
//#include<string.h>
//#include<vector>
//using namespace std;
//char G[105][105];
//int book[105][105][1200], N, M;
//int Next[4][2] = { 0,1,0,-1,1,0,-1,0 };
//int bfs(int, int);
//
//struct node {
//	int x, y, k, step;
//	node(int x, int y, int k, int step) :x(x), y(y), k(k), step(step) {}
//};
//
//int main() {
//	int i, j;
//	//freopen("input.txt","r",stdin);
//	while (scanf("%d%d", &N, &M) != EOF) {
//		for (i = 0; i < N; i++) scanf("%s", G[i]);
//		memset(book, 0, sizeof(book));
//		int flag = 0;
//		for (i = 0; i < N; i++) {
//			if (flag == 1) break;
//			for (j = 0; j < M; j++)
//				if (G[i][j] == '2') {
//					flag = 1;
//					book[i][j][0] = 1;
//					printf("%d\n", bfs(i, j));
//					break;
//				}
//		}
//	}
//}
//
//int bfs(int startX, int startY) {
//	queue<node> Q;
//	Q.push(node(startX, startY, 0, 0));
//	while (!Q.empty()) {
//		node head = Q.front(); Q.pop();
//		if (G[head.x][head.y] == '3') return head.step;
//		for (int i = 0; i < 4; i++) {
//			int nx = head.x + Next[i][0], ny = head.y + Next[i][1];
//			if (nx >= N || nx < 0 || ny >= M || ny < 0 || G[nx][ny] == '0') continue;
//			int key = head.k;
//			if ('a' <= G[nx][ny] && G[nx][ny] <= 'z') key = key | (1 << (G[nx][ny] - 'a'));
//			if ('A' <= G[nx][ny] && G[nx][ny] <= 'Z' && (key&(1 << (G[nx][ny] - 'A'))) == 0) continue;
//			if (!book[nx][ny][key]) {
//				book[nx][ny][key] = 1;
//				Q.push(node(nx, ny, key, head.step + 1));
//			}
//		}
//	}
//	return 0;
//}
//
////这题就是普通的bfs多了‘钥匙’这个状态
////所以book[x][y][key]的意义就是 横坐标为x,纵坐标为y,钥匙状态为key的点是否访问过
////钥匙的状态 就用二进制数表示 最多10 把钥匙 那就是1024
////比如我现在有第二把钥匙和第四把钥匙  那么我的钥匙状态就是 0101000000 也就是 320
//
//
//

//
//#include<cstdio>
//#include<queue>
//#include<cstring>
//using namespace std;
//
//typedef struct point
//{
//	int x, y, key, step;
//	point() {}
//	point(int _x, int _y, int _key, int _step) : x(_x), y(_y), key(_key), step(_step) { }
//} P;
//
//int n, m;
//char maze[107][107];
//bool vis[107][107][1050];
//const int dx[4] = { 0, 0, -1, 1 };
//const int dy[4] = { -1, 1, 0, 0 };
//
//int main_2()
//{
//	memset(vis, false, sizeof(vis));
//	n = 5, m = 5;
//	vector<vector<char>> maze = {
//		{ '0','2','1','1','1' },
//		{ '0','1','a','0','A' },
//		{ '0','1','0','0','3' },
//		{ '0','1','0','0','1' },
//		{ '0','1','1','1','1' } };
//	char ch;
//	int startX, startY;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			if (maze[i][j] == '2')
//			{
//				startX = i;
//				startY = j;
//				break;
//			}
//		}
//	}
//
//	queue<P> que;
//	que.push(P(startX, startY, 0, 0));
//	int curX, curY;
//	P p;
//
//	while (!que.empty())
//	{
//		p = que.front();
//		que.pop();
//		if (maze[p.x][p.y] == '3')
//		{
//			printf("%d\n", p.step);
//			break;
//		}
//
//		for (int i = 0; i < 4; i++)
//		{
//			curX = p.x + dx[i];
//			curY = p.y + dy[i];
//			if (curX < 0 || curX >= n || curY < 0 || curY >= m || maze[curX][curY] == '0'
//				|| vis[curX][curY][p.key])
//				continue;
//			ch = maze[curX][curY];
//			if (ch >= 'A' && ch <= 'Z')
//			{
//				if (p.key & (1 << (ch - 'A')))
//				{
//					que.push(P(curX, curY, p.key, p.step + 1));
//					vis[curX][curY][p.key] = true;
//				}
//			}
//			else if (ch >= 'a' && ch <= 'z')
//			{
//				que.push(P(curX, curY, p.key | (1 << (ch - 'a')), p.step + 1));
//				vis[curX][curY][p.key] = true;
//			}
//			else
//			{
//				que.push(P(curX, curY, p.key, p.step + 1));
//				vis[curX][curY][p.key] = true;
//			}
//		}
//
//	}
//	return 0;
//}
