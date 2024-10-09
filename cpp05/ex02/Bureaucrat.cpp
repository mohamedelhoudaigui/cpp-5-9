/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 21:29:12 by mel-houd          #+#    #+#             */
/*   Updated: 2024/10/09 21:29:14 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
# include "AForm.hpp"

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::Bureaucrat(std::string Name, int Grade): Name(Name), Grade(Grade)
{
	if (Grade < 1)
		throw GradeTooHighException();
	else if (Grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat( const Bureaucrat & src ): Name(src.GetName()), Grade(src.GetGrade())
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat&	Bureaucrat::operator=( Bureaucrat const & src )
{
	if (this != &src)
	{
		this->Grade = src.GetGrade();
	}
	return (*this);
}

std::ostream&			operator<<( std::ostream & o, Bureaucrat const & i )
{
	o << i.GetName() << ", bureaucrat grade " << i.GetGrade();
	return o;
}


int			Bureaucrat::GetGrade() const {
	return (this->Grade);
}

std::string	Bureaucrat::GetName() const {
	return (this->Name);
}

const char*	Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade Too High !");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade Too Low !");
}

void	Bureaucrat::IncrGrade() {
	if (this->Grade == 1)
		throw GradeTooHighException();
	else
		this->Grade -= 1;
}

void	Bureaucrat::DecrGrade() {
	if (this->Grade == 150)
		throw GradeTooLowException();
	else
		this->Grade += 1;
}

void	Bureaucrat::signForm(AForm& f) const {
	try {
		f.beSigned(*this);
		std::cout << *this << " signed " << f << '\n';
	} catch (const std::exception& e) {
		std::cout << *this << " couldn’t sign " << f << " because " << e.what() << '\n';
	}
}

void	Bureaucrat::executeForm(AForm const & form) const {
	try {
		form.execute(*this);
		std::cout << *this << " executed " << form << '\n';
	} catch (const std::exception & e) {
		std::cout << e.what() << '\n';
	}
}
