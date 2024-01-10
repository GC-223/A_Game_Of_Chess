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
    // lets use an enum to deal with the color of the Piece
    enum Color
    {
        White,
        Black,
        Blank,
        
        max_colors,
    } ;
    

    
private:
    Color m_color { Blank } ;
    std::string_view m_symbol { "  " } ;

    
public:
    
    // paramaterized constructor
    Piece( Color color = Blank, std::string_view symbol = "  " )
    : m_color { color }
    , m_symbol { symbol }
    {
    }
    
    // we will probably want a copy constructor
    
    // we will also probably want copy assignment
    Piece& operator=( const Piece& piece )
    {
        m_color = piece.m_color ;
        m_symbol = piece.m_symbol ;
        
        return *this ;
    }
    
    // overload output
    friend std::ostream& operator<<( std::ostream& out, const Piece& piece )
    {
        out << piece.m_symbol ;
        
        return out ;
    }
    
    // function that will tell if a move was legal for the piece or not
    // should probably be virtual
    
    
} ;

class Pawn : public Piece
{
private:
    // perhaps for handling en Passant?
    // a boolean
    // true if Pawn can still en Passant
    bool m_enPassant { } ;
    
    
public:
    // constructor
    Pawn( Color color )
    : Piece( color, ( color == White )? "WP": "BP" )
    {
    }
    
    
} ;

class Rook : public Piece
{
private:
    
    
public:
    // constructor
    Rook( Color color )
    : Piece( color, ( color == White )? "WR": "BR" )
    {
    }
    
    
} ;

class Bishop : public Piece
{
private:
    
    
public:
    // constructor
    Bishop( Color color )
    : Piece( color, ( color == White )? "WB": "BB" )
    {
    }
    
    
} ;


class Knight : public Piece
{
private:
    
    
public:
    // constructor
    Knight( Color color )
    : Piece( color, ( color == White )? "WN": "BN" )
    {
    }
    
    
} ;

class Queen : public Piece
{
private:
    
    
public:
    // constructor
    Queen( Color color )
    : Piece( color, ( color == White )? "WQ": "BQ" )
    {
    }
    
    
} ;


class King : public Piece
{
private:
    
    
public:
    // constructor
    King( Color color )
    : Piece( color, ( color == White )? "WK": "BK" )
    {
    }
    
    
} ;


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
    Tile& operator=( const Tile& t )
    {
//        m_isFull = t.m_isFull ;
        m_piece = t.m_piece ;
        
        return *this ;
    }
    
    // getters for piece and full
//    bool getFull()
//    {
////        return m_isFull ;
//    }
    
    Piece& getPiece()
    {
        return m_piece ;
    }
    
    // setter for full and piece
//    void setFull( bool isFull )
//    {
//        m_isFull = isFull ;
//    }
    
    void setPiece( const Piece& piece )
    {
        m_piece = piece ;
    }
    
    
    // overload output
    friend std::ostream& operator<<( std::ostream& out, const Tile& t )
    {
        out << t.m_piece ;
        
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
    // constructor
    ChessBoard()
    {
        newBoard() ;
        
    }
    
    // function to create a completely new chessBoard
    void newBoard()
    {
        for ( int row = 0 ; row < m_rows ; ++row )
        {
            for ( int col = 0 ; col < m_cols ; ++col )
            {
                
                Piece::Color color { (row < 2)? Piece::Black : Piece::White } ;
                
                if ( row == 0 || row == 7 )
                {
                    switch ( col )
                    {
                        case 0:
                        case 7:
                            m_board[ row ] [ col ].setPiece( Rook( color ) ) ;
                            break;
                        case 1:
                        case 6:
                            m_board[ row ] [ col ].setPiece( Knight( color ) ) ;
                            break ;
                        case 2:
                        case 5:
                            m_board[ row ] [ col ].setPiece( Bishop( color ) ) ;
                            break ;
                        case 3:
                            m_board[ row ] [ col ].setPiece( Queen( color ) ) ;
                            break ;
                        default:
                            m_board[ row ] [ col ].setPiece( King( color ) ) ;
                            break ;

                    }
                }
                else if ( row == 1 || row == 6 )
                {
                    m_board[ row ] [ col ].setPiece( Pawn( color ) ) ;
                }
                
                
            }
        }
    }
    
    
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


int main(int argc, const char * argv[]) 
{
    
    
    
    ChessBoard myBoard { } ;
    
    std::cout << myBoard <<'\n' ;

    
    
    
    
    
    return 0;
}
