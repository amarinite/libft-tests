#include "test_libft.h"
#include <string.h>

void test_ft_substr(void)
{
    printf("Testing ft_substr:\n");
    int failed = 0;

    // Test 1: Basic substring extraction
    char *result = ft_substr("Hello, World!", 0, 5);
    if (result == NULL || strcmp(result, "Hello") != 0) {
        printf("  FAIL: Basic substring extraction test\n");
        printf("    Expected: 'Hello', Got: '%s'\n", result ? result : "(NULL)");
        free(result);
        failed++;
    } else {
        free(result);
    }

    // Test 2: Substring starting after the first character
    result = ft_substr("Hello, World!", 7, 5);
    if (result == NULL || strcmp(result, "World") != 0) {
        printf("  FAIL: Substring starting after the first character test\n");
        printf("    Expected: 'World', Got: '%s'\n", result ? result : "(NULL)");
        free(result);
        failed++;
    } else {
        free(result);
    }

    // Test 3: Substring length longer than the remaining string
    result = ft_substr("Hello, World!", 7, 100);
    if (result == NULL || strcmp(result, "World!") != 0) {
        printf("  FAIL: Substring length longer than remaining string test\n");
        printf("    Expected: 'World!', Got: '%s'\n", result ? result : "(NULL)");
        free(result);
        failed++;
    } else {
        free(result);
    }

    // Test 4: Substring starting beyond the string length (should return empty string)
    result = ft_substr("Hello, World!", 20, 5);
    if (result == NULL || strcmp(result, "") != 0) {
        printf("  FAIL: Substring starting beyond string length test\n");
        printf("    Expected: \"\", Got: '%s'\n", result ? result : "(NULL)");
        if (result) free(result);
        failed++;
    } else {
    	free(result);
    }

    // Test 5: Substring from an empty string (should return empty string)
    result = ft_substr("", 0, 5);
    if (result == NULL || strcmp(result, "") != 0) {
        printf("  FAIL: Substring from empty string test\n");
        printf("    Expected: empty string, Got: '%s'\n", result);
        free(result);
        failed++;
    }

    // Test 6: Substring with zero length (should return empty string)
    result = ft_substr("Hello, World!", 0, 0);
    if (result == NULL || strcmp(result, "") != 0) {
        printf("  FAIL: Substring with zero length test\n");
        printf("    Expected: '', Got: '%s'\n", result ? result : "(NULL)");
        free(result);
        failed++;
    } else {
        free(result);
    }

    // Test 7: Substring at the very end of the string (edge case)
    result = ft_substr("Hello, World!", 12, 1);
    if (result == NULL || strcmp(result, "!") != 0) {
        printf("  FAIL: Substring at the very end of the string test\n");
        printf("    Expected: '!', Got: '%s'\n", result ? result : "(NULL)");
        free(result);
        failed++;
    } else {
        free(result);
    }

    // Test 8: Null input string (should return NULL)
    result = ft_substr(NULL, 0, 5);
    if (result != NULL) {
        printf("  FAIL: Null input string test\n");
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
