class TimeMap:

    def __init__(self):
        self.mp = {}
        

    def set(self, key: str, value: str, timestamp: int) -> None:
        if key not in self.mp:
            self.mp[key] = []

        self.mp[key].append((value, timestamp))

    def get(self, key: str, timestamp: int) -> str:
        if key not in self.mp:
            return ""
        
        values = self.mp[key]

        l = 0
        r = len(values) - 1
        ans = ""

        while l <= r:
            m = l + (r - l) // 2

            if values[m][1] <= timestamp:
                ans = values[m][0]
                l = m + 1


            else:
                r = m - 1

        return ans

        


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)