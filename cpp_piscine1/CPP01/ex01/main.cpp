/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:42:47 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/02 13:29:41 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(int ac, char **av)
{
	if (ac != 3)
		return (1);
	
	int	N = atoi(av[1]);
	Zombie *horde = zombieHorde(N, av[2]);
	
	for (int i = 0; i < N; i++)
		horde[i].announce();

	delete[] horde;
	return (0);
}