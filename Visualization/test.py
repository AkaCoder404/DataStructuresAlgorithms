from BST import BinTree, BinNode, BinNodePosi

import networkx as nx
import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
import pydot
from networkx.drawing.nx_pydot import graphviz_layout

# T = nx.balanced_tree(2, 5)
# pos = graphviz_layout(T, prog="dot")
# nx.draw(T, pos)
# plt.show()

def display_tree(G,pos):
    nx.draw_networkx_nodes(G, pos, node_size=500, alpha=.9, node_color='#0000ac')
    nx.draw_networkx_edges(G, pos,width=2, alpha=0.5, edge_color='k')
    # nx.draw_networkx_edge_labels(G,pos,edge_labels=edgeLabels)
    nx.draw_networkx_labels(G, pos, font_size=10, font_family='sans-serif', font_color='white')
    # plt.ylim([-4.5,1.3])
    limits=plt.axis('off') # turn of axis   
    plt.show()
    plt.draw()

G = nx.Graph()
G.add_node('20')
G.add_node('15')
G.add_node('25')
G.add_node('13')
G.add_node('18')
G.add_node('21')
G.add_node('26')
G.add_node('17')
G.add_node('19')


G.add_edge('20', '15')
G.add_edge('20', '25')
G.add_edge('15', '13')
G.add_edge('15', '18')
G.add_edge('25', '21')
G.add_edge('25', '26')
G.add_edge('18', '17')
G.add_edge('18', '19')
pos = graphviz_layout(G, prog="dot")

count = 50
def onclick(event):
    global count
    if event.button == 1:
        print("onclick")
        G.add_node(count)
        G.add_edge('20', count)
        count = count + 1
    #clear frame
    plt.clf()
    pos = graphviz_layout(G, prog="dot")
    display_tree(G, pos)    

fig,ax=plt.subplots()
fig.canvas.mpl_connect('button_press_event',onclick)

display_tree(G, pos)


# def display_graph(G,pos,edgeLabels):
#     nx.draw_networkx_nodes(G, pos, node_size=800, alpha=.9, node_color='#0000ac')
#     nx.draw_networkx_edges(G, pos,width=2, alpha=0.5, edge_color='k')
#     nx.draw_networkx_edge_labels(G,pos,edge_labels=edgeLabels)
#     nx.draw_networkx_labels(G, pos, font_size=18, font_family='sans-serif', font_color='white')
#     plt.ylim([-4.5,1.3])
#     limits=plt.axis('off') # turn of axis   
#     plt.show()

# G = nx.Graph()
# G.add_node('A')
# G.add_node('B')
# G.add_node('C')
# G.add_node('D')
# G.add_node('E')
# G.add_node('F')
# G.add_node('G')
# G.add_node('H')

# G.add_edge('A', 'B',weight=5)
# G.add_edge('A', 'E',weight=9)
# G.add_edge('A', 'H',weight=8)
# G.add_edge('B', 'C',weight=12)
# G.add_edge('B', 'D',weight=15)
# G.add_edge('B', 'H',weight=4)
# G.add_edge('C', 'D',weight=3)
# G.add_edge('C', 'F',weight=1)
# G.add_edge('C', 'G',weight=11)
# G.add_edge('C', 'H',weight=7)
# G.add_edge('D', 'G',weight=9)
# G.add_edge('E', 'F',weight=4)
# G.add_edge('E', 'G',weight=20)
# G.add_edge('E', 'H',weight=5)
# G.add_edge('F', 'G',weight=13)
# G.add_edge('F', 'H',weight=6)
# G.add_edge('F', 'H',weight=6)

# edgeLabels = nx.get_edge_attributes(G,'weight')

# pos= {'A': [-0.75, 0.4], 'B': [0,0.9], 'C': [0.5,-1.2], 'D': [0.75, 0.4], 'E': [-0.75, -3], 'F': [0, -2], 'G': [0.75, -3], 'H': [ -0.5,-1.2]}

# display_graph(G,pos,edgeLabels)




# binNode_left = BinNode(data=-1)
# binNode_right = BinNode(data=1)
# binNode_root = BinNode(left_child=binNode_left, right_child=binNode_right, data=0)
# binNode_left.parent = binNode_root
# binNode_right.parent = binNode_root


# print(binNode_left.data, "successor is", binNode_left.succ().data, "successor is", binNode_left.succ().succ().data)
# print(binNode_right.right_child)
# print(binNode_right.succ().data)
