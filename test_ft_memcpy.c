#include "test_libft.h"

void test_ft_memcpy()
{
 	printf("Testing ft_memset:\n");
    int failed = 0;

    // Test 1: Basic functionality with a character buffer
        char src1[50] = "Hello, world!";
        char dst1[50];
        char dst1_std[50];
        ft_memcpy(dst1, src1, strlen(src1) + 1);
        memcpy(dst1_std, src1, strlen(src1) + 1);
        if (memcmp(dst1, dst1_std, strlen(src1) + 1) != 0) {
            printf("  FAIL: Basic test with string copy\n");
            failed++;
        }

        // Test 2: Copy with null bytes in the middle
        char src2[50] = "Hello\0world";
        char dst2[50];
        char dst2_std[50];
        ft_memcpy(dst2, src2, 12);
        memcpy(dst2_std, src2, 12);
        if (memcmp(dst2, dst2_std, 12) != 0) {
            printf("  FAIL: Test with null bytes in string\n");
            failed++;
        }

        // Test 3: Copy with non-ASCII values
        unsigned char src3[50];
        unsigned char dst3[50];
        unsigned char dst3_std[50];
        for (int i = 0; i < 50; i++) {
            src3[i] = 128 + i;
        }
        ft_memcpy(dst3, src3, 50);
        memcpy(dst3_std, src3, 50);
        if (memcmp(dst3, dst3_std, 50) != 0) {
            printf("  FAIL: Test with non-ASCII values\n");
            failed++;
        }

        // Test 4: Test with integer array
        int src4[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int dst4[10];
        int dst4_std[10];
        ft_memcpy(dst4, src4, sizeof(src4));
        memcpy(dst4_std, src4, sizeof(src4));
        if (memcmp(dst4, dst4_std, sizeof(dst4)) != 0) {
            printf("  FAIL: Test with integer array\n");
            failed++;
        }

        // Test 5: Test with partial buffer
        char src5[20] = "ABCDEFGHIJKLMNOPQRS";
        char dst5[20] = "12345678901234567890";
        char dst5_std[20] = "12345678901234567890";
        ft_memcpy(dst5 + 5, src5 + 10, 10);
        memcpy(dst5_std + 5, src5 + 10, 10);
        if (memcmp(dst5, dst5_std, 20) != 0) {
            printf("  FAIL: Test with partial buffer\n");
            failed++;
        }

        // Test 6: Zero-length test
        char src6[6] = "ABCDE";
        char dst6[6] = "12345";
        char dst6_std[6] = "12345";
        size_t zero_len = 0;
        ft_memcpy(dst6, src6, zero_len);
        memcpy(dst6_std, src6, zero_len);
        if (memcmp(dst6, dst6_std, 5) != 0) {
            printf("  FAIL: memcmp comparison failed for zero length\n");
            failed++;
        }
        if (strcmp(dst6, "12345") != 0) {
            printf("  FAIL: ft_memcpy changed string with zero length\n");
            failed++;
        }

        // Test 7: Test return value
        char src7[10] = "ABCDEFGHI";
        char dst7[10];
        void *ret1 = ft_memcpy(dst7, src7, 10);
        if (ret1 != dst7) {
            printf("  FAIL: Return value doesn't match pointer to destination buffer\n");
            failed++;
        }

        // Test 8: Large copy
        char src8[1000];
        char dst8[1000];
        char dst8_std[1000];
        for (int i = 0; i < 1000; i++) {
            src8[i] = 33 + (i % 94); // Printable ASCII
        }
        ft_memcpy(dst8, src8, 1000);
        memcpy(dst8_std, src8, 1000);
        if (memcmp(dst8, dst8_std, 1000) != 0) {
            printf("  FAIL: Large memory copy test\n");
            failed++;
        }

        // Test 9: Copying to same location (dest == src)
        char same_buf[20] = "Testing same buffer";
        char same_buf_copy[20];
        strcpy(same_buf_copy, same_buf);
        ft_memcpy(same_buf, same_buf, 20);
        if (memcmp(same_buf, same_buf_copy, 20) != 0) {
            printf("  FAIL: Test copying to same location\n");
            failed++;
        }

        // Print test results
        if (failed == 0)
            printf("  All tests passed!\n\n");
        else
            printf("  %d tests failed!\n\n", failed);
}
