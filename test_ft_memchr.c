#include "test_libft.h"

void test_ft_memchr(void)
{
    printf("Testing ft_memchr:\n");
    int failed = 0;

    // Test 1: Basic functionality with a character buffer
    char str[] = "Hello, world!";
    char *result1 = ft_memchr(str, 'w', strlen(str));
    char *result2 = memchr(str, 'w', strlen(str));

    if (result1 != result2) {
        printf("  FAIL: Basic test with character buffer\n");
        failed++;
    }

    // Test 2: Character not found
    result1 = ft_memchr(str, 'z', strlen(str));
    result2 = memchr(str, 'z', strlen(str));

    if (result1 != result2) {
        printf("  FAIL: Character not found test\n");
        failed++;
    }

    // Test 3: Search limited to first few characters
    result1 = ft_memchr(str, 'o', 5);  // Should find 'o' at index 4
    result2 = memchr(str, 'o', 5);

    if (result1 != result2) {
        printf("  FAIL: Limited search range test\n");
        failed++;
    }

    // Test 4: Search with n = 0
    result1 = ft_memchr(str, 'H', 0);  // Should return NULL
    result2 = memchr(str, 'H', 0);

    if (result1 != result2) {
        printf("  FAIL: Zero-length test\n");
        failed++;
    }

    // Test 5: Test with binary data (not just strings)
    unsigned char binary[] = {0x10, 0x20, 0x30, 0xFF, 0x40, 0x50};
    void *bin_result1 = ft_memchr(binary, 0xFF, sizeof(binary));
    void *bin_result2 = memchr(binary, 0xFF, sizeof(binary));

    if (bin_result1 != bin_result2) {
        printf("  FAIL: Binary data test\n");
        failed++;
    }

    // Print test results
    if (failed == 0)
        printf("  All tests passed!\n\n");
    else
        printf("  %d tests failed!\n\n", failed);
}
