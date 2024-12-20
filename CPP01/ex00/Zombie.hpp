/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:26:26 by kpoilly           #+#    #+#             */
/*   Updated: 2024/03/21 12:54:21 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Zombie_HPP
# define Zombie_HPP

# include <iostream>

class Zombie
{
	private:
		std::string _name;

	public:
		Zombie(std::string);
		~Zombie();
		void announce(void);
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif