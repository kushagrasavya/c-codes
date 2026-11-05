#include<stdio.h>
#include<string.h>
int main() {
    FILE *curr_file, *new_file; int len;
    printf("enter length of the string: ");
    scanf("%d", &len);
    char line[len];
     curr_file = fopen("original.txt", "r");
      if (curr_file == NULL) {
        printf("Unable to open the original file.\n");
        return 1;
    }   
}