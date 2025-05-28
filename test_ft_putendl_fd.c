#include "test_libft.h"

void test_ft_putendl_fd(void)
{
    printf("Testing ft_putendl_fd:\n");
    int failed = 0;

    // Setup a temporary file for testing
    char temp_filename[] = "temp_putendl_test.txt";
    int fd;
    char buffer[100];
    ssize_t bytes_read;

    // Test 1: Write a regular string with newline to file
    fd = open(temp_filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        printf("  FAIL: Could not open test file\n");
        failed++;
    } else {
        ft_putendl_fd("Hello, World!", fd);
        close(fd);

        fd = open(temp_filename, O_RDONLY);
        bytes_read = read(fd, buffer, sizeof(buffer));
        buffer[bytes_read] = '\0';  // Null-terminate the buffer
        close(fd);

        if (strcmp(buffer, "Hello, World!\n") != 0) {
            printf("  FAIL: Writing string with newline\n");
            printf("    Expected: 'Hello, World!\\n', Got: '%s'\n", buffer);
            failed++;
        }
    }

    // Test 2: Write an empty string with newline to file
    fd = open(temp_filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        printf("  FAIL: Could not open test file\n");
        failed++;
    } else {
        ft_putendl_fd("", fd);
        close(fd);

        fd = open(temp_filename, O_RDONLY);
        bytes_read = read(fd, buffer, sizeof(buffer));
        buffer[bytes_read] = '\0';  // Null-terminate the buffer
        close(fd);

        if (strcmp(buffer, "\n") != 0) {
            printf("  FAIL: Writing empty string with newline\n");
            printf("    Expected: '\\n', Got: '%s'\n", buffer);
            failed++;
        }
    }

    // Test 3: Test with NULL string (should do nothing)
    fd = open(temp_filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        printf("  FAIL: Could not open test file\n");
        failed++;
    } else {
        // Write something to the file first
        write(fd, "Test", 4);
        close(fd);

        // Reopen file in truncate mode to clear it
        fd = open(temp_filename, O_WRONLY | O_TRUNC);
        // Call function with NULL
        ft_putendl_fd(NULL, fd);
        close(fd);

        fd = open(temp_filename, O_RDONLY);
        bytes_read = read(fd, buffer, sizeof(buffer));
        buffer[bytes_read] = '\0';  // Null-terminate the buffer
        close(fd);

        if (bytes_read != 0) {
            printf("  FAIL: NULL string test\n");
            printf("    Expected: '', Got: '%s'\n", buffer);
            failed++;
        }
    }

    // Test 4: Write to standard output (this is a visual test)
    ft_putendl_fd("Test output", 1);
    printf("  Did you see 'Test output' on its own line? If not, the test failed.\n");
    // Note: We can't automatically verify this test

    // Clean up
    unlink(temp_filename);

    // Print test results
    if (failed == 0)
        printf("  All automated tests passed! (Check visual test manually)\n\n");
    else
        printf("  %d tests failed!\n\n", failed);
}
