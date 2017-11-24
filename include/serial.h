#include <stdio.h>
#include <stdlib.h>

typedef struct serial_com{
	char* serial_name;
	int file_desc;
}serial_com;

void serial_open(serial_com* sp, const char* name);
void serial_close(serial_com* sp);
ssize_t serial_read(serial_com* sp);
ssize_t serial_write(serial_com* sp, char* message);
ssize_t serial_simple_write(serial_com *sp, char c);
void waitFor (unsigned int secs);