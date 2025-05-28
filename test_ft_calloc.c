#include "test_libft.h"

void test_ft_calloc(void)
{
    printf("Testing ft_calloc:\n");
    int failed = 0;

    // Test 1: Basic functionality with integers
    int *int_arr1 = (int *)ft_calloc(5, sizeof(int));
    int *int_arr2 = (int *)calloc(5, sizeof(int));

    if (int_arr1 && int_arr2) {
        if (memcmp(int_arr1, int_arr2, 5 * sizeof(int)) != 0) {
            printf("  FAIL: Basic test with integer array\n");
            failed++;
        }

        // Write to arrays to ensure they're properly allocated
        for (int i = 0; i < 5; i++) {
            int_arr1[i] = int_arr2[i] = i + 100;
        }

        if (memcmp(int_arr1, int_arr2, 5 * sizeof(int)) != 0) {
            printf("  FAIL: Write test with integer array\n");
            failed++;
        }

        free(int_arr1);
        free(int_arr2);
    } else {
        printf("  FAIL: Memory allocation failed for basic test\n");
        failed++;
    }

    // Test 2: Test with character array
    char *char_arr1 = (char *)ft_calloc(10, sizeof(char));
    char *char_arr2 = (char *)calloc(10, sizeof(char));

    if (char_arr1 && char_arr2) {
        if (memcmp(char_arr1, char_arr2, 10) != 0) {
            printf("  FAIL: Test with character array\n");
            failed++;
        }

        // Test string functionality
        strcpy(char_arr1, "hello");
        strcpy(char_arr2, "hello");

        if (strcmp(char_arr1, char_arr2) != 0) {
            printf("  FAIL: String test after calloc\n");
            failed++;
        }

        free(char_arr1);
        free(char_arr2);
    } else {
        printf("  FAIL: Memory allocation failed for character test\n");
        failed++;
    }

    // Test 3: Test with zero elements
    void *zero_arr1 = ft_calloc(0, sizeof(int));
    void *zero_arr2 = calloc(0, sizeof(int));

    // Some implementations return NULL for zero size, others return a valid pointer
    // We just check that both implementations behave the same way
    if ((zero_arr1 == NULL) != (zero_arr2 == NULL)) {
        printf("  FAIL: Zero elements test inconsistent\n");
        failed++;
    }

    if (zero_arr1) free(zero_arr1);
    if (zero_arr2) free(zero_arr2);

    // Test 4: Test with oversized allocation (should return NULL)
    size_t huge_size = (size_t)-1 / 2;
    void *huge_arr1 = ft_calloc(2, huge_size);
    void *huge_arr2 = calloc(2, huge_size);

    if ((huge_arr1 == NULL) != (huge_arr2 == NULL)) {
        printf("  FAIL: Oversized allocation test inconsistent\n");
        failed++;
    }

    if (huge_arr1) free(huge_arr1);
    if (huge_arr2) free(huge_arr2);

    // Test 5: Test with struct
    typedef struct {
        int x;
        char y;
        double z;
    } test_struct;

    test_struct *struct_arr1 = (test_struct *)ft_calloc(3, sizeof(test_struct));
    test_struct *struct_arr2 = (test_struct *)calloc(3, sizeof(test_struct));

    if (struct_arr1 && struct_arr2) {
        if (memcmp(struct_arr1, struct_arr2, 3 * sizeof(test_struct)) != 0) {
            printf("  FAIL: Struct allocation test\n");
            failed++;
        }

        free(struct_arr1);
        free(struct_arr2);
    } else {
        printf("  FAIL: Memory allocation failed for struct test\n");
        failed++;
    }

    // Print test results
    if (failed == 0)
        printf("  All tests passed!\n\n");
    else
        printf("  %d tests failed!\n\n", failed);
}
