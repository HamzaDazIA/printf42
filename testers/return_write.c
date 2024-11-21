#include <unistd.h>
#include <libc.h>

int main() {
    char message[] = "Hello, World!\n";
    ssize_t bytes_written = write(1, message, 14); // Write to stdout

    // Check how many bytes (characters) were written
    if (bytes_written == -1) {
        write(2, "Write error occurred\n", 21); // Write error message to stderr
    } else {
        char result[] = "Characters printed: ";
        write(1, result, 21);
        char number[4]; // Buffer to hold the number of characters
        snprintf(number, 4, "%ld\n", bytes_written);
        write(1, number, 3); // Write the number of characters
    }
    return 0;
}
