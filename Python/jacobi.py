import numpy as np
from threading import  Thread as Th
import jacobi_aux as ja

if __name__== "__main__":
	threads = []
	A=np.array([[0,3/21,9/21,5/21],[6/26,0,-8/26,2/26],[2/13,4/13,0,-1/13],	[-3/15,-5/15,-2/15,0]],dtype=float)
	A=A
	B=np.array([152/21,315/26,-124/13,162/15],dtype=float)
	B=B
	print(A)
	print(B)
	print(B.shape)

	X0=np.zeros((4),dtype=float)
	Xn=np.zeros((4),dtype=float)
	
	print(X0.shape)
	
	print(Xn.shape)
	
	it=int(15)

	for i in range(it):
		ja.lanza_jaco(A,B,X0,Xn)
	
	print("Solucion: ",X0)
	AX=A.dot(X0)
	print("Producto Ax0: ",AX)
	Val=B-AX
	print("Verificacion: ", Val)


