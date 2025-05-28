#include "test_libft.h"

void test_ft_tolower(void)
{
    printf("Testing ft_tolower:\n");
    int failed = 0;

    // Test 1: Uppercase letters
    for (int c = 'A'; c <= 'Z'; c++) {
        int result = ft_tolower(c);
        int expected = tolower(c);
        if (result != expected) {
            printf("  FAIL: Uppercase letter '%c' test\n", c);
            printf("    Expected: '%c' (%d), Got: '%c' (%d)\n",
                   expected, expected, result, result);
            failed++;
            break;
        }
    }

    // Test 2: Lowercase letters (should remain unchanged)
    for (int c = 'a'; c <= 'z'; c++) {
        int result = ft_tolower(c);
        int expected = tolower(c);
        if (result != expected) {
            printf("  FAIL: Lowercase letter '%c' test\n", c);
            printf("    Expected: '%c' (%d), Got: '%c' (%d)\n",
                   expected, expected, result, result);
            failed++;
            break;
        }
    }

    // Test 3: Numbers (should remain unchanged)
    for (int c = '0'; c <= '9'; c++) {
        int result = ft_tolower(c);
        int expected = tolower(c);
        if (result != expected) {
            printf("  FAIL: Number '%c' test\n", c);
            printf("    Expected: '%c' (%d), Got: '%c' (%d)\n",
                   expected, expected, result, result);
            failed++;
            break;
        }
    }

    // Test 4: Special characters (should remain unchanged)
    const char special_chars[] = " !@#$%^&*()_+-=[]{}|;:,.<>?/";
    for (size_t i = 0; i < strlen(special_chars); i++) {
        int c = special_chars[i];
        int result = ft_tolower(c);
        int expected = tolower(c);
        if (result != expected) {
            printf("  FAIL: Special character '%c' test\n", c);
            printf("    Expected: '%c' (%d), Got: '%c' (%d)\n",
                   expected, expected, result, result);
            failed++;
            break;
        }
    }

    // Print test results
    if (failed == 0)
        printf("  All tests passed!\n\n");
    else
        printf("  %d tests failed!\n\n", failed);
}
