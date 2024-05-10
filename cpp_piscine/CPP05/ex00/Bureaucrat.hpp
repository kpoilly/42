/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpoilly <kpoilly@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 08:18:56 by kpoilly           #+#    #+#             */
/*   Updated: 2024/05/10 10:13:46 by kpoilly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{
	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& copy);
		const Bureaucrat& operator=(const Bureaucrat& copy);
		~Bureaucrat();
		
		std::string getName() const;
		int			getGrade() const;

		Bureaucrat& operator++ ();
		Bureaucrat& operator++ (int);
		Bureaucrat& operator-- ();
		Bureaucrat& operator-- (int);

	private:
		std::string _Name;	
		int 		_Grade;	
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);


#endif