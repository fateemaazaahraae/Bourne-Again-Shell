#include <stdio.h>
#include <string.h>

int main() {
    char dest[20] = "Hello, ";
    char src[] = "";
    strcpy(src, dest);  // Appends first 3 characters of src to dest

    printf("%s\n", src );   // Output: Hello, Wor
    return 0;
}
