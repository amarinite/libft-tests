#include "test_libft.h"

// Helper: Create a new list node with strdup'd string content
static t_list *create_node_str(const char *s)
{
    t_list *node = malloc(sizeof(t_list));
    if (!node)
        return NULL;
    node->content = strdup(s);
    node->next = NULL;
    return node;
}

// Sample function to uppercase string content (assumes content is char *)
static void to_uppercase_content(void *content)
{
    char *str = (char *)content;
    for (int i = 0; str[i]; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
    }
}

// Helper: Free whole list
static void free_list(t_list *lst)
{
    t_list *tmp;
    while (lst)
    {
        tmp = lst->next;
        free(lst->content);
        free(lst);
        lst = tmp;
    }
}

static void print_list(t_list *lst)
{
    while (lst)
    {
        printf("'%s' -> ", (char *)lst->content);
        lst = lst->next;
    }
    printf("NULL\n");
}

void test_ft_lstiter_bonus(void)
{
    printf("Testing ft_lstiter:\n");
    int failed = 0;

    // Create list: "hello" -> "world" -> "test"
    t_list *lst = create_node_str("hello");
    t_list *node2 = create_node_str("world");
    t_list *node3 = create_node_str("test");
    lst->next = node2;
    node2->next = node3;

    ft_lstiter(lst, to_uppercase_content);

    // Expected: "HELLO" -> "WORLD" -> "TEST"
    if (strcmp((char *)lst->content, "HELLO") != 0 ||
        strcmp((char *)lst->next->content, "WORLD") != 0 ||
        strcmp((char *)lst->next->next->content, "TEST") != 0)
    {
        printf("  FAIL: ft_lstiter did not uppercase all nodes\n");
        print_list(lst);
        failed++;
    }

    // Test NULL list and NULL function (should not crash)
    ft_lstiter(NULL, to_uppercase_content);
    ft_lstiter(lst, NULL);

    free_list(lst);

    if (failed == 0)
        printf("  All tests passed!\n\n");
    else
        printf("  %d tests failed!\n\n", failed);
}
