#include "test_libft.h"

void test_ft_strjoin(void)
{
    printf("Testing ft_strjoin:\n");
    int failed = 0;
    char *result;
    char *expected;

    // Test 1: Normal case - joining two non-empty strings
    {
        char *s1 = "Hello, ";
        char *s2 = "world!";
        result = ft_strjoin(s1, s2);
        expected = "Hello, world!";

        if (strcmp(result, expected) != 0) {
            printf("  FAIL: Normal case test\n");
            printf("    Expected: \"%s\", Got: \"%s\"\n", expected, result);
            failed++;
        }
        free(result);
    }

    // Test 2: s1 is NULL
    {
        char *s1 = NULL;
        char *s2 = "Only s2 exists";
        result = ft_strjoin(s1, s2);
        expected = "Only s2 exists";

        if (strcmp(result, expected) != 0) {
            printf("  FAIL: s1 is NULL test\n");
            printf("    Expected: \"%s\", Got: \"%s\"\n", expected, result);
            failed++;
        }
        free(result);
    }

    // Test 3: s2 is NULL
    {
        char *s1 = "Only s1 exists";
        char *s2 = NULL;
        result = ft_strjoin(s1, s2);
        expected = "Only s1 exists";

        if (strcmp(result, expected) != 0) {
            printf("  FAIL: s2 is NULL test\n");
            printf("    Expected: \"%s\", Got: \"%s\"\n", expected, result);
            failed++;
        }
        free(result);
    }

    // Test 4: Both are NULL
    {
        char *s1 = NULL;
        char *s2 = NULL;
        result = ft_strjoin(s1, s2);

        if (result != NULL) {
            printf("  FAIL: Both NULL test\n");
            printf("    Expected: NULL, Got: \"%s\"\n", result);
            failed++;
            free(result);
        }
    }

    // Test 5: Empty strings
    {
        char *s1 = "";
        char *s2 = "";
        result = ft_strjoin(s1, s2);
        expected = "";

        if (strcmp(result, expected) != 0) {
            printf("  FAIL: Empty strings test\n");
            printf("    Expected: \"%s\", Got: \"%s\"\n", expected, result);
            failed++;
        }
        free(result);
    }

    // Test 6: One empty string, one non-empty string
    {
        char *s1 = "";
        char *s2 = "non-empty";
        result = ft_strjoin(s1, s2);
        expected = "non-empty";

        if (strcmp(result, expected) != 0) {
            printf("  FAIL: First string empty test\n");
            printf("    Expected: \"%s\", Got: \"%s\"\n", expected, result);
            failed++;
        }
        free(result);
    }

    // Test 7: One non-empty string, one empty string
    {
        char *s1 = "non-empty";
        char *s2 = "";
        result = ft_strjoin(s1, s2);
        expected = "non-empty";

        if (strcmp(result, expected) != 0) {
            printf("  FAIL: Second string empty test\n");
            printf("    Expected: \"%s\", Got: \"%s\"\n", expected, result);
            failed++;
        }
        free(result);
    }

    // Print test results
    if (failed == 0)
        printf("  All tests passed!\n\n");
    else
        printf("  %d tests failed!\n\n", failed);
}
