class Solution:
    def solveQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        n = len(nums)

        d = {}

        for i in range(n):
            if nums[i] not in d:
                d[nums[i]] = []
            d[nums[i]].append(i)

        a = [float('inf')] * n
        for val, indices in d.items():
            sz = len(indices)
            if sz <= 1:
                continue

            for i in range(sz):
                curr = indices[i]
                prev = indices[(i - 1 + sz) % sz]
                next = indices[(i + 1) % sz]

                d1 = abs(curr - prev)
                d2 = abs(curr - next)

                d1 = min (d1, n - d1)
                d2 = min (d2, n - d2)

                a[curr] = min(d1, d2)
        
        ans = []
        for q in queries:
            if a[q] == float('inf'):
                ans.append(-1)
            else :
                ans.append(a[q])
        
        return ans