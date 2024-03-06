/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 09:05:14 by kpoilly           #+#    #+#             */
/*   Updated: 2024/03/06 09:52:32 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <filesystem>

int	main(int ac, char **av)
{
	if (ac != 4)
		return 42;
	std::ifstream infile (av[1]);
	std::string str;

	if (infile.is_open())
	{
		while (infile.good())
			getline(infile, str, '\0');
	}
	infile.close();
	if (str.empty())
		return 42;
	
	std::string to_rep = av[2];
	if (!to_rep.empty()){
		for (int i = str.find(to_rep, 0); i != std::string::npos; i = str.find(to_rep, i))
		{
			str.erase(i, to_rep.size());
			str.insert(i, av[3]);
		}
	}

	std::string in_name = av[1];
	std::ofstream outfile(in_name + "_replace");
	if (outfile.is_open())
		outfile << str;
}