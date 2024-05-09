/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 08:34:33 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/09 10:11:10 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(): IMateriaSource(), _klSize(0)
{
	for(int i = 0; i < 4; i++)
		this->_Knowledge[i] = NULL;
};
MateriaSource::MateriaSource(const MateriaSource& copy)
{
	*this = copy;
};

const MateriaSource& MateriaSource::operator=(const MateriaSource& copy)
{
	for(int i = 0; i < 4; i++)
	{
		if (this->_Knowledge[i] != NULL)
			delete this->_Knowledge[i];
		this->_Knowledge[i] = copy._Knowledge[i];
	}
	this->_klSize = 0;
	for(int i = 0; i < 4; i++)
	{
		if (this->_Knowledge[i] != NULL)
			this->_klSize++;
	}
	return (*this);
};

MateriaSource::~MateriaSource()
{
	// for(int i = 0; i < 4; i++)
	// {
	// 	if (this->_Knowledge[i] != NULL)
	// 		delete this->_Knowledge[i];
	// 	this->_Knowledge[i] = NULL;
	// }
};

void	MateriaSource::learnMateria(AMateria* mat)
{
	if (this->_klSize >= 4)
		return ;
	this->_Knowledge[this->_klSize] = mat;
	this->_klSize++;
};

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for(int i = 0; i < 4; i++)
		if (this->_Knowledge[i] != NULL
			&& this->_Knowledge[i]->getType() == type)
			return (this->_Knowledge[i]);
	return 0;
};