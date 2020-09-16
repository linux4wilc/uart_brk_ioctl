CROSS_COMPILE := arm-linux-gnueabi-

CC	:= $(CROSS_COMPILE)gcc

CFLAGS	:= -Wall -std=gnu11

SRC	:= uart_brk_ioctl.c
OBJ	:= $(SRC:.c=.o)

PROG	:= uart_brk_ioctl

all: $(PROG)

$(PROG): $(OBJ)
	$(CC) -static $^ -o $@

clean:
	$(RM) $(PROG) $(OBJ)
