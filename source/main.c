/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsanz-sz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:53:13 by gsanz-sz          #+#    #+#             */
/*   Updated: 2020/03/10 21:16:59 by gsanz-sz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	print_d(unsigned int num);

int main(void)
{
	int c;

	c = 0;
	printf("%u\n",c);
	printf("\nMinha Funcao: %d\n",print_d(0));
}
