/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:39:45 by mel-houd          #+#    #+#             */
/*   Updated: 2024/10/20 03:11:46 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Funcs.hpp"

int	main() {
	Base*	ret = generate();
	Base	ptr;

	identify(ret);
	identify(&ptr);
	identify(*ret);
	identify(ptr);

	delete ret;
}


// casting types :


// const_cast example :
// const cast is used to remove the const of an object (not safe and used rarely)

//void	example(char *str)
//{
//	std::cout << str << std::endl;
//}

//int	main()
//{
//	std::string	val = "const_cast example";
//	// this doesnt work beacuse.c_str() returns const char *
//	// example(val.c_str());
//	// we have 2 solutions :
//	// c cast :
//	example((char *)val.c_str());
//	// const_cast :
//	example(const_cast<char *>(val.c_str()));
//}

// static_cast example :
// static_cast is a general purpose cast just like c cast but safer

//void	example(void *args)
//{
//	int	result;
//	// to convert from void * we have also two choices:

//	// c style:
//	result = *(int *)args;
//	std::cout << result << std::endl;

//	// static cast:
//	result = *static_cast<int *>(args);
//	std::cout << result << std::endl;
//}

//int main()
//{
//	int	a = 2;
//	// to pass a to example we have two choices :

//	// c style:
//	example(&a);

//	// static cast :
//	example(static_cast<void *>(&a));

//	// here is a static_cast error :
//	//std::string *error_string = static_cast<std::string *>(&a);
//	//int *error_int = static_cast<int *>(a);

//}


// dynamic_cast example:
// mainly used to cast pointers up, down or sideways the inheritance hierarchy

//int main()
//{
//	Base	base;
//	A		a;
//	B		b;

//	// converting Base to C (down cast):
//	{
//		Base*	base_pointer = &base;
//		C*		c_pointer = dynamic_cast< C* >(base_pointer);
//	}

//	// converting A to Base (up cast):
//	{
//		A*		a_pointer = &a;
//		Base*	base_pointer = dynamic_cast< Base* >(a_pointer);
//	}

//	// converting B to A (sideway cast):
//	{
//		B*	b_pointer = &b;
//		A*	a_pointer = dynamic_cast< A* >(b_pointer);
//	}

//	//// this errors :
//	//int i = 3;
//	//int f = dynamic_cast<int>(i);
//}

// reinterpret_cast example:
// basiclly making crazy low level convertions like fron int to pointer and vice versa (unsafe, doesnt make checks) :

//int main()
//{
//	// convert pointer to integer value :
//	{
//		int			a = 2;
//		int			*a_p = &a;

//		uintptr_t	ptr_value = reinterpret_cast< uintptr_t >(a_p);
//		std::cout << ptr_value << std::endl;
//	}
	
//	// convert int to void * :
//	{
//		int		a = 3;
//		void	*a_to_void = reinterpret_cast< void * >(a);

//		std::cout << a_to_void << std::endl;
//	}
	
//	// this errors :
//	{
//		int		a = -1;
//		void	*a_to_void = reinterpret_cast<void *>(a);
//		int		*a_to_int = reinterpret_cast<int *>(a_to_void);
//		int		error = *a_to_int;

//		std::cout << a_to_void << std::endl;
//		std::cout << a_to_int << std::endl;
//		std::cout << error << std::endl;
//	}
//}