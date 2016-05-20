constant=[]
multiple=[]

def precalc_values(polyY, polyX):
	global constant,multiple
	polycorners = len(polyY)
	j=polycorners-1
	for i in range(polycorners):
		if(polyY[j]==polyY[i]):
			constant[i]=polyX[i]
			multiple[i]=0
		else:
			constant[i]=polyX[i]-(polyY[i]*polyX[j])/(polyY[j]-polyY[i])+(polyY[i]*polyX[i])/(polyY[j]-polyY[i])
			multiple[i]=(polyX[j]-polyX[i])/(polyY[j]-polyY[i])
		j=i


def pointInPolygon(polyY, polyX, x, y):
	global constant,multiple
	polycorners = len(polyY)
	j=polycorners-1
	oddNodes=0
	# print x,y
	# print polyX
	# print polyY
	for i in range(polycorners):
		if(polyY[i]< y and polyY[j]>=y or polyY[j]< y and polyY[i]>=y):
			oddNodes^=(y*multiple[i]+constant[i]<x)
			j=i
	return oddNodes


# polyX=[-2,-1,2,2,1,-2]
# polyY=[2,1,2,-1,-2,-2]

# for i in range(len(polyY)):
# 	constant.append(0)
# 	multiple.append(0)

# precalc_values(len(polyY), polyY, polyX)

# print pointInPolygon(len(polyY), polyY, polyX,1,1)
# print pointInPolygon(len(polyY), polyY, polyX,1,-1)
# print pointInPolygon(len(polyY), polyY, polyX,-1,-1)
# print pointInPolygon(len(polyY), polyY, polyX,3,3)

def polyInPoly(poly1X, poly1Y, poly2X, poly2Y):
	for p in range(len(poly2X)):
		if (pointInPolygon(poly1Y, poly1X,poly2X[p],poly2Y[p]) == 0):
			return False
	return True

T = long(raw_input())

for testcase in range(T):
	polygons = []
	count = 0
	N = long(raw_input())
	for corners in range(N):
		M = long(raw_input())
		polyY = []
		polyX = []
		points = map(long, raw_input().split())
		h=0
		for point in range(M):
			polyX.append(points[2*point])
			h+=1
			polyY.append(points[2*point+1])
			h+=1
		polygons.append([polyX, polyY,0])


	for k in range(N):
		poly = polygons[k]
		
		constant=[]
		multiple=[]

		for i in range(len(poly[0])):
			constant.append(0)
			multiple.append(0)

		precalc_values(poly[1], poly[0])
		j=(k+1)%N
		count = 0
		while j!=k:
			temppoly = polygons[j]
			if polyInPoly(poly[0],poly[1],temppoly[0],temppoly[1]):
				count+=1
			# print k,j
			j=(j+1)%N
		poly[2] = count
		print count
