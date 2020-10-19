/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <ellarbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 12:13:54 by ellarbi           #+#    #+#             */
/*   Updated: 2020/08/09 12:13:59 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"

static void		strlen_test(char *s) {
	int yours = ft_strlen(s); int std = strlen(s);
	printf("Testing strlen(%s)\n", s);
	printf("yours = %d, std = %d\n", yours, std);
	if (yours != std)
		printf(RED"ERROR\n"RESET);
	else
		printf(GREEN"SUCCESS\n"RESET);
}

static void		strcpy_test(char *s) {
	char buf1[10000] = {0}; char buf2[10000] = {0};
	char *ret1 = ft_strcpy(buf1, s); char *ret2 = ft_strcpy(buf2, s);
	printf("\tbuf1 = |%s|\n\tbuf2 = |%s|\n", buf1, buf2);
	if (strcmp(buf1, buf2) != 0)
		printf(RED"ERROR\n"RESET);
	else
		printf(GREEN"SUCCESS\n"RESET);
}

static void		strcmp_test(char *s1, char *s2) {
	int ret2 = strcmp(s1, s2); int ret1 = ft_strcmp(s1, s2); 
	printf("comparing |%s| and |%s|\n", s1, s2);
	printf("ret1 = %d, ret2 = %d\n", ret1, ret2);
	if ((ret1 < 0 && ret2 < 0) || (!ret1 && !ret2 ) || (ret1 > 0 && ret2 > 0))
		printf(GREEN"SUCCESS\n"RESET);
	else
		printf(RED"ERROR\n"RESET);
}

static void	strcmp_test_back_to_back(char *s1, char *s2, char *s3, char *s4) {
	int ret2 = strcmp(s1, s2); int ret1 = ft_strcmp(s1, s2); 
	printf("comparing |%s| and |%s|\n", s1, s2);
	printf("ret1 = %d, ret2 = %d\n", ret1, ret2);
	if ((ret1 < 0 && ret2 < 0) || (!ret1 && !ret2 ) || (ret1 > 0 && ret2 > 0))
		printf(GREEN"SUCCESS\n"RESET);
	else
		printf(RED"ERROR\n"RESET);
	int ret3 = ft_strcmp(s3, s4); int ret4 = strcmp(s3, s4); 
	printf("comparing |%s| and |%s|\n", s3, s4);
	printf("ret3 = %d, ret4 = %d\n", ret3, ret4);
	if ((ret3 < 0 && ret4 < 0) || (!ret3 && !ret4 ) || (ret3 > 0 && ret4 > 0))
		printf(GREEN"SUCCESS\n"RESET);
	else
		printf(RED"ERROR\n"RESET);
}

static void		write_test(int fd, char *s) {
	char	buf1[4096] = {0}; char buf2[4096] = {0}; int ret1, ret2;
	printf("testing fd = %d, s = |%s|\n", fd, s);
	if (fd > 2) {
		int fd1 = open("testfile_write_1", O_CREAT | O_TRUNC | O_RDWR, 0777);
		int fd2 = open("testfile_write_2", O_CREAT | O_TRUNC | O_RDWR, 0777);
		ret1 = ft_write(fd1, s, strlen(s));
		read(fd1, buf1, strlen(s) + 1);
		ret2 = write(fd2, s, strlen(s));
		read(fd2, buf2, strlen(s) + 1);
	} else if (fd < 0) {
		errno = 0;
		ret1 = ft_write(fd, s, strlen(s) + 1);
		printf("errno = %d, strerror = |%s|\n", errno, strerror(errno));
		errno = 0;
		ret2 = write(fd, s, strlen(s) + 1);
		printf("errno = %d, strerror = |%s|\n", errno, strerror(errno));
	} else {
		ret1 = ft_write(fd, s, strlen(s) + 1);
		ret2 = write(fd, s, strlen(s) + 1);
	}
	printf("ret1 = %d, wrote |%s|, ret2 = %d, wrote |%s|\n",
		ret1, buf1, ret2, buf2);

	if (ret1 == ret2) {
		printf(GREEN"ret value OK, "RESET);
		if (strcmp(buf1, buf2) == 0) {
			printf(GREEN"contents OK, SUCCESS\n"RESET);
		} else {
			printf(RED"contents not the same, ERROR\n"RESET);
		}
	} else { printf(RED"Ret values not OK, ERROR\n"RESET); }
}

static void		read_test_openfd(char *s) {
	char buf1[4096] = {0}; char buf2[4096] = {0};
	int fd = open("testfile_read", O_CREAT | O_RDWR | O_TRUNC, 0777);
	write(fd, s, strlen(s));
	printf("testing read on fd = %d, contents = |%s|\n", fd, s);
	int ret1, ret2;
	lseek(fd, 0, SEEK_SET);
	errno = 0; ret2 = read(fd, buf2, 1000);
	printf("ret2 = %d, bufd = |%s|, errno %d |%s|\n", ret2, buf2, errno, strerror(errno));
	lseek(fd, 0, SEEK_SET);
	errno = 0; ret1 = ft_read(fd, buf1, 1000);
	printf("ret1 = %d, buf1 = |%s|, errno %d |%s|\n", ret1, buf1, errno, strerror(errno));
	if (ret1 == ret2) {
		if (!(strcmp(buf1, buf2))) {
			printf(GREEN"SUCCESS\n"RESET);
		} else {
			printf(RED"buf1 != buf2, ERROR\n"RESET);
		}
	} else {
		printf(RED"ret1 != ret2, ERROR\n"RESET);
	}
}

static void		read_test_badfd(void) {
	char buf1[4096] = {0}; char buf2[4096] = {0};
	int ret1, ret2;
	printf("testing read on badfd\n");
	errno = 0; ret1 = ft_read(-1, buf1, 42);
	printf("ret1 = %d, buf1 = |%s|, errno = %d, strerror = |%s|\n",
			ret1, buf1, errno, strerror(errno));
	errno = 0; ret2 = read(-1, buf2, 42);
	printf("ret2 = %d, buf2 = |%s|, errno = %d, strerror = |%s|\n",
			ret2, buf2, errno, strerror(errno));
	if (ret1 == ret2) {
		if (!(strcmp(buf1, buf2))) {
			printf(GREEN"SUCCESS\n"RESET);
		} else {
			printf(RED"buf1 != buf2, ERROR\n"RESET);
		}
	} else {
		printf(RED"ret1 != ret2, ERROR\n"RESET);
	}
}

static void		read_test_stdin(void) {

	char buf1[4096] = {0}; char buf2[4096] = {0};
	printf("testing ft_read on stdin, please type something :\n");
	int ret1, ret2;

	errno = 0;
	ret1 = ft_read(1, buf1, 1000);
	printf("\nret1 = %d, buf1 = |%s|, errno = %d, strerror = |%s|\n",
			ret1, buf1, errno, strerror(errno));

	errno = 0;
	printf("To compare with glibc read on stdin, please type it again :\n");
	ret2 = read(1, buf2, 1000);
	printf("\nret2 = %d, buf2 = |%s|, errno = %d, strerror = |%s|\n",
			ret2, buf2, errno, strerror(errno));

	if (ret1 == ret2) {
		if (!(strcmp(buf1, buf2))) {
			printf(GREEN"SUCCESS\n"RESET);
		} else {
			printf(RED"buf1 != buf2, ERROR\n"RESET);
		}
	} else {
		printf(RED"ret1 != ret2, ERROR\n"RESET);
	}
}

static void		strdup_test(char *s) {
	char *s1, *s2;
	errno = 0;
	s1 = ft_strdup(s);
	printf("s1 = |%s|, errno = %d |%s|\n", s1, errno, strerror(errno));
	errno = 0;
	s2 = strdup(s);
	printf("s2 = |%s|, errno = %d |%s|\n", s2, errno, strerror(errno));
	if (!strcmp(s1, s2))
		printf(GREEN"SUCCESS\n"RESET);
	else
		printf(RED"ERROR\n"RESET);
	free(s1); free(s2);
}

static void		strdup_heap_test(char *str) {
	char *s1, *s2;
	char *s = strdup(str);
	errno = 0;
	s1 = ft_strdup(s);
	printf("s1 = |%s|, errno = %d |%s|\n", s1, errno, strerror(errno));
	errno = 0;
	s2 = strdup(s);
	printf("s2 = |%s|, errno = %d |%s|\n", s2, errno, strerror(errno));
	if (!strcmp(s1, s2))
		printf(GREEN"SUCCESS\n"RESET);
	else
		printf(RED"ERROR\n"RESET);
	free(s); free(s1); free(s2);
}

int main()
{
	printf(CYAN"------------Testing strlen-----------\n"RESET);
	strlen_test("");
	strlen_test("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.");
	strlen_test("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.");

	printf(CYAN"------------Testing strcpy-----------\n"RESET);
	strcpy_test("");
	strcpy_test("Lorem ipsum dolor sit amet, consectetur adipiscing elit");
	strcpy_test("Lorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elitLorem ipsum dolor sit amet, consectetur adipiscing elit");
	strcpy_test("a");

	printf(CYAN"------------Testing strcmp-----------\n"RESET);
	strcmp_test("", "");
	strcmp_test("", "hello_world");
	strcmp_test("wonderful world", "");
	strcmp_test("bonjour", "au revoir");
	strcmp_test("ces strings sont identiques", "ces strings sont identiques");
	strcmp_test_back_to_back("abcd", "abcd", "bonjour", "au revoir");

	printf(CYAN"------------Testing write-----------\n"RESET);
	write_test(fileno(stdout), "this goes to stdout");
	write_test(-1, "this goes to badfd");
	write_test(42, "this goes to open file fd");

	printf(CYAN"------------Testing read-----------\n"RESET);
	read_test_openfd("This goes to a fd");
	read_test_badfd();
	read_test_stdin();

	printf(CYAN"------------Testing strdup, source on stack-----------\n"RESET);
	strdup_test("");
	strdup_test("hello");
	strdup_test("trud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequattempor incididunt ut labore aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequattempor incididunt ut labore aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequattrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequattempor incididunt ut labore aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequattempor incididunt ut labore aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequattempor incididunt ut labore aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequattempor incididunt ut labore aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequattempor incididunt ut labore aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.trud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequattempor incididunt ut labore aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequattempor incididunt ut labore aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequattrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequattempor incididunt ut labore aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequattempor incididunt ut labore aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequattempor incididunt ut labore aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequattempor incididunt ut labore aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequattempor incididunt ut labore aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.");

	printf(CYAN"------------Testing strdup, source on heap-----------\n"RESET);
	strdup_heap_test("hello");
	strdup_heap_test("trud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequattempor incididunt ut labore aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequattempor incididunt ut labore aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequattrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequattempor incididunt ut labore aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequattempor incididunt ut labore aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequattempor incididunt ut labore aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequattempor incididunt ut labore aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequattempor incididunt ut labore aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.");
	strdup_heap_test("");
	strdup_heap_test("a");
}
