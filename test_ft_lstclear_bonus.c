#include "test_libft.h"

static void del_content(void *content)
{
    free(content);
}

typedef struct s_data {
    int x;
    char y;
} t_data;


void test_ft_lstclear_bonus(void)
{
    printf("Testing ft_lstclear:\n");
    int failed = 0;

    // Test 1: Clear a list of 3 nodes
    t_list *head = NULL;
    for (int i = 0; i < 3; i++) {
        int *val = malloc(sizeof(int));
        *val = i;
        t_list *node = ft_lstnew(val);
        ft_lstadd_back(&head, node);
    }

    ft_lstclear(&head, del_content);

    if (head != NULL) {
        printf("  FAIL: List not cleared\n");
        failed++;
    }

    // Test 2: Clear NULL list
    ft_lstclear(NULL, del_content); // Should do nothing

    // Test 3: Clear with NULL del
    t_list *node = ft_lstnew(malloc(sizeof(int)));
    *(int*)node->content = 42;
    t_list *temp = node;
    ft_lstclear(&temp, NULL); // Should do nothing or crash; we are testing that it doesn't crash

    free(node->content); // manually free since clear failed
    free(node);

    // Test 4: Clear list with custom struct content
    t_list *struct_list = NULL;
    for (int i = 0; i < 2; i++) {
        t_data *data = malloc(sizeof(t_data));
        data->x = i * 10;
        data->y = 'A' + i;
        t_list *s_node = ft_lstnew(data);
        ft_lstadd_back(&struct_list, s_node);
    }

    ft_lstclear(&struct_list, del_content);

    if (struct_list != NULL) {
        printf("  FAIL: List not cleared (struct list)\n");
        failed++;
    }

    if (failed == 0)
        printf("  All tests passed!\n\n");
    else
        printf("  %d tests failed!\n\n", failed);
}
