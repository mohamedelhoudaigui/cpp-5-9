

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"


PresidentialPardonForm::PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target):
AForm("PresidentialPardonForm", 25, 5), target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & src ):
AForm(src.GetName(), src.GetGSign(), src.GetGExec()), target(src.GetTarget())
{
}


PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm&	PresidentialPardonForm::operator=( PresidentialPardonForm const & src )
{
	if ( this != &src )
	{
		this->target = src.GetTarget();
	}
	return *this;
}


std::string	PresidentialPardonForm::GetTarget() const {
	return (this->target);
}

const char*	PresidentialPardonForm::GradeTooLowException::what() const throw() {
	return ("Grade too low !");
}

const char*	PresidentialPardonForm::FormNotSignedException::what() const throw() {
	return ("Form not signed !");
}

void	PresidentialPardonForm::execute(const Bureaucrat & executor) const {
	if (this->GetStatus() == false)
		throw FormNotSignedException();
	else if (executor.GetGrade() > this->GetGExec())
		throw GradeTooLowException();
	else
		std::cout << this->target << " has been pardoned by Zaphod Beeblebrox\n";
}