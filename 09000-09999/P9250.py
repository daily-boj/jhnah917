import copy

class Node:
    def __init__(self):
        self.string = None
        self.terminal = -1
        self.ch = {}
        self.fail = None
        self.out = []

nd = [] # node pool

def aho_init():
    nd.clear()
    nd.append(Node())

def aho_insert(s, num, idx=0, root=0):
    nd[root].string = s[0:idx]
    if(idx == len(s)):
        nd[root].terminal = num
        return
    id = ord(s[idx])
    if id not in nd[root].ch:
        nd[root].ch[id] = len(nd)
        nd.append(Node())
    aho_insert(s, num, idx+1, nd[root].ch[id])

def aho_getfail(root=0):
    q = []
    pv = 0
    nd[root].fail = root
    q.append(root)
    while pv < len(q):
        now = q[pv]
        pv += 1
        for i in nd[now].ch:
            child = nd[now].ch[i]
            if root == now: nd[child].fail = root
            else:
                t = nd[now].fail
                while t != root and i not in nd[t].ch: t = nd[t].fail
                if i in nd[t].ch: t = nd[t].ch[i]
                nd[child].fail = t
            nd[child].out = copy.deepcopy(nd[nd[child].fail].out)
            if nd[child].terminal != -1:
                nd[child].out.append(nd[child].terminal)
            q.append(child)

def aho_find(s, root=0):
    ret = []
    state = root
    for i in range(0, len(s)):
        while state != root and ord(s[i]) not in nd[state].ch: state = nd[state].fail
        id = ord(s[i])
        if id in nd[state].ch: state = nd[state].ch[id]
        for j in nd[state].out:
            ret.append((i, j))
    return ret

aho_init()
words = []
n = int(input())
for i in range(n):
    s = input()
    words.append(s)
    aho_insert(words[i], i)
aho_getfail()
m = int(input())
for i in range(m):
    s = input()
    res = aho_find(s)
    if len(res) == 0:
        print("NO")
    else:
        print("YES")