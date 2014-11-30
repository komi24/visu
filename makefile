CC = g++

ARCH = $(shell getconf LONG_BIT)
ifeq ($(ARCH), 32)
  LIBPATH = ./libxl/lib
else
  LIBPATH = ./libxl/lib64
endif


CFLAGS = -I ./libxl/include_cpp -L $(LIBPATH) -lxl -Wl,-rpath,$(LIBPATH)

all: main

main: main.cpp
	$(CC) -o main main.cpp $(CFLAGS)

clean:
	rm main

