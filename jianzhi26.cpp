

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

  void create_tree(TreeNode* node, int a[], int len, int index)
{
	if (index >= len)
		return;
	//tree = new TreeNode();
    TreeNode* tree;

	tree->val = a[index];
	tree->left = NULL;
	tree->right = NULL;
	create_tree(tree->left, a, len, 2 * index + 1);
	create_tree(tree->right, a, len, 2 * index + 2);
}
 
class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        bool flag = false;

        if(!A && !B){
            //flag = AhasB(A,B);
            //cout<<flag<<endl; 
            //if(!flag) isSubStructure(A->left,B);
            //cout<<flag<<endl; 
            if(!flag) isSubStructure(A->right,B);
            //cout<<flag<<endl; 

        }  
        return flag;
    }
private:
    bool AhasB(TreeNode* A, TreeNode* B){
        
        if(!B) return true;
        if(!A){
            return false;
        }
        if(A->val!=B->val) return false;
        return AhasB(A->left,B->left) && AhasB(A->right,B->right);
        
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
    int p[7] = { 1, 2, 3, 4 };
    int q[1] = {3};
	TreeNode*A;
    TreeNode*B;

	create_tree(A, p, 4, 0);
    create_tree(B, p, 1, 0);


    Solution s;
    bool result = s.isSubStructure(A,B);
    
        cout<<result<<endl;
    // while(cur1){
    //     cout<<cur1->val<<endl;
    //     cur1 = cur1->next;
    // }
    return 0;
} 