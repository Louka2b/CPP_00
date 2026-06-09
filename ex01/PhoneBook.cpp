/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: louka <louka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 12:47:45 by louka             #+#    #+#             */
/*   Updated: 2026/06/09 15:33:17 by louka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstdlib>

PhoneBook::PhoneBook()
{
    _count = 0;
    _current_index = 0;
}

PhoneBook::~PhoneBook()
{
}

void print_name(std::string tmp)
{
    std::string space = "                                            ";
    if(tmp.size() > 10)
    {
        tmp.resize(9);
        std::cout << tmp << ".|";
    }
    else
    {
        std::cout << tmp;
        if(tmp.size() < 10)
        {
            space.resize(10 - tmp.size());
            std::cout << space;
        }
        std::cout << "|";
    } 
}

void PhoneBook::search_contact()
{
    int i = 0;
    int nbr = 0;
    std::string tmp = "";

    if (_count == 0)
    {
        std::cout << "PHONEBOOK IS EMPTY" << '\n';
        return;
    }

    std::cout << '\n' << "ID|FIRST NAME|LAST NAME |NICKNAME  |NUMBER    |";
    while(i < _count)
    {
        std::cout << '\n';
        std::cout << i << " |" ;
        print_name(_contacts[i].get_first_name());
        print_name(_contacts[i].get_last_name());
        print_name(_contacts[i].get_nickname());
        print_name(_contacts[i].get_phone_number());
        i++;
    }
    std::cout << '\n' << "SELECT AN ID: ";
    if (!std::getline(std::cin, tmp))
        return;
    if (tmp.length() == 1 && tmp[0] >= '0' && tmp[0] <= '9')
        nbr = tmp[0] - '0';
    else
        nbr = -1;
    if(nbr < 0 || nbr >= _count)
    {
        std::cout << "ERROR BAD ID" << '\n';
        return;
    }
    
    std::cout << "First Name: " << _contacts[nbr].get_first_name() << '\n';
    std::cout << "Last Name: " << _contacts[nbr].get_last_name() << '\n';
    std::cout << "Nickname: " << _contacts[nbr].get_nickname() << '\n';
    std::cout << "Phone Number: " << _contacts[nbr].get_phone_number() << '\n';
}

void PhoneBook::add_contact()
{
    std::string fn;
    std::string ln;
    std::string nm;
    std::string num;

    std::cout << "ENTER FIRST NAME" << '\n';
    if (!std::getline(std::cin, fn)) return;
    std::cout << "ENTER LAST NAME" << '\n';
    if (!std::getline(std::cin, ln)) return;
    std::cout << "ENTER NICKNAME" << '\n';
    if (!std::getline(std::cin, nm)) return;
    std::cout << "ENTER NUMBER" << '\n';
    if (!std::getline(std::cin, num)) return;
    _contacts[_current_index].set_info(fn, ln, nm, num);
    if (_count < 8)
        _count++;    
    _current_index++;
    if (_current_index >= 8)
        _current_index = 0;
}

int main(void)
{
    PhoneBook phonebook;
    std::string line = "";
    while(1)
    {
        if (!std::getline(std::cin, line))
            return(0);
        if(line == "EXIT")
            return(0);
        if(line == "SEARCH")
            phonebook.search_contact();
        if(line == "ADD")
            phonebook.add_contact();
    }
}