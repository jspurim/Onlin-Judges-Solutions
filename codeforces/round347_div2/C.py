from sys import stdin

t = int(input())


def solve(s):
    if len(s)==1:
        return 1989 if s == "9" else 1990 + int(s)

    ks = s[1:]
    prev = solve(ks)

    ans = prev/(10**len(s))
    ans +=1
    ans *= 10**len(s)
    ans = ans+int(s)

    ans2 = prev/(10**len(s))
    ans2 *= 10**len(s)
    ans2 = ans2+int(s)
    if(ans2 > prev):
        ans=min(ans,ans2)
    if (ans > int(s) and int(s)>prev):
        return int(s)
    return ans


for i in range(t):
    s = raw_input();
    s=s[4:]
    print solve(s)
