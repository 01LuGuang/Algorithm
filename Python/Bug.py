class Bug:
    def __init__(self):
        #初始化虫子的位置
        self.x = 0
        self.y = 0
        self.direction = (1, 0)
    
    def turn(self, x):
        #改变虫子的方向
        if x == -1:
            self.direction = (-self.direction[1], self.direction[0])
        elif x == -2:
            self.direction = (self.direction[1], -self.direction[0])

    def move(self, d):
        #移动虫子
        self.x += d * self.direction[0]
        self.y += d * self.direction[1]

    def print_position(self):
        print(f"({self.x}, {self.y})")

if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().strip().split()
    commands = [int(x) for x in data]
    bug = Bug()
    for x in commands:
        if x >= 0:
            bug.move(x)
        else:
            bug.turn(x)
    bug.print_position()


