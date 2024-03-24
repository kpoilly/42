/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:12:14 by marvin            #+#    #+#             */
/*   Updated: 2024/03/24 15:12:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap tim("Tim");

	tim.attack("Bob");
	tim.takeDamage(5);
	tim.beRepaired(2);
	tim.guardGate();
	tim.takeDamage(97);
	tim.beRepaired(5);
	tim.guardGate();

	return (0);
}