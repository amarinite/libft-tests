#include "test_libft.h"

void test_ft_bzero(void)
{
    printf("Testing ft_bzero:\n");
    int failed = 0;

    // Test 1: Basic functionality with a character buffer
    char str1[50];
    char str2[50];
    // Fill with non-zero values first
    memset(str1, 'A', 50);
    memset(str2, 'A', 50);
    // Then zero out part of it
    ft_bzero(str1, 10);
    bzero(str2, 10);
    if (memcmp(str1, str2, 50) != 0) {
        printf("  FAIL: Basic test with character buffer\n");
        failed++;
    }

    // Test 2: Test with already zeroed memory
    ft_bzero(str1, 15);  // Zero out first 15 bytes
    bzero(str2, 15);     // Zero out first 15 bytes
    if (memcmp(str1, str2, 50) != 0) {
        printf("  FAIL: Test with already zeroed memory\n");
        failed++;
    }

    // Test 3: Test with larger buffer
    char large1[100];
    char large2[100];
    memset(large1, 0xFF, 100);  // Fill with all bits set
    memset(large2, 0xFF, 100);  // Fill with all bits set
    ft_bzero(large1, 50);
    bzero(large2, 50);
    if (memcmp(large1, large2, 100) != 0) {
        printf("  FAIL: Test with larger buffer\n");
        failed++;
    }

    // Test 4: Test with an integer array
    int int_arr1[10];
    int int_arr2[10];
    // Fill with non-zero values
    for (int i = 0; i < 10; i++) {
        int_arr1[i] = int_arr2[i] = 0xCAFEBABE;
    }
    ft_bzero(int_arr1, sizeof(int_arr1));
    bzero(int_arr2, sizeof(int_arr2));
    if (memcmp(int_arr1, int_arr2, sizeof(int_arr1)) != 0) {
        printf("  FAIL: Test with integer array\n");
        failed++;
    }

    // Test 5: Test zeroing only part of a buffer
    char partial1[20];
    char partial2[20];
    for (int i = 0; i < 20; i++) {
        partial1[i] = partial2[i] = 'X';
    }
    ft_bzero(partial1 + 5, 10);
    bzero(partial2 + 5, 10);
    if (memcmp(partial1, partial2, 20) != 0) {
        printf("  FAIL: Test with partial buffer\n");
        failed++;
    }

    // Test 6: Zero-length test
    char zero1[6] = "ABCDE";
    char zero2[6] = "ABCDE";
    size_t zero_len = 0;
    ft_bzero(zero1, zero_len);
    bzero(zero2, zero_len);
    if (memcmp(zero1, zero2, 6) != 0) {
        printf("  FAIL: memcmp comparison failed for zero length\n");
        failed++;
    }
    if (strcmp(zero1, "ABCDE") != 0) {
        printf("  FAIL: ft_bzero changed string with zero length\n");
        failed++;
    }

    // Test 7: Very large buffer test
    unsigned char *large_buf1 = malloc(1024);
    unsigned char *large_buf2 = malloc(1024);
    if (large_buf1 && large_buf2) {
        memset(large_buf1, 0x55, 1024);  // Fill with pattern
        memset(large_buf2, 0x55, 1024);  // Fill with same pattern

        ft_bzero(large_buf1, 1024);
        bzero(large_buf2, 1024);

        if (memcmp(large_buf1, large_buf2, 1024) != 0) {
            printf("  FAIL: Test with very large buffer\n");
            failed++;
        }

        free(large_buf1);
        free(large_buf2);
    }

    // Print test results
    if (failed == 0)
        printf("  All tests passed!\n\n");
    else
        printf("  %d tests failed!\n\n", failed);
}
