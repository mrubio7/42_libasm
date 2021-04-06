/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrubio <mrubio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 20:30:17 by mrubio            #+#    #+#             */
/*   Updated: 2021/04/06 10:03:18 by mrubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h"

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

void	check_strlen(char *str)
{
	int n1;
	int n2;

	n1 = ft_strlen(str);
	n2 = strlen(str);
	if (n1 == n2)
	{
		green();
		printf("OK [%i] ", n1);
	}
	else
	{
		red();
		printf("KO my:[%i] orig:[%i] ", n1, n2);
	}
	printf(">> %s\n",str);

}

int		main(void)
{
	yellow();
	printf("FT_STRLEN\n");
	check_strlen("Holahola");
	check_strlen("");
	check_strlen("que tal como estas 42madrid, libasm es bien, services es el demonio");
	check_strlen("1234%%&/(&$$$$$$&/(/&u567465345)");
	end();
	return (0);
}