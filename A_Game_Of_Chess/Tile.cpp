//
//  Tile.cpp
//  A_Game_Of_Chess
//
//  Created by Greyson Chavez on 1/13/24.
//

#include "Tile.hpp"

// copy assignment
Tile& Tile::operator=( const Tile& t )
{
//        m_isFull = t.m_isFull ;
    m_piece = t.m_piece ;
    
    return *this ;
}


Piece& Tile::getPiece()
{
    return m_piece ;
}


void Tile::setPiece( const Piece& piece )
{
    m_piece = piece ;
}
