/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:09:48 by kpoilly           #+#    #+#             */
/*   Updated: 2024/03/05 12:46:59 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"

#ifndef HumanA_HPP
# define HumanA_HPP

class HumanB
{
	private:
		std::string name;
		Weapon* weapon_type;

	public:
		HumanB(std::string name);
		~HumanB();
		void attack();
};

#endif