#include "test_libft.h"

void test_ft_strtrim(void)
{
    printf("Testing ft_strtrim:\n");
    int failed = 0;

    // Test 1: Trim spaces from both ends
    char *result = ft_strtrim("  Hello, World!  ", " ");
    if (result == NULL || strcmp(result, "Hello, World!") != 0) {
        printf("  FAIL: Trim spaces from both ends\n");
        printf("    Expected: 'Hello, World!', Got: '%s'\n", result ? result : "(NULL)");
        free(result);
        failed++;
    } else {
        free(result);
    }

    // Test 2: Trim multiple characters from both ends
    result = ft_strtrim("--Hello--", "-");
    if (result == NULL || strcmp(result, "Hello") != 0) {
        printf("  FAIL: Trim hyphens from both ends\n");
        printf("    Expected: 'Hello', Got: '%s'\n", result ? result : "(NULL)");
        free(result);
        failed++;
    } else {
        free(result);
    }

    // Test 3: Trim characters that are not present
    result = ft_strtrim("Hello", "x");
    if (result == NULL || strcmp(result, "Hello") != 0) {
        printf("  FAIL: Trim characters not present in string\n");
        printf("    Expected: 'Hello', Got: '%s'\n", result ? result : "(NULL)");
        free(result);
        failed++;
    } else {
        free(result);
    }

    // Test 4: Trim all characters (result should be empty string)
    result = ft_strtrim("aaaaaa", "a");
    if (result == NULL || strcmp(result, "") != 0) {
        printf("  FAIL: Trim entire string\n");
        printf("    Expected: '', Got: '%s'\n", result ? result : "(NULL)");
        free(result);
        failed++;
    } else {
        free(result);
    }

    // Test 5: Trim from an empty string
    result = ft_strtrim("", " ");
    if (result == NULL || strcmp(result, "") != 0) {
        printf("  FAIL: Trim from empty string\n");
        printf("    Expected: '', Got: '%s'\n", result ? result : "(NULL)");
        free(result);
        failed++;
    } else {
        free(result);
    }

    // Test 6: NULL as s1 (should return NULL)
    result = ft_strtrim(NULL, " ");
    if (result != NULL) {
        printf("  FAIL: NULL s1 input test\n");
        printf("    Expected: NULL, Got: '%s'\n", result);
        free(result);
        failed++;
    }

    // Test 7: NULL as set (should return full copy of s1)
    result = ft_strtrim("Hello", NULL);
    if (result == NULL || strcmp(result, "Hello") != 0) {
        printf("  FAIL: NULL set input test\n");
        printf("    Expected: 'Hello', Got: '%s'\n", result ? result : "(NULL)");
        free(result);
        failed++;
    } else {
        free(result);
    }

    // Test 8: Trim special characters from ends
    result = ft_strtrim("***Hello***", "*");
    if (result == NULL || strcmp(result, "Hello") != 0) {
        printf("  FAIL: Trim special characters\n");
        printf("    Expected: 'Hello', Got: '%s'\n", result ? result : "(NULL)");
        free(result);
        failed++;
    } else {
        free(result);
    }

    // Print test results
    if (failed == 0)
        printf("  All tests passed!\n\n");
    else
        printf("  %d tests failed!\n\n", failed);
}
