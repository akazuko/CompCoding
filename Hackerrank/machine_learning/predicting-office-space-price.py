# Enter your code here. Read input from STDIN. Print output to STDOUT
from sklearn import linear_model
from sklearn.preprocessing import PolynomialFeatures

f,n = map(int,raw_input().split())
x_train = []
y_train = []

poly = PolynomialFeatures(degree=3)

for i in range(n):
    data = map(float,raw_input().split())
    x_train.append(data[:-1])
    y_train.append(data[-1])

x_train = poly.fit_transform(x_train)

clf = linear_model.LinearRegression()
clf.fit(x_train,y_train)

k = int(raw_input())
x_test = []
for i in range(k):
    data = map(float,raw_input().split())
    x_test.append(data)
x_test = poly.fit_transform(x_test)
for d in x_test:
	print "%.2f" %(clf.predict([d]))
