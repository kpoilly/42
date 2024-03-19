/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 08:59:00 by kpoilly           #+#    #+#             */
/*   Updated: 2024/03/19 07:31:07 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	megaphone(std::string str)
{
	for(int i = 0; i < str.size(); i++)
	{
		if (islower(str[i]))
			std::cout << (char)toupper(str[i]);
		else
			std::cout << (char)str[i];
	}
}

int	main(int argc, char **argv)
{
	if (argc < 2 || !*(argv[1]))
	{
		std::cout << "* LOUD AND UNBEARBALE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	for(int i = 1; i < argc; i++)
		megaphone(argv[i]);
	std::cout<<std::endl;
	return (0);
}