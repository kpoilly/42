/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 10:36:23 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/03 10:29:18 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include "brain.hpp"

class Animal
{
	protected:
		std::string _type;

	public:
		Animal();
		Animal(const Animal& copy);
		Animal& operator=(const Animal& copy);
		~Animal();
		
		virtual void makeSound() const;
		std::string getType() const;
};

#endif