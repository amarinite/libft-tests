#include "test_libft.h"

void test_ft_putnbr_fd(void)
{
    printf("Testing ft_putnbr_fd:\n");
    int failed = 0;

    // Setup a temporary file for testing
    char temp_filename[] = "temp_putnbr_test.txt";
    int fd;
    char buffer[100];
    ssize_t bytes_read;

    // Test 1: Write a positive integer to file
    fd = open(temp_filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        printf("  FAIL: Could not open test file\n");
        failed++;
    } else {
        ft_putnbr_fd(12345, fd);
        close(fd);

        fd = open(temp_filename, O_RDONLY);
        bytes_read = read(fd, buffer, sizeof(buffer));
        buffer[bytes_read] = '\0';  // Null-terminate the buffer
        close(fd);

        if (strcmp(buffer, "12345") != 0) {
            printf("  FAIL: Writing positive integer\n");
            printf("    Expected: '12345', Got: '%s'\n", buffer);
            failed++;
        }
    }

    // Test 2: Write a negative integer to file
    fd = open(temp_filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        printf("  FAIL: Could not open test file\n");
        failed++;
    } else {
        ft_putnbr_fd(-9876, fd);
        close(fd);

        fd = open(temp_filename, O_RDONLY);
        bytes_read = read(fd, buffer, sizeof(buffer));
        buffer[bytes_read] = '\0';  // Null-terminate the buffer
        close(fd);

        if (strcmp(buffer, "-9876") != 0) {
            printf("  FAIL: Writing negative integer\n");
            printf("    Expected: '-9876', Got: '%s'\n", buffer);
            failed++;
        }
    }

    // Test 3: Write zero to file
    fd = open(temp_filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        printf("  FAIL: Could not open test file\n");
        failed++;
    } else {
        ft_putnbr_fd(0, fd);
        close(fd);

        fd = open(temp_filename, O_RDONLY);
        bytes_read = read(fd, buffer, sizeof(buffer));
        buffer[bytes_read] = '\0';  // Null-terminate the buffer
        close(fd);

        if (strcmp(buffer, "0") != 0) {
            printf("  FAIL: Writing zero\n");
            printf("    Expected: '0', Got: '%s'\n", buffer);
            failed++;
        }
    }

    // Test 4: Write INT_MIN (-2147483648) to file
    fd = open(temp_filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        printf("  FAIL: Could not open test file\n");
        failed++;
    } else {
        ft_putnbr_fd(-2147483648, fd);
        close(fd);

        fd = open(temp_filename, O_RDONLY);
        bytes_read = read(fd, buffer, sizeof(buffer));
        buffer[bytes_read] = '\0';  // Null-terminate the buffer
        close(fd);

        if (strcmp(buffer, "-2147483648") != 0) {
            printf("  FAIL: Writing INT_MIN\n");
            printf("    Expected: '-2147483648', Got: '%s'\n", buffer);
            failed++;
        }
    }

    // Test 5: Write INT_MAX (2147483647) to file
    fd = open(temp_filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        printf("  FAIL: Could not open test file\n");
        failed++;
    } else {
        ft_putnbr_fd(2147483647, fd);
        close(fd);

        fd = open(temp_filename, O_RDONLY);
        bytes_read = read(fd, buffer, sizeof(buffer));
        buffer[bytes_read] = '\0';  // Null-terminate the buffer
        close(fd);

        if (strcmp(buffer, "2147483647") != 0) {
            printf("  FAIL: Writing INT_MAX\n");
            printf("    Expected: '2147483647', Got: '%s'\n", buffer);
            failed++;
        }
    }

    // Test 6: Write to standard output (this is a visual test)
    ft_putnbr_fd(42, 1);
    printf("\n");
    printf("  Did you see '42'? If not, the test failed.\n");
    // Note: We can't automatically verify this test

    // Clean up
    unlink(temp_filename);

    // Print test results
    if (failed == 0)
        printf("  All automated tests passed! (Check visual test manually)\n\n");
    else
        printf("  %d tests failed!\n\n", failed);
}
