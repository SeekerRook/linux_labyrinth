from os import system

system ("diff wrong correct > i")
f = open ('i','r')
system("rm i")

if f.read() == "":
    print ("The files are the same")
    print("The flag is : \n L1nux")
else :
    print("the files are not the same")
