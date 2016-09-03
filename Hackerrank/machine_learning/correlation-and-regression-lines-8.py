from sklearn.preprocessing import PolynomialFeatures
from sklearn import linear_model

poly = PolynomialFeatures(degree=1)
x_train = "15 12 8 8 7 7 7 6 5 3"
y_train = "10 25 17 11 13 17 20 13 9 15"
x_train = map(int, x_train.split())
y_train = map(int,y_train.split())
x_train = map(lambda x : [x], x_train)

x_train = poly.fit_transform(x_train)

clf = linear_model.LinearRegression()
clf.fit(x_train,y_train)

x_test = [[10]]
x_test = poly.fit_transform(x_test)
print clf.predict(x_test)