text: str = """c(r)
igu(n,r,fin,n+2)
asi(t,1)
cop(n,j)
asi(1,r)
"""

text = text.splitlines()
for i,line in enumerate(text):
    print(f'n+{i}: {line}')