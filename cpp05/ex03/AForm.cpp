/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 03:19:33 by mel-houd          #+#    #+#             */
/*   Updated: 2024/10/08 08:12:03 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"


AForm::AForm(): GSign(1), GExec(1) 
{
}

AForm::AForm(std::string Name, int GSign, int GExec): Name(Name), GSign(GSign), GExec(GExec), Signed(false)
{
	if (GSign < 1 || GExec < 1)
		throw GradeTooHighException();
	if (GSign > 150 || GExec > 150)
		throw GradeTooLowException();
}

AForm::AForm( const AForm & src ): Name(src.GetName()), GSign(src.GetGSign()), GExec(src.GetGExec()), Signed(src.GetStatus())
{
}

AForm::~AForm()
{
}

AForm&	AForm::operator=( AForm const & src )
{
	if ( this != &src )
	{
		this->Signed = src.GetStatus();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, AForm const & i )
{
	o << "AForm name : " << i.GetName() << " - Grade to execute : " << i.GetGExec() << " - Grade to sign : " << i.GetGSign();
	return o;
}

const char*	AForm::GradeTooHighException::what() const throw() {
	return ("Grade Too High !");
}

const char*	AForm::GradeTooLowException::what() const throw() {
	return ("Grade Too Low !");
}

std::string	AForm::GetName() const {
	return (this->Name);
}

bool		AForm::GetStatus()	const {
	return (this->Signed);
}



int			AForm::GetGSign()	const {
	return (this->GSign);
}

int			AForm::GetGExec()	const {
	return (this->GExec);
}

void	AForm::beSigned(const Bureaucrat& b) {
	if (b.GetGrade() <= this->GSign)
		this->Signed = true;
	else
		throw GradeTooLowException();
}

