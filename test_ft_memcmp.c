#include "test_libft.h"

void test_ft_memcmp(void)
{
    printf("Testing ft_memcmp:\n");
    int failed = 0;

    // Test 1: Equal memory blocks
    unsigned char arr1[] = {1, 2, 3, 4, 5};
    unsigned char arr2[] = {1, 2, 3, 4, 5};
    int result1 = ft_memcmp(arr1, arr2, sizeof(arr1));
    int expected1 = memcmp(arr1, arr2, sizeof(arr1));
    if (result1 != expected1) {
        printf("  FAIL: Equal memory blocks test\n");
        printf("    Expected: %d, Got: %d\n", expected1, result1);
        failed++;
    }

    // Test 2: Different memory blocks (s1 > s2)
    unsigned char arr3[] = {1, 2, 3, 4, 5};
    unsigned char arr4[] = {1, 2, 0, 4, 5};
    int result2 = ft_memcmp(arr3, arr4, sizeof(arr3));
    int expected2 = memcmp(arr3, arr4, sizeof(arr3));
    if ((result2 <= 0) || (expected2 <= 0) || ((result2 > 0) != (expected2 > 0))) {
        printf("  FAIL: Different memory blocks (s1 > s2) test\n");
        printf("    Expected: %d, Got: %d\n", expected2, result2);
        failed++;
    }

    // Test 3: Different memory blocks (s1 < s2)
    unsigned char arr5[] = {1, 2, 0, 4, 5};
    unsigned char arr6[] = {1, 2, 3, 4, 5};
    int result3 = ft_memcmp(arr5, arr6, sizeof(arr5));
    int expected3 = memcmp(arr5, arr6, sizeof(arr5));
    if ((result3 >= 0) || (expected3 >= 0) || ((result3 < 0) != (expected3 < 0))) {
        printf("  FAIL: Different memory blocks (s1 < s2) test\n");
        printf("    Expected: %d, Got: %d\n", expected3, result3);
        failed++;
    }

    // Test 4: Zero-length comparison
    unsigned char arr7[] = {1, 2, 3};
    unsigned char arr8[] = {4, 5, 6};
    int result4 = ft_memcmp(arr7, arr8, 0);
    int expected4 = memcmp(arr7, arr8, 0);
    if (result4 != expected4) {
        printf("  FAIL: Zero-length comparison test\n");
        printf("    Expected: %d, Got: %d\n", expected4, result4);
        failed++;
    }

    // Test 5: Compare strings with different characters after n bytes
    char str1[] = "Hello World";
    char str2[] = "Hello Test";
    int result5 = ft_memcmp(str1, str2, 5); // Only compare "Hello"
    int expected5 = memcmp(str1, str2, 5);
    if (result5 != expected5) {
        printf("  FAIL: Strings differing after n bytes test\n");
        printf("    Expected: %d, Got: %d\n", expected5, result5);
        failed++;
    }

    // Test 6: Compare with NULL byte in the middle
    unsigned char arr9[] = {1, 2, 0, 4, 5};
    unsigned char arr10[] = {1, 2, 0, 3, 5};
    int result6 = ft_memcmp(arr9, arr10, sizeof(arr9));
    int expected6 = memcmp(arr9, arr10, sizeof(arr9));
    if ((result6 <= 0 && expected6 > 0) || (result6 >= 0 && expected6 < 0) ||
        (result6 == 0 && expected6 != 0) || (result6 != 0 && expected6 == 0)) {
        printf("  FAIL: Compare with NULL byte in the middle test\n");
        printf("    Expected: %d, Got: %d\n", expected6, result6);
        failed++;
    }

    // Print test results
    if (failed == 0)
        printf("  All tests passed!\n\n");
    else
        printf("  %d tests failed!\n\n", failed);
}
