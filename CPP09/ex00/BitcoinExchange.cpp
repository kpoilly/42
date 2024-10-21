/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:32:55 by kpoilly           #+#    #+#             */
/*   Updated: 2024/06/07 10:52:39 by kpoilly          ###   ########.fr       */
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

std::string itos(int i)
{
	std::stringstream ss;
	std::string convert;
	ss << i;
	ss >> convert;
	if (i < 10)
		convert = "0" + convert;
	return convert;
};

bool	check_date(std::string date)
{
	std::string checker = date.substr(0, date.find("-"));
	if (stringtold(checker) < 2009)
		return true;
	checker = date.substr(date.find("-") + 1, 2);
	if (stringtold(checker) < 0 || stringtold(checker) > 12)
		return true;
	checker = date.substr(date.find("-") + 1, 5);
	checker = checker.substr(checker.find("-") + 1, checker.find("-"));
	if (stringtold(checker) < 0 || stringtold(checker) > 31)
		return true;
	return false;
};

std::string get_date()
{
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);
	return (itos(now->tm_year + 1900) + "-" + itos(now->tm_mon + 1) + "-" + itos(now->tm_mday));	
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

bool check_errors(std::string str)
{
	if (str.find(" | ") == std::string::npos)
	{
		std::cerr << "\033[1;31mError: Input file format should be 'date | value'." << std::endl;
		std::cerr << "=> \033[30m" << str << "\033[0m" << std::endl;
		return true;
	}

	std::string date = str.substr(0, str.find(" | "));
	if (check_date(date))
	{
		std::cerr << "\033[1;31mError: Invalid date format (must be YEAR-MM-DD)." << std::endl;
		std::cerr << "=> \033[30m" << date << "\033[0m" << std::endl;
		return true;
	}
	if (date < "2009-01-02" || date > get_date())
	{
		std::cerr << "\033[1;31mError: Invalid date (must be between 2009-01-02 and today)." << std::endl;
		std::cerr << "=> \033[30m" << date << "\033[0m" << std::endl;
		return true;
	}
	long double value = stringtold(str.substr(str.find(" | ") + 3, std::string::npos));
	if (value < 0)
	{
		std::cerr << "\033[1;31mError: Should be a positive number." << std::endl;
		std::cerr << "=> \033[30m" << value << "\033[0m" << std::endl;
		return true;
	}
	if (value > 1000)
	{
		std::cerr << "\033[1;31mError: Number too large." << std::endl;
		std::cerr << "=> \033[30m" << value << "\033[0m" << std::endl;
		return true;
	}
	return false;
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
