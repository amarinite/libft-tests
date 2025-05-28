#include "test_libft.h"

void test_ft_strlcat(void)
{
    int failed = 0;

    printf("Testing ft_strcat:\n");

    // Test 1: Normal case - append to a string with enough space
    char dest1[30] = "Hello, ";
    char dest1_std[30] = "Hello, ";
    const char *src1 = "world!";

    size_t ret1 = ft_strlcat(dest1, src1, sizeof(dest1));
    size_t ret1_std = strlcat(dest1_std, src1, sizeof(dest1_std));

    if (strcmp(dest1, dest1_std) != 0 || ret1 != ret1_std) {
        printf("  FAIL: Test 1 - Normal case\n");
        printf("  Expected: '%s' (return %zu)\n", dest1_std, ret1_std);
        printf("  Got: '%s' (return %zu)\n", dest1, ret1);
        failed++;
    }

    // Test 2: Dest has exactly enough space for src + NULL
    char dest2[13] = "Hello, ";
    char dest2_std[13] = "Hello, ";
    const char *src2 = "world!";

    size_t ret2 = ft_strlcat(dest2, src2, sizeof(dest2));
    size_t ret2_std = strlcat(dest2_std, src2, sizeof(dest2_std));

    if (strcmp(dest2, dest2_std) != 0 || ret2 != ret2_std) {
        printf("  FAIL: Test 2 - Exact space\n");
        printf("  Expected: '%s' (return %zu)\n", dest2_std, ret2_std);
        printf("  Got: '%s' (return %zu)\n", dest2, ret2);
        failed++;
    }

    // Test 3: Truncation - not enough space for all of src
    char dest3[10] = "Hello, ";
    char dest3_std[10] = "Hello, ";
    const char *src3 = "world!";

    size_t ret3 = ft_strlcat(dest3, src3, sizeof(dest3));
    size_t ret3_std = strlcat(dest3_std, src3, sizeof(dest3_std));

    if (strcmp(dest3, dest3_std) != 0 || ret3 != ret3_std) {
        printf("  FAIL: Test 3 - Truncation\n");
        printf("  Expected: '%s' (return %zu)\n", dest3_std, ret3_std);
        printf("  Got: '%s' (return %zu)\n", dest3, ret3);
        failed++;
    }

    // Test 4: Empty dest string
    char dest4[20] = "";
    char dest4_std[20] = "";
    const char *src4 = "Hello!";

    size_t ret4 = ft_strlcat(dest4, src4, sizeof(dest4));
    size_t ret4_std = strlcat(dest4_std, src4, sizeof(dest4_std));

    if (strcmp(dest4, dest4_std) != 0 || ret4 != ret4_std) {
        printf("  FAIL: Test 4 - Empty dest\n");
        printf("  Expected: '%s' (return %zu)\n", dest4_std, ret4_std);
        printf("  Got: '%s' (return %zu)\n", dest4, ret4);
        failed++;
    }

    // Test 5: Empty src string
    char dest5[20] = "Hello!";
    char dest5_std[20] = "Hello!";
    const char *src5 = "";

    size_t ret5 = ft_strlcat(dest5, src5, sizeof(dest5));
    size_t ret5_std = strlcat(dest5_std, src5, sizeof(dest5_std));

    if (strcmp(dest5, dest5_std) != 0 || ret5 != ret5_std) {
        printf("  FAIL: Test 5 - Empty src\n");
        printf("  Expected: '%s' (return %zu)\n", dest5_std, ret5_std);
        printf("  Got: '%s' (return %zu)\n", dest5, ret5);
        failed++;
    }

    // Test 6: Size is 0
    char dest6[20] = "Hello!";
    char dest6_std[20] = "Hello!";
    const char *src6 = "World";

    size_t ret6 = ft_strlcat(dest6, src6, 0);
    size_t ret6_std = strlcat(dest6_std, src6, 0);

    if (strcmp(dest6, dest6_std) != 0 || ret6 != ret6_std) {
        printf("  FAIL: Test 6 - Size is 0\n");
        printf("  Expected: '%s' (return %zu)\n", dest6_std, ret6_std);
        printf("  Got: '%s' (return %zu)\n", dest6, ret6);
        failed++;
    }

    // Test 7: Size is less than dest len
    char dest7[20] = "Hello!";
    char dest7_std[20] = "Hello!";
    const char *src7 = "World";

    size_t ret7 = ft_strlcat(dest7, src7, 3);
    size_t ret7_std = strlcat(dest7_std, src7, 3);

    if (strcmp(dest7, dest7_std) != 0 || ret7 != ret7_std) {
        printf("  FAIL: Test 7 - Size less than dest len\n");
        printf("  Expected: '%s' (return %zu)\n", dest7_std, ret7_std);
        printf("  Got: '%s' (return %zu)\n", dest7, ret7);
        failed++;
    }

    // Test 8: Size is exactly dest len
    char dest8[20] = "Hello!";
    char dest8_std[20] = "Hello!";
    const char *src8 = "World";

    size_t ret8 = ft_strlcat(dest8, src8, 6);
    size_t ret8_std = strlcat(dest8_std, src8, 6);

    if (strcmp(dest8, dest8_std) != 0 || ret8 != ret8_std) {
        printf("  FAIL: Test 8 - Size equals dest len\n");
        printf("  Expected: '%s' (return %zu)\n", dest8_std, ret8_std);
        printf("  Got: '%s' (return %zu)\n", dest8, ret8);
        failed++;
    }

    // Test 9: Large strings
    char dest9[100];
    char dest9_std[100];
    memset(dest9, 'A', 50);
    memset(dest9_std, 'A', 50);
    dest9[50] = '\0';
    dest9_std[50] = '\0';

    char src9[50];
    memset(src9, 'B', 48);
    src9[48] = '\0';

    size_t ret9 = ft_strlcat(dest9, src9, sizeof(dest9));
    size_t ret9_std = strlcat(dest9_std, src9, sizeof(dest9_std));

    if (strcmp(dest9, dest9_std) != 0 || ret9 != ret9_std) {
        printf("  FAIL: Test 9 - Large strings\n");
        printf("  Expected return: %zu\n", ret9_std);
        printf("  Got return: %zu\n", ret9);
        failed++;
    }

    // Print final result
    if (failed == 0)
        printf("  All tests passed!\n\n");
    else
        printf("  Failed %d test(s)\n\n", failed);

}
