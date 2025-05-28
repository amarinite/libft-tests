#include "test_libft.h"

static int del_called = 0;

static void del_tracker(void *content)
{
    del_called = 1;
    free(content);
}

void test_ft_lstdelone_bonus(void)
{
    printf("Testing ft_lstdelone:\n");
    int failed = 0;

    // Test 1: Normal deletion (should call del)
    del_called = 0;
    int *val = malloc(sizeof(int));
    *val = 99;
    t_list *node = ft_lstnew(val);

    ft_lstdelone(node, del_tracker);

    if (del_called == 0) {
        printf("  FAIL: del was not called for normal deletion\n");
        failed++;
    }

    // Test 2: Null node (should not crash, del should not be called)
    del_called = 0;
    ft_lstdelone(NULL, del_tracker);
    if (del_called != 0) {
        printf("  FAIL: del should not be called for NULL node\n");
        failed++;
    }

    // Test 3: Null del (should not crash, content should remain untouched)
    t_list *dummy = ft_lstnew(NULL);
    ft_lstdelone(dummy, NULL); // Should not call del or crash
    // can't check if it leaked, but test passes if no crash

    if (failed == 0)
        printf("  All tests passed!\n\n");
    else
        printf("  %d tests failed!\n\n", failed);
}
