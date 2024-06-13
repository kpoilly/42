/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:11:05 by kpoilly           #+#    #+#             */
/*   Updated: 2024/06/13 11:14:46 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base*	Base::generate(void)
{
	int ran = rand()%3;
	switch (ran)
	{
		case 0:
			std::cout << "\033[1;32mBase::generate: Object of type A has been generated.\033[0m" << std::endl;
			return (new A);
		case 1:
			std::cout << "\033[1;32mBase::generate: Object of type B has been generated.\033[0m" << std::endl;
			return (new B);
		case 2:
			std::cout << "\033[1;32mBase::generate: Object of type C has been generated.\033[0m" << std::endl;
			return (new C);
	}
	return (NULL);
};

void	Base::identify(Base* p)
{
	std::cout << "\033[1;33mBase::identify: object p is type ";
	if (A* test = dynamic_cast<A*>(p))
		std::cout << "A.\033[0m" << std::endl;
	else if (B* test = dynamic_cast<B*>(p))
		std::cout << "B.\033[0m" << std::endl;
	else if (C* test = dynamic_cast<C*>(p))
		std::cout << "C.\033[0m" << std::endl;
};

void	Base::identify(Base& p)
{
	std::cout << "\033[1;34mBase::identify: object p is type ";
	if (A* test = dynamic_cast<A*>(&p))
		std::cout << "A.\033[0m" << std::endl;
	if (B* test = dynamic_cast<B*>(&p))
		std::cout << "B.\033[0m" << std::endl;
	if (C* test = dynamic_cast<C*>(&p))
		std::cout << "C.\033[0m" << std::endl;
};
