from sklearn import linear_model


x = "15 12 8 8 7 7 7 6 5 3"
y = "10 25 17 11 13 17 20 13 9 15"
x = map(int, x.split())
y = map(int,y.split())
x = map(lambda x : [x], x)
# print x,y
clf = linear_model.LinearRegression()
clf.fit(x,y)
print "%.3f" %(clf.coef_[0])