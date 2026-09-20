class Solution:
    def findOrder(self, numCourses: int, prerequisites: list[list[int]]) -> list[int]:

        preMap = {i:[] for i in range(numCourses)}

        for pre, crs in prerequisites:
            preMap[pre].append(crs)
        
        cycle = set()
        output = []

        def dfs(crs):
            if crs in cycle:
                return False
            
            if preMap[crs] is None:
                return True
            
            cycle.add(crs)

            for pre in preMap[crs]:
                if not dfs(pre):
                    return False
            
            preMap[crs] = None
            cycle.remove(crs)
            output.append(crs)
            return True
        
        for c in range(numCourses):
            if not dfs(c):
                return []

        return output
        