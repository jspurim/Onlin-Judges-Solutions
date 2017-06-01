T = int(input())

points = [(x,y) for x in range(1,51) for y in range(1,51)]

def dist(snake, p):
    (x,y) = p
    ((sx1, sy1),(sx2,sy2)) = snake
    if sx1 == sx2:
        (y,x) = p
        ((sy1, sx1),(sy2,sx2)) = snake
    # now our snake is horizontal
    ans = abs(y-sy1)
    (sx1,sx2) = (min(sx1,sx2),max(sx1,sx2))
    if x < sx1:
        ans += sx1-x
    elif sx2 < x:
        ans += x-sx2
    return ans

for _ in range(T):
    n = int(input())
    snakes = []
    for _ in range(n):
        (x1,y1,x2,y2) = tuple(int(x.strip()) for x in raw_input().split(' '));
        snakes.append(((x1,y1),(x2,y2)))
    print min([max([dist(s,p) for s in snakes]) for p in points])
