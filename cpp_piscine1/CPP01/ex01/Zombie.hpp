/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:26:26 by kpoilly           #+#    #+#             */
/*   Updated: 2024/03/05 11:53:06 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Zombie_HPP
# define Zombie_HPP

# include <iostream>

class Zombie
{
	private:
		std::string name;

	public:
	Zombie();
	Zombie(std::string);
	~Zombie();
	void set_name(std::string name);
	void announce(void);
};

Zombie*	zombieHorde(int N, std::string name);

#endif