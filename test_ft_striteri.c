#include "test_libft.h"

// Sample function to pass to ft_striteri
void to_uppercase(unsigned int i, char *c)
{
    (void)i;
    if (*c >= 'a' && *c <= 'z')
        *c = *c - 32;
}

// Another sample function to test index-based transformation
void add_index_to_char(unsigned int i, char *c)
{
    *c += i;
}

void test_ft_striteri(void)
{
    printf("Testing ft_striteri:\n");
    int failed = 0;

    // Test 1: Uppercase conversion
    char str1[] = "hello";
    ft_striteri(str1, to_uppercase);
    if (strcmp(str1, "HELLO") != 0) {
        printf("  FAIL: Convert lowercase to uppercase\n");
        printf("    Expected: 'HELLO', Got: '%s'\n", str1);
        failed++;
    }

    // Test 2: Add index to each character
    char str2[] = "abcd";
    ft_striteri(str2, add_index_to_char);
    if (strcmp(str2, "aceg") != 0) {
        printf("  FAIL: Add index to each character\n");
        printf("    Expected: 'aceg', Got: '%s'\n", str2);
        failed++;
    }

    // Test 3: NULL string input (should do nothing, not crash)
    ft_striteri(NULL, to_uppercase); // no crash = pass

    // Test 4: NULL function input (should do nothing, not crash)
    char str3[] = "test";
    ft_striteri(str3, NULL);
    if (strcmp(str3, "test") != 0) {
        printf("  FAIL: NULL function pointer should not modify string\n");
        printf("    Expected: 'test', Got: '%s'\n", str3);
        failed++;
    }

    // Test 5: Empty string input
    char str4[] = "";
    ft_striteri(str4, to_uppercase);
    if (strcmp(str4, "") != 0) {
        printf("  FAIL: Empty string test\n");
        printf("    Expected: '', Got: '%s'\n", str4);
        failed++;
    }

    // Print results
    if (failed == 0)
        printf("  All tests passed!\n\n");
    else
        printf("  %d tests failed!\n\n", failed);
}
