def fun_r(r, n, mod):
    if n == 1:
        return r % mod
    t = fun_r(r, n // 2, mod) % mod
    if n % 2 == 0:
        return t * t % mod
    else:
        return (t * t * r) % mod

def fun_sn(r, n, mod):
    if n == 1:
        return 1
    if n % 2 == 0:
        return ((fun_sn(r, n // 2, mod) % mod) * ((fun_r(r, n // 2, mod) + 1) % mod)) % mod
    else:
        return (fun_sn(r, n - 1, mod) % mod + fun_r(r, n - 1, mod) % mod) % mod

a, r, n, mod = map(int, input().split())
result = ((a % mod) * fun_sn(r, n, mod)) % mod
print(result)
