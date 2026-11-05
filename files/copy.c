#include <stdio.h>
int main(int argc, char *argv[])
{
FILE *fptr1, *fptr2;
int i;
char ch;
printf("Total number of argument passed: %d\n", argc);
//open source file in read mode
 // if error then exit 
 if( (fptr1 = fopen(argv[1], "r") ) == NULL ) {
        printf("Cannot open file: %s\n", argv[1]); return -1;
    }


// check if the destination file exists 
if( (fptr2 = fopen(argv[2], "r") ) != NULL) {
    printf("Warning: File %s already exists.\n", argv[2]); 
    printf("Press Y to overwrite. Or any other key to exit: "); 
    ch = getchar();
    // if user don't want to overwrite
    // then, exit 
    if(ch != 'Y' && ch != 'y'){
     printf("Terminating the copy process.\n");
     fclose(fptr1); fclose(fptr2); return -1;
    }
    else {
        fclose(fptr2); 
        fptr2 = fopen(argv[2], "w");
        }
    }

// if destination file doesn't exists 
// then, open destination file in write mode
 else {
    fptr2 = fopen(argv[2], "w");
    }

// copy the content of source to destination 
while( !feof(fptr1) ){
     ch = getc(fptr1); 
     if(ch != EOF) {
    putc(ch, fptr2);
    }
}
}