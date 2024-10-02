/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:40:08 by mel-houd          #+#    #+#             */
/*   Updated: 2024/10/02 19:03:01 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP


class Base {
	public:
		virtual ~Base();
};

class A: public Base {
	public:
		~A();
};

class B: public Base {
	public:
		~B();
};

class C: public Base {
	public:
		~C();
};


#endif