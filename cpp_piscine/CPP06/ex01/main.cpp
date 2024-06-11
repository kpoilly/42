/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:06:35 by kpoilly           #+#    #+#             */
/*   Updated: 2024/06/11 06:55:11 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int	main(void)
{
	Data data;
	
	data.a = 42;
	data.b = '*';
	data.c  = "Salut !";

	uintptr_t serial = Serializer::serialize(&data);
	Data* dataptr = Serializer::deserialize(serial);

	std::cout << dataptr->a << " ; " << dataptr->b << " ; " << dataptr->c << std::endl;
};