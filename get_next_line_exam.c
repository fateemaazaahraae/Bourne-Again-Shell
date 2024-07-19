/*  #include <stdio.h>
#include <string.h>
int main()
{
    char dest[10] = "hello ";
    char src[5] = "world";
    int i = strlcat(dest, src, 3);
    printf("%i --> %s\n", i, dest);
} */

#include <stdio.h>
#include <string.h>

int main() {
    char dest[10] = "hello ";
    char src[] = "world";
    
    size_t size = 10; // Total size of the destination buffer
    size_t result = strlcat(dest, src, size);
    
    printf("Result: %zu\n", result); // The length of the string they tried to create
    printf("Destination: '%s'\n", dest); // The final destination string
    
    return 0;
}
