/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 11:16:54 by ellarbi           #+#    #+#             */
/*   Updated: 2019/11/04 11:16:57 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	*ft_memset(void *str, int value, size_t size)
{
	unsigned char	*ptr;

	ptr = str;
	while (size-- > 0)
		*ptr++ = value;
	return str;
}

int main() 
{
    int array[] = {54, 85, 20, 63, 21};
    size_t size = sizeof(int) * 5;
    int length;

    /* Display the initial values */
    for(length = 0; length < 5; length++) {
        printf("%d ", array[length]);
    }
    printf("\n");

    /* Reset the memory bloc */
    ft_memset(array, 6, size);

    /* Display the new values */
    for(length = 0; length < 5; length++) {
        printf("%d ", array[length]);
    }
    printf("\n");
    return 0;
}
