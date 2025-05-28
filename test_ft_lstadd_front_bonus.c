#include "test_libft.h"

void test_ft_lstadd_front_bonus(void)
{
    printf("Testing ft_lstadd_front:\n");
    int failed = 0;

    // Test 1: Add to NULL list
    t_list *list1 = NULL;
    int *num1 = malloc(sizeof(int));
    *num1 = 42;
    t_list *new_node1 = ft_lstnew(num1);

    ft_lstadd_front(&list1, new_node1);
    if (list1 != new_node1) {
        printf("  FAIL: Add to NULL list\n");
        printf("    Expected: list points to new node\n");
        printf("    Got: list=%p, new_node=%p\n", list1, new_node1);
        failed++;
    }

    // Test 2: Add to existing list
    int *num2 = malloc(sizeof(int));
    *num2 = 84;
    t_list *new_node2 = ft_lstnew(num2);

    ft_lstadd_front(&list1, new_node2);
    if (list1 != new_node2 || list1->next != new_node1) {
        printf("  FAIL: Add to existing list\n");
        printf("    Expected: list points to new node, new_node->next points to old first node\n");
        printf("    Got: list=%p, new_node=%p, list->next=%p, old_first=%p\n",
            list1, new_node2, list1 ? list1->next : NULL, new_node1);
        failed++;
    }

    // Test 3: Multiple additions to check order
    int *num3 = malloc(sizeof(int));
    *num3 = 168;
    t_list *new_node3 = ft_lstnew(num3);

    ft_lstadd_front(&list1, new_node3);
    if (list1 != new_node3 || list1->next != new_node2 || list1->next->next != new_node1) {
        printf("  FAIL: Multiple additions to check order\n");
        printf("    Expected: correct order - node3->node2->node1\n");
        printf("    Got: first=%p, node3=%p, next=%p, node2=%p, next->next=%p, node1=%p\n",
            list1, new_node3, list1 ? list1->next : NULL, new_node2,
            list1 && list1->next ? list1->next->next : NULL, new_node1);
        failed++;
    }

    // Test 4: Add node with NULL content
    t_list *new_node4 = ft_lstnew(NULL);
    ft_lstadd_front(&list1, new_node4);
    if (list1 != new_node4 || list1->next != new_node3) {
        printf("  FAIL: Add node with NULL content\n");
        printf("    Expected: list points to new node with NULL content\n");
        printf("    Got: list=%p, new_node=%p, list->next=%p, node3=%p\n",
            list1, new_node4, list1 ? list1->next : NULL, new_node3);
        failed++;
    }

    // Test 5: Add to list pointer initialized with allocated but empty list
    t_list **list_ptr = malloc(sizeof(t_list*));
    *list_ptr = NULL;
    int *num5 = malloc(sizeof(int));
    *num5 = 255;
    t_list *new_node5 = ft_lstnew(num5);

    ft_lstadd_front(list_ptr, new_node5);
    if (*list_ptr != new_node5) {
        printf("  FAIL: Add to allocated list pointer\n");
        printf("    Expected: list pointer points to new node\n");
        printf("    Got: list_ptr=%p, *list_ptr=%p, new_node=%p\n",
            list_ptr, *list_ptr, new_node5);
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
    free(num5);
    free(new_node1);
    free(new_node2);
    free(new_node3);
    free(new_node4);
    free(new_node5);
    free(list_ptr);
}
