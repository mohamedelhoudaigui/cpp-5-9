/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 03:19:33 by mel-houd          #+#    #+#             */
/*   Updated: 2024/10/08 04:19:51 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"


Form::Form(): GSign(1), GExec(1) 
{
}

Form::Form(std::string Name, int GSign, int GExec): Name(Name), GSign(GSign), GExec(GExec), Signed(false)
{
	if (GSign < 1 || GExec < 1)
		throw GradeTooHighException();
	if (GSign > 150 || GExec > 150)
		throw GradeTooLowException();
}

Form::Form( const Form & src ): Name(src.GetName()), GSign(src.GetGSign()), GExec(src.GetGExec()), Signed(src.GetStatus())
{
}

Form::~Form()
{
}

Form&	Form::operator=( Form const & src )
{
	if ( this != &src )
	{
		this->Signed = src.GetStatus();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Form const & i )
{
	o << "Form name : " << i.GetName() << " - Grade to execute : " << i.GetGExec() << " - Grade to sign : " << i.GetGSign();
	return o;
}

const char*	Form::GradeTooHighException::what() const throw() {
	return ("Grade Too High !");
}

const char*	Form::GradeTooLowException::what() const throw() {
	return ("Grade Too Low !");
}

std::string	Form::GetName() const {
	return (this->Name);
}

bool		Form::GetStatus()	const {
	return (this->Signed);
}



int			Form::GetGSign()	const {
	return (this->GSign);
}

int			Form::GetGExec()	const {
	return (this->GExec);
}

void	Form::beSigned(const Bureaucrat& b) {
	if (b.GetGrade() <= this->GSign)
		this->Signed = true;
	else
		throw GradeTooLowException();
}