# Generate a PDF containing the requested algorithms and pseudocode using reportlab.platypus

from reportlab.platypus import SimpleDocTemplate, Paragraph, Spacer, Preformatted
from reportlab.lib.styles import getSampleStyleSheet
from reportlab.lib.pagesizes import A4

file_path = "C:\Users\ibrah\OneDrive\B.Tech\Sem - 4\Data Structures (ARI 204)"

styles = getSampleStyleSheet()
title = Paragraph("Expression Conversion Algorithms and Pseudocode (Stack Based)", styles['Title'])

content = []

content.append(title)
content.append(Spacer(1,20))

sections = [
("1. Infix to Postfix",
"""Algorithm:
1. Create empty stack S for operators.
2. Create empty postfix string P.
3. Scan infix expression left to right.
4. If operand → add to P.
5. If '(' → push to stack.
6. If ')' → pop from stack to P until '(' is found.
7. If operator → pop operators with higher/equal precedence from stack to P.
8. Push current operator to stack.
9. After scanning expression, pop remaining operators to P.

Pseudocode:
Algorithm InfixToPostfix(infix)

Create empty stack S
Create empty string postfix

for each symbol ch in infix from left to right
    if ch is operand
        postfix = postfix + ch
    else if ch == '('
        push(S, ch)
    else if ch == ')'
        while top(S) != '('
            postfix = postfix + pop(S)
        pop(S)
    else if ch is operator
        while S not empty AND precedence(top(S)) >= precedence(ch)
            postfix = postfix + pop(S)
        push(S, ch)

while S not empty
    postfix = postfix + pop(S)

return postfix
"""),

("2. Infix to Prefix",
"""Algorithm:
1. Reverse the infix expression.
2. Replace '(' with ')' and ')' with '('.
3. Convert the expression to postfix.
4. Reverse the postfix expression.
5. Result is prefix expression.

Pseudocode:
Algorithm InfixToPrefix(infix)

reverse(infix)

for each symbol in infix
    if '(' replace with ')'
    else if ')' replace with '('

postfix = InfixToPostfix(infix)

prefix = reverse(postfix)

return prefix
"""),

("3. Postfix to Infix",
"""Algorithm:
1. Create empty stack S.
2. Scan postfix expression left to right.
3. If operand → push to stack.
4. If operator:
   pop operand2
   pop operand1
   create (operand1 operator operand2)
   push result back to stack.
5. Final stack value is infix expression.

Pseudocode:
Algorithm PostfixToInfix(postfix)

Create empty stack S

for each symbol ch in postfix
    if ch is operand
        push(S, ch)
    else if ch is operator
        op2 = pop(S)
        op1 = pop(S)
        temp = "(" + op1 + ch + op2 + ")"
        push(S, temp)

return pop(S)
"""),

("4. Postfix to Prefix",
"""Algorithm:
1. Create empty stack.
2. Scan postfix expression left to right.
3. If operand → push.
4. If operator:
   pop operand2
   pop operand1
   form operator + operand1 + operand2
   push result.
5. Final stack element is prefix expression.

Pseudocode:
Algorithm PostfixToPrefix(postfix)

Create empty stack S

for each symbol ch in postfix
    if ch is operand
        push(S, ch)
    else if ch is operator
        op2 = pop(S)
        op1 = pop(S)
        temp = ch + op1 + op2
        push(S, temp)

return pop(S)
"""),

("5. Prefix to Infix",
"""Algorithm:
1. Create empty stack.
2. Scan prefix expression from right to left.
3. If operand → push.
4. If operator:
   pop operand1
   pop operand2
   create (operand1 operator operand2)
   push result.
5. Final stack element is infix.

Pseudocode:
Algorithm PrefixToInfix(prefix)

Create empty stack S

for each symbol ch in prefix from right to left
    if ch is operand
        push(S, ch)
    else if ch is operator
        op1 = pop(S)
        op2 = pop(S)
        temp = "(" + op1 + ch + op2 + ")"
        push(S, temp)

return pop(S)
"""),

("6. Prefix to Postfix",
"""Algorithm:
1. Create empty stack.
2. Scan prefix expression from right to left.
3. If operand → push.
4. If operator:
   pop operand1
   pop operand2
   create operand1 operand2 operator
   push result.
5. Final stack element is postfix.

Pseudocode:
Algorithm PrefixToPostfix(prefix)

Create empty stack S

for each symbol ch in prefix from right to left
    if ch is operand
        push(S, ch)
    else if ch is operator
        op1 = pop(S)
        op2 = pop(S)
        temp = op1 + op2 + ch
        push(S, temp)

return pop(S)
""")
]

for title_text, body in sections:
    content.append(Paragraph(title_text, styles['Heading2']))
    content.append(Spacer(1,8))
    content.append(Preformatted(body, styles['Code']))
    content.append(Spacer(1,20))

doc = SimpleDocTemplate(file_path, pagesize=A4)
doc.build(content)

file_path