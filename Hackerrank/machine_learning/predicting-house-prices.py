# Enter your code here. Read input from STDIN. Print output to STDOUT
from sklearn import linear_model
import numpy as np
f,n = map(int,raw_input().split())
x_train = []
y_train = []
for i in range(n):
    data = map(float,raw_input().split())
    x_train.append(data[:-1])
    y_train.append(data[-1])

clf = linear_model.LinearRegression()
clf.fit(x_train,y_train)
k = int(raw_input())
for i in range(k):
    data = map(float,raw_input().split())
    print "%.2f" %(clf.predict([data])[0])
