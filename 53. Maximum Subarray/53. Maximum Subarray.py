


class Solution:
    def maxSubArray(nums) -> int:
        total = 0
        maxx = float("-inf")
        for i in range(len(nums)):
            total += nums[i]
            if maxx < total:
                maxx = total
            if total < 0:
                total = 0

        return maxx


Data = [-2,1,-3,4,-1,2,1,-5,4]

print(Solution.maxSubArray(Data))

print(Data)