/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:30:07 by mel-houd          #+#    #+#             */
/*   Updated: 2024/07/29 14:32:21 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PresidentialPardonForm_HPP
#define PresidentialPardonForm_HPP

#include <exception>
#include <iostream>
#include <string>

#include "Form.hpp"

class	PresidentialPardonForm : public Form
{
	public:
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& other);
		~PresidentialPardonForm();

		std::string	getTarget() const;
		std::string	getSignGrade() const;
		std::string	getExecGrade() const;

		void	execute(const Bureaucrat& executor)
		
	private:
		unsigned int	execGrade;
		unsigned int	signGrade;
		std::string		target;
};



#endif