#최소힙 
import sys
input = sys.stdin.readline

class MinHeap():
    def __init__(self):
        self.queue = []
    
    def insert(self, data):
        self.queue.append(data)
        last_index = len(self.queue)-1
        while 0 <= last_index :
            parent_index = self.parent(last_index)
            if 0<=parent_index and self.queue[parent_index] > self.queue[last_index]:
                self.swap(last_index, parent_index)
                last_index = parent_index
            else :
                break
    
    def minHeapify(self, i):
        left_index = self.leftChild(i)
        right_index = self.rightChild(i)
        min_index = i

        if left_index <= len(self.queue)-1 and self.queue[min_index] > self.queue[left_index]:
            min_index = left_index
        if right_index <= len(self.queue)-1 and self.queue[min_index] > self.queue[right_index]:
            min_index = right_index

        if min_index != i :
            self.swap(i,min_index)
            self.minHeapify(min_index)
    
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

    def findMin(self):
        if not self.queue:
            return 0
        if len(self.queue) == 1:
            return self.queue.pop()
        root = self.queue[0]
        self.queue[0] = self.queue.pop() #맨 마지막에 있는 값을 루트로 옮기기
        self.minHeapify(0)
        return root
    
heap = MinHeap()
n = int(input().strip())

for _ in range(n):
    iInput = int(input().strip())
    if iInput == 0:
        print(heap.findMin())
    else:
        heap.insert(iInput)
