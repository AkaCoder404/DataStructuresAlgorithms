import sys
import math

sys.path.append('../')
from Implementations.List import List
import pygame 
import random

class ListDrawInformation():
  # define colors
  BLACK = 0, 0, 0
  WHITE = 255, 255, 255
  GREEN = 0, 255, 0
  RED = 255, 0, 0
  GREY = 128, 128, 128
  BACKGROUND_COLOR = WHITE

  window_width = 0
  window_height = 0
  window : pygame.Surface 
  window_side_pad = 100
  window_top_pad = 150
  block_width = 0
  block_height = 0
  start_x = 0

  # game
  game : pygame = pygame
  # list 
  lst : 'List[int]' 
  min_value = 0
  max_value = 0

  font_type = ""
  FONT = ""
  LARGE_FONT =  ""

  running = True
  sorting = False
  sorting_algorithm_name = "insertion"
  sorting_algorithm_generator = None

  def __init__(self) -> None:
    self.window_width = 800
    self.window_height = 600
    self.game.init()

    self.font_type = self.game.font.get_default_font()
    self.FONT = self.game.font.SysFont(self.font_type, 30)
    self.LARGE_FONT = self.game.font.SysFont(self.font_type, 40)

    # create window
    self.window = self.game.display.set_mode((self.window_width, self.window_height))

    # create caption
    self.game.display.set_caption("Sorting List DS Visualizer")

    # set list
    self.generate_list()
    self.set_list()
    self.sorting_algorithm_generator = self.lst.insertionSortGenerator()
    print(self.sorting_algorithm_generator)

    # game loop
    self.run()

  def set_list(self) -> None:
    self.min_value = self.lst.selectMin()._data # get min value for scaling
    self.max_value = self.lst.selectMax()._data # get max value for scaling
    
    # block width relative to size of list
    self.block_width = round((self.window_width - self.window_side_pad) / self.lst.size())
    self.block_height = math.floor((self.window_height - self.window_top_pad) / (self.max_value - self.min_value) * .8)
    self.start_x = self.window_side_pad // 2

    # set new generator
    if self.sorting_algorithm_name == "insertion":
      self.sorting_algorithm_generator = self.lst.insertionSortGenerator()
    elif self.sorting_algorithm_name == "selection":
      self.sorting_algorithm_generator = self.lst.selectionSortGenerator()
    elif self.sorting_algorithm_name == "radix":
      self.sorting_algorithm_generatior = self.lst.radixSortGenerator()

  def generate_list(self) -> None:
    # generate list data structure
    min_value = 1
    max_value = 100
    value_range = 100
    test = List[int]()
    randomList = []
    for i in range(0, value_range):
      n = random.randint(min_value, max_value)
      randomList.append(n)

    for e in randomList:
      test.insertAsLast(e)
    
    self.lst = test
    self.set_list()
  
  def draw(self) -> None:
    self.window.fill(self.BLACK)

    display = self.LARGE_FONT.render(f"{self.sorting_algorithm_name} sort for List Data Structure", 1 , self.WHITE)
    self.window.blit(display, (10, 5))

    controls = self.FONT.render("R - Reset | SPACE - Sort", 1, self.WHITE)
    self.window.blit(controls, (10 , 30))

    sorting = self.FONT.render("I - Insertion Sort | S - Selection Sort | X - Radix Sort | M - Merge Sort", 1, self.WHITE)
    self.window.blit(sorting, (10, 50))
    self.draw_list()
    self.game.display.update()

  def draw_list(self, clear_bg=False) -> None: 
    if clear_bg:
      clear_rect = (self.window_side_pad // 2, self.window_top_pad, self.window_width - self.window_side_pad, self.window_height - self.window_top_pad)
      self.game.draw.rect(self.window, self.BLACK, clear_rect)

    currentNode = self.lst.first()
    # shift 
    i = 0
    while currentNode != self.lst._trailer:
      x = self.start_x + i * self.block_width
      y = self.window_height - (currentNode._data - self.min_value) * self.block_height
      self.game.draw.rect(self.window, self.WHITE, (x, y, self.block_width, self.window_height)) 
      currentNode = currentNode._succ
      i = i + 1

    if clear_bg:
      self.game.display.update()
  
  def run(self) -> None:
    clock = self.game.time.Clock()
    self.draw()

    while self.running:
      clock.tick(10)

      self.game.display.update()

      if self.sorting:
        try: 
          next(self.sorting_algorithm_generator)
          self.draw_list(clear_bg=True)
        except StopIteration:
          self.sorting = False
        except Exception as e:
          self.sorting = False
      else: 
        self.draw()
        
      for event in pygame.event.get():
        if event.type == pygame.QUIT: # exit game loop
          self.running = False

        if event.type != self.game.KEYDOWN:
          continue

        if event.key == self.game.K_r: # reset list
          # generate new list
          self.generate_list()
          self.sorting = False
        
        elif event.key == self.game.K_SPACE and self.sorting == False: # start sort if not already sorting
          self.sorting = True
    
        elif event.key == self.game.K_i and self.sorting == False:
          self.sorting_algorithm_name = "insertion"
          self.sorting_algorithm_generator = self.lst.insertionSortGenerator() 
          
        elif event.key == self.game.K_s and self.sorting == False:
          self.sorting_algorithm_name = "selection"
          self.sorting_algorithm_generator = self.lst.selectionSortGenerator() 

        elif event.key == self.game.K_x and self.sorting == False:
          self.sorting_algorithm_name = "radix"
          self.sorting_algorithm_generator = self.lst.radixSortGenerator()

run = ListDrawInformation()