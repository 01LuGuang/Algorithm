import math

class Cannonball:
    def __init__(self, x, y, v, a):
        self.x = x
        self.y = y
        self.v = v
        self.a = a
        self.g = 9.81

    def get_position(self, t):
        x = self.x + self.v * math.cos(math.radians(self.a)) * t
        y = self.y + self.v * math.sin(math.radians(self.a)) * t - 0.5 * self.g * t**2
        return x, y
    
x, y, v, a = map(float, input().split())

cannonball = Cannonball(x, y, v, a)

t = 0;
while True:
    x, y = cannonball.get_position(t)
    if y <= 0:
        break
    t += 0.01

print(f"{cannonball.get_position(t)[0]:.2f}")