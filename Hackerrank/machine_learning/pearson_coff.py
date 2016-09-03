# Enter your code here. Read input from STDIN. Print output to STDOUT
x = [15,12,8,8,7,7,7,6,5,3]
X= sum(x)
y = [10,25,17,11,13,17,20,13,9,15]
Y=sum(y)

xx = map(lambda c : c**2 , x)
XX = sum(xx)

yy = map(lambda c : c**2, y)
YY = sum(yy)

XY = 0
n = len(x)
for i in range(n):
    XY+=x[i]*y[i]

val = (n*XY - X*Y)/(((n*XX-X**2)*(n*YY-Y**2))**0.5)
print val
