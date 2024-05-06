/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:01:27 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/02 13:56:17 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = *stringPTR;

	std::cout<<"address:"<<std::endl;
	std::cout<<&str<<std::endl;
	std::cout<<stringPTR<<std::endl;
	std::cout<<&stringREF<<std::endl;

	std::cout<<std::endl<<"value:"<<std::endl;
	std::cout<<str<<std::endl;
	std::cout<<*stringPTR<<std::endl;
	std::cout<<stringREF<<std::endl;
}