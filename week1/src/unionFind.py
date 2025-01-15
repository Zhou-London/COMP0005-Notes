#Written by Zhouzhou Zhang, Jan 14

class UnionFind:
    def __init__(self, length):
        self.length = length
        self.list = []
        for i in range(self.length):
            self.list.append(i)

    def find(self, u, v):
        return self.list[u] == self.list[v]
    
    def union(self, u, v):

        if(self.find(u,v) 
           or u not in self.list
           or v not in self.list):
            return False
        
        uid = self.list[u]
        vid = self.list[v]
        for i in range(self.length):
            if self.list[i] == uid:
                self.list[i] = vid

        return True

uf = UnionFind(10)
uf.union(1,2);
print(uf.find(2,3))