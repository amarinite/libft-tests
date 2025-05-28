#include "test_libft.h"

void test_ft_isalpha(void)
{
    printf("Testing ft_isalpha:\n");
    int failed = 0;

    // Test a range of ASCII values
    for (int c = 0; c <= 127; c++) {
        if ((ft_isalpha(c) != 0) != (isalpha(c) != 0)) {
            printf("  FAIL: ft_isalpha(%d/'%c') = %d, expected %s\n",
                   c, isprint(c) ? c : ' ', ft_isalpha(c),
                   isalpha(c) ? "non-zero" : "zero");
            failed++;
        }
    }

    // Test extended ASCII values (128-255)
    for (int c = 128; c <= 255; c++) {
        if ((ft_isalpha(c) != 0) != (isalpha(c) != 0)) {
            printf("  FAIL: ft_isalpha(%d) = %d, expected %s\n",
                   c, ft_isalpha(c), isalpha(c) ? "non-zero" : "zero");
            failed++;
        }
    }

    // Test some edge cases
    int edge_cases[] = {-1, 256, 1000};
    for (size_t i = 0; i < sizeof(edge_cases) / sizeof(edge_cases[0]); i++) {
        int c = edge_cases[i];
        if ((ft_isalpha(c) != 0) != (isalpha(c) != 0)) {
            printf("  FAIL: ft_isalpha(%d) = %d, expected %s\n",
                   c, ft_isalpha(c), isalpha(c) ? "non-zero" : "zero");
            failed++;
        }
    }

    if (failed == 0)
        printf("  All tests passed!\n\n");
    else
        printf("  %d tests failed!\n\n", failed);
}
