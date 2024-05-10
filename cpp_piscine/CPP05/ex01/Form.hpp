/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:01:40 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/10 11:23:47 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Form
{
	public:
		Form(std::string name, int grades, int gradex);
		Form(const Form& copy);
		const Form& operator=(const Form& copy);
		~Form();

		std::string getName() const;
		bool		isSigned() const;
		int 		getGradeS() const;
		int 		getGradeX() const;
		
		void		beSigned(const Bureaucrat& signer) const;

	private:
		const std::string 	_Name;
		bool				_Signed;
		const int			_GradeS;
		const int			_GradeX;
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif