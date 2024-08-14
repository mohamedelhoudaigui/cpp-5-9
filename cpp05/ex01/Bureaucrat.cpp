/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 09:06:14 by mel-houd          #+#    #+#             */
/*   Updated: 2024/08/14 05:47:10 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other)
{
	this->grade = other.getGrade();
	return (*this);
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
	*this = other;
}

Bureaucrat::~Bureaucrat() {}

//---------------------------------------------------------

std::string	Bureaucrat::getName() const
{
	return (this->name);
}

unsigned int	Bureaucrat::getGrade() const
{
	return (this->grade);
}

//---------------------------------------------------------

void	Bureaucrat::incrGrade()
{
	if (grade <= 1)
	{
		throw GradeTooHighException();
	}
	this->grade--;
}

void	Bureaucrat::decrGrade()
{
	if (grade >= 150)
	{
		throw GradeTooLowException();
	}
	this->grade++;
}

//------------------------------------------------------------

void	Bureaucrat::signForm(Form& form) const
{
	form.beSigned(*this);
	std::cout << *this << " signed " << form.getName() << "\n";
}

//----------------------------------------------------------

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat grade too high !");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat grade too low !");
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return (os);
}