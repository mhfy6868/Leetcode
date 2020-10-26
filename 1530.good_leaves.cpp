
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
#include <functional> 


using namespace std;
  
  struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

     void Insert( TreeNode* node, int value ){
    if( node == NULL ) {
        node = new TreeNode( value );
        return;
    }
    if(!node->left)
        node->left = new TreeNode( value );
        //Insert( node->left, value );
    else if(!node->right)
        node->right = new TreeNode( value );
    else if (node->left && node->right)
        node->left->left = new TreeNode( value );
    else if (node->left && node->right && node->left->left)
        node->left->right = new TreeNode( value );
    return;
    
};

// class Solution {
// public:
//     int countPairs(TreeNode* root, int distance) {
//         int ans = 0;
//         dfs(root,distance,ans);
//         return ans;
        
//     }

//     vector<int> dfs(TreeNode* c,int &distance,int &ans)
//         {
//             vector<int> f(distance+1);
//             if(!c) return f;
//             if(!c->left && !c->right) {
//                 f[0] = 1;
//                 return f;
//             }
//             const vector<int>& l=dfs(c->left,distance,ans);
//             const vector<int>& r=dfs(c->right,distance,ans);
//             for(int i=0;i+1<=distance;++i)
//                 for(int j=0;i+j+2<=distance;++j)
//                     ans+=l[i]*r[j];
//             for(int i=0;i<distance;++i)
//                 f[i+1]=l[i]+r[i];
//             return f;
//         };
// };

class Solution {
public:
  int countPairs(TreeNode* root, int distance) {
    int ans = 0;
    function<vector<int>(TreeNode*)> dfs 
      = [&](TreeNode* c) -> vector<int> {
      // f[i] = number of leaves node at distance i.
      vector<int> f(distance + 1);
      if (!c) return f;      
      if (!c->left && !c->right) {        
        f[0] = 1; // a single leaf node
        return f;
      }
      const vector<int>& l = dfs(c->left);
      const vector<int>& r = dfs(c->right);
      for (int i = 0; i + 1 <= distance; ++i)
        for (int j = 0; i + j + 2 <= distance; ++j)
          ans += l[i] * r[j];
      for (int i = 0; i < distance; ++i)
        f[i + 1] = l[i] + r[i];
      return f;
    };
    dfs(root);
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
    int distance = 3;
    int values[] = {1,2,3,NULL,4};
    TreeNode* root = new TreeNode(values[0]);
    //TreeNode* cur = root;
    int n = sizeof(values)/sizeof(values[0]);

    for (int i = 1; i < n; ++i) {
        Insert(root,values[i]);
    }

    Solution s;
    int result = s.countPairs(root,distance);
    //for (auto m: result)
        cout<<result<<endl;
    // while(cur1){
    //     cout<<cur1->val<<endl;
    //     cur1 = cur1->next;
    // }
    return 0;
} 
