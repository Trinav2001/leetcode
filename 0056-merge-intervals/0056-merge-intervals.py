class Solution:
    def merge(self, intervals: list[list[int]]) -> list[list[int]]:
        output = []
        intervals.sort()
        output.append(intervals[0])

        for interval in intervals:
            start = interval[0]
            end = interval[1]

            lastIntervalEnd = output[-1][1]

            if start <= lastIntervalEnd:
                output[-1][1] = max(end, lastIntervalEnd)
            
            else:
                output.append([start, end])
        
        return output
        