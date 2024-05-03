/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 10:34:35 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/03 14:04:37 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.hpp"
#include "dog.hpp"
#include "cat.hpp"

int	main(void)
{

	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;//should not create a leak
	delete i;
	
	Animal *refuge[30];

	for (int i = 0; i < 15; i++)
		refuge[i] = new Dog();
	for (int i = 15; i < 30; i++)
		refuge[i] = new Cat();
	
	for (int i = 0; i < 30; i++)
	{
		std::cout << refuge[i]->getType() << " #" << i << std::endl;
		refuge[i]->makeSound();
	}

	for (int i = 0; i < 30; i++)
		delete refuge[i];

	//Animal nope;
	//const Animal* meta = new Animal();
}
