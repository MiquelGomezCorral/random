simbols = {"a", "b","c"}
states = {"q1","q2","q3"}
print("PCA2 = "+"{"+str(simbols.union(states))+",{")

simbols = list(simbols)
states = list(states)

for i in states:
    for j in states:
        for k in states:
            print("{"+i+","+j+","+k+","+j+"},")
            
for i in simbols:
    for j in simbols:
        for k in simbols:
            print("{"+i+","+j+","+k+","+j+"},")
            
for i in simbols:
    for n, j in enumerate(simbols):
        for k in states:
            print("{"+i+","+j+","+k+","+states[n**2 % len(states)]+"},")

for i in states:
    for n, j in enumerate(simbols):
        for k in simbols:
            print("{"+i+","+j+","+k+","+states[n**3 % len(states)]+"},")

for i in states:
    for n, j in enumerate(simbols):
        for k in states:
            print("{"+i+","+j+","+k+","+states[n**4 % len(states)]+"},")

for i in states:
    for n, j in enumerate(states):
        for k in simbols:
            print("{"+i+","+j+","+k+","+states[n**4 % len(states)]+"},")
for i in simbols:
    for n, j in enumerate(states):
        for k in states:
            print("{"+i+","+j+","+k+","+states[n**4 % len(states)]+"},")
            
            
print("},{"+states[0]+"}"+"}")