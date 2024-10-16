n = int(input())
s = input()

school = ["SMU","SHOU","SUEP","SDJU","SJQU"]

for name in school:
    ok = True
    for char in name:
        if char not in s:
            ok = False
            break
    if ok:
        print(name)
        exit(0)
print("IMPOSSIBLE")