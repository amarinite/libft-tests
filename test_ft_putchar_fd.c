#include "test_libft.h"

void test_ft_putchar_fd(void)
{
    printf("Testing ft_putchar_fd:\n");
    int failed = 0;

    // Setup a temporary file for testing
    char temp_filename[] = "temp_putchar_test.txt";
    int fd;
    char buffer[10];
    ssize_t bytes_read;

    // Test 1: Write a regular character to file
    fd = open(temp_filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        printf("  FAIL: Could not open test file\n");
        failed++;
    } else {
        ft_putchar_fd('A', fd);
        close(fd);

        fd = open(temp_filename, O_RDONLY);
        bytes_read = read(fd, buffer, sizeof(buffer));
        close(fd);

        if (bytes_read != 1 || buffer[0] != 'A') {
            printf("  FAIL: Writing regular character 'A'\n");
            printf("    Expected: 'A', Got: '%.*s'\n", (int)bytes_read, buffer);
            failed++;
        }
    }

    // Test 2: Write a special character to file
    fd = open(temp_filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        printf("  FAIL: Could not open test file\n");
        failed++;
    } else {
        ft_putchar_fd('\n', fd);
        close(fd);

        fd = open(temp_filename, O_RDONLY);
        bytes_read = read(fd, buffer, sizeof(buffer));
        close(fd);

        if (bytes_read != 1 || buffer[0] != '\n') {
            printf("  FAIL: Writing newline character\n");
            printf("    Expected: newline, Got: '%.*s'\n", (int)bytes_read, buffer);
            failed++;
        }
    }

    // Test 3: Write to standard output (this is a visual test)
    ft_putchar_fd('X', 1);
    printf("\n");
    printf("  Did you see 'X'? If not, the test failed.\n");
    // Note: We can't automatically verify this test

    // Clean up
    unlink(temp_filename);

    // Print test results
    if (failed == 0)
        printf("  All automated tests passed! (Check visual test manually)\n\n");
    else
        printf("  %d tests failed!\n\n", failed);
}
