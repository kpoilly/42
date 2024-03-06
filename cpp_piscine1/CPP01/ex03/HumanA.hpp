/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:09:41 by kpoilly           #+#    #+#             */
/*   Updated: 2024/03/06 09:03:33 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"

#ifndef HumanA_HPP
# define HumanA_HPP

class HumanA
{
	private:
		std::string name;
		Weapon& weapon_type;

	public:
		HumanA(std::string name, Weapon& weapon);
		~HumanA();
		void attack();
		void setWeapon(Weapon &weapon);
};

#endif