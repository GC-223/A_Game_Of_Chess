//
//  Tile.hpp
//  A_Game_Of_Chess
//
//  Created by Greyson Chavez on 1/13/24.
//

#ifndef Tile_hpp
#define Tile_hpp

#include "Piece.hpp"

class Tile
{
private:
    
    // returns true if there is a piece occupying this tile
//    bool m_isFull { } ;
    
    Piece m_piece { } ;
    
public:
    // constructor
    // honestly lets just have the tile constructor default to an empty tile
    Tile() = default ;
    
    // copy constructor - we probably won't need this
    
    // copy assignment
    Tile& operator=( const Tile& t ) ;
    
    // getters for piece and full
//    bool getFull()
//    {
////        return m_isFull ;
//    }
    
    Piece& getPiece() ;
    
    
    // setter for full and piece
//    void setFull( bool isFull )
//    {
//        m_isFull = isFull ;
//    }
    
    void setPiece( const Piece& piece ) ;
    
    
    // overload output
    friend std::ostream& operator<<( std::ostream& out, const Tile& t )
    {
        out << t.m_piece ;
        
        return out ;
    }
    
    
} ;


#endif /* Tile_hpp */
