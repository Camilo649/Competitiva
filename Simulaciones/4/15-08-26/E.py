
import sys
sys.stdin = open('easy.in','r')
sys.stdout = open('easy.out','w')


text = input()
expressions = []


if text[0] not in  ['-', '+']:
    expressions.append([])
for c in text:
    if c in ['+', '-']:
        expressions.append([])
    expressions[-1].append(c)


for i, expression in enumerate(expressions):
    if expression[0] == '-':
        if len(expression) <= 2:
            expressions[i] = ''.join(expression)
            continue

        expression.insert(2, '+')
        
        j = 4
        while j < len(expression):
            if expression[j-1] == '0':
                expression.insert(j, '+')
                j += 2
            else:
                break
        

    expressions[i] = ''.join(expression)

ans = ''.join(expressions)

print(ans)



