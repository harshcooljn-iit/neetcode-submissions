class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        for i in range(n):
            nums[i] = [nums[i], i]
        nums.sort()
        ans = []
        i, j = 0, n-1
        while i < j:
            if nums[i][0] + nums[j][0] > target:
                j -= 1
            elif nums[i][0] + nums[j][0] < target:
                i += 1
            else:
                ans.append([min(nums[i][1],nums[j][1]),max(nums[i][1],nums[j][1])])
                i += 1
                j -= 1
                while i < j and nums[i][0] == nums[i-1][0]:
                    i += 1
        return ans[0]