from sys import stdin

cases = enumerate([([int(x) for x in l[:-1]], int(l)) for l in stdin.readlines()[1:]])

def fromDigits(d):
  return sum([k * 10**i for (i,k) in enumerate(reversed(d))])

for (c, (digits, n)) in cases:
  l = len(digits)
  ans = [0]*l

  for i, d in enumerate(digits):
    ans[i:] = [d] * (l-i)
    if(fromDigits(ans) > n):
      ans[i] = d-1
      ans[i+1:] =  [9]*(l-i-1)
      break
  print "Case #%s: %s" % (c+1, fromDigits(ans))



