#include<vector>
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

//¡°student.a am I¡± -> ¡°I am a student.¡±

class Solution {
public:
	string ReverseSentence(string str) {
		if (str.empty()) return str;
		vector<string> v;
		int pos = 0;
		while (pos < str.size())
		{
			string cur;
			while ((str[pos] >= 'a' && str[pos] <= 'z') ||
				(str[pos] >= 'A' && str[pos] <= 'Z')) {
				cur += str[pos]; ++pos;
			}
			if (pos < str.size()) {
				if (str[pos] == ' ') ++pos;
				else { cur += str[pos]; pos += 2; }
			}
			v.push_back(cur);
		}
		reverse(v.begin(), v.end());
		string res;
		for (auto i : v)
		{
			res += i;
			//if (i.back() < 'a' || i.back() > 'z') continue;
			//else res += ' ';
			res += ' ';
		}
		res.erase(res.end() - 1);
		return res;
	}
};


//int main()
//{
//	Solution n;
//	cout << n.ReverseSentence("student. a am I") << endl;
//	cout << "I am a student." << endl;
//	return 0;
//}