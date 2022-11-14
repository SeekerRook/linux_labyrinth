
#pip install random-word
from random_word import RandomWords
r=RandomWords()
s=""
cnt=0
for i in range(500):
    s+=r.get_random_word()
    s+=" "
    cnt+=1
    if(cnt==2):
        s+="\n"
        cnt=0
s+= "creppe NTUA_H4CK \n"
for i in range(500):
    s+=r.get_random_word()
    s+=" "
    if(cnt==2):
        s+="\n"
        cnt=0
print(s)