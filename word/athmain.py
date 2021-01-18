with open("ath.in","r") as f:
    lines = f.read().split("\n")
    N, K = lines[0].split(" ")
    N,K = int(N), int(K)
    l = 0
    with open("ath.out","a") as o:
        for i in lines[1].split(" "):
            if l+len(i) > K:
                o.write(f"\n{i}")
                l = len(i)
            else:
                o.write(i+" ")
                l += len(i)


    
    