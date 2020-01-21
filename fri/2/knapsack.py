items = [(7, 4), (8, 5), (1, 1), (2, 3)]
cost = 6


items = sorted(items, key=lambda x:-x[0]/x[1])

def z(res):
    sum = 0
    for i in range(len(res)):
        sum += items[i][0] * res[i]

    return sum

# 実数可能解を調べる
print(items)

i = cost
tmp_ans = []
for item in items:
    if i >= item[1]:
        tmp_ans.append(1)
        i -= item[1]
    else:
        tmp_ans.append(0)

tmp_max = z(tmp_ans)

print(tmp_ans)
print(tmp_max)

free_vars = list(map(lambda item: item[0], sorted([(i, items[i][1]) for i in range(len(items))], key=lambda item:-item[1])))
print(free_vars)

seek_nodes = []



seek_nodes.append(([free_vars[0]], [], free_vars[1:]))
seek_nodes.append(([], [free_vars[0]], free_vars[1:]))
