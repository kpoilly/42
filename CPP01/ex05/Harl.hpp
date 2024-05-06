/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 09:54:25 by kpoilly           #+#    #+#             */
/*   Updated: 2024/03/21 12:58:57 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

#ifndef Harl_HPP
# define Harl_HPP

class Harl
{
	private:
		void _debug(void);
		void _info(void);
		void _warning(void);
		void _error(void);

	public:
		Harl();
		~Harl();
		void complain(std::string level);
};

#endif