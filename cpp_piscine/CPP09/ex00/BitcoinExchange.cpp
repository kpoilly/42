/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:32:55 by kpoilly           #+#    #+#             */
/*   Updated: 2024/06/06 18:27:58 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static long double stringtold(std::string str)
{
	std::stringstream ss(str);
	long double ld;
	ss >> ld;
	return ld;
};

static long double calc_rate(std::string str, std::map<std::string, long double> data)
{
	std::string date = str.substr(0, str.find(" | "));
	long double nb = stringtold(str.substr(str.find(" | ") + 3, std::string::npos));
	long double value = 0;
	
	for(std::map<std::string, long double>::iterator i = data.begin(); i != data.end(); i++)
	{
		if (i->first <= date)
			value = i->second;
		else
			break ;
	}
	return (nb * value);
};

int check_errors(std::string str)
{
	long double value;
	
	if (str.find(" | ") == std::string::npos)
	{
		std::cerr << "\033[1;31mError: Input file format should be 'date | value'." << std::endl;
		std::cerr << "=> \033[0m" << str << std::endl;
		return 1;
	}

	//Need to check date format Year-Month-Day (4 chiffre-(2 <= 12) - (2 <= 31))
	value = stringtold(str.substr(str.find(" | ") + 3, std::string::npos));
	if (value < 0)
	{
		std::cerr << "\033[1;31mError: Should be a positive number." << std::endl;
		std::cerr << "=> \033[0m" << value << std::endl;
		return 1;
	}
	if (value > 1000)
	{
		std::cerr << "\033[1;31mError: Number too large." << std::endl;
		std::cerr << "=> \033[0m" << value << std::endl;
		return 1;
	}
	return 0;
};

std::map<std::string, long double> get_data()
{
	std::map<std::string, long double> data;
	std::ifstream dataFile ("./data.csv");
	std::string str;
	
	if (dataFile.is_open())
	{
		while (std::getline(dataFile, str, '\n'))
			data[str.substr(0, str.find(","))] = stringtold(str.substr(str.find(",") + 1, std::string::npos));
		str.clear();
	}
	else
		std::cerr << "Error: Cannot open data.csv." << std::endl;
	dataFile.close();
	return data;
};

void	read_input(char *filename, std::map<std::string, long double> data)
{
	std::ifstream infile(filename);
	std::string line;

	if (infile.is_open())
	{
		while (infile.good())
		{
			std::getline(infile, line, '\n');
			if (check_errors(line))
				continue ;
			std::cout << line.substr(0, line.find(" | "));
			std::cout << " => " << line.substr(line.find(" | ") + 3,  std::string::npos);
			std::cout << " = " << calc_rate(line, data) << std::endl;
			line.clear();
		}
	}
	else
		std::cerr << "Error: Cannot open " << filename << "." << std::endl;
	infile.close();
};
