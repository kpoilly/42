/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:06:31 by kpoilly           #+#    #+#             */
/*   Updated: 2024/06/11 06:56:12 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>

# include "Data.hpp"

class Serializer
{
	public:
		static uintptr_t serialize(Data *ptr);
		static Data* deserialize(uintptr_t raw);	
};

#endif
