import random
fo = open("test.txt", "w")
mm=100
a=[]
b=[]
for x in range(1,mm):
  for y in range(1,mm):
     if x+y<mm:
       a.append(str(x)+'\t+\t'+str(y)+' = \t;\t')
     if x>y:
       a.append(str(x)+'\t-\t'+str(y)+' = \t;\t')
 
random.shuffle(a)

lin = 0
for e in a:
   fo.write(e)
   lin+=1
   if lin==2:
     lin=0
     fo.write('\r\n')

fo.close()


