'''
def my_function(a, b):
    return a + b

x =int(input())
y =int(input())
#x,y = int,input().split=(" ")
print(my_function(x,y))

try:
    1 / 0
except ZeroDivisionError as e:
    print(e)

d = {'a': 1, 'b': 2}
for k, v in d.items():
    print(k, v)
'''
def my1_function(a: int, b: int) -> int:
    return a + b

x =int(input())
y =int(input())
#x,y = int,input().split=(" ")
print(my1_function(x,y))

def my2_function(a, b):
    return a + b

m =int(input())
n =int(input())
#x,y = int,input().split=(" ")
print(my2_function(m,n))

