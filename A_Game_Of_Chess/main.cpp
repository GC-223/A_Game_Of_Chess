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

class Piece
{
public:
    // do we really need a constructor for this parent class?
    // i don't think we do
    Piece( bool color, std::string_view symbol )
    : m_color { color }
    {
        
    }
    
//    enum PieceType
//    {
//        pawn,
//        bishop,
//        rook,
//        knight,
//        queen,
//        king,
//        
//        max_types,
//    } ;
    
    // getters
    bool getColor()
    {
        return m_color ;
    }
    
    std::string_view getSymbol()
    {
        return m_symbol ;
    }
    
//    PieceType getType()
//    {
//        return m_type ;
//    }
    
    // setters
//    void setColor( bool color )
//    {
//        m_color = color ;
//    }
//    
//    void setSymbol( std::string_view symbol )
//    {
//        m_symbol = symbol ;
//    }

    
    
private:
    
    // a boolean to represent color
    const bool m_color { } ;
    
    const std::string m_symbol { } ;
    
//    PieceType m_type { } ;
    
    
} ;

class Pawn : public Piece
{
private:
    
public:
    // constructor
    
} ;



class Tile
{
private:
    
    // boolean to tell if the tile is occupied
    bool m_isOccupied { } ;
    
    // and then i guess the piece that would go on the space
    // and this doesn't have to be initialized to anything
    // we could have it be a pointer and just initialize it to nullPtr?
    
    
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
    
    // we will obviously need getters and setters for m_isOccupied
    bool isOccupied()
    {
        return m_isOccupied ;
    }
    
    void setOccupied( bool occupied )
    {
        m_isOccupied = occupied ;
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
    ChessBoard()
    {
        // loop through rows and cols for initial setup of board
        for ( int row = 0 ; row < m_rows ; ++row )
        {
            for ( int col = 0 ; col < m_cols ; ++col )
            {
                // ok so if we are in the first two rows ( aka row 8 and 7 )
                if ( row == 0 || row == 1 )
                {
                    m_board[ row ] [ col ].setOccupied( true ) ;
                }
                else if ( row == 6 || row == 7 )
                {
                    m_board[ row ] [ col ].setOccupied( true ) ;
                }
            }
        }
    }
    
    // reset for a brand new chessboard
    
    // print chessBoard
    
    // update board? or should we update the individual tiles
    
    // check if a king is in check/checkmate
    
    // print the board
    friend std::ostream& operator<<( std::ostream& out, const ChessBoard& board )
    {
        // rowCounter
        int rowCounter { m_rows } ;
        char colCounter { 'A' } ;
        
        out << "\n ----------------------------------\n" ;

        
        // loop through the rows and cols of the board
        for ( int row = 0 ; row < m_rows ; ++row )
        {
            // when we print we want the row number on the left
            out << rowCounter-- << " | " ;
            
            for ( int col = 0 ; col < m_cols ; ++col )
            {
                out << board.m_board [ row ] [ col ] << " | " ;
            }
            
            // now we want horizontal separators
            out << "\n ----------------------------------\n" ;
            
        }
        
        // now we want to to print the colNumber at the very bottom
        while ( colCounter <= 'H' )
        {
            if ( colCounter == 'A' )
            {
                out << "  | " ;
            }
            
            out << colCounter++ << " | " ;
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
