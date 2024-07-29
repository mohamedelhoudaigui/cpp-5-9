/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:30:05 by mel-houd          #+#    #+#             */
/*   Updated: 2024/07/29 14:32:33 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Excep.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : execGrade(5), signGrade(25)
{

}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
{
	*this = other;
}

PresidentialPardonForm&	operator=(const PresidentialPardonForm& other)
{
	this->target = other.getTarget();
	this->execGrade = other.getExecGrade();
	this->signGrade = other.getSignGrade();
	return (*this);
}

//--------------------------------------------------------------------------------


void	PresidentialPardonForm::execute(const Bureaucrat& executor)
{

}
	


//----------------------------------------------------------------------------------

std::string	PresidentialPardonForm::getTarget() const
{
	return (this->target);
}

std::string	PresidentialPardonForm::getExecGrade() const
{
	return (this->execGrade);
}

std::string	PresidentialPardonForm::getSignGrade() const
{
	return (this->signGrade);
}