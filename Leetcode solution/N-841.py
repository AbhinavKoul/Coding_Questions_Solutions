class Solution(object):
    def canVisitAllRooms(self, rooms):
        l=len(rooms)
        visited=[]
        queue=[]
        for i in range(l):
            visited.append(0)
        p=len(rooms[0])
        visited[0]=1
        for i in range(p):
            visited[rooms[0][i]]=1
            queue.append(rooms[0][i])
        while len(queue)!=0:
            elem=queue[0]
            visited[elem]=1
            p=len(rooms[elem])
            for i in range(p):
                if visited[rooms[elem][i]]==0:
                    queue.append(rooms[elem][i])
            queue.pop(0)
        if visited.count(1)==l:
            return True
        else:
            return False