import sys

s = input()
probs = []

p = ""
for c in s:
    if c in "0123456789+*/-()":
        if c == "/":
            p+="//"
        else:
            p+=c
    else:
        if p != "":
            probs.append(p)
        p = ""

if p != "":
    probs.append(p)

for p in probs:
    print(eval(p))
