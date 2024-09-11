# std.exe
# solve.py
# data.py
import subprocess
dpath="data.py"
t = 0
while True:
    t+=1
    result=subprocess.run(['python',dpath],capture_output=True)
    r1=subprocess.run("std.exe",input=result.stdout,capture_output=True)
    r2=subprocess.run(['python',"solve.py"],input=result.stdout,capture_output=True)
    if r1.stdout!=r2.stdout:
        with open("flog.txt","ab") as f:
            f.write(result.stdout)
        break
    else:
        print(f"AC in test {t}")