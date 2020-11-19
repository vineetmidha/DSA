# Reverse String Using Stack

def push(stack, element):
    stack.append(element)

def pop(stack):
    return stack.pop()

def empty(stack):
    return stack==[]

def peek(stack):
    return stack[-1]

def display(stack):
    for i in range(-1,-len(stack)-1,-1):
        print(stack[i])
        
def sortStack(originalStack):
    helpStack = []

    while not empty(originalStack):
        t = pop(originalStack)
        
        while not empty(helpStack) and t > peek(helpStack):
            out = pop(helpStack)
            push(originalStack, out)

        push(helpStack, t)

    return helpStack

def sortArrayWithStack(a, stack):
    # transfer array to stack

    for i in a:
        push(stack, i)
    
    # sort stack
    
    stack = sortStack(stack)

    # transfer stack to array

    a = ''
    while not empty(stack):
        val = pop(stack)
        a += val
    
    # Return array
    
    return a

a = "data structure through python"
stack = []

print("Original Array: ", a)

a = sortArrayWithStack(a, stack)

print("Sorted Array: ", a.strip())

'''

Original Array:  data structure through python
Sorted Array:  aacdeghhhnooprrrstttttuuuy

'''
