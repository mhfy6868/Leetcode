leetcode 240周赛 第三题

```cpp
class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        vector<long long> sum(n+1);
        for(int i=0;i<n;++i)sum[i+1]=sum[i]+nums[i];
        vector<int> pre(n),nex(n);
        pre[0]=-1;
        for(int i=1;i<n;++i){
            int j=i-1;
            while(j>-1&&nums[j]>=nums[i])j=pre[j];//找到左边递增的最大值
            pre[i]=j;
        }
        nex[n-1]=n;
        for(int i=n-2;i>=0;--i){
            int j=i+1;
            while(j<n&&nums[j]>=nums[i])j=nex[j];//找到右边递增的最大值
            nex[i]=j;
        }
        for(int i=0;i<n;++i){
            ans=max(ans,nums[i]*(sum[nex[i]]-sum[pre[i]+1]));
        }
        return ans%int(1e9+7);
    }
};
```

