#!/usr/bin/env python2
# -*- coding: utf-8 -*-
import networkx as nx
import numpy as np

G = nx.DiGraph()
# Adiciona nos de oferta
G.add_node(1, demand=-35)
G.add_node(2, demand=-42)
G.add_node(3, demand=-23)
# Adiciona nos de demanda
G.add_node(4, demand=20)
G.add_node(5, demand=10)
G.add_node(6, demand=40)
G.add_node(7, demand=30)
# Adiciona os arcos
G.add_edge(1, 4, weight=5)
G.add_edge(2, 4, weight=3)
G.add_edge(3, 4, weight=4)
# ###################################
G.add_edge(1, 5, weight=6)
G.add_edge(2, 5, weight=6)
G.add_edge(3, 5, weight=1)
# ###################################
G.add_edge(1, 6, weight=2)
G.add_edge(2, 6, weight=8)
G.add_edge(3, 6, weight=9)
# ####################################
G.add_edge(1, 7, weight=4)
G.add_edge(2, 7, weight=2)
G.add_edge(3, 7, weight=10)
flowCost, flowDict = nx.network_simplex(G)
print flowCost
# print flowDict
k,w = 0,0
mat = np.zeros([3,4])
cost = np.zeros([3,4])
total = 0
for i in flowDict:
    #print "i:%d\n"%i
    w = 0
    for j in flowDict[i]:
        # print flowDict[i][j],
        mat[k,w] = flowDict[i][j]
        cost[k,w] = G[i][j]["weight"]
        w += 1
        total += flowDict[i][j]*G[i][j]["weight"]
    k += 1
    #print "\n"
print mat
print cost
print total
