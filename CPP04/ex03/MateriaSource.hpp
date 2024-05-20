/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 08:34:35 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/09 09:37:34 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& copy);
		const MateriaSource& operator=(const MateriaSource& copy);
		~MateriaSource();

		void	learnMateria(AMateria*);
		AMateria*	createMateria(std::string const & type);
		
	protected:
		AMateria* _Knowledge[4];
		int	_klSize;
};

#endif