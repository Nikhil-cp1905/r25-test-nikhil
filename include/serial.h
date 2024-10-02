#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdarg.h>
#include <stdint.h>
FILE* open_file(const char* portname, char* mode);
void read_SBUS(uint8_t* buffer, size_t size, size_t n, FILE* fd);
void write_to_SB(FILE* fd, char* fmt, ...); 
void close_file(FILE* fd);
