/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhakhan <muhakhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:31:16 by muhakhan          #+#    #+#             */
/*   Updated: 2024/11/14 18:40:17 by muhakhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;
	int	j;

	i = 0;
	if(!*little)
		return ((char *) big);
	while (big[i] && i < len)
	{
		j = 0;
		if (big[i] == little[j])
		{
			while (big[i + j] == little[j] && i+j < len)
			{
				if (!little[j + 1])
					return ((char *) &big[i]);
				j++;
			}
		}
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>

int	main(void)
{
	char str[] = "Hello, world!";
	char to_find[] = "world";
	char *result;

	result = ft_strstr(str, to_find);
	if (result)
		printf("Found: %s\n", result);
	else
		printf("Not found\n");

	return (0);
}*/
// A simple implementation of strnstr for testing purposes
// char *strnstr(const char *big, const char *little, size_t len) {
//     size_t i, j;

//     // If little is an empty string, return big
//     if (*little == '\0')
//         return (char *)big;

//     // Iterate over big within the length limit
//     for (i = 0; big[i] != '\0' && i < len; i++) {
//         // Check if the substring starting from big[i] matches little
//         for (j = 0; little[j] != '\0' && (i + j) < len && big[i + j] == little[j]; j++);

//         // If we reached the end of little, return the starting position
//         if (little[j] == '\0')
//             return (char *)(big + i);
//     }

//     // If little is not found, return NULL
//     return NULL;
// }
// #include <stdio.h>
// #include <string.h>

// int main(void)
// {
//     // Test case 1: Basic test, substring exists within the length
//     const char *big1 = "Hello, World!";
//     const char *little1 = "World";
//     printf("Test 1: %s\n", (ft_strnstr(big1, little1, 13) == strnstr(big1, little1, 13)) ? "Passed" : "Failed");

//     // Test case 2: Substring not found within the length limit
//     const char *big2 = "Hello, World!";
//     const char *little2 = "world"; // lowercase 'w' to ensure no match
//     printf("Test 2: %s\n", (ft_strnstr(big2, little2, 13) == strnstr(big2, little2, 13)) ? "Passed" : "Failed");

//     // Test case 3: Substring exists but exceeds the length limit
//     const char *big3 = "Hello, World!";
//     const char *little3 = "World";
//     printf("Test 3: %s\n", (ft_strnstr(big3, little3, 5) == strnstr(big3, little3, 5)) ? "Passed" : "Failed");

//     // Test case 4: Empty little, should return big
//     const char *big4 = "Hello, World!";
//     const char *little4 = "";
//     printf("Test 4: %s\n", (ft_strnstr(big4, little4, 13) == strnstr(big4, little4, 13)) ? "Passed" : "Failed");

//     // Test case 5: little length exceeds big length
//     const char *big5 = "Short";
//     const char *little5 = "This is a very long little";
//     printf("Test 5: %s\n", (ft_strnstr(big5, little5, 13) == strnstr(big5, little5, 13)) ? "Passed" : "Failed");

//     // Test case 6: Both big and little are empty
//     const char *big6 = "";
//     const char *little6 = "";
//     printf("Test 6: %s\n", (ft_strnstr(big6, little6, 0) == strnstr(big6, little6, 0)) ? "Passed" : "Failed");

//     // Test case 7: Only big is empty
//     const char *big7 = "";
//     const char *little7 = "NotEmpty";
//     printf("Test 7: %s\n", (ft_strnstr(big7, little7, 8) == strnstr(big7, little7, 8)) ? "Passed" : "Failed");

//     // Test case 8: Only little is empty, should return big
//     const char *big8 = "NonEmpty";
//     const char *little8 = "";
//     printf("Test 8: %s\n", (ft_strnstr(big8, little8, 8) == strnstr(big8, little8, 8)) ? "Passed" : "Failed");

//     // Test case 9: Full match at the beginning
//     const char *big9 = "Begin and End";
//     const char *little9 = "Begin";
//     printf("Test 9: %s\n", (ft_strnstr(big9, little9, 5) == strnstr(big9, little9, 5)) ? "Passed" : "Failed");

//     // Test case 10: Partial match of little in big, should not match
//     const char *big10 = "big with little in the middle";
//     const char *little10 = "littles";
//     printf("Test 10: %s\n", (ft_strnstr(big10, little10, 40) == strnstr(big10, little10, 40)) ? "Passed" : "Failed");

//     return 0;
// }