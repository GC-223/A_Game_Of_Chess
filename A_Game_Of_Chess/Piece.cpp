//
//  Piece.cpp
//  A_Game_Of_Chess
//
//  Created by Greyson Chavez on 1/13/24.
//

#include "Piece.hpp"


// copy assignment
Piece& Piece::operator=( const Piece& piece )
{
    if ( this == &piece )
    {
        return *this ;
    }
    
    m_color = piece.m_color ;
    m_symbol = piece.m_symbol ;
    
    return *this ;
}


