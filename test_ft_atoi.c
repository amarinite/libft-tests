#include "test_libft.h"

void test_ft_atoi(void)
{
    printf("Testing ft_atoi:\n");
    int failed = 0;

    // Test 1: Basic positive numbers
    char num1[] = "12345";
    if (ft_atoi(num1) != atoi(num1)) {
        printf("  FAIL: Basic positive number test\n");
        printf("    ft_atoi: %d, atoi: %d\n", ft_atoi(num1), atoi(num1));
        failed++;
    }

    // Test 2: Basic negative numbers
    char num2[] = "-42";
    if (ft_atoi(num2) != atoi(num2)) {
        printf("  FAIL: Basic negative number test\n");
        printf("    ft_atoi: %d, atoi: %d\n", ft_atoi(num2), atoi(num2));
        failed++;
    }

    // Test 3: Leading whitespace
    char num3[] = "  \t\n\v\f\r 789";
    if (ft_atoi(num3) != atoi(num3)) {
        printf("  FAIL: Leading whitespace test\n");
        printf("    ft_atoi: %d, atoi: %d\n", ft_atoi(num3), atoi(num3));
        failed++;
    }

    // Test 4: Leading sign
    char num4[] = "+123";
    if (ft_atoi(num4) != atoi(num4)) {
        printf("  FAIL: Leading plus sign test\n");
        printf("    ft_atoi: %d, atoi: %d\n", ft_atoi(num4), atoi(num4));
        failed++;
    }

    // Test 5: Non-digit characters after number
    char num5[] = "456abc";
    if (ft_atoi(num5) != atoi(num5)) {
        printf("  FAIL: Non-digit characters after number test\n");
        printf("    ft_atoi: %d, atoi: %d\n", ft_atoi(num5), atoi(num5));
        failed++;
    }

    // Test 6: Non-digit characters before number
    char num6[] = "abc123";
    if (ft_atoi(num6) != atoi(num6)) {
        printf("  FAIL: Non-digit characters before number test\n");
        printf("    ft_atoi: %d, atoi: %d\n", ft_atoi(num6), atoi(num6));
        failed++;
    }

    // Test 7: Zero
    char num7[] = "0";
    if (ft_atoi(num7) != atoi(num7)) {
        printf("  FAIL: Zero test\n");
        printf("    ft_atoi: %d, atoi: %d\n", ft_atoi(num7), atoi(num7));
        failed++;
    }

    // Test 8: Whitespace and sign
    char num8[] = "  \t-42";
    if (ft_atoi(num8) != atoi(num8)) {
        printf("  FAIL: Whitespace and sign test\n");
        printf("    ft_atoi: %d, atoi: %d\n", ft_atoi(num8), atoi(num8));
        failed++;
    }

    // Test 9: Empty string
    char num9[] = "";
    if (ft_atoi(num9) != atoi(num9)) {
        printf("  FAIL: Empty string test\n");
        printf("    ft_atoi: %d, atoi: %d\n", ft_atoi(num9), atoi(num9));
        failed++;
    }

    // Print test results
    if (failed == 0)
        printf("  All tests passed!\n\n");
    else
        printf("  %d tests failed!\n\n", failed);
}
