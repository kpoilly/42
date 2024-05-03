/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 10:34:35 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/03 09:05:37 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.hpp"
#include "dog.hpp"
#include "cat.hpp"

int	main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << "j is a " << j->getType() << " " << std::endl;
	std::cout << "i is a " << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	
	j = i;
	j->makeSound();
	meta->makeSound();
}
