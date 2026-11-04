#include "libft.h"
#include <stdio.h>
#include <string.h>

/* Lists tests */

static void	del_content(void *content)
{
	free(content);
}

static void	*double_number(void *content)
{
	int	*n;

	n = malloc(sizeof(int));
	if (!n)
		return (NULL);
	*n = *(int *)content * 2;
	return (n);
}

static void	print_string(void *content)
{
	printf("%s ", (char *)content);
}

static char	uppercase(unsigned int i, char c)
{
	(void)i;
	return (ft_toupper(c));
}

static void	uppercase_iter(unsigned int i, char *c)
{
	(void)i;
	*c = ft_toupper(*c);
}

int	main(void)
{
	char	buffer[100];
	char	buffer2[100];
	char	**split;
	char	*str;
	int		i;
	t_list	*lst;
	t_list	*new_lst;

	printf("\n========== CHAR TESTS ==========\n");

	printf("isalpha: %d (expected %d)\n", ft_isalpha('A'), 1);
	printf("isdigit: %d (expected %d)\n", ft_isdigit('5'), 1);
	printf("isalnum: %d (expected %d)\n", ft_isalnum('Z'), 1);
	printf("isascii: %d (expected %d)\n", ft_isascii(127), 1);
	printf("isprint: %d (expected %d)\n", ft_isprint(' '), 1);
	printf("toupper: %c (expected A)\n", ft_toupper('a'));
	printf("tolower: %c (expected a)\n", ft_tolower('A'));

	printf("\n========== STRING TESTS ==========\n");

	printf("strlen: %d (expected 5)\n", ft_strlen("Hello"));

	ft_strlcpy(buffer, "Hello", sizeof(buffer));
	printf("strlcpy: %s (expected Hello)\n", buffer);

	ft_strlcat(buffer, " World", sizeof(buffer));
	printf("strlcat: %s (expected Hello World)\n", buffer);

	printf("strchr: %s (expected llo)\n", ft_strchr("Hello", 'l'));
	printf("strrchr: %s (expected o)\n", ft_strrchr("Hello", 'o'));

	printf("strncmp: %d (expected 0)\n",
		ft_strncmp("Hello", "Hello", 5));

	printf("strncmp: %d (expected negative)\n",
		ft_strncmp("Hello", "World", 5));

	printf("strnstr: %s (expected World)\n",
		ft_strnstr("Hello World", "World", 11));

	printf("atoi: %d (expected -42)\n", ft_atoi("-42"));

	str = ft_strdup("Hello World");
	printf("strdup: %s (expected Hello World)\n", str);
	free(str);

	str = ft_substr("Hello World", 6, 5);
	printf("substr: %s (expected World)\n", str);
	free(str);

	str = ft_strjoin("Hello ", "World");
	printf("strjoin: %s (expected Hello World)\n", str);
	free(str);

	str = ft_strtrim("  Hello World  ", " ");
	printf("strtrim: %s (expected Hello World)\n", str);
	free(str);

	split = ft_split("Hello World 42", ' ');
	printf("split:\n");
	i = 0;
	while (split[i])
	{
		printf("  [%d] %s\n", i, split[i]);
		free(split[i]);
		i++;
	}
	free(split);

	printf("itoa: %s (expected -12345)\n", str = ft_itoa(-12345));
	free(str);

	str = ft_strmapi("hello", uppercase);
	printf("strmapi: %s (expected HELLO)\n", str);
	free(str);

	str = ft_strdup("hello");
	ft_striteri(str, uppercase_iter);
	printf("striteri: %s (expected HELLO)\n", str);
	free(str);

	printf("\n========== MEMORY TESTS ==========\n");

	ft_memset(buffer, 'A', 5);
	buffer[5] = '\0';
	printf("memset: %s (expected AAAAA)\n", buffer);

	ft_bzero(buffer, 5);
	printf("bzero: first byte = %d (expected 0)\n", buffer[0]);

	ft_memcpy(buffer, "Hello", 6);
	printf("memcpy: %s (expected Hello)\n", buffer);

	ft_memmove(buffer2, buffer, 6);
	printf("memmove: %s (expected Hello)\n", buffer2);

	printf("memcmp: %d (expected 0)\n",
		ft_memcmp("Hello", "Hello", 5));

	printf("memcmp: %d (expected negative)\n",
		ft_memcmp("ABC", "ABD", 3));

	printf("memchr: %s (expected llo)\n",
		(char *)ft_memchr("Hello", 'l', 5));

	printf("calloc: ");
	str = ft_calloc(5, sizeof(char));
	if (str)
	{
		printf("%d %d %d %d %d (expected all 0)\n",
			str[0], str[1], str[2], str[3], str[4]);
		free(str);
	}
	else
		printf("FAILED\n");

	printf("\n========== OUTPUT TESTS ==========\n");

	ft_putchar_fd('A', 1);
	printf(" (expected A)\n");

	ft_putstr_fd("Hello", 1);
	printf(" (expected Hello)\n");

	ft_putendl_fd("Hello", 1);

	ft_putnbr_fd(-42, 1);
	printf(" (expected -42)\n");

	printf("\n========== LINKED LIST TESTS ==========\n");

	lst = NULL;

	lst = ft_lstnew(ft_strdup("First"));
	printf("lstnew: %s (expected First)\n", (char *)lst->content);

	ft_lstadd_front(&lst, ft_lstnew(ft_strdup("Zero")));
	printf("lstadd_front: %s (expected Zero)\n",
		(char *)lst->content);

	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("Last")));
	printf("lstadd_back: %s (expected Last)\n",
		(char *)ft_lstlast(lst)->content);

	printf("lstsize: %d (expected 3)\n", ft_lstsize(lst));

	printf("lstlast: %s (expected Last)\n",
		(char *)ft_lstlast(lst)->content);

	ft_lstiter(lst, (void (*)(void *))print_string);
	/* Use lstiter with compatible content if testing integers. */

	printf("\n");

	new_lst = ft_lstmap(lst, (void *(*)(void *))double_number,
		del_content);

	printf("lstmap: %s\n",
		new_lst ? "SUCCESS" : "FAILED");

	ft_lstclear(&lst, del_content);
	ft_lstclear(&new_lst, del_content);

	printf("lstclear: %s (expected NULL)\n",
		lst == NULL ? "SUCCESS" : "FAILED");

	printf("\n========== END OF TESTS ==========\n");

	return (0);
}
