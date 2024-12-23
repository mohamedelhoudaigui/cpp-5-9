/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:30:19 by mel-houd          #+#    #+#             */
/*   Updated: 2024/11/24 14:46:38 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template<typename T>
void printStack(const MutantStack<T>& mstack, const std::string& label) {
    std::cout << "\n=== " << label << " ===\n";
    MutantStack<T> copy = mstack;  // Create a copy to preserve original
    while (!copy.empty()) {
        std::cout << copy.top() << " ";
        copy.pop();
    }
    std::cout << std::endl;
}

int main() {
    // Test 1: Basic stack operations with integers
    std::cout << "\n=== Test 1: Basic Stack Operations (Int) ===\n";
    MutantStack<int> mstack;
    
    // Test push and size
    std::cout << "Pushing elements: 5, 17, 3, 9, 11\n";
    mstack.push(5);
    mstack.push(17);
    mstack.push(3);
    mstack.push(9);
    mstack.push(11);
    std::cout << "Stack size: " << mstack.size() << std::endl;
    
    // Test top
    std::cout << "Top element: " << mstack.top() << std::endl;
    
    // Test pop
    mstack.pop();
    std::cout << "After pop, top element: " << mstack.top() << std::endl;
    std::cout << "Stack size after pop: " << mstack.size() << std::endl;

    // Test 2: Iterator functionality
    std::cout << "\n=== Iterator Functionality ===\n";
    std::cout << "Iterating through stack from bottom to top: ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Test 3: Const iterator functionality
    std::cout << "\n=== Const Iterator Functionality ===\n";
    const MutantStack<int> const_mstack = mstack;
    std::cout << "Const iteration through stack: ";
    for (MutantStack<int>::const_iterator it = const_mstack.begin(); it != const_mstack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Different data types
    std::cout << "\n=== String Stack ===\n";
    MutantStack<std::string> string_stack;
    string_stack.push("Hello");
    string_stack.push("World");
    string_stack.push("!");

    std::cout << "String stack contents: ";
    for (MutantStack<std::string>::iterator it = string_stack.begin(); it != string_stack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Copy constructor and assignment operator (inherited from std::stack)
    std::cout << "\n=== Copy Operations ===\n";
    MutantStack<int> stack_copy(mstack);
    std::cout << "Copied stack contents: ";
    for (MutantStack<int>::iterator it = stack_copy.begin(); it != stack_copy.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    MutantStack<int> stack_assigned;
    stack_assigned = mstack;
    std::cout << "Assigned stack contents: ";
    for (MutantStack<int>::iterator it = stack_assigned.begin(); it != stack_assigned.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Empty check and clearing
    std::cout << "\n=== Test 7: Empty and Clear Operations ===\n";
    MutantStack<int> empty_stack;
    std::cout << "Is empty stack empty? " << (empty_stack.empty() ? "Yes" : "No") << std::endl;
    std::cout << "Is original stack empty? " << (mstack.empty() ? "Yes" : "No") << std::endl;
    
    while (!mstack.empty()) {
        mstack.pop();
    }
    std::cout << "After clearing, is original stack empty? " << (mstack.empty() ? "Yes" : "No") << std::endl;

    return 0;
}