# ----------------------------
# Makefile Options
# ----------------------------

NAME = MBROT
ICON = icon.png
DESCRIPTION = "Mandelbrot set generator"
COMPRESSED = NO
ARCHIVED = NO

CFLAGS = -Wall -Wextra -Oz
CXXFLAGS = -Wall -Wextra -Oz

# ----------------------------

include $(shell cedev-config --makefile)
