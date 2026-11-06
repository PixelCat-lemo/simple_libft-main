#include "libft.h"
#include <stdio.h>
#include <string.h>

/* Lists tests */
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

	printf("isalpha: %d (expected %d)\n", ft_isalpha('A'), 1); // char is an alphabetic letter.
	printf("isdigit: %d (expected %d)\n", ft_isdigit('5'), 1); // char is a decimal digit (0–9).
	printf("isalnum: %d (expected %d)\n", ft_isalnum('Z'), 1); // char is alphanumeric.
	printf("isascii: %d (expected %d)\n", ft_isascii(1237), 1); // char belongs to the ASCII char set (0–127).
	printf("isprint: %d (expected %d)\n", ft_isprint(' '), 1); // char is printable.
	printf("toupper: %c (expected A)\n", ft_toupper('a')); // lowercase letter into uppercase.
	printf("tolower: %c (expected a)\n", ft_tolower('A')); // uppercase letter into lowercase.

	printf("\n========== STRING TESTS ==========\n");

	printf("strlen: %d (expected 5)\n", ft_strlen("Hello")); //Returns the length of a str, minus null terminator.

	ft_strlcpy(buffer, "Hello", sizeof(buffer)); // Copies a str into a destination buffer with size protection.
	printf("strlcpy: %s (expected Hello)\n", buffer);

	ft_strlcat(buffer, " World", sizeof(buffer)); // Appends a str to another while respecting the destination size.
	printf("strlcat: %s (expected Hello World)\n", buffer);

	printf("strchr: %s (expected llo)\n", ft_strchr("Hello", 'l')); // Finds the first occurrence of a character in a str.
	printf("strrchr: %s (expected o)\n", ft_strrchr("Hello", 'o')); // Finds the last occurrence of a character in a str.

	printf("strncmp: %d (expected 0)\n", ft_strncmp("Hello", "Hello", 5)); // Compares 2 strs up to a specified number of characters.

	printf("strncmp: %d (expected negative)\n", ft_strncmp("Hello", "World", 5)); // strncmp negative result

	printf("strnstr: %s (expected World)\n", ft_strnstr("Hello World", "World", 11)); // Searches for a substr within a str up to a specified len.

	printf("atoi: %d (expected -42)\n", ft_atoi("-42")); // Converts a str with nbrs into an int value.

	str = ft_strdup("Hello World"); // Creates a dynamically allocated duplicate of a str.
	printf("strdup: %s (expected Hello World)\n", str);
	free(str);

	str = ft_substr("Hello World", 6, 5); // Creates a new str containing a substring from a specified index and length.
	printf("substr: %s (expected World)\n", str);
	free(str);

	str = ft_strjoin("Hello ", "World"); // Creates a new str by concatenating two strs.
	printf("strjoin: %s (expected Hello World)\n", str);
	free(str);

	str = ft_strtrim("  Hello World  ", " "); // Removes specified chars from the beginning and end of a str.
	printf("strtrim: %s (expected Hello World)\n", str);
	free(str);

	split = ft_split("Hello World 42", ' '); // Splits a str into an array of strs using a delimiter char.
	printf("split:\n");
	i = 0;
	while (split[i])
	{
		printf("  [%d] %s\n", i, split[i]);
		free(split[i]);
		i++;
	}
	free(split);

	printf("itoa: %s (expected -12345)\n", str = ft_itoa(-12345)); // Converts an int into a dynamically allocated str.
	free(str);

	str = ft_strmapi("hello", uppercase); // Creates a new str by applying a function to each char and its index.
	printf("strmapi: %s (expected HELLO)\n", str);
	free(str);

	str = ft_strdup("hello"); 
	ft_striteri(str, uppercase_iter); // Creates a dynamically allocated duplicate of a str.
	printf("striteri: %s (expected HELLO)\n", str);
	free(str);

	printf("\n========== MEMORY TESTS ==========\n");

	ft_memset(buffer, 'A', 5); // Fills a memory block with a specified byte value.
	buffer[5] = '\0';
	printf("memset: %s (expected AAAAA)\n", buffer);

	ft_bzero(buffer, 5); // Sets a specified number of bytes to zero.
	printf("bzero: first byte = %d (expected 0)\n", buffer[0]);

	ft_memcpy(buffer, "Hello", 6); // Copies a specified number of bytes between memory areas.
	printf("memcpy: %s (expected Hello)\n", buffer);

	ft_memmove(buffer2, buffer, 6); // Copies memory safely, even when source and destination overlap.
	printf("memmove: %s (expected Hello)\n", buffer2);

	printf("memcmp: %d (expected 0)\n", 
		ft_memcmp("Hello", "Hello", 5)); // Searches for a byte within a memory block.

	printf("memcmp: %d (expected negative)\n",
		ft_memcmp("ABC", "ABD", 3)); // Compares two memory blocks byte by byte.

	printf("memchr: %s (expected llo)\n",
		(char *)ft_memchr("Hello", 'l', 5)); // Searches for a byte within a memory block.

	printf("calloc: ");
	str = ft_calloc(5, sizeof(char)); // Allocates memory for an array and initializes it to zero.
	if (str)
	{
		printf("%d %d %d %d %d (expected all 0)\n",
			str[0], str[1], str[2], str[3], str[4]);
		free(str);
	}
	else
		printf("FAILED\n");

	printf("\n========== OUTPUT TESTS ==========\n");

	ft_putchar_fd('A', 1); // Writes a character to a specified file descriptor.
	printf(" (expected A)\n");

	ft_putstr_fd("Hello", 1); // Writes a string to a specified file descriptor.
	printf(" (expected Hello)\n");

	ft_putendl_fd("Hello", 1); // Writes a string followed by a newline to a specified file descriptor.

	ft_putnbr_fd(-42, 1); // Writes an integer to a specified file descriptor.
	printf(" (expected -42)\n");

	printf("\n========== LINKED LIST TESTS ==========\n");

	lst = NULL;

	lst = ft_lstnew(ft_strdup("First")); // Creates a new linked lst node containing the specified content.
	printf("lstnew: %s (expected First)\n", (char *)lst->content);

	ft_lstadd_front(&lst, ft_lstnew(ft_strdup("Zero"))); // Adds a new node to the beginning of a linked list.
	printf("lstadd_front: %s (expected Zero)\n",
	(char *)lst->content);

	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("Last"))); // Adds a new node to the end of a linked list.
	printf("lstadd_back: %s (expected Last)\n",
	(char *)ft_lstlast(lst)->content);

	printf("lstsize: %d (expected 3)\n", ft_lstsize(lst)); // Returns the number of nodes in a linked list.

	printf("lstlast: %s (expected Last)\n",
	(char *)ft_lstlast(lst)->content); // Returns the last node of a linked list.

	ft_lstiter(lst, print_string); // Applies a function to the content of every node.
	printf("\n");

/* Free the original list */
	ft_lstclear(&lst, free);
	printf("ft_lstclear/ft_lstdelone: clean complete\n");

	printf("\n========== END OF TESTS ==========\n");

	return (0);
}
