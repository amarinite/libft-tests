#include "test_libft.h"

void test_ft_strrchr(void)
{
    printf("Testing ft_strrchr:\n");
    int failed = 0;

    // Test 1: Character present in the middle of the string
    char s1[] = "Hello, world!";
    char c1 = 'o';
    char *result1 = ft_strrchr(s1, c1);
    char *expected1 = strrchr(s1, c1);
    if (result1 != expected1) {
        printf("  FAIL: Character in the middle test\n");
        printf("    Expected: %p (%s), Got: %p (%s)\n",
               expected1, expected1 ? expected1 : "NULL",
               result1, result1 ? result1 : "NULL");
        failed++;
    }

    // Test 2: Character present multiple times (should find last occurrence)
    char s2[] = "Hello, world!";
    char c2 = 'l';
    char *result2 = ft_strrchr(s2, c2);
    char *expected2 = strrchr(s2, c2);
    if (result2 != expected2) {
        printf("  FAIL: Multiple occurrences test\n");
        printf("    Expected: %p (%s), Got: %p (%s)\n",
               expected2, expected2 ? expected2 : "NULL",
               result2, result2 ? result2 : "NULL");
        failed++;
    }

    // Test 3: Character at the beginning of the string
    char s3[] = "Hello, world!";
    char c3 = 'H';
    char *result3 = ft_strrchr(s3, c3);
    char *expected3 = strrchr(s3, c3);
    if (result3 != expected3) {
        printf("  FAIL: Character at beginning test\n");
        printf("    Expected: %p (%s), Got: %p (%s)\n",
               expected3, expected3 ? expected3 : "NULL",
               result3, result3 ? result3 : "NULL");
        failed++;
    }

    // Test 4: Character at the end of the string (before null)
    char s4[] = "Hello, world!";
    char c4 = '!';
    char *result4 = ft_strrchr(s4, c4);
    char *expected4 = strrchr(s4, c4);
    if (result4 != expected4) {
        printf("  FAIL: Character at end test\n");
        printf("    Expected: %p (%s), Got: %p (%s)\n",
               expected4, expected4 ? expected4 : "NULL",
               result4, result4 ? result4 : "NULL");
        failed++;
    }

    // Test 5: Character not present in the string
    char s5[] = "Hello, world!";
    char c5 = 'z';
    char *result5 = ft_strrchr(s5, c5);
    char *expected5 = strrchr(s5, c5);
    if (result5 != expected5) {
        printf("  FAIL: Character not present test\n");
        printf("    Expected: %p, Got: %p\n", expected5, result5);
        failed++;
    }

    // Test 6: Null terminator character
    char s6[] = "Hello, world!";
    char c6 = '\0';
    char *result6 = ft_strrchr(s6, c6);
    char *expected6 = strrchr(s6, c6);
    if (result6 != expected6) {
        printf("  FAIL: Null terminator test\n");
        printf("    Expected: %p, Got: %p\n", expected6, result6);
        failed++;
    }

    // Test 7: Empty string with non-null character
    char s7[] = "";
    char c7 = 'a';
    char *result7 = ft_strrchr(s7, c7);
    char *expected7 = strrchr(s7, c7);
    if (result7 != expected7) {
        printf("  FAIL: Empty string test\n");
        printf("    Expected: %p, Got: %p\n", expected7, result7);
        failed++;
    }

    // Print test results
    if (failed == 0)
        printf("  All tests passed!\n\n");
    else
        printf("  %d tests failed!\n\n", failed);
}
