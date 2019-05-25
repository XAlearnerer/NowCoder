//
// Created by zhao on 19-5-25.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> odd,even;
        for(int i=0;i<array.size();++i)
        {
            if(array[i]%2!=0) odd.push_back(array[i]);
            else even.push_back(array[i]);
        }
        array.clear();
        array.insert(array.end(),odd.begin(),odd.end());
        array.insert(array.end(),even.begin(),even.end());
    }
};

class Solution2 {
public:
    void reOrderArray(vector<int> &array) {
        for(int i = 0;i < array.size();i++){
            for(int j = array.size()-1; j>i;j--){
                if(array[j]%2==1 && array[j-1]%2==0)
                    swap(array[j],array[j-1]);
            }
        }
    }
};


//int main()
//{
//    Solution2 n;
//
//    vector<int> a={1,2,10,12,3,4,5,6,7,8,9};
//    n.reOrderArray(a);
//    for(auto i:a)
//        cout<<i<<" ";
//
//    return 0;
//}