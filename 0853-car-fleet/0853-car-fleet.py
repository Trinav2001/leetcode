class Solution:
    def carFleet(self, target: int, position: list[int], speed: list[int]) -> int:

        cars = list(zip(position, speed))
        cars.sort(reverse=True)

        stack = []
        
        for pos, spd in cars:

            time = (target - pos) / spd

            if stack and time <= stack[-1]:
                continue
            
            stack.append(time)
        
        return len(stack)

        