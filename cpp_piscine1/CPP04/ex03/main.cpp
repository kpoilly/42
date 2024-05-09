/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:26:32 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/09 13:17:53 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int	main(void)
{
	{
	std::cout << "	= Subject's Main : =" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	std::cout << "	 =================\n" << std::endl;
	}
	{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* paul = new Character("Paul");
	ICharacter* bob = new Character("Bob");
	AMateria* tmp;
	AMateria* save;
	tmp = src->createMateria("ice");
	paul->equip(tmp);
	bob->equip(tmp); //already equipped.
	tmp = src->createMateria("ice");
	bob->equip(tmp);
	tmp = src->createMateria("cure");
	paul->equip(tmp);
	save = tmp;
	tmp = src->createMateria("cure");
	bob->equip(tmp);

	std::cout << std::endl;
	bob->use(0, *paul);
	paul->use(0, *bob);
	bob->use(1, *bob);
	
	std::cout << "\n	= Invalid Materia ID (use) =" << std::endl;
	paul->use(0, *bob); //works
	paul->use(2, *bob); //doesn't
	paul->use(-14, *bob); //doesn't
	std::cout << "		==============\n" << std::endl;
	
	std::cout << "	= Invalid Materia ID (unequip) =" << std::endl;
	paul->use(1, *bob); //works
	paul->unequip(1);
	paul->unequip(-14); //doesn't
	paul->use(1, *bob); //doesn't
	paul->unequip(3); //doesn't
	paul->equip(src->createMateria("cure"));
	paul->use(1, *bob); //works
	std::cout << "		================" << std::endl;
	
	delete bob;
	delete paul;
	delete src;
	delete save;
	}
	return 0;
};
