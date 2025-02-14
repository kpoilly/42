/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:01:40 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/10 12:34:12 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include <filesystem>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string name);
		ShrubberyCreationForm(const ShrubberyCreationForm& copy);
		~ShrubberyCreationForm();

		void	execute(const Bureaucrat& executor);

		class CannotOpenException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{return "ShrubberyCreationForm::CannotOpen";};
		};

	private:
		std::string _Target;
};

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& obj);

#endif