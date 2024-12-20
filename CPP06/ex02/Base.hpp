/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:12:32 by kpoilly           #+#    #+#             */
/*   Updated: 2024/09/25 18:15:28 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <stdlib.h>
# include <time.h>

class Base
{
	public:
		virtual ~Base(){};

		Base*	generate(void);
		void	identify(Base* p);
		void	identify(Base& p);
};

class A: public Base {};

class B: public Base {};

class C: public Base {};

class D: public Base 
{
	public:
		D(){};
		~D(){};
};

#endif