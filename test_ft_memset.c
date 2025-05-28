#include "test_libft.h"

void test_ft_memset(void)
{
    printf("Testing ft_memset:\n");
    int failed = 0;

    // Test 1: Basic functionality with a character buffer
    char str1[50];
    char str2[50];
    ft_memset(str1, 'A', 10);
    memset(str2, 'A', 10);
    if (memcmp(str1, str2, 10) != 0) {
        printf("  FAIL: Basic test with character 'A'\n");
        failed++;
    }

    // Test 2: Test with null character (0)
    ft_memset(str1, 0, 15);
    memset(str2, 0, 15);
    if (memcmp(str1, str2, 15) != 0) {
        printf("  FAIL: Test with null character (0)\n");
        failed++;
    }

    // Test 3: Test with non-ASCII value
    ft_memset(str1, 128, 20);
    memset(str2, 128, 20);
    if (memcmp(str1, str2, 20) != 0) {
        printf("  FAIL: Test with non-ASCII value (128)\n");
        failed++;
    }

    // Test 4: Test with an integer array
    int int_arr1[10];
    int int_arr2[10];
    ft_memset(int_arr1, 0, sizeof(int_arr1));
    memset(int_arr2, 0, sizeof(int_arr2));
    if (memcmp(int_arr1, int_arr2, sizeof(int_arr1)) != 0) {
        printf("  FAIL: Test with integer array\n");
        failed++;
    }

    // Test 5: Test setting only part of a buffer
    char partial1[20];
    char partial2[20];
    for (int i = 0; i < 20; i++) {
        partial1[i] = partial2[i] = 'X';
    }
    ft_memset(partial1 + 5, 'Y', 10);
    memset(partial2 + 5, 'Y', 10);
    if (memcmp(partial1, partial2, 20) != 0) {
        printf("  FAIL: Test with partial buffer\n");
        failed++;
    }

    // Test 6: Zero-length test
    char zero1[6] = "ABCDE";
    char zero2[6] = "ABCDE";
    size_t zero_len = 0;
    ft_memset(zero1, 'Z', zero_len);
    memset(zero2, 'Z', zero_len);
    if (memcmp(zero1, zero2, 5) != 0) {
        printf("  FAIL: memcmp comparison failed for zero length\n");
        failed++;
    }
    if (strcmp(zero1, "ABCDE") != 0) {
        printf("  FAIL: ft_memset changed string with zero length\n");
        failed++;
    }

    // Test 7: Test return value
    char ret_val[10];
    void *ret1 = ft_memset(ret_val, 'R', 10);
    if (ret1 != ret_val) {
        printf("  FAIL: Return value doesn't match pointer to buffer\n");
        failed++;
    }

    // Print test results
    if (failed == 0)
        printf("  All tests passed!\n\n");
    else
        printf("  %d tests failed!\n\n", failed);
}
