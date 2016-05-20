class MinStack:
    def __init__(self):
        self.s = []
        self.minarr = []
        self.prev_min = -1
        
    # @param x, an integer
    def push(self, x):
        self.s.append(x)
        if(self.minarr==[] or x<self.minarr[-1]):
            self.minarr.append(x)

    # @return nothing
    def pop(self):
        if self.s!=[]:
            if(self.minarr[-1]==self.s[-1]):
                self.minarr.pop()
            self.s.pop()

    # @return an integer
    def top(self):
        if self.s!=[]:
            return self.s[-1]
        else:
            return -1

    # @return an integer
    def getMin(self):
        if self.s!=[]:
            return self.minarr[-1]
        else:
            return -1
