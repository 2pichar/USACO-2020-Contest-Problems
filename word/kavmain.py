import sys

with open("kav.in", "r") as out:
    f = out.read().split("\n")
    g, m = f[0].split(" ")
    g,m = int(g),int(m)
    with open("kav.out", "w") as lout:
        l = 0
        for s in f[1].split():
            if l + len(s) > m:
                fout.write("\n" + s)
                l = len(s)
            else:
                if l > 0:
                    lout.write(" ")
                lout.write(s)
                l += len(s)
        lout.write("\n")
