/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 20:30:17 by mrubio            #+#    #+#             */
/*   Updated: 2021/04/15 23:17:33 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

//COLOR
void	green()
{
	printf("\033[0;32m");
}
void	red()
{
	printf("\033[0;31m");
}
void	yellow()
{
	printf("\033[0;33m");
}
void	end()
{
	printf("\033[0m");
}
//COLOR

void	check_strlen(char *str)
{
	int n1;
	int n2;

	n1 = ft_strlen(str);
	n2 = strlen(str);
	if (n1 == n2)
	{
		green();
		printf("OK [%i]   ", n1);
		printf(">> %s\n",str);
	}
	else
	{
		red();
		printf("KO   my:[%i] orig:[%i] ", n1, n2);
	}

}

void	check_strcpy(char *str)
{
	char *my;
	char *or;

	my = malloc(ft_strlen(str));
	or = malloc(ft_strlen(str));
	ft_strcpy(my, str);
	strcpy(or, str);
	if (strcmp(or, my) == 0)
	{
		green();
		printf("OK   ");
		printf(">> %s\n",str);
	}
	else
	{
		red();
		printf("KO   SRC> [%s] || MY> [%s] ", or, my);
	}
}

void	check_strcmp(char *s1, char *s2)
{
	int my;
	int or;

	my = ft_strcmp(s1, s2);
	or = strcmp(s1, s2);
	if (my == or)
	{
		green();
		printf("OK   [%i]  ||  arg1> [%s]   arg2> [%s]\n", my, s1, s2);
	}
	else
	{
		red();
		printf("KO   my[%i] or[%i]  ||  arg1> [%s]   arg2> [%s]\n", my, or, s1, s2);
	}
}

void	check_strdup(char *str)
{
	char *s1;
	char *s2;

	s1 = strdup(str);
	s2 = ft_strdup(str);
	if (*s1 == *s2)
	{
		green();
		printf("OK   || [%s]\n", str);
	}
	else
	{
		red();
		printf("KO   || my:[%s] or:[%s]\n", s2, s1);
	}
}

void	check_read(char *file)
{
	int fd;
	char *s1;
	char *s2;
	int ret_ft_read;
	int ret_read;
	s1 = malloc(25);
	s2 = malloc(25);
	fd = open(file, O_RDONLY);
	errno = 0;
	ret_read = read(fd, s1, 25);
	errno = 0;
	ret_ft_read = ft_read(fd, s2, 25);
	if (ret_ft_read == ret_read)
	{
		green();
		printf("OK errno:[%d] > [%i][%s]\n", errno, ret_ft_read, s2);
	}
	else
	{
		red();
		printf("KO > Orig:[%i][%i][%s]   My:[%i][%i][%s]\n", ret_read, errno, s1, ret_ft_read, errno, s2);
	}
	free(s1);
	free(s2);
	close(fd);
}

int		main(void)
{
	yellow();
	printf("FT_STRLEN\n");
	check_strlen("Holahola");
	check_strlen("");
	check_strlen("que tal como estas 42madrid, libasm es bien, el proyecto services es el demonio");
	check_strlen("1234%%&/(&$$$$$$&/(/&u567465345)");

	yellow();
	printf("\nFT_STRCPY\n");
	check_strcpy("Holahola");
	check_strcpy("");
	check_strcpy("que tal como estas 42madrid, libasm es bien, el proyecto services es el demonio");
	check_strcpy("1234%%&(/&$$$$$$&//&u567465345)");

	yellow();
	printf("\nFT_STRCMP\n");
	check_strcmp("Holhola", "Quetal");
	check_strcmp("", "");
	check_strcmp("Holhola", "");
	check_strcmp("Holholb", "");
	check_strcmp("Holaholb", "Holhola");
	check_strcmp("", "Holholb");

	yellow();
	printf("\nFT_STRDUP\n");
	check_strdup("Hola");
	check_strdup("");
	check_strdup("Holadadsadnjefjl3fh3ufo3ef");

	yellow();
	printf("\nFT_READ\n");
	char *my = malloc(200);
	char *ori = malloc(200);
	int fd = open("test.txt", O_RDONLY);
	printf("My funct > [%lu] -> [%s] // errno: %i\n", ft_read(fd, my, 50), my, errno);
	printf("Original > [%lu] -> [%s] // errno: %i", read(fd, ori, 50), ori, errno);


	end();
	return (0);
}