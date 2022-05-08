import random

# random
def dice(*args):
  if len(args) == 1 and isinstance(args[0], int):  # int [0, range)
    return random.randint(0, args[0])
  elif len(args) == 2 and isinstance(args[0], int): # int [lo, hi)
    return args[0] + random.randint(0, args[1] - args[0])
  elif len(args) == 1 and isinstance(args[0], float):
    return random.randint(0, 1000 * int(args[0])) / float(1000.0)

