import scipy as sp
import numpy as np
import pygame
from pygame.locals import *


class Object(pygame.sprite.Sprite):
    def __init__(self, x: int, y: int, m: float):
        super.__init__(self)
        self.__x, self.__y, self.m = x, y, m
        