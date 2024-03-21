/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:09:57 by kpoilly           #+#    #+#             */
/*   Updated: 2024/03/21 12:57:50 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef Weapon_HPP
# define Weapon_HPP

class Weapon
{
	private:
		std::string _type;

	public:
		Weapon (std::string type);
		~Weapon();
		const std::string getType();
		void setType(std::string type);
};

#endif