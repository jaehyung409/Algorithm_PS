from math import factorial

def nCr(n,r):
    return int(factorial(n)/(factorial(r)*factorial(n-r)))

def getPercentage(p):
    pc = 1 - p
    ans = 0
    li = {0,1,4,6,8,9,10,12,14,15,16,18}
    for i in li:
        ans += pow(p,i) * pow(pc,18-i) * nCr(18,i)
    return ans

A = int(input())
B = int(input())
print(1 - (getPercentage(A/100) * getPercentage(B/100)))
