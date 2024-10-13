#include <stdio.h>
#include <string.h>

int main(){
        FILE* fd = fopen("binary.bin","wb");
        char* text = "This is the string entered in the binary file.\n";
        size_t wrote = fwrite(text, sizeof(char), strlen(text) , fd);
        fputs("Created and written in a binary file.\n", stdout);
        fclose(fd);
        char buffer[100];
        FILE* fd2 = fopen("binary.bin", "rb");
        size_t bytesRead = fread(buffer, sizeof(char), sizeof(buffer) - 1, fd2);
        fprintf(stdout, "From binary file, we fetched %s.", buffer);

        return 0;

}

