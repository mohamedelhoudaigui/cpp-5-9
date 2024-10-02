/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 10:37:45 by mel-houd          #+#    #+#             */
/*   Updated: 2024/10/01 13:53:33 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class	Bureaucrat;

class	AForm
{
	public:
		AForm(std::string name, unsigned int execGrade, unsigned int signGrade);
		virtual ~AForm();
		AForm&	operator=(const AForm& other);
		AForm(const AForm& other);

		std::string		getName() const;
		bool			getStatus() const;
		unsigned int	getExecGrade() const;
		unsigned int	getSignGrade() const;

		void			beSigned(const Bureaucrat& br);
		virtual void	execute(const Bureaucrat& executor) const = 0;


		class FormNotSigned : public std::exception
		{
			public:
				const char* what() const throw();
		};

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
		bool				status;
		const unsigned int	grade_to_sign;
		const std::string	name;
		const unsigned int	grade_to_exec;
		
};

std::ostream&	operator<<(std::ostream& os, const AForm& obj);

#endif