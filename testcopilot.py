for num in range(1, 11):
    print(num)


while True:
    print("Hello, World!")
    break

def fib(n):
    if n <= 1:
        return n
    return fib(n - 1) + fib(n - 2)

print(fib(10))

def factorial(n):
    if n == 0:
        return 1
    return n * factorial(n - 1)

def node (value, next=None):
    return {"value": value, "next": next}

node1 = node(1)
print(node1["value"])
