class Solution:
    def firstStableIndex(self, nums: list[int], k: int) -> int:
        n = len(nums)

        M = [0] * n
        M[0] = nums[0]
        for i in range (1,n):
            M[i] = max(nums[i], M[i-1])

        m = [0] * n
        m[n-1] = nums[n-1]
        for i in range (n-2, -1, -1):
            m[i] = min (m[i+1], nums[i])

        for i in range (n):
            if M[i] - m[i] <= k:
                return i

        return -1