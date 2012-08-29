PROJ_NAME = mand
CC = gcc
VECTFLAGS = -ftree-vectorize -ffast-math -fsingle-precision-constant
CFLAGS = -Wall -O3 -g -march=armv7-a -mcpu=cortex-a8  -mfloat-abi=softfp  -mfpu=neon $(VECTFLAGS)
LIBS = -lm
OBJFILES := $(patsubst %.c,%.o,$(wildcard *.c))
$(PROJ_NAME): $(OBJFILES) 
	echo $(OBJFILES)
	$(CC) -o $(PROJ_NAME) $(OBJFILES) $(LIBS)
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<
%.lst: %.c
	$(CC) $(CFLAGS) -Wa,-adhln $(LIBS) $< > $@
clean:
	rm -f *.o *.lst