#### [LCP 28. 采购方案](https://leetcode-cn.com/problems/4xy4Wx/)

难度简单3收藏分享切换为英文接收动态反馈

小力将 N 个零件的报价存于数组 `nums`。小力预算为 `target`，假定小力仅购买两个零件，要求购买零件的花费不超过预算，请问他有多少种采购方案。

注意：答案需要以 `1e9 + 7 (1000000007)` 为底取模，如：计算初始结果为：`1000000008`，请返回 `1`

**示例 1：**

> 输入：`nums = [2,5,3,5], target = 6`
>
> 输出：`1`
>
> 解释：预算内仅能购买 nums[0] 与 nums[2]。

**示例 2：**

> 输入：`nums = [2,2,1,9], target = 10`
>
> 输出：`4`
>
> 解释：符合预算的采购方案如下：
> nums[0] + nums[1] = 4
> nums[0] + nums[2] = 3
> nums[1] + nums[2] = 3
> nums[2] + nums[3] = 10

**提示：**

- `2 <= nums.length <= 10^5`
- `1 <= nums[i], target <= 10^5`

```c++
#define ll long long

class Solution {
public:
    int purchasePlans(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        ll sum = 0;
        for(int i=0;i<n;i++){         
            if(target - nums[i]>0 && nums[i]<=target/2){
                auto upper = upper_bound(nums.begin(),nums.end(),target-nums[i]);
                int dis = std::distance(nums.begin(), upper);
                sum += dis - i-1;
            }
            
        }
        sum = (sum)%(int)(1e9+7);
        return sum;
    }
};
```

这个题自己能明白用二分查找，但是居然不知道要开long long，活活被搞死。。



```c++
#define ll long long
const ll MOD=1e9+7;
class Solution {
public:
    int purchasePlans(vector<int>& a, int tar) {
        sort(a.begin(),a.end());
        int n=a.size();
        ll ans=0;              //不开long long见祖宗
        for(int i=0;i<n;++i){
            if(a[i]>tar)break; //如果单个零件就超预算了
            int l=i+1,r=n-1;
            while(l<=r){
                int mid=(l+r)/2;
                if(a[i]+a[mid]<=tar)l=mid+1;
                else r=mid-1;
            }
            //printf("i=%d l=%d r=%d\n",i,l,r);
            ans+=(r-i);
        }
        //puts("");
        return ans%MOD;
    }
};

```

这个是别人的常规的一个版本，注意人家这个打印调试的方式。