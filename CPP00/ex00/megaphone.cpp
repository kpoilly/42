/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 08:59:00 by kpoilly           #+#    #+#             */
/*   Updated: 2025/03/03 21:33:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

void	megaphone(std::string str)
{
	for(unsigned long i = 0; i < str.size(); i++)
			std::cout << (char)std::toupper(str[i]);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARBALE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	
	std::string str = argv[1];
	if (str.find_first_not_of(" \t\v\n") == std::string::npos && argc == 2)
	{
		std::cout << "* LOUD AND UNBEARBALE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	
	for(int i = 1; i < argc; i++)
	{
		megaphone(argv[i]);
		std::string str = argv[i];
	}
	std::cout<<std::endl;
	return (0);
}