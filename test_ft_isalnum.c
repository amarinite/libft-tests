#include "test_libft.h"

void test_ft_isalnum(void)
{
    printf("Testing ft_isalnum:\n");
    int failed = 0;

    // Test regular ASCII values (0-127)
    for (int c = 0; c <= 127; c++) {
        if ((ft_isalnum(c) != 0) != (isalnum(c) != 0)) {
            printf("  FAIL: ft_isalnum(%d/'%c') = %d, expected %s\n",
                   c, isprint(c) ? c : ' ', ft_isalnum(c),
                   isalnum(c) ? "non-zero" : "zero");
            failed++;
        }
    }

    // Test extended ASCII values (128-255)
    for (int c = 128; c <= 255; c++) {
        if ((ft_isalnum(c) != 0) != (isalnum(c) != 0)) {
            printf("  FAIL: ft_isalnum(%d) = %d, expected %s\n",
                   c, ft_isalnum(c), isalnum(c) ? "non-zero" : "zero");
            failed++;
        }
    }

    // Test some edge cases
    int edge_cases[] = {-1, 256, 1000};
    for (size_t i = 0; i < sizeof(edge_cases) / sizeof(edge_cases[0]); i++) {
        int c = edge_cases[i];
        if ((ft_isalnum(c) != 0) != (isalnum(c) != 0)) {
            printf("  FAIL: ft_isalnum(%d) = %d, expected %s\n",
                   c, ft_isalnum(c), isalnum(c) ? "non-zero" : "zero");
            failed++;
        }
    }

    if (failed == 0)
        printf("  All tests passed!\n\n");
    else
        printf("  %d tests failed Lol what a looser!\n\n", failed);
}
