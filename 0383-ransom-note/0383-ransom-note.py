class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        counts = defaultdict(int)

        for ch in magazine:
            counts[ch] += 1

        for ch in ransomNote:
            counts[ch] -= 1

            if counts[ch] < 0:
                return False
        
        return True
        