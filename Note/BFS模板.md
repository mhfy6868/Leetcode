## BFS模板

```cpp
vector<vector<int>> levelOrder(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    //...
    while(q.size())
    {
        int size=q.size();
        //...
        for(int i=0;i<size;i++)
        {
            TreeNode* rt=q.front();q.pop();
            //...
            if(rt->left) q.push(rt->left);
            if(rt->right) q.push(rt->right);
        }
    }
    //return ...
}


```

