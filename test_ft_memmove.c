#include "test_libft.h"

void test_ft_memmove(void)
{
    printf("Testing ft_memmove:\n");
    int failed = 0;

    // Test 1: Basic functionality with a character buffer (non-overlapping)
    char src1[50] = "Hello, world!";
    char dst1[50];
    char dst1_std[50];
    ft_memmove(dst1, src1, strlen(src1) + 1);
    memmove(dst1_std, src1, strlen(src1) + 1);
    if (memcmp(dst1, dst1_std, strlen(src1) + 1) != 0) {
        printf("  FAIL: Basic test with string copy (non-overlapping)\n");
        failed++;
    }

    // Test 2: Copy with null bytes in the middle
    char src2[50] = "Hello\0world";
    char dst2[50];
    char dst2_std[50];
    ft_memmove(dst2, src2, 12);
    memmove(dst2_std, src2, 12);
    if (memcmp(dst2, dst2_std, 12) != 0) {
        printf("  FAIL: Test with null bytes in string\n");
        failed++;
    }

    // Test 3: Overlapping memory - destination after source
    char overlap1[50] = "abcdefghijklmnopqrstuvwxyz";
    char overlap1_std[50] = "abcdefghijklmnopqrstuvwxyz";
    ft_memmove(overlap1 + 5, overlap1, 10);  // Move "abcdefghij" to position starting at "f"
    memmove(overlap1_std + 5, overlap1_std, 10);
    if (memcmp(overlap1, overlap1_std, 50) != 0) {
        printf("  FAIL: Test with overlapping memory (dest > src)\n");
        failed++;
    }

    // Test 4: Overlapping memory - destination before source
    char overlap2[50] = "abcdefghijklmnopqrstuvwxyz";
    char overlap2_std[50] = "abcdefghijklmnopqrstuvwxyz";
    ft_memmove(overlap2, overlap2 + 5, 10);  // Move "fghijklmno" to start of buffer
    memmove(overlap2_std, overlap2_std + 5, 10);
    if (memcmp(overlap2, overlap2_std, 50) != 0) {
        printf("  FAIL: Test with overlapping memory (dest < src)\n");
        failed++;
    }

    // Test 5: Large overlap - almost entire buffer
    char overlap3[50];
    char overlap3_std[50];
    memset(overlap3, 'A', 50);
    memset(overlap3_std, 'A', 50);
    ft_memmove(overlap3 + 1, overlap3, 49);
    memmove(overlap3_std + 1, overlap3_std, 49);
    if (memcmp(overlap3, overlap3_std, 50) != 0) {
        printf("  FAIL: Test with large overlap\n");
        failed++;
    }

    // Test 6: Test with integer array
    int src4[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int dst4[10];
    int dst4_std[10];
    ft_memmove(dst4, src4, sizeof(src4));
    memmove(dst4_std, src4, sizeof(src4));
    if (memcmp(dst4, dst4_std, sizeof(dst4)) != 0) {
        printf("  FAIL: Test with integer array\n");
        failed++;
    }

    // Test 7: Test move within same array (integers)
    int overlap_int[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int overlap_int_std[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ft_memmove(overlap_int + 2, overlap_int, 5 * sizeof(int));
    memmove(overlap_int_std + 2, overlap_int_std, 5 * sizeof(int));
    if (memcmp(overlap_int, overlap_int_std, 10 * sizeof(int)) != 0) {
        printf("  FAIL: Test with overlapping integer array\n");
        failed++;
    }

    // Test 8: Zero-length test
    char src6[6] = "ABCDE";
    char dst6[6] = "12345";
    char dst6_std[6] = "12345";
    size_t zero_len = 0;
    ft_memmove(dst6, src6, zero_len);
    memmove(dst6_std, src6, zero_len);
    if (memcmp(dst6, dst6_std, 6) != 0) {
        printf("  FAIL: memcmp comparison failed for zero length\n");
        failed++;
    }
    if (strcmp(dst6, "12345") != 0) {
        printf("  FAIL: ft_memmove changed string with zero length\n");
        failed++;
    }

    // Test 9: Test return value
    char src7[10] = "ABCDEFGHI";
    char dst7[10];
    void *ret1 = ft_memmove(dst7, src7, 10);
    if (ret1 != dst7) {
        printf("  FAIL: Return value doesn't match pointer to destination buffer\n");
        failed++;
    }

    // Test 10: Destination and source are the same
    char same[20] = "Testing same pointer";
    char same_std[20] = "Testing same pointer";
    ft_memmove(same, same, 20);
    memmove(same_std, same_std, 20);
    if (memcmp(same, same_std, 20) != 0) {
        printf("  FAIL: Test with identical source and destination\n");
        failed++;
    }

    // Test 11: Non-aligned memory test (test byte-by-byte operation)
    char align_test[30];
    char align_test_std[30];
    memset(align_test, 'X', 30);
    memset(align_test_std, 'X', 30);

    // Fill source region with test pattern
    for (int i = 0; i < 20; i++) {
        align_test[i + 5] = 'A' + i;
        align_test_std[i + 5] = 'A' + i;
    }

    // Move from odd address to odd address
    ft_memmove(align_test + 3, align_test + 7, 15);
    memmove(align_test_std + 3, align_test_std + 7, 15);

    if (memcmp(align_test, align_test_std, 30) != 0) {
        printf("  FAIL: Test with non-aligned addresses\n");
        failed++;
    }

    // Print test results
    if (failed == 0)
        printf("  All tests passed!\n\n");
    else
        printf("  %d tests failed!\n\n", failed);
}
