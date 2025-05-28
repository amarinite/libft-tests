#include "test_libft.h"

static void	print_split_result(char **result)
{
	if (!result)
	{
		printf("(NULL)\n");
		return;
	}
	int i = 0;
	printf("[");
	while (result[i])
	{
		printf("\"%s\"", result[i]);
		if (result[i + 1])
			printf(", ");
		i++;
	}
	printf("]\n");
}

static void	free_split_result(char **result)
{
	if (!result)
		return;
	int i = 0;
	while (result[i])
		free(result[i++]);
	free(result);
}

void test_ft_split(void)
{
	printf("Testing ft_split:\n");
	int failed = 0;
	char **result;

	// Test 1: Normal case
	result = ft_split("Hello world this is C", ' ');
	if (!result || strcmp(result[0], "Hello") || strcmp(result[1], "world") ||
		strcmp(result[2], "this") || strcmp(result[3], "is") || strcmp(result[4], "C") || result[5] != NULL)
	{
		printf("  FAIL: Normal split\n");
		printf("    Expected: [\"Hello\", \"world\", \"this\", \"is\", \"C\"]\n    Got: ");
		print_split_result(result);
		free_split_result(result);
		failed++;
	}
	else
		free_split_result(result);

	// Test 2: String with consecutive delimiters
	result = ft_split("Hello,,World", ',');
	if (!result || strcmp(result[0], "Hello") || strcmp(result[1], "World") || result[2] != NULL)
	{
		printf("  FAIL: Consecutive delimiters\n");
		printf("    Expected: [\"Hello\", \"World\"]\n    Got: ");
		print_split_result(result);
		free_split_result(result);
		failed++;
	}
	else
		free_split_result(result);

	// Test 3: String with only delimiters
	result = ft_split(",,,", ',');
	if (!result || result[0] != NULL)
	{
		printf("  FAIL: Only delimiters\n");
		printf("    Expected: []\n    Got: ");
		print_split_result(result);
		free_split_result(result);
		failed++;
	}
	else
		free_split_result(result);

	// Test 4: Empty string
	result = ft_split("", ',');
	if (!result || result[0] != NULL)
	{
		printf("  FAIL: Empty string\n");
		printf("    Expected: []\n    Got: ");
		print_split_result(result);
		free_split_result(result);
		failed++;
	}
	else
		free_split_result(result);

	// Test 5: No delimiter present
	result = ft_split("HelloWorld", ',');
	if (!result || strcmp(result[0], "HelloWorld") || result[1] != NULL)
	{
		printf("  FAIL: No delimiter present\n");
		printf("    Expected: [\"HelloWorld\"]\n    Got: ");
		print_split_result(result);
		free_split_result(result);
		failed++;
	}
	else
		free_split_result(result);

	// Test 6: NULL input
	result = ft_split(NULL, ' ');
	if (result != NULL)
	{
		printf("  FAIL: NULL input string\n");
		printf("    Expected: NULL\n    Got: ");
		print_split_result(result);
		free_split_result(result);
		failed++;
	}

	// Test 7: Delimiter at start and end
	result = ft_split(",Hello,World,", ',');
	if (!result || strcmp(result[0], "Hello") || strcmp(result[1], "World") || result[2] != NULL)
	{
		printf("  FAIL: Delimiter at start and end\n");
		printf("    Expected: [\"Hello\", \"World\"]\n    Got: ");
		print_split_result(result);
		free_split_result(result);
		failed++;
	}
	else
		free_split_result(result);

	// Print test results
	if (failed == 0)
		printf("  All tests passed!\n\n");
	else
		printf("  %d tests failed!\n\n", failed);
}
