# Evaluate postfix expression

def push(stack, element):
    stack.append(element)

def pop(stack):
    return stack.pop()

def isOperator(symbol):
    return symbol in "+-*/%^"

def evaluatePostfix(postfix):
    stack = []

    postfix = postfix.split(",")

    for symbol in postfix:
        if not isOperator(symbol):
            push(stack, int(symbol))
        else:
            operand2 = pop(stack)
            operand1 = pop(stack)
            result = eval(str(operand1) + symbol + str(operand2))
            push(stack, result)

    return pop(stack)

expressions = ["10,20,+,15,5,+,*", "50,40,+,18,14,-,4,*,+", "10,20,+,25,15,-,*,30,/"]

for expn in expressions:
    print(f"[{expn}] = {evaluatePostfix(expn)}")


'''

[10,20,+,15,5,+,*] = 600
[50,40,+,18,14,-,4,*,+] = 106
[10,20,+,25,15,-,*,30,/] = 10.0

'''
