e,s,m = map(int,input().split())

def S(y,s):
    s_temp = s
    if y % 28 == s :
        return y
    elif y % 28 == 0 : 
        s_temp = 28
        if s_temp == s:
            return y
        else :
            return False
    else:
        return False

def M(y,m):
    m_temp = m
    if y % 19 == m :
        return y
    elif y % 19 == 0 : 
        m_temp = 19
        if m_temp == m:
            return y
        else :
            return False
    else:
        return False
    
for i in range(533):
    y = e + 15*i
    if S(y,s) == False or M(y,m) == False:
        continue
    elif S(y,s) == M(y,m):
        print(S(y,s))
        break