/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 10:37:43 by mel-houd          #+#    #+#             */
/*   Updated: 2024/07/29 13:30:48 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"


Form::Form(std::string name, unsigned int execGrade, unsigned int signGrade) : name(name), grade_to_sign(signGrade), grade_to_exec(execGrade)
{
	this->status = false;
	if (grade_to_exec < 1 || grade_to_sign < 1)
		throw GradeTooHighException();
	else if (grade_to_exec > 150 || grade_to_sign > 150)
		throw GradeTooLowException();
}

Form::~Form() {}

Form&	Form::operator=(const Form& other)
{
	this->status = other.status;
	return (*this);
}

Form::Form(const Form& other) : name(other.getName()), status(other.getStatus()), grade_to_sign(other.getSignGrade()), grade_to_exec(other.getExecGrade())
{
}

std::string	Form::getName() const
{
	return (this->name);
}

bool		Form::getStatus() const
{
	return (this->status);
}

unsigned int	Form::getExecGrade() const
{
	return (this->grade_to_exec);	
}

unsigned int	Form::getSignGrade() const
{
	return (this->grade_to_sign);	
}

void	Form::beSigned(const Bureaucrat& br)
{
	if (br.getGrade() <= this->getSignGrade())
		this->status = true;
	else
		throw GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const _NOEXCEPT
{
	return ("Bureaucrat : Grade is too high!");
}

const char* Form::GradeTooLowException::what() const _NOEXCEPT
{
	return ("Bureaucrat : Grade is too low!");
}



std::ostream&	operator<<(std::ostream& os, const Form& obj)
{
	os << "Form name : " << obj.getName() << "\n"; 
	os << "Form status : " << obj.getStatus() << "\n"; 
	os << "Form sign grade : " << obj.getSignGrade() << "\n"; 
	os << "Form execute grade : " << obj.getExecGrade() << "\n"; 
	return (os);
}