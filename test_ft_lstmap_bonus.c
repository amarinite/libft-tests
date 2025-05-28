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

// Helper: Free string content
static void del_str(void *content)
{
    free(content);
}

// Sample function to duplicate string content in uppercase (for ft_lstmap)
static void *map_to_uppercase(void *content)
{
    char *str = (char *)content;
    int len = strlen(str);
    char *newstr = malloc(len + 1);
    if (!newstr)
        return NULL;
    for (int i = 0; i < len; i++)
    {
        char c = str[i];
        if (c >= 'a' && c <= 'z')
            c -= 32;
        newstr[i] = c;
    }
    newstr[len] = '\0';
    return newstr;
}

// Helper: Compare two lists of strings content, returns 1 if equal else 0
static int compare_lists(t_list *l1, t_list *l2)
{
    while (l1 && l2)
    {
        if (strcmp((char *)l1->content, (char *)l2->content) != 0)
            return 0;
        l1 = l1->next;
        l2 = l2->next;
    }
    return (l1 == NULL && l2 == NULL);
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

void test_ft_lstmap_bonus(void)
{
    printf("Testing ft_lstmap:\n");
    int failed = 0;

    // Create list: "abc" -> "def" -> "ghi"
    t_list *lst = create_node_str("abc");
    t_list *node2 = create_node_str("def");
    t_list *node3 = create_node_str("ghi");
    lst->next = node2;
    node2->next = node3;

    // Map list with map_to_uppercase
    t_list *mapped = ft_lstmap(lst, map_to_uppercase, del_str);

    // Expected list: "ABC" -> "DEF" -> "GHI"
    t_list *expected = create_node_str("ABC");
    expected->next = create_node_str("DEF");
    expected->next->next = create_node_str("GHI");

    if (!compare_lists(mapped, expected))
    {
        printf("  FAIL: ft_lstmap did not produce expected transformed list\n");
        printf("  Original list: ");
        print_list(lst);
        printf("  Mapped list:   ");
        print_list(mapped);
        printf("  Expected list: ");
        print_list(expected);
        failed++;
    }

    // Test NULL list or NULL function returns NULL
    if (ft_lstmap(NULL, map_to_uppercase, del_str) != NULL)
    {
        printf("  FAIL: ft_lstmap(NULL, f, del) should return NULL\n");
        failed++;
    }
    if (ft_lstmap(lst, NULL, del_str) != NULL)
    {
        printf("  FAIL: ft_lstmap(lst, NULL, del) should return NULL\n");
        failed++;
    }

    free_list(lst);
    free_list(mapped);
    free_list(expected);

    if (failed == 0)
        printf("  All tests passed!\n\n");
    else
        printf("  %d tests failed!\n\n", failed);
}
