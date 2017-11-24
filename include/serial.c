#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include "serial.h"

// int main(int argc, char const *argv[]){
// 	serial_com tty;
// 	serial_open(&tty, "/dev/cu.usbmodem1411");
// 	ssize_t bytes_read;
// 	ssize_t t;
// 	do{
// 		//bytes_read = serial_read(&tty);
// 		t = serial_simple_write(&tty, 'b');
// 	}while (bytes_read != 0 || t !=0);

// 	// while(1){
// 	// 	serial_open(&tty, "/dev/cu.usbmodem1421");
// 	// 	serial_write(&tty, "bonjour");
// 	// 	waitFor(1);
// 	// 	serial_close(&tty);
// 	// }
// 	//serial_write(&tty, "h");
// 	serial_close(&tty);
// 	return 0;
// }

void serial_open(serial_com* sp, const char* name){
	sp->serial_name = name;
	sp->file_desc = open(name, O_RDWR);
}

void serial_close(serial_com* sp){
	close(sp->file_desc);
	sp = NULL;
}

ssize_t serial_read(serial_com* sp){
	char buf;
	ssize_t read_bytes = read(sp->file_desc, &buf, sizeof(buf));
	if (buf == '<'){
		buf = 0;
		while(buf != '>'){
			printf("%c", buf);
			read_bytes = read(sp->file_desc, &buf, sizeof(buf));
		}
		printf("\n");
		return read_bytes;
	}
	else
		return read_bytes;
}

ssize_t serial_write(serial_com* sp, char* message){
	char open = '<', close = '>';
	int i, len = sizeof(message)/sizeof(char) - 1;
	printf("%d\n", len);
	ssize_t wx = write(sp->file_desc, &open, sizeof(char));
	printf("<");
	for (int i = 0; i < len; i++){
		wx = write(sp->file_desc, &message[i], sizeof(char));
		printf("%c", message[i]);
	}
	wx = write(sp->file_desc, &close, sizeof(char));
	printf(">\n");
	return wx;
}

ssize_t serial_simple_write(serial_com *sp, char c){
	char car = c;
	return write(sp->file_desc, &car, sizeof(char));
}

void waitFor (unsigned int secs) {
    unsigned int retTime = time(0) + secs;
    while (time(0) < retTime);
}