#include "test_libft.h"

void test_ft_lstnew_bonus(void)
{
    printf("Testing ft_lstnew:\n");
    int failed = 0;

    // Test 1: Create a node with integer content
    int *num = malloc(sizeof(int));
    *num = 42;
    t_list *node1 = ft_lstnew(num);

    if (node1 == NULL || node1->content != num || *(int*)node1->content != 42 || node1->next != NULL) {
        printf("  FAIL: Create node with integer content\n");
        printf("    Expected: content=42, next=NULL\n");
        printf("    Got: %s, content=%d, next=%p\n",
            node1 ? "node created" : "NULL node",
            node1 ? *(int*)node1->content : 0,
            node1 ? node1->next : NULL);
        failed++;
    }

    // Test 2: Create a node with string content
    char *str = strdup("Hello, world!");
    t_list *node2 = ft_lstnew(str);

    if (node2 == NULL || node2->content != str || strcmp((char*)node2->content, "Hello, world!") != 0 || node2->next != NULL) {
        printf("  FAIL: Create node with string content\n");
        printf("    Expected: content=\"Hello, world!\", next=NULL\n");
        printf("    Got: %s, content=\"%s\", next=%p\n",
            node2 ? "node created" : "NULL node",
            node2 ? (char*)node2->content : "(NULL)",
            node2 ? node2->next : NULL);
        failed++;
    }

    // Test 3: Create a node with NULL content
    t_list *node3 = ft_lstnew(NULL);

    if (node3 == NULL || node3->content != NULL || node3->next != NULL) {
        printf("  FAIL: Create node with NULL content\n");
        printf("    Expected: content=NULL, next=NULL\n");
        printf("    Got: %s, content=%p, next=%p\n",
            node3 ? "node created" : "NULL node",
            node3 ? node3->content : NULL,
            node3 ? node3->next : NULL);
        failed++;
    }

    // Test 4: Create a node with empty string
    char *empty_str = strdup("");
    t_list *node4 = ft_lstnew(empty_str);

    if (node4 == NULL || node4->content != empty_str || strcmp((char*)node4->content, "") != 0 || node4->next != NULL) {
        printf("  FAIL: Create node with empty string\n");
        printf("    Expected: content=\"\", next=NULL\n");
        printf("    Got: %s, content=\"%s\", next=%p\n",
            node4 ? "node created" : "NULL node",
            node4 ? (char*)node4->content : "(NULL)",
            node4 ? node4->next : NULL);
        failed++;
    }

    // Test 5: Create a node with structure content
    typedef struct s_data {
        int a;
        char b;
    } t_data;

    t_data *data = malloc(sizeof(t_data));
    data->a = 100;
    data->b = 'X';
    t_list *node5 = ft_lstnew(data);

    if (node5 == NULL || node5->content != data ||
        ((t_data*)node5->content)->a != 100 ||
        ((t_data*)node5->content)->b != 'X' ||
        node5->next != NULL) {
        printf("  FAIL: Create node with structure content\n");
        printf("    Expected: content={a=100, b='X'}, next=NULL\n");
        printf("    Got: %s, content={a=%d, b='%c'}, next=%p\n",
            node5 ? "node created" : "NULL node",
            node5 ? ((t_data*)node5->content)->a : 0,
            node5 ? ((t_data*)node5->content)->b : '0',
            node5 ? node5->next : NULL);
        failed++;
    }

    // Print test results
    if (failed == 0)
        printf("  All tests passed!\n\n");
    else
        printf("  %d tests failed!\n\n", failed);

    // Free allocated memory
    free(num);
    free(str);
    free(empty_str);
    free(data);
    free(node1);
    free(node2);
    free(node3);
    free(node4);
    free(node5);
}
