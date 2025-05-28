#include "test_libft.h"

void test_ft_itoa(void)
{
    printf("Testing ft_itoa:\n");
    int failed = 0;

    struct {
        int input;
        const char *expected;
    } tests[] = {
        {0, "0"},
        {1, "1"},
        {-1, "-1"},
        {42, "42"},
        {-42, "-42"},
        {123456, "123456"},
        {-123456, "-123456"},
        {INT_MAX, "2147483647"},
        {INT_MIN, "-2147483648"},
    };

    int num_tests = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < num_tests; i++) {
        char *result = ft_itoa(tests[i].input);
        if (!result || strcmp(result, tests[i].expected) != 0) {
            printf("  FAIL: ft_itoa(%d)\n", tests[i].input);
            printf("    Expected: '%s', Got: '%s'\n", tests[i].expected, result ? result : "(NULL)");
            failed++;
        }
        free(result);
    }

    // Allocation failure simulation is not feasible without mocking malloc,
    // but we assume malloc failures would return NULL correctly as covered in calloc tests.

    if (failed == 0)
        printf("  All tests passed!\n\n");
    else
        printf("  %d tests failed!\n\n", failed);
}
