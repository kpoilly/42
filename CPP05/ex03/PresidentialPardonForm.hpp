/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:01:40 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/10 12:34:12 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string name);
		PresidentialPardonForm(const PresidentialPardonForm& copy);
		~PresidentialPardonForm();

		void	execute(const Bureaucrat& executor);

	private:
		std::string _Target;
};

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& obj);

#endif