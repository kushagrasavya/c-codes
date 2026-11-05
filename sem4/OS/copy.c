#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *sourceFile, *destinationFile;
    char sourceFilename[100], destinationFilename[100];
    char c;

    // Prompt user to enter source filename
    printf("Enter the source filename with extension (e.g., source.txt): ");
    scanf("%s", sourceFilename);

    // Prompt user to enter destination filename
    printf("Enter the destination filename with extension (e.g., destination.txt): ");
    scanf("%s", destinationFilename);

    // Open source file for reading
    sourceFile = fopen(sourceFilename, "r"); //instead of sourceFilename use the actual nname
    if (sourceFile == NULL) {
        printf("Error opening source file!\n");
        exit(1);
    }

    // Open destination file for writing
    destinationFile = fopen(destinationFilename, "w");
    if (destinationFile == NULL) {
        printf("Error opening destination file!\n");
        fclose(sourceFile);
        exit(1);
    }

    // Copy contents from source file to destination file
    while ((c = fgetc(sourceFile)) != EOF) {
        fputc(c, destinationFile);
    }

    // Close both files
    fclose(sourceFile);
    fclose(destinationFile);

    printf("Contents copied from \"%s\" to \"%s\".\n", sourceFilename, destinationFilename);

    return 0;
}

