/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 10:37:45 by mel-houd          #+#    #+#             */
/*   Updated: 2024/07/29 14:22:44 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class	Bureaucrat;

class	Form
{
	public:
		Form(std::string name, unsigned int execGrade, unsigned int signGrade);
		~Form();
		Form&	operator=(const Form& other);
		Form(const Form& other);

		std::string		getName() const;
		bool			getStatus() const;
		unsigned int	getExecGrade() const;
		unsigned int	getSignGrade() const;

		void			beSigned(const Bureaucrat& br);

	private:
		const std::string	name;
		bool				status;
		const unsigned int	grade_to_sign;
		const unsigned int	grade_to_exec;
		
};

std::ostream&	operator<<(std::ostream& os, const Form& obj);

#endif