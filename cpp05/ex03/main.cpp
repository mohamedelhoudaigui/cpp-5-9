/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 09:28:10 by mel-houd          #+#    #+#             */
/*   Updated: 2024/08/15 10:48:55 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void    f(void)
{
    system("leaks Bureaucrat");
}

int main ()
{
    //atexit(f);
    try
    {
        Bureaucrat B("bureaucrat", 1);
        Intern i;
        AForm *f1 = i.makeForm("robotomy request", "hello");
        std::cout << *f1;
        B.signForm(*f1);
        f1->execute(B);
        delete f1;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return (1);
    }
}
