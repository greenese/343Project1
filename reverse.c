#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "file_utils.h"

int main(int argc,char *argv[]) {
    //Declares pointers
    char *a = argv[1];
	char *z = argv[2];
    char *b;

    //Sets variable equal to the return value of read_file()
    int size = read_file(a,&b);

    //Creates a new buffer with appropriate size
    char *c = malloc(size);

    //Iterates through buffer b backwards and assigns its values to buffer c forwards
    for(int i = 0; i < size ; i++){
        c[i] = b[size-i-1];
        printf("%c", c[i]);
    }

    //Writes contents of buffer c to output file
    write_file(z, c, size);

    //Frees buffers
    free(b);
    free(c);

    return 0;
}