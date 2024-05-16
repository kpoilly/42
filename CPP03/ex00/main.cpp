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

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap bob("Bob");

	bob.attack("Jim");
	bob.takeDamage(5);
	bob.beRepaired(2);
	bob.takeDamage(7);
	bob.beRepaired(5);

	return (0);
}