/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:02:26 by kpoilly           #+#    #+#             */
/*   Updated: 2024/09/25 18:24:43 by kpoilly          ###   ########.fr       */
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
	
	D *random3 = new D;
	base.identify(random3);
	base.identify(*random3);

	base.identify(NULL);
	Base *mty = NULL;
	base.identify(*mty);

	delete random1;
	delete random2;
	delete random3;
	delete mty;
}