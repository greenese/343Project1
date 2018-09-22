#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int read_file( char* filename, char **buffer ) {
    //Points to the correct file to be read
    FILE *input = fopen(filename, "r");

    //Throws error if input file does not open
    if (input == NULL){
        fprintf( stderr, "Cannot open input file" );
    }

    //Finds size of input file
    struct stat st;
    stat(filename, &st);
    int bSize = st.st_size;

    //Saves appropriate amount of memory based on size of input file
    *buffer = malloc(bSize);

    //Reads data from file into buffer
    fread(*buffer, bSize, 1, input);

    //Frees pointer
    fclose(input);

    return bSize;
}



int write_file( char* filename, char *buffer, int size){
    //Points to the correct file to be written to
    FILE *output = fopen(filename, "w");

    //Throws error if output file does not open
    if (output == NULL){
        fprintf( stderr, "Cannot open output file" );
    }

    //Throws error if buffer did not retain allocated memory
    if (buffer == NULL){
        fprintf( stderr, "Buffer did not save" );
    }

    //Writes data from buffer into file
    fwrite(buffer, 1, size, output);

    //Frees pointer
    fclose(output);

	return 0;
}
