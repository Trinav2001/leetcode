class Solution:
    def countCommas(self, n: int) -> int:
        commas = 0
        commas_per_range = 1
        threshold = 1000
        2,000,000
        while threshold <= n:
            nextThreshold = threshold * 1000

            right = min(n, nextThreshold - 1)

            commas += (right - threshold + 1) * commas_per_range

            threshold = nextThreshold
            commas_per_range += 1

        return commas

        