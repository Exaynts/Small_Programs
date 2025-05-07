f = open("input.txt", 'r')
l = [line.split() for line in f]
n = int(l[0][0])
m = int(l[0][1])
k = int(l[0][2])
exits = []
for i in range(len(l[1])):
    exits += [int(l[1][i])]
f.close()

plan = []
cell = 1
load = 0
while (cell <= n):
    if not exits:
        add1 = k-load+1
    else:
         add1 = min(exits[0]-cell, k-load+1)
    plan += add1*['R']
    cell += add1
    load += add1
    if (load > k):
        plan = ['NO']
        break
    else:
        plan += ['X']
        exits.pop(0)
        cell += 1
        load += 1
    if not exits:
        add2 = k-load+1
    else :
        add2 = min(exits[0]-cell, k-load+1)
    plan += add2*['L']
    cell += add2
    load += add2
    if (load > k):
        load = 0
    else:
        plan += ['X']
        exits.pop(0)  
        cell += 1
        load += 1
ans = ''
for i in range(len(ans)):
    ans += str(plan[i])
print(ans)
