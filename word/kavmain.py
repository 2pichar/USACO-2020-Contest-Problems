import sys;
with open("kav.in","r") as out:
  f = out.read().split("\n")
  g,m = map(f[0].split())
  with open("kav.out","w") as lout:
    l = 0
    for s in f[1].split():
      if l+len(s) > z:
        fout.write("\n"+ s)
        l = len(s)
    else: 
      if l > 0:
        lout.write(" ")
      lout.write(s)
      l += len(s)
    lout.write("\n")
