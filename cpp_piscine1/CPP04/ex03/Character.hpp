/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 09:59:03 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/07 12:45:02 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

# include <iostream>
# include "Materia.hpp"

class Character : virtual ICharacter
{
	public:
		Character();
		Character(std::string Name);
		Character(const Character& copy);
		Character& operator=(const Character& copy);
		~Character();

		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		
	private:
		std::string	_Name;
		int	_invSize;
		AMateria* _Inventory[4];
};

#endif