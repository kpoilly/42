/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:09:48 by kpoilly           #+#    #+#             */
/*   Updated: 2024/03/21 12:57:05 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"

#ifndef HumanB_HPP
# define HumanB_HPP

class HumanB
{
	private:
		std::string _name;
		Weapon *_weapon_type;

	public:
		HumanB(std::string name);
		~HumanB();
		void attack();
		void setWeapon(Weapon& weapon);
};

#endif