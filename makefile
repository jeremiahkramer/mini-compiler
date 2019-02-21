CC = gcc
exe_file = driver
$(exe_file): list.c driver.c
	$(CC) -g list.c driver.c -o driver
