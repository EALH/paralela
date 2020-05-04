import numpy as np
import matplotlib.pyplot as mp
import math
import os

def 	f0( d ) :
		y =pow( d, 3) - 3*pow(d , 2) -12
		return y
os.system("clear")
print('========================')
print('====Metodo de Biseccion=======')
print('========================')

a=float(input('De el extremo izquierdo del intervalo: '))
b=float(input('De el extremo derecho del intervalo: '))
it=int(input('De el numero de iteraciones: '))
k=int(1)
tol=float(pow(10,-5))
err=float(1.0)
fa=f0(a)
fb=f0(b)
print(fa)
print(fb)

if  fa * fb  > 0:
	print('En este intervalo no hay raiz')
else:
	print('Calculando la raiz')
	
	while  k < it  : 
		c=float((a+b)/2.0)
		print(k,a,b,c)
		fa=f0(a)
		fc=f0(c)
		if 	fa*fc > 0:
			a=c
		else:
			b=c
		err=abs(fc)
		k +=1		
	print("a raiz es:  ", c)
x=np.linspace(a-2,b+2,100) 
y1=pow( x, 3) - 3*pow(x , 2) -12
figure, ax=mp.subplots()
ax.plot(x,y1)
ax.grid()
mp.show()



