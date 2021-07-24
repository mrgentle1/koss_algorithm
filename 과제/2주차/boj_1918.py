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


sik = input()[:-1]
st = Stack()
result = ''

for i in sik:
    if i.isalpha():
        result += i
    else:
        if i == '(':
            st.push(i)
        elif i == '*' or i == '/':
            while not st.empty() and (st.top() == '*' or st.top() == '/'):
                result += st.pop()
            st.push(i) 
        elif i == '+' or i == '-':
            while not st.empty() and st.top() != '(':
                result += st.pop()
            st.push(i)
        elif i == ')':
            while not st.empty() and st.top() != '(':
                result += st.pop()
            st.pop()

while not st.empty():
    result += st.pop()

print(result)
