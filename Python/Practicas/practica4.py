#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon May  4 12:45:10 2020

@author: AntonioLagunasHernandez
"""

import numpy as np
from threading import Thread as th
import os

def mxv(M, v1):
    v2 = M.dot(v1)
    return v2
def jaco(v1, v2, v3, k):
    v3[k] = v1[k] - v2[k]

def lanzaJaco(V1, V2, V3):
    threads = []
    for j in range(4):
        t = th(target = jaco, args = (V1, V2, V3, j))
        threads.append(t)
        t.start()
        t.join()
    return V3

A = np.array([[0, 3/21, 9/21, 5/21], [6/26, 0, -8/26, 2/26], [2/13, 4/13, 0, -1/13], [-3/15, -5/15, -2/15, 0]], dtype = float)
M = np.array([[21, 3, 9, 5], [6, 26, -8, 2], [2, 4, 13, -1], [-3, -5, -2, 15]], dtype = float)
X0 = np.zeros((4), dtype = float)
Xn = np.zeros((4), dtype = float)
X = np.zeros((4), dtype = float)
Val = np.zeros((4), dtype = float)
X1 = np.zeros((4), dtype = float)

if __name__ == '__main__':
    os.system("clear")
    A = A
    B = np.array([152/21, 315/26, -124/13, 162/15], dtype = float)
    b = np.array([152, 315, -124, 162], dtype = float)
    B = B
    print(A)
    print(B)
    
    it = int(15)
    for i in range(it):
        X = mxv(A,X0)
        X1 = lanzaJaco(B, X, Xn)
        print(X1)
        X0 = X1
        
    print("solición: ", X0)
    Ax = M.dot(X0)
    print("Producto Ax: ", Ax)
    Val = b - Ax
    print("Verificación (b - Ax): ", Val)
    
    
    
    
