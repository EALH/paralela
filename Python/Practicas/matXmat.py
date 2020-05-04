#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon May  4 13:19:39 2020

@author: AntonioLagunasHernandez
"""

import numpy as np
from threading import Thread as th
import vecXvec as vv

if __name__ == '__main__':
    threads = []
    A = np.loadtxt('matA.dat', skiprows = 0, delimiter = None, dtype = float)
    B = np.loadtxt('matB.dat', skiprows = 0, delimiter = None, dtype = float)
    C = np.zeros((A.shape[0], B.shape[1]), dtype = float)
    Bt = B.T
    
    for i in range(4):
        ini = int(i * 25)
        fin = int(ini + 25)
        t = th(target = vv.ejec_hilo, args = (A, Bt, ini, fin))
        threads.append(t)
        t.start()
        t.join()
    print(C)