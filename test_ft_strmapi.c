#include "test_libft.h"

static char alt_uppercase(unsigned int i, char c) {
    if (i % 2 == 0 && c >= 'a' && c <= 'z')
        return c - 32;
    return c;
}

// Sample mapping function: shift each character by index
static char shift_by_index(unsigned int i, char c) {
    return c + i;
}

void test_ft_strmapi(void)
{
    printf("Testing ft_strmapi:\n");
    int failed = 0;

    // Test 1: Alternating uppercase
    char *result = ft_strmapi("abcdef", alt_uppercase);
    if (result == NULL || strcmp(result, "AbCdEf") != 0) {
        printf("  FAIL: Alternating uppercase\n");
        printf("    Expected: 'AbCdEf', Got: '%s'\n", result ? result : "(NULL)");
        free(result);
        failed++;
    } else {
        free(result);
    }

    // Test 2: Shift characters by index
    result = ft_strmapi("abcd", shift_by_index);
    if (result == NULL || strcmp(result, "aceg") != 0) {
        printf("  FAIL: Shift characters by index\n");
        printf("    Expected: 'aceg', Got: '%s'\n", result ? result : "(NULL)");
        free(result);
        failed++;
    } else {
        free(result);
    }

    // Test 3: Empty string input
    result = ft_strmapi("", alt_uppercase);
    if (result == NULL || strcmp(result, "") != 0) {
        printf("  FAIL: Empty string input\n");
        printf("    Expected: '', Got: '%s'\n", result ? result : "(NULL)");
        free(result);
        failed++;
    } else {
        free(result);
    }

    // Test 4: NULL string input (should return NULL)
    result = ft_strmapi(NULL, alt_uppercase);
    if (result != NULL) {
        printf("  FAIL: NULL string input\n");
        printf("    Expected: NULL, Got: '%s'\n", result);
        free(result);
        failed++;
    }

    // Test 5: NULL function pointer (should return NULL)
    result = ft_strmapi("hello", NULL);
    if (result != NULL) {
        printf("  FAIL: NULL function pointer\n");
        printf("    Expected: NULL, Got: '%s'\n", result);
        free(result);
        failed++;
    }

    // Print test results
    if (failed == 0)
        printf("  All tests passed!\n\n");
    else
        printf("  %d tests failed!\n\n", failed);
}
