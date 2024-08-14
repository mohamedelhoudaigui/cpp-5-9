/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 09:06:14 by mel-houd          #+#    #+#             */
/*   Updated: 2024/08/14 06:13:46 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

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

//--------------------------------------------------------

const char* Bureaucrat::GradeTooHighException::what() const _NOEXCEPT
{
	return ("Bureaucrat : Grade is too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const _NOEXCEPT
{
	return ("Bureaucrat : Grade is too low!");
}


//------------------------------------------------------------

void	Bureaucrat::signForm(AForm& form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << *this << " signed " << form.getName() << "\n";
	}
	catch (const std::exception& e)
	{
		std::cerr << *this << " couldn't sign " << form.getName() << " because " << e.what() << "\n";
	}
}

//----------------------------------------------------------


std::ostream&	operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return (os);
}