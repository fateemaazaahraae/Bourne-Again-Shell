#include <stdio.h>
#include <string.h>

int main() {
    char dest[20] = "Hello, ";
    char src[] = "World!";
    strncat(dest, src, 3);  // Appends first 3 characters of src to dest

    printf("%s\n", dest);   // Output: Hello, Wor
    return 0;
}
