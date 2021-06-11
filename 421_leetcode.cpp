#include <iostream>
#include <unordered_set>
#include<algorithm>
#include <cstring>
#include <vector>
#include <memory>
#include <mutex>
#include <string>
#include <sstream>
#include <unordered_map>
#include <limits.h>

using namespace std;


class Solution {
    class TrieNode
    {
        public:
        TrieNode* next[2];
    };
public:
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode();
        for (auto num:nums)
        {
            TrieNode* node = root;
            for(int k=31;k>=0;k--)
            {
                if(node->next[(num>>k)&1]==NULL)
                    node->next[(num>>k)&1] = new TrieNode();
                node = node->next[(num>>k)&1];
            }
        }
        int ret = 0;
        for (auto num:nums)
        {
            TrieNode* node = root;
            int ans = 0;
            for(int k=31; k>=0; k--){
                if(node->next[1-(num>>k)&1]!=NULL)
                {
                    ans = ans*2+1;
                    node = node->next[1-(num>>k)&1];
                }
                else
                {
                    ans = ans*2+0;
                    node = node->next[(num>>k)&1];
                }
            }
            ret = max(ret,ans);
        }
        return ret;
    }
};


int main(){
   
    vector<int> k= {3,10,5,25,2,8};
     

    //vector<int> m= {3,3,4};
    //vector<int> k = {3,4,4};
  

    Solution s;
    int result = s.findMaximumXOR(k);

    // for(auto it:result)
    //     for (auto it1:it)
    cout<<"result is: "<<result<<endl;

    return 0;
} 