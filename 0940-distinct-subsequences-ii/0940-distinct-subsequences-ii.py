class Solution:
    MOD = 1000000007
    def distinctSubseqII(self, s: str) -> int:
        x = 1

        m = {}

        for c in s:
            y = x

            x = (2*x - m.get(c, 0) + self.MOD) % self.MOD

            m[c] = y

        return (x - 1 + self.MOD) % self.MOD