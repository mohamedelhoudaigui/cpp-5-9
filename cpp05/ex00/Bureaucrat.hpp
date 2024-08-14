/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 08:58:50 by mel-houd          #+#    #+#             */
/*   Updated: 2024/08/14 05:39:41 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class	Bureaucrat
{
	public:
		Bureaucrat(std::string name, unsigned int grade);
		~Bureaucrat();
		Bureaucrat&	operator=(const Bureaucrat& other);
		Bureaucrat(const Bureaucrat& other);


		std::string		getName() const;
		unsigned int	getGrade() const;

		void			incrGrade();
		void			decrGrade();

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};

	private:
		const std::string	name;
		unsigned int		grade;
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& obj);

#endif