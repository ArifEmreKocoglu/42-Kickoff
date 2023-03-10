/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:10:51 by ftekdrmi          #+#    #+#             */
/*   Updated: 2022/11/09 14:10:52 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() { cout << "Brain default constructor called" << endl; }

Brain::Brain( const Brain &cpy )
{
    cout << "Brain copy constructor called" << endl;
    *this = cpy;
}

Brain& Brain::operator = ( const Brain &obj )
{
    ideas[99] = obj.ideas[99];
    return ( *this );
}

Brain::~Brain() { cout << "Brain destructor called" << endl; }