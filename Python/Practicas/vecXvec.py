#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon May  4 13:30:00 2020

@author: AntonioLagunasHernandez
"""

import os

os.system('clear')

def ejec_hilo(M, N, Q, ini, fin):
    for i in range(ini, fin):
        cij = float(0)
        for j in range(N.shape[0]):
            cij = M[i].dot(N[j])
            Q[i,j] = cij
    return