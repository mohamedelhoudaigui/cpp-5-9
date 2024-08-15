/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 10:37:43 by mel-houd          #+#    #+#             */
/*   Updated: 2024/08/15 09:57:03 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string name, unsigned int execGrade, unsigned int signGrade) : status(false), grade_to_sign(signGrade), name(name), grade_to_exec(execGrade)
{
	if (grade_to_exec < 1 || grade_to_sign < 1)
		throw GradeTooHighException();
	else if (grade_to_exec > 150 || grade_to_sign > 150)
		throw GradeTooLowException();
}

AForm::~AForm() {}

AForm&	AForm::operator=(const AForm& other)
{
	this->status = other.status;
	return (*this);
}

AForm::AForm(const AForm& other) : status(other.getStatus()), grade_to_sign(other.getSignGrade()), name(other.getName()), grade_to_exec(other.getExecGrade())
{
}

std::string	AForm::getName() const
{
	return (this->name);
}

bool		AForm::getStatus() const
{
	return (this->status);
}

unsigned int	AForm::getExecGrade() const
{
	return (this->grade_to_exec);	
}

unsigned int	AForm::getSignGrade() const
{
	return (this->grade_to_sign);	
}

void	AForm::beSigned(const Bureaucrat& br)
{
	if (br.getGrade() <= this->getSignGrade())
		this->status = true;
	else
		throw GradeTooLowException();
}

const char*	AForm::FormNotSigned::what() const throw()
{
	return ("Error form not signed !");
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("grade too high !");
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("grade too low !");
}

std::ostream&	operator<<(std::ostream& os, const AForm& obj)
{
	os << "Form name : " << obj.getName() << "\n"; 
	os << "Form status : " << obj.getStatus() << "\n"; 
	os << "Form sign grade : " << obj.getSignGrade() << "\n"; 
	os << "Form execute grade : " << obj.getExecGrade() << "\n"; 
	return (os);
}