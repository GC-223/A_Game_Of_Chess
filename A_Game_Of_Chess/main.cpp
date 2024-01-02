//
//  main.cpp
//  A_Game_Of_Chess
//
//  Created by Greyson Chavez on 12/29/23.
//

#include <array>
#include <iostream>
#include <string>
#include <string_view>

class Tile
{
private:
    
    // boolean to tell if the tile is occupied
    bool m_isOccupied { } ;
    
public:
    
    // lets overload the output operator to be able to print whatever occupies the board
    friend std::ostream& operator<<( std::ostream& out, const Tile& tile )
    {
        if ( tile.m_isOccupied )
        {
            out << "X" ;
        }
        else
        {
            out << " " ;
        }
        
        return out ;
    }
    
} ;

class ChessBoard
{
private:
    
    static constexpr int m_rows { 8 } ;
    static constexpr int m_cols { 8 } ;
    
    std::array< std::array< Tile, m_cols >, m_rows > m_board { } ;
    
public:
    
    // constructor for a brand new chess board
    
    // reset for a brand new chessboard
    
    // print chessBoard
    
    // update board? or should we update the individual tiles
    
    // check if a king is in check/checkmate
    
    // print the board
    friend std::ostream& operator<<( std::ostream& out, const ChessBoard& board )
    {
        // loop through the rows and cols of the board
        for ( int row = 0 ; row < m_rows ; ++row )
        {
            for ( int col = 0 ; col < m_cols ; ++col )
            {
                out << " [ " << board.m_board[ row ] [ col ] << " ] " ;
            }
            
            out << '\n' ;
        }
        
        return out ;
    }
    
} ;


int main(int argc, const char * argv[]) 
{
    
    ChessBoard myBoard { } ;
    
    std::cout << myBoard ;
    
    
    
    
    return 0;
}
