#include<iostream>
#include<vector>

using namespace std;



const int MAXN = 3000001;
int prime[MAXN];//保存素数 
bool vis[MAXN];//初始化 

int Prime(int n)
{
	int cnt = 0;
	memset(vis, 0, sizeof(vis));
	for (int i = 2; i < n; i++)
	{
		if (!vis[i])
			prime[cnt++] = i;
		for (int j = 0; j < cnt && i*prime[j] < n; j++)
		{
			vis[i*prime[j]] = 1;
			if (i%prime[j] == 0)//关键 
				break;
		}
	}
	return cnt;//返回小于n的素数的个数 
}

int main_prime()
{
	cout << Prime(100) << endl;
	for (auto i : prime)
	{
		if (i != 0)
			cout << i << " ";
	}
	cout << endl;
	return 0;
}


//////////////////////////////////////////////////////////////////////////////


//埃氏筛法
//https://skywt.cn/posts/aishi-eular-shai/



int visi[1000];

void my_prime_ai(int n, vector<int>& v)
{
	for (int i = 2; i < n; ++i)
	{
		if (visi[i] == 0)
		{
			v.push_back(i);
			visi[i] = 1;
			for (int j = i; j < 1000; j += i)  //筛出 素数i 的所有倍数
			{
				visi[j] = 1;
			}
		}
	}
}

// 埃拉托斯特尼筛法 会重复筛选  比如 30 = 5×6 = 2×15

// 欧拉筛法的核心思想和埃氏筛法差不多，不过它的复杂度是真正的线性！
// 因为它的优化使得每个合数都保证只会被一个质数筛去。

int visi2[1000];
int my_prime_OU(int n, vector<int>& prime)
{
	int res = 0;
	for (int i = 2; i < n; ++i)
	{
		if (visi2[i] == 0)
		{
			prime.push_back(i);
			visi2[i] = 1;
			++res;
		}

		for (int j = 0; j < res; ++j)
		{
			if (i*prime[j] > 100) break;
			visi2[i*prime[j]] = 1;


			if (i%prime[j] == 0)  break;
			// 这里是关键,如果i是一个合数(这当然是允许的)而且i mod prime[j] = 0 ,那么跳出
			// 因为i*prime[ (- over -)j ]一定已经被筛去了,被一个素因子比i小的数
				
		}
	}

	return res;
}



int main_OUAI()
{
	vector<int> v;
	my_prime_ai(100, v);

	for (auto i : v)
		cout << i << " ";
	cout << endl;


	vector<int> v2;
	cout << my_prime_OU(100, v2) << endl;

	for (auto i : v2)
		cout << i << " ";
	cout << endl;

	return 0;
}


