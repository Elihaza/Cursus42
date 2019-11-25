/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 18:47:13 by ellarbi           #+#    #+#             */
/*   Updated: 2019/11/12 18:47:14 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void f(void)
{
    static int i = 0; /* i sera initialisée à 0 à la compilation seulement */
    int j = 0; /* j sera initialisée à chaque appel de f */;
    i++;
    j++;
    printf("i vaut %d et j vaut %d.\n", i, j);
}

int main(void)
{
    f();
    f();
    f();
    return 0;
}
