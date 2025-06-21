import numpy as np

dim1 = 200
dim2 = 100

n = 1_000_0
total = 0
for seed in range(n):
    np.random.seed(seed)
    # Page rank
    M = np.random.uniform((dim1,dim2))

    V1 = np.random.uniform((dim1,1))
    V2 = np.random.uniform((dim1,1))

    d1 = np.linalg.norm(V1-V2)
    
    V1s = M @ V1
    V2s = M @ V2
    d2 = np.linalg.norm(V1s-V2s)

    diff = abs(d1 - d2)
    total += diff
    print(f"{seed}: {d1 = :.4f}, {d2 = :.4f} -> {diff = :0.4f}")


print(f"\nmean = {total/n:.4f}")
