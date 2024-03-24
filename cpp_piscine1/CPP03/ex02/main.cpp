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
#include "FragTrap.hpp"

int main(void)
{
	FragTrap eric("Eric");

	eric.attack("Bob");
	eric.takeDamage(5);
	eric.beRepaired(2);
	eric.highFivesGuys();
	eric.takeDamage(97);
	eric.beRepaired(5);
	eric.highFivesGuys();

	return (0);
}