

# infix to postfix and prefix

def push(stack, symbol):
    stack.append(symbol)

def pop(stack):
    return stack.pop()

def isOperator(symbol):
    return symbol in "+-*/%^"

def isOperand(symbol):
    return not isOperator(symbol)

def empty(stack):
    return stack == []

def peek(stack):
    return stack[-1]

def priority(opr):
    if opr in "+-":
        p = 1
    elif opr in "*/%":
        p = 2
    elif opr == "^":
        p = 3

    return p

# infix to postfix

def in2post(expn):
    stack = []
    postfix = ""

    for symbol in expn:
        if symbol.isspace():
            continue
        if symbol == '(':
            push(stack, symbol)
        elif symbol.isalnum():  # Operand
            postfix += symbol
        elif isOperator(symbol):
            if peek(stack) == '(':
                push(stack, symbol)
            elif isOperator(peek(stack)):
                while peek(stack) != '(' and priority(symbol) <= priority(peek(stack)):
                    postfix += pop(stack)
                push(stack, symbol)
        elif symbol == ')':
            while peek(stack) != '(':
                postfix += pop(stack)
            pop(stack)
    return postfix

# infix to prefix
# reverse expression, swap ( and ), find postfix, reverse the result

def in2pre(expn):
    stack = []
    prefix = ""

    for symbol in expn:
        if symbol.isspace():
            continue
        if symbol == ')':
            push(stack, symbol)
        elif symbol.isalnum():  # Operand
            prefix += symbol
        elif isOperator(symbol):
            if peek(stack) == ')':
                push(stack, symbol)
            elif isOperator(peek(stack)):
                while peek(stack) != ')' and priority(symbol) <= priority(peek(stack)):
                    prefix += pop(stack)
                push(stack, symbol)
        elif symbol == '(':
            while peek(stack) != ')':
                prefix += pop(stack)
            pop(stack)
    return prefix[::-1]

expn = "A+(B*C-(D/E^F)*G)*H"
expn = "A * B + C / D"
expn = "(A - B/C) * (A/K-L)"
expn = "A+(B*C-(D/E^F)*G)*H"

expn = '(' + expn + ')'

print(expn[1:-1])
print("Postfix:", in2post(expn))
print("Prefix:", in2pre(expn[::-1]))

'''

A+(B*C-(D/E^F)*G)*H
Postfix: ABC*DEF^/G*-H*+
Prefix: +A*-*BC*/D^EFGH

A * B + C / D
Postfix: AB*CD/+
Prefix: +*AB/CD

(A - B/C) * (A/K-L)
Postfix: ABC/-AK/L-*
Prefix: *-A/BC-/AKL

A+(B*C-(D/E^F)*G)*H
Postfix: ABC*DEF^/G*-H*+
Prefix: +A*-*BC*/D^EFGH

'''
