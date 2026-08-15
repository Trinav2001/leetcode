class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mp = {}
        for str in strs:
            count = [0] * 26
            for c in str:
                count[ord(c) - ord('a')] += 1
            
            key = tuple(count)
            
            # if key not in mp:
            #     mp[key] = []

            # mp[key].append(str)

            mp.setdefault(key, []).append(str)
           
        
        return list(mp.values())
        