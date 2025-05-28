#include "test_libft.h"

void test_ft_lstlast_bonus(void)
{
    printf("Testing ft_lstlast:\n");
    int failed = 0;

    // Test 1: Empty list (NULL)
    t_list *empty_list = NULL;
    t_list *result1 = ft_lstlast(empty_list);
    if (result1 != NULL) {
        printf("  FAIL: Last node of empty list\n");
        printf("    Expected: NULL\n");
        printf("    Got: %p\n", result1);
        failed++;
    }

    // Test 2: List with one node
    int *num1 = malloc(sizeof(int));
    *num1 = 42;
    t_list *single_node = ft_lstnew(num1);
    t_list *result2 = ft_lstlast(single_node);
    if (result2 != single_node) {
        printf("  FAIL: Last node of single node list\n");
        printf("    Expected: %p\n", single_node);
        printf("    Got: %p\n", result2);
        failed++;
    }

    // Test 3: List with multiple nodes
    int *num2 = malloc(sizeof(int));
    *num2 = 84;
    t_list *second_node = ft_lstnew(num2);
    single_node->next = second_node;

    int *num3 = malloc(sizeof(int));
    *num3 = 168;
    t_list *third_node = ft_lstnew(num3);
    second_node->next = third_node;

    t_list *result3 = ft_lstlast(single_node);
    if (result3 != third_node) {
        printf("  FAIL: Last node of multi-node list\n");
        printf("    Expected: %p (third node)\n", third_node);
        printf("    Got: %p\n", result3);
        failed++;
    }

    // Print test results
    if (failed == 0)
        printf("  All tests passed!\n\n");
    else
        printf("  %d tests failed!\n\n", failed);

    // Free allocated memory
    free(num1);
    free(num2);
    free(num3);
    free(third_node);
    free(second_node);
    free(single_node);
}
