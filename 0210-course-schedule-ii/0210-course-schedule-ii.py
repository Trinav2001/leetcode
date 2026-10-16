class Solution:
    def findOrder(self, numCourses: int, prerequisites: list[list[int]]) -> list[int]:
        preMap = {i : [] for i in range(numCourses)}

        output = []
        visited = set()
        visiting = set()

        for crs, pre in prerequisites:
            preMap[crs].append(pre)
        
        def dfs(crs):
            if crs in visiting:
                return False
            
            if crs in visited:
                return True
            
            visiting.add(crs)
            for nei in preMap[crs]:
                if not dfs(nei):
                    return False
            
            visiting.remove(crs)
            visited.add(crs)
            output.append(crs)
            return True

        for crs in range(numCourses):
            if not dfs(crs):
                return []
        
        return output