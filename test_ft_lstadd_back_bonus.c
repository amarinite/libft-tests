#include "test_libft.h"

void test_ft_lstadd_back_bonus(void)
{
    printf("Testing ft_lstadd_back:\n");
    int failed = 0;

    // Test 1: Add to empty list
    t_list *list1 = NULL;
    int *val1 = malloc(sizeof(int));
    *val1 = 10;
    t_list *node1 = ft_lstnew(val1);
    ft_lstadd_back(&list1, node1);

    if (list1 != node1 || list1->next != NULL) {
        printf("  FAIL: Add to empty list\n");
        failed++;
    }

    // Test 2: Add to non-empty list
    int *val2 = malloc(sizeof(int));
    *val2 = 20;
    t_list *node2 = ft_lstnew(val2);
    ft_lstadd_back(&list1, node2);

    if (list1->next != node2 || node2->next != NULL) {
        printf("  FAIL: Add to non-empty list\n");
        failed++;
    }

    // Test 3: Add NULL node
    ft_lstadd_back(&list1, NULL); // should do nothing
    if (list1->next != node2 || node2->next != NULL) {
        printf("  FAIL: Add NULL node\n");
        failed++;
    }

    if (failed == 0)
        printf("  All tests passed!\n\n");
    else
        printf("  %d tests failed!\n\n", failed);

    // Free memory
    free(val1);
    free(val2);
    free(node1);
    free(node2);
}
