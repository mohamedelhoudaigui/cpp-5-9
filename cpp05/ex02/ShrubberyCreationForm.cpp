

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src ):
AForm(src.GetName(), src.GetGSign(), src.GetGExec()), target(src.GetTarget())
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=( ShrubberyCreationForm const & src )
{
	if ( this != &src )
	{
		this->target = src.GetTarget();
	}
	return *this;
}

std::string	ShrubberyCreationForm::GetTarget() const {
	return (this->target);
}

const char*	ShrubberyCreationForm::GradeTooLowException::what() const throw() {
	return ("Grade too low !");
}

const char*	ShrubberyCreationForm::FormNotSignedException::what() const throw() {
	return ("Form not signed !");
}

void	ShrubberyCreationForm::execute(const Bureaucrat & executor) const {
	if (this->GetStatus() == false)
		throw FormNotSignedException();
	else if (executor.GetGrade() > this->GetGExec())
		throw GradeTooLowException();
	else {
		std::string	FileName = this->target + "_shrubbery";
		std::ofstream	File(FileName.c_str());
		if (!File.is_open())
		{
			std::cerr << "Error opening file\n";
			return ;
		}
		File << "           / |    |/\n";
		File << "        / / /||/  /_/___/_\n";
		File << "         //   |/ //\n";
		File << "    __/_/_/   |  /_____/_\n";
		File << "           /  | /          /\n";
		File << "  __ _-----`  |{,---------~\n";
		File << "            /}{\n";
		File << "             }{{\n";
		File << "             }}{\n";
		File << "             {{}\n";
		File.close();
	}
	
}