#include "test_libft.h"

void test_ft_strchr(void)
{
    printf("Testing ft_strchr:\n");
    int failed = 0;

    // Test 1: Character present in the middle of the string
    char s1[] = "Hello, world!";
    char c1 = 'o';
    char *result1 = ft_strchr(s1, c1);
    char *expected1 = strchr(s1, c1);
    if (result1 != expected1) {
        printf("  FAIL: Character in the middle test\n");
        printf("    Expected: %p (%s), Got: %p (%s)\n",
               expected1, expected1, result1, result1);
        failed++;
    }

    // Test 2: Character present multiple times (should find first occurrence)
    char s2[] = "Hello, world!";
    char c2 = 'l';
    char *result2 = ft_strchr(s2, c2);
    char *expected2 = strchr(s2, c2);
    if (result2 != expected2) {
        printf("  FAIL: Multiple occurrences test\n");
        printf("    Expected: %p (%s), Got: %p (%s)\n",
               expected2, expected2, result2, result2);
        failed++;
    }

    // Test 3: Character at the beginning of the string
    char s3[] = "Hello, world!";
    char c3 = 'H';
    char *result3 = ft_strchr(s3, c3);
    char *expected3 = strchr(s3, c3);
    if (result3 != expected3) {
        printf("  FAIL: Character at beginning test\n");
        printf("    Expected: %p (%s), Got: %p (%s)\n",
               expected3, expected3, result3, result3);
        failed++;
    }

    // Test 4: Character not present in the string
    char s4[] = "Hello, world!";
    char c4 = 'z';
    char *result4 = ft_strchr(s4, c4);
    char *expected4 = strchr(s4, c4);
    if (result4 != expected4) {
        printf("  FAIL: Character not present test\n");
        printf("    Expected: %p, Got: %p\n", expected4, result4);
        failed++;
    }

    // Test 5: Null terminator character
    char s5[] = "Hello, world!";
    char c5 = '\0';
    char *result5 = ft_strchr(s5, c5);
    char *expected5 = strchr(s5, c5);
    if (result5 != expected5) {
        printf("  FAIL: Null terminator test\n");
        printf("    Expected: %p, Got: %p\n", expected5, result5);
        failed++;
    }

    // Test 6: Empty string with non-null character
    char s6[] = "";
    char c6 = 'a';
    char *result6 = ft_strchr(s6, c6);
    char *expected6 = strchr(s6, c6);
    if (result6 != expected6) {
        printf("  FAIL: Empty string test\n");
        printf("    Expected: %p, Got: %p\n", expected6, result6);
        failed++;
    }

    // Print test results
    if (failed == 0)
        printf("  All tests passed!\n\n");
    else
        printf("  %d tests failed!\n\n", failed);
}
