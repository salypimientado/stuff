import math

class Vector:
    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y

    def __repr__(self):
        return f'Vector({self.x!r}, {self.y!r})'

    def __abs__(self):
        return math.hypot(self.x, self.y)

    def __bool__(self):
        return bool(abs(self))

    def __add__(self, other):
        x = self.x + other.x
        y = self.y + other.y
        return Vector(x, y)

    def __mul__(self, other):
        return Vector(self.x * scalar, self.y * scalar)


v1 = Vector(0,1)
v2 = Vector(3,4)
v3 = Vector(0,0)

print(v1)
print(f'{bool(v2)=}')
print(f'{bool(v3)=}')
print(v1 + v2)
