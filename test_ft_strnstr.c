#include "test_libft.h"

void test_ft_strnstr(void)
{
    printf("Testing ft_strnstr:\n");
    int failed = 0;

    // Test 1: Basic functionality - find substring in string
    const char *haystack1 = "Hello world";
    const char *needle1 = "world";
    char *result1 = ft_strnstr(haystack1, needle1, strlen(haystack1));
    char *expected1 = strnstr(haystack1, needle1, strlen(haystack1));
    if (result1 != haystack1 + 6 || result1 != expected1) {
        printf("  FAIL: Basic test - find 'world' in 'Hello world'\n");
        printf("    Expected: %p (%s), Got: %p (%s)\n", expected1, expected1, result1, result1);
        failed++;
    }

    // Test 2: Substring not in string
    const char *haystack2 = "Hello world";
    const char *needle2 = "banana";
    char *result2 = ft_strnstr(haystack2, needle2, strlen(haystack2));
    char *expected2 = strnstr(haystack2, needle2, strlen(haystack2));
    if (result2 != NULL || result2 != expected2) {
        printf("  FAIL: Test - 'banana' not in 'Hello world'\n");
        printf("    Expected: NULL, Got: %p\n", result2);
        failed++;
    }

    // Test 3: Empty needle
    const char *haystack3 = "Hello world";
    const char *needle3 = "";
    char *result3 = ft_strnstr(haystack3, needle3, strlen(haystack3));
    char *expected3 = strnstr(haystack3, needle3, strlen(haystack3));
    if (result3 != haystack3 || result3 != expected3) {
        printf("  FAIL: Test with empty needle\n");
        printf("    Expected: %p, Got: %p\n", expected3, result3);
        failed++;
    }

    // Test 4: Needle larger than haystack
    const char *haystack4 = "Hi";
    const char *needle4 = "Hello";
    char *result4 = ft_strnstr(haystack4, needle4, strlen(haystack4));
    char *expected4 = strnstr(haystack4, needle4, strlen(haystack4));
    if (result4 != NULL || result4 != expected4) {
        printf("  FAIL: Test with needle larger than haystack\n");
        printf("    Expected: NULL, Got: %p\n", result4);
        failed++;
    }

    // Test 5: Len parameter limits search
    const char *haystack5 = "Hello world";
    const char *needle5 = "world";
    char *result5 = ft_strnstr(haystack5, needle5, 7); // Just enough to find "wo"
    char *expected5 = strnstr(haystack5, needle5, 7);
    if (result5 != expected5) {
        printf("  FAIL: Test with len parameter just enough\n");
        printf("    Expected: %p, Got: %p\n", expected5, result5);
        failed++;
    }

    // Test 6: Len parameter too small
    char *result6 = ft_strnstr(haystack5, needle5, 5); // Not enough to find "world"
    char *expected6 = strnstr(haystack5, needle5, 5);
    if (result6 != NULL || result6 != expected6) {
        printf("  FAIL: Test with len parameter too small\n");
        printf("    Expected: NULL, Got: %p\n", result6);
        failed++;
    }

    // Test 7: Zero length
    const char *haystack9 = "Hello world";
    const char *needle9 = "world";
    char *result9 = ft_strnstr(haystack9, needle9, 0);
    char *expected9 = strnstr(haystack9, needle9, 0);
    if (result9 != NULL || result9 != expected9) {
        printf("  FAIL: Test with zero length\n");
        printf("    Expected: NULL, Got: %p\n", result9);
        failed++;
    }

    // Print test results
    if (failed == 0)
        printf("  All tests passed!\n\n");
    else
        printf("  %d tests failed!\n\n", failed);
}
