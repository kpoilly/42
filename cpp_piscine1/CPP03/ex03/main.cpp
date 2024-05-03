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

#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap thierry("Thierry");
	DiamondTrap thierry2("Pouet");

	thierry.attack("Pouet");
	thierry.whoAmI();
	thierry2.whoAmI();
	thierry2 = thierry;
	thierry.whoAmI();

	return (0);
}