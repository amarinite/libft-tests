#include "test_libft.h"

void	test_ft_lstsize_bonus()
{
	printf("Testing ft_lstsize:\n");
    int failed = 0;

    // Test 1: Empty list (NULL)
    t_list *empty_list = NULL;
    int size1 = ft_lstsize(empty_list);
    if (size1 != 0) {
        printf("  FAIL: Size of empty list\n");
        printf("    Expected: 0\n");
        printf("    Got: %d\n", size1);
        failed++;
    }

    // Test 2: List with one node
    int *num1 = malloc(sizeof(int));
    *num1 = 42;
    t_list *list = ft_lstnew(num1);
    int size2 = ft_lstsize(list);
    if (size2 != 1) {
        printf("  FAIL: Size of single node list\n");
        printf("    Expected: 1\n");
        printf("    Got: %d\n", size2);
        failed++;
    }

    // Test 3: List with multiple nodes
    int *num2 = malloc(sizeof(int));
    *num2 = 84;
    t_list *node2 = ft_lstnew(num2);
    list->next = node2;

    int size3 = ft_lstsize(list);
    if (size3 != 2) {
        printf("  FAIL: Size of two-node list\n");
        printf("    Expected: 2\n");
        printf("    Got: %d\n", size3);
        failed++;
    }

    // Test 4: Longer list
    int *num3 = malloc(sizeof(int));
    *num3 = 126;
    t_list *node3 = ft_lstnew(num3);
    node2->next = node3;

    int *num4 = malloc(sizeof(int));
    *num4 = 168;
    t_list *node4 = ft_lstnew(num4);
    node3->next = node4;

    int *num5 = malloc(sizeof(int));
    *num5 = 210;
    t_list *node5 = ft_lstnew(num5);
    node4->next = node5;

    int size4 = ft_lstsize(list);
    if (size4 != 5) {
        printf("  FAIL: Size of five-node list\n");
        printf("    Expected: 5\n");
        printf("    Got: %d\n", size4);
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
    free(num4);
    free(num5);
    free(list);
    free(node2);
    free(node3);
    free(node4);
    free(node5);
}
