def argv(n):
    from sys import argv
    return argv[n]

def run(st):
    from os import system
    system(f"{st} > i")
    f = open("i",'r')
    system("rm i")
    return f.read()



