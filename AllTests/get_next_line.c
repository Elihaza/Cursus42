/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:38:01 by ellarbi           #+#    #+#             */
/*   Updated: 2019/11/25 14:38:02 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define	BUFF_SIZE 512
 
char        *get_next_line(const int fd)
{
  char      buffer[BUFF_SIZE];
  char      *str;
  static int    compt;
  int       i;
  int       save;
 
  read(fd, buffer, BUFF_SIZE);
  if (compt != 0)
    compt += 1;
  save = compt;
  while (buffer[compt] != '\n')
    compt += 1;
  str = malloc(sizeof(*str) * (compt - save));
  i = 0;
  while ((i + save) != compt)
    {
      str[i] = buffer[save + i];
      i += 1;
    }
  return (str);
}
       
int     main(int argc, char **argv)
{
  int	fd;
  (void)argc;
 
  fd = open(argv[1], O_RDONLY);
  printf("%s\n", get_next_line(fd));
  printf("%s\n", get_next_line(fd));
  printf("%s\n", get_next_line(fd));
  printf("%s\n", get_next_line(fd));
  close(fd);
}
