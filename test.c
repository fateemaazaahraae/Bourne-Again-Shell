/* #include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>

int main(void) {
    DIR *dir;
    struct dirent *entry;

    // Open the directory
    dir = opendir("builtins");
    if (dir == NULL) {
        perror("opendir");
        return EXIT_FAILURE;
    }

    // Read entries in the directory
   entry = readdir(dir);
   entry = readdir(dir);
   entry = readdir(dir);

        printf("%lu\n", entry->d_ino);
        printf("%lu\n", entry->d_off);
        printf("g %hu\n", entry->d_reclen);
        printf("%c!\n", entry->d_type);
        printf("%s\n", entry->d_name);

    // Close the directory
    if (closedir(dir) != 0) {
        perror("closedir");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
} */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <limits.h>

void change_and_print_dir(const char *path) {
    char cwd[PATH_MAX];

    // Change the current working directory
    if (chdir(path) != 0) {
        perror("chdir");
        return;
    }

    // Get and print the current working directory
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Changed to directory: %s\n", cwd);
    } else {
        perror("getcwd");
    }
}

int main(void) {
    // Print the initial working directory
    change_and_print_dir(".");

    // Change to a relative directory
    change_and_print_dir("../");
    change_and_print_dir(".");

    // Change to an absolute directory
    change_and_print_dir("../");
    change_and_print_dir(".");


    return 0;



}


