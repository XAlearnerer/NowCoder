#include<iostream>
#include<vector>
#include<string>

using namespace std;

// 72106547548473106236 * 982161082972751393
// = 70820244829634538040848656466105986748
int main_WORNG() 
{
	string s1, s2;
	//cin >> s1 >> s2;
	//s1 = "72106547548473106236";
	//s2 = "982161082972751393";

	s1 = "19";
	s2 = "90";

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



int main_dazhengshu()
{
	string s1, s2;
	cin >> s1 >> s2;
	//s1 = "72106547548473106236";
	//s2 = "982161082972751393";

	int len1 = s1.size(), len2 = s2.size();
	int takeover = 0, offset = 0;
	int len = len1 + len2;
	string res(len, '0');

	for (int i = 1; i <= len1; ++i)
	{
		int right = s1[len1 - i] - '0';
		int j;
		takeover = 0;
		for (j = 1; j <= len2; ++j)
		{
			int post = res[len - j - offset] - '0';
			int num = post + takeover + right*(s2[len2 - j] - '0');
			takeover = num / 10;
			res[len - j - offset] = num % 10 + '0';
		}
		if (takeover != 0)
			res[len - j - offset] = takeover + '0';
		++offset;
	}

	if (res[0] == '0') res.erase(res.begin());
	cout << res << endl;
	return 0;
}








