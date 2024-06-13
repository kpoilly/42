/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:02:26 by kpoilly           #+#    #+#             */
/*   Updated: 2024/06/13 11:16:03 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(void)
{
	srand(time(NULL));
	Base base;
	
	Base *random1 = base.generate();
	base.identify(random1);
	base.identify(*random1);
	Base *random2 = base.generate();
	base.identify(random2);
	base.identify(*random2);
	Base *random3 = base.generate();
	base.identify(random3);
	base.identify(*random3);
	Base *random4 = base.generate();
	base.identify(random4);
	base.identify(*random4);

	delete random1;
	delete random2;
	delete random3;
	delete random4;
}