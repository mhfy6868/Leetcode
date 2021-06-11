#### [LCP 29. 乐团站位](https://leetcode-cn.com/problems/SNJvJP/)

难度简单4收藏分享切换为英文接收动态反馈

某乐团的演出场地可视作 `num * num` 的二维矩阵 `grid`（左上角坐标为 `[0,0]`)，每个位置站有一位成员。乐团共有 `9` 种乐器，乐器编号为 `1~9`，每位成员持有 `1` 个乐器。

为保证声乐混合效果，成员站位规则为：自 `grid` 左上角开始顺时针螺旋形向内循环以 `1，2，...，9` 循环重复排列。例如当 num = `5` 时，站位如图所示

![image.png](https://pic.leetcode-cn.com/1616125411-WOblWH-image.png)

请返回位于场地坐标 [`Xpos`,`Ypos`] 的成员所持乐器编号。

**示例 1：**

> 输入：`num = 3, Xpos = 0, Ypos = 2`
>
> 输出：`3`
>
> 解释：
> ![image.png](https://pic.leetcode-cn.com/1616125437-WUOwsu-image.png)

**示例 2：**

> 输入：`num = 4, Xpos = 1, Ypos = 2`
>
> 输出：`5`
>
> 解释：
> ![image.png](https://pic.leetcode-cn.com/1616125453-IIDpxg-image.png)

**提示：**

- `1 <= num <= 10^9`
- `0 <= Xpos, Ypos < num`



思路
我们可以先计算出当前坐标位于第几层，比如说 (3,3) 位于第 4 层，而 (0, 0) 位于第 0 层。

首先我们要知道 (x, y) 处于第几层：

layer(x, y) = min(x, y, n-1-x, n-1-y)
layer(x,y)=min(x,y,n−1−x,n−1−y)

大家可以通过画图思考一下上述公式的来由。

然后我们需要计算当前层外面所有层元素个数之和，只有这样我们才可以确定当前层的起始数字为多少。下面的例子展现了如何求得这些层的元素个数之和。


1 2 3 4
3 4 5 5
2 7 6 6
1 9 8 7

n = 4
layer[0] = 4 * (n-1 - 2*0) = 4 * 3 = 12
layer[1] = 4 * (n-1 - 2*1) = 4 * 1 = 4
...
layer[i] = 4 * (n-1 - 2*i)

sum(layer) = 4 * ((n-1) + (n-1 - 2) + ... + (n-1 - 2(l - 1))) = 4 * ((n - 1) * l - l * (l-1)))
确定了当前层的起始元素之后，我们需要知道当前位置 (x, y) 处于当前层的第几个位置。因此，我们把当前层分为 4 个阶段，分别是: 从左到右，从上到下，从右到左，从下到上。

通过分情况讨论可以得到最终的答案。



```c++
class Solution {
public:
    int orchestraLayout(int n, int x, int y) {
        long long ans;
        long long l;
        l = min(x , y);
        l = min(min((int)l, n-1-x), n-1-y);
        ans = ((n - 1) * l - l * (l-1)) % 9;
        ans = (4 * ans) % 9 - 1;
        if (x == l) { 
            ans = (ans + y - l + 1) % 9; 
        } else if (y == n-1-l) {
            ans = (ans + n-1-2*l + x-l + 1) % 9;
        } else if (x == n-1-l) {
            ans = (ans + 2 * (n-1-2*l) + (n-1-l - y) + 1) % 9;
        } else {
            ans = (ans + 3 * (n-1-2*l) + (n-1-l - x) + 1) % 9;
        }
        return ans + 1;
    }
};


```

