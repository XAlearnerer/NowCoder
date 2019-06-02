#include<iostream>
#include<vector>
#include<string>

using namespace std;

// 72106547548473106236 * 982161082972751393
// = 70820244829634538040848656466105986748
int main()
{
	string s1, s2;
	//cin >> s1 >> s2;
	s1 = "72106547548473106236";
	s2 = "982161082972751393";

	//s1 = "19";
	//s2 = "99";

	int carry = 0, res = 0;
	string fin;
	for (int i = s1.size() - 1; i >= 0; --i)
	{
		string cur; carry = 0, res = 0;
		for (int j = s2.size() - 1; j >= 0; --j)
		{
			res = carry + (s1[i] - '0')*(s2[j] - '0');
			carry = res / 10;
			res = res % 10;
			cur += (res + '0');
		}
		if (carry != 0)
			cur += (carry + '0');
		reverse(cur.begin(), cur.end());
		if (!fin.empty()) cur += '0';

		carry = 0, res = 0;
		int add_i = cur.size() - 1, add_j = fin.size() - 1;
		string t;
		while (add_i >= 0 && add_j >= 0)
		{
			res = carry + (cur[add_i] - '0') + (fin[add_j] - '0');
			carry = res / 10;
			res = res % 10;
			t += (res + '0');
			--add_i; --add_j;
		}
		while (add_i >= 0)
		{
			res = carry + (cur[add_i] - '0');
			carry = res / 10;
			res = res % 10;
			t += (res + '0');
			--add_i;
		}
		while (add_j >= 0)
		{
			res = carry + (fin[add_j] - '0');
			carry = res / 10;
			res = res % 10;
			t += (res + '0');
			--add_j;
		}
		if (carry != 0)
			t += (carry + '0');
		reverse(t.begin(), t.end());
		fin = t;
	}

	cout << fin << endl;
	return 0;
}








string Mul(string left, string right)
{

	size_t Lsize = left.size();
	size_t Rsize = right.size();
	size_t Size = Lsize + Rsize;
	string res(Size, '0');

	int takevoer = 0;//进位
	int offset = 0;//移位

	size_t idx = 1, j = 1;
	for (idx = 1; idx <= Rsize; ++idx)
	{
		takevoer = 0;
		int rightnum = right[Rsize - idx] - '0';
		//计算每一位与left相乘
		for (j = 1; j <= Lsize; ++j)
		{
			char resBit = res[Size - j - offset] - '0';
			int num = rightnum * (left[Lsize - j] - '0') + takevoer + resBit;
			takevoer = num / 10;
			res[Size - j - offset] = num % 10 + '0';
		}
		if (takevoer != 0)
			res[Size - j - offset] = takevoer + '0';
		offset++;
	}

	//如果没有进位的话，res最高位没有数字
	if (res[0] == '0')
		res.erase(0, 1);
	return res;
}

int main1()
{
	string s1, s2;
	s1 = "72106547548473106236";
	s2 = "982161082972751393";
	string str = Mul(s1, s2);
	cout << str << endl;
	return 0;
}
