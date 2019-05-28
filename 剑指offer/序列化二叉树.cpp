#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<sstream>

using namespace std;


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
	char* Serialize(TreeNode *root) {

		if (!root) return "#";
		string cur = to_string(root->val);
		cur += " ";
		char* le = Serialize(root->left);
		char* ri = Serialize(root->right);
		char* res = new char[cur.size() + strlen(le) + strlen(ri)];

		strcpy(res, cur.c_str());
		strcat(res, le);
		strcat(res, ri);
		return res;
	}

	TreeNode* Deserialize(char *str) {
		return decode(str);
	}

	TreeNode* decode(char *&str) {
		if (*str == '#') {
			str++;
			return NULL;
		}
		int num = 0;
		while (*str != ' ')
			num = num * 10 + (*(str++) - '0');
		str++;
		TreeNode *root = new TreeNode(num);
		root->left = decode(str);
		root->right = decode(str);
		return root;
	}

};




class Codec3 {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		ostringstream os;
		serialize(root, os);
		return os.str();
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		istringstream is(data);
		return deserialize(is);
	}

	void serialize(TreeNode* root, ostringstream& os) {
		if (!root) os << "# ";
		else {
			os << root->val << " ";
			serialize(root->left, os);
			serialize(root->right, os);
		}
	}

	TreeNode* deserialize(istringstream& is) {
		string val = "";
		is >> val;
		if (val == "#") return NULL;
		TreeNode* node = new TreeNode(stoi(val));
		node->left = deserialize(is);
		node->right = deserialize(is);
		return node;
	}
};







class Solution2 {
public:
	char* Serialize(TreeNode *root) {
		if (root == NULL)
			return NULL;
		string str;
		Serialize(root, str);
		char *ret = new char[str.length() + 1];
		int i;
		for (i = 0; i < str.length(); i++) {
			ret[i] = str[i];
		}
		ret[i] = '\0';
		return ret;
	}
	void Serialize(TreeNode *root, string& str) {
		if (root == NULL) {
			str += '#';
			return;
		}
		string r = to_string(root->val);
		str += r;
		str += ',';
		Serialize(root->left, str);
		Serialize(root->right, str);
	}

	TreeNode* Deserialize(char *str) {
		if (str == NULL)
			return NULL;
		TreeNode *ret = Deserialize(&str);

		return ret;
	}
	TreeNode* Deserialize(char **str) {//由于递归时，会不断的向后读取字符串
		if (**str == '#') {  //所以一定要用**str,
			++(*str);         //以保证得到递归后指针str指向未被读取的字符
			return NULL;
		}
		int num = 0;
		while (**str != '\0' && **str != ',') {
			num = num * 10 + ((**str) - '0');
			++(*str);
		}
		TreeNode *root = new TreeNode(num);
		if (**str == '\0')
			return root;
		else
			(*str)++;
		root->left = Deserialize(str);
		root->right = Deserialize(str);
		return root;
	}
};


class Solution3 {
public:

private:
	TreeNode* decode(char *&str) {
		if (*str == '#') {
			str++;
			return NULL;
		}
		int num = 0;
		while (*str != ',')
			num = num * 10 + (*(str++) - '0');
		str++;
		TreeNode *root = new TreeNode(num);
		root->left = decode(str);
		root->right = decode(str);
		return root;
	}
public:
	char* Serialize(TreeNode *root) {
		if (!root) return "#";
		string r = to_string(root->val);
		r.push_back(',');
		char *left = Serialize(root->left);
		char *right = Serialize(root->right);
		char *ret = new char[strlen(left) + strlen(right) + r.size()];
		strcpy(ret, r.c_str());
		strcat(ret, left);
		strcat(ret, right);
		return ret;
	}
	TreeNode* Deserialize(char *str) {
		return decode(str);
	}
};