#include "test_libft.h"

void test_ft_strdup(void)
{
    printf("Testing ft_strdup:\n");
    int failed = 0;

    // Test 1: Basic string duplication
    const char *s1 = "Hello, world!";
    char *res1 = ft_strdup(s1);
    if (!res1 || strcmp(res1, s1) != 0) {
        printf("  FAIL: Basic duplication\n");
        printf("    Expected: '%s', Got: '%s'\n", s1, res1 ? res1 : "(NULL)");
        failed++;
    }
    free(res1);

    // Test 2: Duplication of empty string
    const char *s2 = "";
    char *res2 = ft_strdup(s2);
    if (!res2 || strcmp(res2, s2) != 0) {
        printf("  FAIL: Duplication of empty string\n");
        printf("    Expected: '', Got: '%s'\n", res2 ? res2 : "(NULL)");
        failed++;
    }
    free(res2);

    // Test 3: Duplication with special characters
    const char *s3 = "123\n\t!@#";
    char *res3 = ft_strdup(s3);
    if (!res3 || strcmp(res3, s3) != 0) {
        printf("  FAIL: Duplication with special characters\n");
        printf("    Expected: '%s', Got: '%s'\n", s3, res3 ? res3 : "(NULL)");
        failed++;
    }
    free(res3);

    // Test 4: Ensure result is null-terminated
    const char *s4 = "Test";
    char *res4 = ft_strdup(s4);
    if (!res4 || res4[ft_strlen(s4)] != '\0') {
        printf("  FAIL: Result is not null-terminated\n");
        failed++;
    }
    free(res4);

    // Test 5: Make sure original and copy don't share memory
    const char *s5 = "No aliasing!";
    char *res5 = ft_strdup(s5);
    if (!res5 || res5 == s5) {
        printf("  FAIL: Memory aliasing detected\n");
        failed++;
    }
    free(res5);

    // Print test results
    if (failed == 0)
        printf("  All tests passed!\n\n");
    else
        printf("  %d tests failed!\n\n", failed);
}
