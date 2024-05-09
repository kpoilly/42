/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 08:34:33 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/09 12:35:41 by kpoilly          ###   ########.fr       */
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
		if (this->_Knowledge[i])
			delete this->_Knowledge[i];
		this->_Knowledge[i] = copy._Knowledge[i]->clone();
	}
	this->_klSize = 0;
	for(int i = 0; i < 4; i++)
	{
		if (this->_Knowledge[i])
			this->_klSize++;
	}
	return (*this);
};

MateriaSource::~MateriaSource()
{
	for(int i = 0; i < 4; i++)
		if (this->_Knowledge[i])
		{
			delete this->_Knowledge[i];
			this->_Knowledge[i] = NULL;
		}
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
		if (this->_Knowledge[i]
			&& this->_Knowledge[i]->getType() == type)
			return (this->_Knowledge[i]->clone());
	return 0;
};