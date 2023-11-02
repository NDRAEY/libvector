SRC = src/vector.c
OBJS = $(SRC:%.c=%.o)
OUT = libvector.a

CFLAGS ?= -Wall -Wextra -ggdb3 -O0

all: $(OUT)

$(OUT): $(OBJS)
	ar rs $(OUT) $(OBJS)

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) $< -c -o $@

clean:
	-rm $(OBJS)
	-rm $(OUT)

example: $(OUT)
	$(CC) example.c $(CFLAGS) $(OUT) -o test
