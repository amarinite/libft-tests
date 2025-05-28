#include "test_libft.h"

void test_ft_strlen(void)
{
    printf("Testing ft_strlen:\n");
    int failed = 0;

    // Test cases
    const char *test_strings[] = {
        "",
        "a",
        "hello",
        "This is a longer test string",
        "1234567890",
        "Special chars: !@#$%^&*()"
    };

    for (size_t i = 0; i < sizeof(test_strings) / sizeof(test_strings[0]); i++) {
        int orig = strlen(test_strings[i]);
        int yours = ft_strlen(test_strings[i]);

        if (orig != yours) {
            printf("  FAIL: ft_strlen(\"%s\") = %d, expected %d\n",
                   test_strings[i], yours, orig);
            failed++;
        }
    }

    if (failed == 0)
        printf("  All tests passed!\n\n");
    else
        printf("  %d tests failed!\n\n", failed);
}
