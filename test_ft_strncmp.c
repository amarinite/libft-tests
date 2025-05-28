#include "test_libft.h"

void test_ft_strncmp(void)
{
    printf("Testing ft_strncmp:\n");
    int failed = 0;

    // Test 1: Equal strings
    char s1[] = "Hello, world!";
    char s2[] = "Hello, world!";
    int result1 = ft_strncmp(s1, s2, strlen(s1));
    int expected1 = strncmp(s1, s2, strlen(s1));
    if (result1 != expected1) {
        printf("  FAIL: Equal strings test\n");
        printf("    Expected: %d, Got: %d\n", expected1, result1);
        failed++;
    }

    // Test 2: Different strings (s1 > s2)
    char s3[] = "Hello, world!";
    char s4[] = "Hello, earth!";
    int result2 = ft_strncmp(s3, s4, strlen(s3));
    int expected2 = strncmp(s3, s4, strlen(s3));
    if ((result2 <= 0) || (expected2 <= 0) || ((result2 > 0) != (expected2 > 0))) {
        printf("  FAIL: Different strings (s1 > s2) test\n");
        printf("    Expected: %d, Got: %d\n", expected2, result2);
        failed++;
    }

    // Test 3: Different strings (s1 < s2)
    char s5[] = "Hello, earth!";
    char s6[] = "Hello, world!";
    int result3 = ft_strncmp(s5, s6, strlen(s5));
    int expected3 = strncmp(s5, s6, strlen(s5));
    if ((result3 >= 0) || (expected3 >= 0) || ((result3 < 0) != (expected3 < 0))) {
        printf("  FAIL: Different strings (s1 < s2) test\n");
        printf("    Expected: %d, Got: %d\n", expected3, result3);
        failed++;
    }

    // Test 4: Limited comparison length (difference beyond n)
    char s7[] = "Hello, world!";
    char s8[] = "Hello, earth!";
    int result4 = ft_strncmp(s7, s8, 7); // Compare only "Hello, "
    int expected4 = strncmp(s7, s8, 7);
    if (result4 != expected4) {
        printf("  FAIL: Limited comparison length test\n");
        printf("    Expected: %d, Got: %d\n", expected4, result4);
        failed++;
    }

    // Test 5: Empty string
    char s9[] = "";
    char s10[] = "Hello";
    int result5 = ft_strncmp(s9, s10, 5);
    int expected5 = strncmp(s9, s10, 5);
    if ((result5 >= 0) || (expected5 >= 0) || ((result5 < 0) != (expected5 < 0))) {
        printf("  FAIL: Empty string test\n");
        printf("    Expected: %d, Got: %d\n", expected5, result5);
        failed++;
    }

    // Test 6: Zero length comparison
    char s11[] = "Different";
    char s12[] = "Strings";
    int result6 = ft_strncmp(s11, s12, 0);
    int expected6 = strncmp(s11, s12, 0);
    if (result6 != expected6) {
        printf("  FAIL: Zero length comparison test\n");
        printf("    Expected: %d, Got: %d\n", expected6, result6);
        failed++;
    }

    // Print test results
    if (failed == 0)
        printf("  All tests passed!\n\n");
    else
        printf("  %d tests failed!\n\n", failed);
}
