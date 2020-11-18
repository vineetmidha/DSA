// Stock Span

def push(stack, element):
    stack.append(element)

def pop(stack):
    return stack.pop()

def peek(stack):
    return stack[-1]

def empty(stack):
    return stack==[]

def stockSpan(a):
    span = [0]*len(a)
    stack = []

    push(stack, 0)
    span[0] = 1

    for index in range(1, len(a)):
        if a[peek(stack)] > a[index]:
            span[index] = 1
        else:
            while not empty(stack) and a[peek(stack)] <= a[index]:
                pop(stack)

            if empty(stack):
                span[index] = index + 1
            else:
                span[index] = index - peek(stack)

        push(stack, index)

    return span

a = [100, 80, 60, 70, 60, 75, 85] 		# {1, 1, 1, 2, 1, 4, 6}
b = [10, 4, 5, 90, 120, 80]     		# {1, 1, 2, 4, 5, 1}

print(stockSpan(a))
print(stockSpan(b))

