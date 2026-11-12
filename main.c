/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-lemo <pde-lemo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 10:46:35 by pde-lemo          #+#    #+#             */
/*   Updated: 2026/11/12 16:49:16 by pde-lemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static void	*add_exclamation(void *content)
{
	char	*new;

	new = malloc(ft_strlen(content) + 2);
	if (!new)
		return (NULL);
	ft_strlcpy(new, content, ft_strlen(content) + 1);
	ft_strlcat(new, "!", ft_strlen(content) + 2);
	return (new);
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
	// char is an alphabetic letter.
	printf("isdigit: %d (expected %d)\n", ft_isdigit('5'), 1);
	// char is a decimal digit (0–9).
	printf("isalnum: %d (expected %d)\n", ft_isalnum('Z'), 1);
	// char is alphanumeric.
	printf("isascii: %d (expected %d)\n", ft_isascii(127), 1);
	// char belongs to the ASCII char set (0–127).
	printf("isprint: %d (expected %d)\n", ft_isprint(' '), 1);
	// char is printable.
	printf("toupper: %c (expected A)\n", ft_toupper('a'));
	// lowercase letter into uppercase.
	printf("tolower: %c (expected a)\n", ft_tolower('A'));
	// uppercase letter into lowercase.

	printf("\n========== STRING TESTS ==========\n");

	printf("strlen: %zu (expected 5)\n", ft_strlen("hello world!"));
	//Returns the length of a str, minus null terminator.

	ft_strlcpy(buffer, "Hello", sizeof(buffer));
	// Copies a str into a destination buffer with size protection.
	printf("strlcpy: %s (expected Hello)\n", buffer);

	ft_strlcat(buffer2, "Hello World", sizeof(buffer2));
	// Appends a str to another while respecting the destination size.
	printf("ft_strlcat str: %s (expected Hello World)\n", buffer2);
	printf("ft_strlcat size_t(dest null): %zu (expected 11)\n", ft_strlcat(NULL, "Hello World", 0));

	// printf("strchr: %s (expected llo)\n", strchr(NULL, 'l'));
	// NULL wont even compile. its undefined behavior
	printf("strchr: %s (expected llo)\n", ft_strchr("hello", 'l'));
	// Finds the first occurrence of a character in a str.
	printf("strrchr: %s (expected o)\n", ft_strrchr("hello", 'o'));
	// Finds the last occurrence of a character in a str.

	printf("\nstrncmp tests\n");
	printf("strncmp: %d (expected 0)\n", ft_strncmp("Hello", "Hello", 5));
	// Compares 2 strs up to a specified number of characters.
	printf("strncmp: %d (expected negative)\n", ft_strncmp("NULL", "World", 5));
	// strncmp negative result
	printf("strncmp: %d (expected 0)\n", ft_strncmp(NULL, "World", 0));
	printf("strncmp: %d (expected 0)\n", ft_strncmp("NULL", NULL, 0));
	printf("strncmp: %d (expected 0)\n", ft_strncmp(NULL, NULL, 0));

	printf("\nstrnstr tests\n");
	printf("strnstr: %s (expected World)\n", ft_strnstr("Hello World", "W", 11));
	// Searches for a substr within a str up to a specified len.
	printf("strnstr: %p (expected NULL)\n", (void *)ft_strnstr(NULL, "", 0));

	printf("atoi: %d (expected -42)\n", ft_atoi("-42"));
	// Converts a str with nbrs into an int value.

	str = ft_strdup("Hello World");
	// Creates a dynamically allocated duplicate of a str.
	printf("strdup: %s (expected Hello World)\n", str);
	free(str);

	printf("\nsubstr tests\n");
	str = ft_substr("World", 6, 5);
	// Creates a new str containing a substring from a specified index and length.
	printf("substr: %s (expected World)\n", str);
	free(str);
	str = ft_substr(NULL, 6, 5);
	// NULL
	printf("substr: %s (expected NULL)\n", str);
	free(str);

	printf("\nstrjoin tests\n");
	str = ft_strjoin("Hello ", "World");
	// Creates a new str by concatenating two strs.
	printf("strjoin: %s (expected Hello World)\n", str);
	free(str);
	str = ft_strjoin("Hello ", NULL);
	// Creates a new str by concatenating two strs.
	printf("strjoin: %s (expected NULL)\n", str);
	free(str);

	printf("\nstrtrim tests\n");
	str = ft_strtrim("xxxxHello WorldXxxxx", "xX");
	// Removes specified chars from the beginning and end of a str.
	printf("strtrim: %s (expected Hello World)\n", str);
	free(str);
	str = ft_strtrim(NULL, NULL);
	printf("strtrim: %s (expected nothing/NULL)\n", str);
	free(str);

	printf("\nsplit\n");
	printf("1. Normal\n");
	split = ft_split("  B R  Two  ", ' ');
	i = 0;
	while (split && split[i])
	{
		printf("  [%d] %s\n", i, split[i]);
		free(split[i]);
		i++;
	}
	free(split);
	printf("2. NULL\n");
	split = ft_split(NULL, ' ');
	i = 0;
	while (split && split[i])
	{
		printf("  [%d] %s\n", i, split[i]);
		free(split[i]);
		i++;
	}
	free(split);
	printf("3. Empty\n");
	split = ft_split("", ' ');
	i = 0;
	while (split && split[i])
	{
		printf("  [%d] %s\n", i, split[i]);
		free(split[i]);
		i++;
	}
	free(split);
	printf("4. Only delimiters\n");
	split = ft_split("     ", ' ');
	i = 0;
	while (split && split[i])
	{
		printf("  [%d] %s\n", i, split[i]);
		free(split[i]);
		i++;
	}
	free(split);
	printf("5. No delimiters\n");
	split = ft_split("HelloWorld", ' ');
	i = 0;
	while (split && split[i])
	{
		printf("  [%d] %s\n", i, split[i]);
		free(split[i]);
		i++;
	}
	free(split);
	printf("6. Different delimiter\n");
	split = ft_split("Hello,World,42", ',');
	i = 0;
	while (split && split[i])
	{
		printf("  [%d] %s\n", i, split[i]);
		free(split[i]);
		i++;
	}
	free(split);
	printf("7. Consecutive delimiters\n");
	split = ft_split(",,,,Hello,,,World,,,", ',');
	i = 0;
	while (split && split[i])
	{
		printf("  [%d] %s\n", i, split[i]);
		free(split[i]);
		i++;
	}
	free(split);
	printf("8. Single character\n");
	split = ft_split("A", ' ');
	i = 0;
	while (split && split[i])
	{
		printf("  [%d] %s\n", i, split[i]);
		free(split[i]);
		i++;
	}
	free(split);
	printf("9. NULL delimiter\n");
	split = ft_split("Hello", '\0');
	i = 0;
	while (split && split[i])
	{
		printf("  [%d] %s\n", i, split[i]);
		free(split[i]);
		i++;
	}
	free(split);

	printf("itoa\n");
	printf("itoa: %s (expected -123)\n", str = ft_itoa(-123));
	// Converts an int into a dynamically allocated str.
	free(str);
	printf("itoa: %s (expected INT_MAX)\n", str = ft_itoa(INT_MAX));
	// Converts an int into a dynamically allocated str.
	free(str);
	printf("itoa: %s (expected INT_MIN)\n", str = ft_itoa(INT_MIN));
	// Converts an int into a dynamically allocated str.
	free(str);
	printf("itoa: %s (expected 0)\n", str = ft_itoa(0));
	// Converts an int into a dynamically allocated str.
	free(str);
	printf("itoa: %s (expected )\n", str = ft_itoa(+- 1));
	// Converts an int into a dynamically allocated str.
	free(str);

	printf("strmapi\n");
	str = ft_strmapi("hello", NULL);
	// Creates a new str by applying a function to each char and its index.
	printf("strmapi: %s (expected HELLO)\n", str);
	free(str);

	str = ft_strdup("hello");
	
	ft_striteri(str, uppercase_iter);
	// Creates a dynamically allocated duplicate of a str.
	printf("striteri: %s (expected HELLO)\n", str);
	free(str);

	printf("\n========== MEMORY TESTS ==========\n");

	printf("ft_memset\n");
	// 1. Normal
	ft_memset(buffer, 'A', 5);
	// Fills a memory block with a specified byte value.
	buffer[5] = '\0';
	printf("memset: %s (expected AAAAA)\n", buffer);
	// 2. Zero bytes
	ft_memset(buffer, 'A', 0);
	printf("memset: %s (expected AAAAA)\n", buffer);
	// 3. Fill with zero
	ft_memset(buffer, 0, sizeof(buffer));
	printf("memset: %d (expected 0)\n", buffer[0]);
	// 4. Negative character
	ft_memset(buffer, -1, 5);
	printf("memset: %d (expected 255)\n", (unsigned char)buffer[0]);
	// 5. Different character
	ft_memset(buffer, 'x', 5);
	buffer[5] = '\0';
	printf("memset: %s (expected xxxxx)\n", buffer);
	// 6. NULL, zero size
	printf("memset: %p (expected NULL)\n",
    ft_memset(NULL, 'A', 0));
	// 7. NULL, non-zero size (undefined behavior)
	// ft_memset(NULL, 'A', 5);	

	printf("\nft_bzero\n");
	// 1. Normal
	ft_bzero(buffer, 5);
	// Sets a specified number of bytes to zero.
	printf("bzero: first byte = %d (expected 0)\n", buffer[0]);
	// 2. Zero bytes
	ft_bzero(buffer, 0);
	// 3. NULL, zero size
	ft_bzero(NULL, 0);
	// 4. NULL, non-zero size (undefined behavior)
	// ft_bzero(NULL, 5);

	printf("\nft_memcpy\n");
	ft_memcpy(buffer, "Hello", 6);
	// Copies a specified number of bytes between memory areas.
	printf("memcpy: %s (expected Hello)\n", buffer);
	// 2. Zero bytes
	ft_memcpy(buffer, "World", 0);
	// 3. NULL, zero size
	ft_memcpy(NULL, NULL, 0);
	// 4. NULL, non-zero size (undefined behavior)
	// ft_memcpy(NULL, "Hello", 5);
	// ft_memcpy(buffer, NULL, 5);
	// 5. Overlapping memory (undefined behavior)
	// ft_memcpy(buffer + 1, buffer, 5);

	printf("\nft_memmove\n");
	// 1. Normal
	ft_memmove(buffer2, buffer, 6);
	printf("memmove: %s (expected Hello)\n", buffer2);
	// 2. Overlapping destination after source
	ft_memcpy(buffer, "Hello", 6);
	ft_memmove(buffer + 1, buffer, 5);
	buffer[6] = '\0';
	printf("memmove: %s (expected HHello)\n", buffer);
	// 3. Overlapping destination before source
	ft_memcpy(buffer, "Hello", 6);
	ft_memmove(buffer, buffer + 1, 5);
	printf("memmove: %s (expected ello)\n", buffer);
	// 4. Zero bytes
	ft_memcpy(buffer, "Hello", 6);
	ft_memmove(buffer, buffer2, 0);
	printf("memmove: %s (expected Hello)\n", buffer);
	// 5. NULL, zero size
	printf("memmove: %p (expected NULL)\n", ft_memmove(NULL, NULL, 0));
	// 6. NULL, non-zero size (undefined behavior)
	// ft_memmove(NULL, buffer, 5);

	printf("\nft_memcmp\n");
	printf("memcmp: %d (expected 0)\n", ft_memcmp("Hello", "Hello", 5));
	printf("memcmp: %d (expected negative)\n", ft_memcmp("ABC", "ABD", 3));
	// Compares two memory blocks byte by byte.
	printf("memcmp: %d (expected negative)\n", ft_memcmp("ABD", "ABC", 3));
	printf("memcmp: %d (expected cmp /0 and D)\n", ft_memcmp("ABD", "", 3));
	printf("memcmp: %d (expected 0 bytes)\n", ft_memcmp(NULL, NULL, 0));
	// 5. NULL, non-zero size (undefined behavior)
	// ft_memcmp(NULL, "Hello", 5);

	printf("\nft_memchr\n");
	// Searches for a byte within a memory block.
	// 1. Character found
	printf("memchr: %s (expected llo)\n", (char *)ft_memchr("Hello", 'l', 5));
	// 2. Character not found
	printf("memchr: %p (expected NULL)\n", ft_memchr("Hello", 'z', 5));
	// 3. Zero bytes
	printf("memchr: %p (expected NULL)\n", ft_memchr("Hello", 'H', 0));
	// 4. Search for '\0'
	printf("memchr: %p (expected terminator)\n", ft_memchr("Hello", '\0', 6));
	// 5. NULL, zero size
	printf("memchr: %p (expected NULL)\n", ft_memchr(NULL, 'A', 0));
	// 6. NULL, non-zero size (undefined behavior)
	// ft_memchr(NULL, 'A', 5);

	printf("\nft_calloc\n");
	
	// Allocates memory for an array and initializes it to zero.
	// 1. Normal
	int *arr = ft_calloc(5, sizeof(int));
	printf("calloc: %d (expected 0)\n", arr[0]);
	free(arr);
	// 2. Multiple elements
	int *arr2 = ft_calloc(3, sizeof(int));
	printf("calloc: %d (expected 0)\n", arr2[2]);
	free(arr2);
	// 3. Zero elements
	void *ptr = ft_calloc(0, sizeof(int));
	printf("calloc: %s (allocated or NULL)\n", ptr == NULL ? "null" : "allocated");
	free(ptr);
	// 4. Zero size
	ptr = ft_calloc(5, 0);
	printf("calloc: %s (allocated or NULL)\n", ptr == NULL ? "null" : "allocated");
	free(ptr);
	// 5. Both zero
	ptr = ft_calloc(0, 0);
	printf("calloc: %s (allocated or NULL)\n", ptr == NULL ? "null" : "allocated");
	free(ptr);
	// 6. Overflow
	#include <stdint.h>
	ptr = ft_calloc(SIZE_MAX, 2);
	printf("calloc: %s (expected NULL)\n", ptr == NULL ? "null" : "allocated");
	free(ptr);

	printf("\n========== OUTPUT TESTS ==========\n");

	ft_putchar_fd('A', 1);
	// Writes a character to a specified file descriptor.
	printf(" (expected A)\n");

	ft_putstr_fd("Hello", 1);
	// Writes a string to a specified file descriptor.
	printf(" (expected Hello)\n");

	ft_putendl_fd("Hello", 1);
	// Writes a string followed by a newline to a specified file descriptor.
	printf(" (expected 'Hello\\n')\n");

	ft_putnbr_fd(-42, 1);
	// Writes an integer to a specified file descriptor.
	printf(" (expected -42)\n");

	printf("\n========== LINKED LIST TESTS ==========\n");

	lst = NULL;

	// 1. lstnew
	lst = ft_lstnew(ft_strdup("First"));
	printf("lstnew: %s (expected First)\n", (char *)lst->content);
	// 2. lstadd_front
	ft_lstadd_front(&lst, ft_lstnew(ft_strdup("Zero")));
	printf("lstadd_front: %s (expected Zero)\n", (char *)lst->content);
	// 3. lstadd_back
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("Last")));
	printf("lstadd_back: %s (expected Last)\n", (char *)ft_lstlast(lst)->content);
	// 4. lstsize
	printf("lstsize: %d (expected 3)\n", ft_lstsize(lst));
	// 5. lstlast
	printf("lstlast: %s (expected Last)\n", (char *)ft_lstlast(lst)->content);
	// 6. lstiter
	ft_lstiter(lst, print_string);
	printf("\n");
	// 7. Empty list
	printf("lstsize empty: %d (expected 0)\n", ft_lstsize(NULL));
	printf("lstlast empty: %p (expected NULL)\n", (void *)ft_lstlast(NULL));
	// 8. lstmap
	t_list	*temp;

	lst = NULL;
	lst = ft_lstnew(ft_strdup("Hello"));
	lst->next = ft_lstnew(ft_strdup("World"));
	lst->next->next = ft_lstnew(ft_strdup("42"));

	new_lst = ft_lstmap(lst, add_exclamation, free);

	printf("lstmap original: ");
	temp = lst;
	while (temp)
	{
		printf("%s ", (char *)temp->content);
		temp = temp->next;
	}
	printf("(expected Hello World 42)\n");
	printf("lstmap mapped: ");
	temp = new_lst;
	while (temp)
	{
		printf("%s ", (char *)temp->content);
		temp = temp->next;
	}
	printf("(expected Hello! World! 42!)\n");
	printf("lstmap size: %d (expected 3)\n", ft_lstsize(new_lst));
	ft_lstclear(&lst, free);
	ft_lstclear(&new_lst, free);
	// 10. Empty
	new_lst = ft_lstmap(NULL, add_exclamation, free);
	printf("lstmap empty: %p (expected NULL)\n", (void *)new_lst);
	// 11. lstmap single node
	lst = ft_lstnew(ft_strdup("42"));
	new_lst = ft_lstmap(lst, add_exclamation, free);
	printf("lstmap single: %s (expected 42!)\n", (char *)new_lst->content);
	ft_lstclear(&lst, free);
	ft_lstclear(&new_lst, free);
	// 9. Cleanup
	ft_lstclear(&lst, free);
	printf("lstclear: %p (expected NULL)\n", (void *)lst);

	printf("\n========== END OF TESTS ==========\n");
	return (0);
}
