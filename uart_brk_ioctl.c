/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (c) 2012 - 2018 Microchip Technology Inc., and its subsidiaries.
 * All rights reserved.
 */

#include <stdlib.h>
#include <stdio.h>
#include <termios.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <unistd.h>

#define DEV_TTY_UART_PATH	"/dev/ttyS1"
int main(int argc, char *argv[])
{
	int fd, val;

	if (argc != 2) {
		printf("Invalid argument count [%d]\n", argc);
		return -EINVAL;
	}

	fd = open(DEV_TTY_UART_PATH, O_RDWR);
	if (!fd)
		return -EINVAL;

	val = atoi(argv[1]);
	if (val == 1) {
		printf("assert on %d\n", fd);
		ioctl(fd, TIOCCBRK, 0);
	} else if (val == 0){
		printf("deassert on %d\n", fd);
		ioctl(fd, TIOCSBRK, 0);
	} else{
		printf("Ignore invalid paramter, please pass 1 or 0\n");
	}

	close(fd);

	return 0;
}
