import sys

input = sys.stdin.readline

class Queue:
    def __init__(self):
        self.st = []
    
    def push(self, e):
        self.st.append(e)
    
    def pop(self):
        rt = self.st[0]
        self.st = self.st[1:]
        return rt
    
    def top(self):
        return self.st[0]
    
    def empty(self):
        return len(self.st) == 0

    def size(self):
        return len(self.st)

buffer_size = int(input())
buffer = Queue()
n = int(input())
buffer.push(n)

while True:
    n = int(input())
    if n == -1: break
    elif n == 0: buffer.pop()
    else: 
        if buffer_size > buffer.size():
            buffer.push(n)

while not buffer.empty():
    print(buffer.pop())