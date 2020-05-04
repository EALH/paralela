import numpy as np
from threading import  Thread as Th
import math as m


def  jaco(V1,b,x0,xn,k):
	xn=b-V1.dot(x0)
	x0[k]=xn
	print(x0)
	return 

def lanza_jaco(A,B,X0,Xn):
	threads = []
	for j in range(4):
		t = Th(target=jaco, args=(A[j],B[j],X0,Xn[j],j))
		threads.append(t)
		t.start()
		t.join()


if __name__=="__main__":
	pass


