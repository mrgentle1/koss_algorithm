import sys

input = sys.stdin.readline

class Stack:
    def __init__(self):
        self.st = []
    
    def push(self, e):
        self.st.append(e)
    
    def pop(self):
        rt = self.st[-1]
        self.st = self.st[:-1]
        return rt
    
    def top(self):
        return self.st[-1]
    
    def empty(self):
        return len(self.st) == 0


def solution():
    line = input()[:-1]
<<<<<<< HEAD
    # line = line[:-1]
=======
>>>>>>> 2708eb947babdf4b8fd0b534aa47ee7b7a0e4c10
    st = Stack()
    for i in line:
        if i == '(':
            st.push(1)
        else:
            if not st.empty():
                st.pop()
            else:
                print('NO')
                return
    if st.empty(): print('YES')
    else: print('NO')

t = int(input())
for _ in range(t):
    solution()
                
