#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
#include<unordered_map>
#include<map>

using namespace std;



class Solution {
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
		unordered_map<int, int> m;
		for (auto i : data)  ++m[i];
		bool flag = false;

		for (auto i = m.begin(); i != m.end(); ++i)
		{
			if (i->second == 1)
			{
				if (!flag)
				{
					*num1 = i->first;
					flag = true;
				}
				else
				{
					*num2 = i->first;
					break;
				}
			}
		}
	}
};











//���ǻ��Ǵ�ͷ��β������������е�ÿһ�����֣�
//��ô���յõ��Ľ����������ֻ����һ�ε����ֵ��������
//��Ϊ�������ֶ����������Σ��������ȫ���������ˡ�
//�������������ֿ϶���һ������ô���������϶���Ϊ0 ��
//Ҳ����˵�����������ֵĶ����Ʊ�ʾ�����پ���һλΪ1 ��
//�����ڽ���������ҵ���һ��Ϊ1 ��λ��λ�ã���Ϊ��N λ��
//���������Ե�N λ�ǲ���1 Ϊ��׼��ԭ�����е����ֳַ����������飬
//��һ����������ÿ�����ֵĵ�N λ��Ϊ1 �����ڶ����������ÿ�����ֵĵ�N λ��Ϊ0 ��
//
//���������Ѿ���ԭ����ֳ������������飬
//ÿ�������鶼����һ��ֻ����һ�ε����֣�
//���������ֶ����������Ρ���˵���Ϊֹ�����е��������Ƕ��Ѿ������

