import os
import subprocess
l=[]
if os.system("g++ -fopenmp parallel_version.cpp -o out") == 0:
    # print(os.system("g++ -fopenmp parallel_version.cpp -o out"))
    for i in range(100):
        a=str(subprocess.check_output("./out",shell=True))[2:]
        print(a)
        l.append(float(str(a)[:-1]))
else:
    print ("Failed")
print(l)
import xlsxwriter
workbook=xlsxwriter.Workbook("Ass.xlsx")
x=workbook.add_worksheet()
for i in range(len(l)):
    x.write(i,0,i+1)
    x.write(i,1,l[i])
workbook.close()
