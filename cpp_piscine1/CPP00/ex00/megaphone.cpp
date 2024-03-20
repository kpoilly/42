/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 08:59:00 by kpoilly           #+#    #+#             */
/*   Updated: 2024/03/20 13:19:01 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	megaphone(std::string str)
{
	for(int i = 0; i < str.size(); i++)
			std::cout << (char)toupper(str[i]);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARBALE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	
	std::string str = argv[1];
	if (str.find_first_not_of(" \t\v\n") && argc == 2)
	{
		std::cout << "* LOUD AND UNBEARBALE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	
	for(int i = 1; i < argc; i++)
	{
		megaphone(argv[i]);
		std::string str = argv[i];
		if (i < argc - 1 && *(argv[i + 1]) != ' ' && str.back() != ' ')
			std::cout << " ";
	}
	std::cout<<std::endl;
	return (0);
}