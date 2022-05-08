# gui for bst 

import tkinter as tk
from tkinter import Frame, Tk
from matplotlib.axes import Axes

import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import (FigureCanvasTkAgg, NavigationToolbar2Tk)
from matplotlib.backend_bases import MouseEvent
from matplotlib.figure import Figure


import pandas as pd
import numpy as np
import pydot
import sys

import networkx as nx 
from networkx import Graph
from networkx.drawing.nx_pydot import graphviz_layout

from BST import BinTree


class BSTUI(object):
  _window : Tk = Tk()
  # _nx : nx = nx
  _graph : Graph = Graph()
  _fig : Figure
  _ax : Axes
  _canvas : FigureCanvasTkAgg
  _search : int = 0
  _remove : int = 0
  _insert : int = 0
  _selected_node = 0
  _count : int = 0
  _count_graph : int = 0

  def __init__(self) -> None:
    self._geometry()  # set dimensions
    self._title() # set title
    self._controls() # set buttons and input

    self._graph_setup()

    self._fig.canvas.mpl_connect('button_press_event', self._onclick)
    # self._ax.add_subplot(111)
  
    self._test_setup() # setup graph with example nodes
    # run 
    self._window.mainloop()

  def _geometry(self) -> None:
    self._window.geometry("800x450")

  def _title(self) -> None:
    self._window.title("Binary Search Tree")


  def _destroy(self) -> None:
    self._window.quit()
    self._window.destroy()

  def _graph_setup(self) -> None:
    self._fig = Figure(figsize = (5, 5), dpi = 100)
    self._ax = self._fig.add_subplot(111)
    self._ax.axis("off")
    # creating the Tkinter canvas containing matplotlib figure
    self._canvas = FigureCanvasTkAgg(self._fig, self._window)
    self._canvas.draw()
    # placeing the canvas on the tkinter window 
    self._canvas.get_tk_widget().pack()

    # creating the matplotlib toolbar
    # toolbar = NavigationToolbar2Tk(self._canvas, self._window)
    # toolbar.update()

    # placing the toolbar on the tkinter window
    self._canvas.get_tk_widget().pack()
    

  def _controls(self) -> None:
    # destroy
    self._window.protocol("WM_DELETE_WINDOW", self._destroy)

    # buttons
    top = tk.Frame(self._window)
    bottom = tk.Frame(self._window)
    top.pack(side=tk.BOTTOM)
    bottom.pack(side=tk.BOTTOM, fill=tk.BOTH, expand=True)

    # create the widgets for the bottom part of the GUI
    btn_generate_tree = tk.Button(self._window, text='Generate', width = 10, height = 1, command=self._generate_tree)
    # btn_add_node = tk.Button(self.window, text='Add', width = 10, height = 1)
    btn_insert_node = tk.Button(self._window, text='Insert', width = 10, height = 1, command=self._insert_node)
    btn_remove_node = tk.Button(self._window, text='Remove', width = 10, height = 1, command=self._remove_node)
    btn_search_node = tk.Button(self._window, text='Search', width = 10, height = 1, command=self._search_node)

    

    # lay widgets out 
    btn_generate_tree.pack(in_=top, side=tk.LEFT)
    # btn_add_node.pack(in_=top, side=tk.LEFT)
    btn_remove_node.pack(in_=top, side=tk.LEFT)
    btn_insert_node.pack(in_=top, side=tk.LEFT)
    btn_search_node.pack(in_=top, side=tk.LEFT)

  
     
   # button commands
  def _generate_tree(self):
    print("generating tree", self._count)
    self._count = self._count + 1

  def _insert_node(self):
    """ """
    print("inserting node")

  def _remove_node(self):
    """ """
    print("removing node")

  def _search_node(self):
    """ """
    print("seraching node")
  
  # tree functions
  def _display_tree(self, graph, pos) -> None:
    self._ax.clear()
    self._ax.axis("off")
    nx.draw_networkx_nodes(graph, pos, node_size=300, alpha=.9, node_color='#0000ac', ax=self._ax)
    nx.draw_networkx_edges(graph, pos,width=2, alpha=0.5, edge_color='k', ax=self._ax)
    # nx.draw_networkx_edge_labels(G,pos,edge_labels=edgeLabels)
    nx.draw_networkx_labels(graph, pos, font_size=9, font_family='sans-serif', font_color='white', ax=self._ax)
    # plt.ylim([-4.5,1.3])
    limits = plt.axis('off') # turn of axis   

    # redraw canvas
    self._canvas.draw()

  def _onclick(self, event: MouseEvent):
    if event.button == 1:
      print("onclick")
      self._graph.add_node(self._count)
      self._graph.add_edge('20', self._count)
      self._count = self._count + 1
    #clear frame
    plt.clf()
    pos = graphviz_layout(self._graph, prog="dot") # recalculate pos
    self._display_tree(self._graph, pos)    

  def _test_setup(self) -> None:
    self._graph.add_node('20')
    self._graph.add_node('15')
    self._graph.add_node('25')
    self._graph.add_node('13')
    self._graph.add_node('18')
    self._graph.add_node('21')
    self._graph.add_node('26')
    self._graph.add_node('17')
    self._graph.add_node('19')

    self._graph.add_edge('20', '15')
    self._graph.add_edge('20', '25')
    self._graph.add_edge('15', '13')
    self._graph.add_edge('15', '18')
    self._graph.add_edge('25', '21')
    self._graph.add_edge('25', '26')
    self._graph.add_edge('18', '17')
    self._graph.add_edge('18', '19')

    pos = graphviz_layout(self._graph, prog="dot")
    self._display_tree(self._graph, pos)

ui = BSTUI()
