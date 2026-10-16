class Solution:
    def canFinish(self, numCourses: int, prerequisites: list[list[int]]) -> bool:
        preMap = {i:[] for i in range(numCourses)}

        for pre, crs in prerequisites:
            preMap[pre].append(crs)
        
        visit = set()

        def dfs(crs):
            if crs in visit:
                return False

            if preMap[crs] == []:
                return True

            visit.add(crs)
            for nei in preMap[crs]:
                if not dfs(nei):
                    return False
            
            preMap[crs] = []
            visit.remove(crs)
            return True
                
        
        for crs in range(numCourses):
            if not dfs(crs):
                return False
            
        return True


        