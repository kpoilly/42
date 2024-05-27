/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:01:40 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/10 12:34:12 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		~AForm();

		std::string 	getName() const;
		bool			isSigned() const;
		int 			getGradeS() const;
		int 			getGradeX() const;
		
		void			beSigned(const Bureaucrat& signer);
		virtual void	execute(const Bureaucrat& executor) = 0;

	protected:
		AForm(std::string name, int grades, int gradex);
		AForm(const AForm& copy);

		const std::string 	_Name;
		bool				_Signed;
		const int			_GradeS;
		const int			_GradeX;

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{return "AForm::GradeTooLow";};
	};
	
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{return "AForm::GradeTooHigh";};
	};

	class NotSignedException : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{return "AForm::NotSigned";};
	};
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif