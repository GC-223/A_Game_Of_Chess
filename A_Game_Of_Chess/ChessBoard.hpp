//
//  ChessBoard.hpp
//  A_Game_Of_Chess
//
//  Created by Greyson Chavez on 1/13/24.
//

#ifndef ChessBoard_hpp
#define ChessBoard_hpp


#include "Piece.hpp"
#include "Tile.hpp"

class ChessBoard
{
private:
    static constexpr int m_rows { 8 } ;
    static constexpr int m_cols { 8 } ;
    
    std::array< std::array< Tile, m_cols >, m_rows > m_board { } ;
    
public:
    // constructor
    ChessBoard() ;
    
    // function to create a completely new chessBoard
    void newBoard() ;
    
    
    // lets overload the output operator in order to print the board
    friend std::ostream& operator<<( std::ostream& out, const ChessBoard& board )
    {
        // we are also going to want counters for our rows and cols
        // use these to annotate and so user can see rows/cols
        int rowCounter { m_rows } ;
        char colCounter { 'A' } ;
        
        out << "\n ------------------------------------------\n" ;

        
        for ( int row = 0 ; row < m_rows ; ++row )
        {
            out << rowCounter-- << " | " ;
            
            for ( int col = 0 ; col < m_cols ; ++col )
            {
                // we want to print the contents of the tile
                // in order to print the contents of the tile we need to print the contents of the piece in the tile
                // in order to do that we want to print the symbol of the piece
                out << board.m_board[ row ] [ col ] << " | " ;
            }
            
            // now we want a new line after we are done printing the cols for that row
            // we also want separators between each line
            out << "\n ------------------------------------------\n" ;
        }
        
        // ok so now that we are all done with the actual grid
        // lets now loop one more time to print the colCounter at the bottom
        out << "  | " ;
        for ( int col = 0 ; col < m_cols ; ++col )
        {
            out << colCounter++ << "  | " ;
        }
        
        return out ;
    }
    
    
    
    
    
} ;

#endif /* ChessBoard_hpp */
