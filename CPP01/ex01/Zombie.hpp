/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:26:26 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/02 13:37:24 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Zombie_HPP
# define Zombie_HPP

# include <iostream>
# include <cstdlib>

class Zombie
{
	private:
		std::string _name;

	public:
		Zombie();
		Zombie(std::string);
		~Zombie();
		void set_name(std::string name);
		void announce(void);
};

Zombie*	zombieHorde(int N, std::string name);

#endif