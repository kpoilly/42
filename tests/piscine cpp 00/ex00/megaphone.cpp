/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:31:26 by kpoilly           #+#    #+#             */
/*   Updated: 2023/12/11 15:36:57 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;

int	ft_strlen(string str)
{
	int	i = 0;
	
	while (str[i])
		i++;
	return (i);
}

void	megaphone(string str)
{
	int len = ft_strlen(str);
	for(int i = 0; i <len; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			cout << (char)(str[i] - 32);
		else
			cout << (char)str[i];
	}
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		cout << "* LOUD AND UNBEARBALE FEEDBACK NOISE *"<<endl;
		return (0);
	}
	megaphone(argv[1]);
}