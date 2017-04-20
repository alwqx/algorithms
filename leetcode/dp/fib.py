def fib(n):
    if n ==0 or n == 1:
        return n
    else:
        return fib(n-1) + fib(n-2)

m = {0:0,1:1}
def fibopt(n):
    if n not in m:
        m[n] = fibopt(n-1) + fibopt(n-2)
    return m[n]

#print(fibopt(9))
print(fibopt(100))
#print(fibopt(40))
#print(fibopt(60))

"""
fibopt()中hash表m必须定义成全局的，这样每次递归调用的共享这个m，
不需要冲去计算。如果写成
def fib(n):
    m = {0:0,1:1}
    if n not in m:
        m[n] = fib(n-1) + fib(n-2)
    return m[2]
这样就没有起到“记忆”的作用，因为每次递归调用子fib是的m都是{0:0,1:1}，
每次还是需要重新计算。
"""
