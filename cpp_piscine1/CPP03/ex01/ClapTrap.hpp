/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:12:56 by marvin            #+#    #+#             */
/*   Updated: 2024/03/24 15:12:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	protected:
		std::string _Name;
		int			_HitPoints = 100;
		int			_EnergyPoints = 50;
		int			_AttackDmg = 20;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& copy);
		~ClapTrap();
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amout);
		void	beRepaired(unsigned int amout);
};

#endif