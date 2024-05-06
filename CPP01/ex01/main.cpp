/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:42:47 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/03 07:41:38 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int	N = 7;
	Zombie *horde = zombieHorde(N, "Paul");
	
	for (int i = 0; i < N; i++)
		horde[i].announce();

	delete[] horde;
	return (0);
}