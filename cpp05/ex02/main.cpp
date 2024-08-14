/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 09:28:10 by mel-houd          #+#    #+#             */
/*   Updated: 2024/08/14 08:18:56 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

//int main ()
//{
//    Bureaucrat B("bureaucrat", 2);
//    AForm *f = new ShrubberyCreationForm("home");
//    AForm *f2 = new RobotomyRequestForm("home");
//    AForm *f3 = new PresidentialPardonForm("home");

//    try
//    {
//        B.decrGrade();
//    }
//    catch (const std::exception& e)
//    {
//        std::cout << "Error : " << e.what() << std::endl;
//    }  
//    try
//    {
//        f->beSigned(B);
//        f->execute(B);
//    }
//    catch (const std::exception& e)
//    {
//        std::cout << "Error : " << e.what() << std::endl;
//    }  
//    std::cout << std::endl << " ----------------------------- " << std::endl;
//    try
//    {
//        B.signForm(*f2);
//        f2->execute(B);
//    }
//    catch (const std::exception& e)
//    {
//        std::cout << "Error : " << e.what() << std::endl;
//    }  
//    std::cout << std::endl << " ----------------------------- " << std::endl;
//    try
//    {
//        f3->beSigned(B);
//        f3->execute(B);
//    }
//    catch (const std::exception& e)
//    {
//        std::cout << "Error : " << e.what() << std::endl;
//    }
//    std::cout << B << std::endl;
//    std::cout << *f << std::endl;
//    delete f;
//    delete f2;
//    delete f3;
//    return (0);
//}

int main(void)
{
	Bureaucrat B("simo", 100);
	Bureaucrat A("erya", 1);

	ShrubberyCreationForm f("home");
	RobotomyRequestForm f2("home");
	PresidentialPardonForm f3("home");
	B.signForm(f);
	f.execute(B);
	try
	{
		B.signForm(f3);
		f3.execute(B);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}