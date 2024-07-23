#최대힙 
import sys
input = sys.stdin.readline

class MaxHeap():
    def __init__(self):
        self.queue = []
    
    def insert(self, data):
        self.queue.append(data)
        last_index = len(self.queue)-1
        while 0 <= last_index :
            parent_index = self.parent(last_index)
            if 0<=parent_index and self.queue[parent_index] < self.queue[last_index]:
                self.swap(last_index, parent_index)
                last_index = parent_index
            else :
                break
    
    def maxHeapify(self, i):
        left_index = self.leftChild(i)
        right_index = self.rightChild(i)
        max_index = i

        if left_index <= len(self.queue)-1 and self.queue[max_index] < self.queue[left_index]:
            max_index = left_index
        if right_index <= len(self.queue)-1 and self.queue[max_index] < self.queue[right_index]:
            max_index = right_index

        if max_index != i :
            self.swap(i,max_index)
            self.maxHeapify(max_index)
    
    def swap(self, i , parent_index):
        self.queue[i], self.queue[parent_index] = self.queue[parent_index], self.queue[i]

    def parent(self,index):
        return (index-1)//2
    
    def leftChild(self,index):
        return index*2+1

    def rightChild(self,index):
        return index*2 + 2
    
    def printHeap(self):
        print(self.queue)

    def findMax(self):
        if not self.queue:
            return 0
        if len(self.queue) == 1:
            return self.queue.pop()
        root = self.queue[0]
        self.queue[0] = self.queue.pop() #맨 마지막에 있는 값을 루트로 옮기기
        self.maxHeapify(0)
        return root
    
heap = MaxHeap()
n = int(input().strip())

for _ in range(n):
    iInput = int(input().strip())
    if iInput == 0:
        print(heap.findMax())
    else:
        heap.insert(iInput)
