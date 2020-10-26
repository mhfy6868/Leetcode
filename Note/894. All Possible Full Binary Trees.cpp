
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
#include <cstddef>


using namespace std;
  
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        if(N%2 == 0) return {};
        if(N ==1 )return {new TreeNode(0)};
        vector<TreeNode*> ans;
        for(int i=1;i<N;i+=2){
            for(auto l:allPossibleFBT(i))
                for(auto r:allPossibleFBT(N-i-1)){
                    auto root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                } 
        }
        return ans;

    }
};


int main(){
    
    // int values[] = {2,1,1,3,6,7,9,4,3};
    // ListNode* list = new ListNode(values[0]);
    // ListNode* cur = list;
    // int n = sizeof(values)/sizeof(values[0]);
    // for (int i = 1; i < n; ++i) {
    // cur->next = new ListNode(values[i]);
    // cur = cur->next;
    // }

    Solution s;
    vector<TreeNode*> result = s.allPossibleFBT(9);
    for (auto m: result)
        cout<<m->val<<endl;
    // while(cur1){
    //     cout<<cur1->val<<endl;
    //     cur1 = cur1->next;
    // }
    return 0;
} 
