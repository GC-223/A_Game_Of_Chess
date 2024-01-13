//
//  main.cpp
//  A_Game_Of_Chess
//
//  Created by Greyson Chavez on 12/29/23.
//

#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <string_view>




struct Point2D
{
    // this is what column we are in
    int m_x { } ;
    
    // this is what row we are in
    int m_y { } ;
} ;

namespace UserInput
{
    // a function to get the piece/location of piece that they would like to move
    std::string getPositionInput()
    {
        
        // ok lets use a boolean to tell us when to get out of this loop
        bool validPosition { false } ;

        // variable to hold chessNotation position of piece
        std::string position { } ;
        
        // while we don't have a valid position we should loop
        while ( !validPosition )
        {
            std::cout << "Enter Position: " ;
            std::cin >> position ;
            
            // must make sure to do error handling for all user input
            // ignore everything that we do not use
            std::cin.ignore( 1000000, '\n' ) ;
            
            
            // lets just force the char value to be all lowercase
            position[ 0 ] = std::tolower( position[ 0 ] ) ;
            
            if ( position.length() != 2 || ( position[0] < 'a' || position[0] > 'h' ) || ( position[1] < '1' || position[1] > '8' ) || !std::cin )
            {
                std::cout << "Error! Invalid Position!\n" ;
                
                // make sure to cleare any error flags and then also ignore everything left over that we don't want to use
                std::cin.clear() ;
                std::cin.ignore( 100000000, '\n' ) ;
            }
            else
            {
                validPosition = true ;
            }
            
        }
        
        return position ;
    }

// now we want the function to convert the positionInput into values that we can use to index our chessBoard/turn it into a Point2D
    Point2D convertToPoint( std::string_view positionString )
    {
        // this is what col we are in
        // the column number corresponds to first char in string
        // col corresponds to chars on bottom of board
        int x { positionString[ 0 ] - 'a' } ;
        
        // this is what row we are in
        // row corresponds to 2nd number in the string
        // row corresponds to numbers on left of board
        int y { -(positionString[ 1 ] - '8') } ;
        
        return { x, y } ;
    }

    // function to getMoveInput and convert to Point2D
    Point2D getMoveInputAndConvert()
    {
        return convertToPoint( getPositionInput() ) ;
    }
    
}




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
    // any blank piece that we are trying to move should be automatically false - (can't move a piece that doesn't exist)
    // should probably be virtual
    virtual bool legalMove()
    {
        return false ;
    }
    
    Color getColor()
    {
        return m_color ;
    }
    
    
} ;

class Pawn : public Piece
{
private:
    // perhaps for handling en Passant?
    // a boolean
    // true if Pawn can still en Passant
    bool m_canEnPassant { } ;
    
    // must also input functionality for two space charge as first move
    // maybe a boolean for if this piece has moved or not
    bool m_canDoubleStep { } ;
    
    
public:
    // constructor
    Pawn( Color color, bool canDoStuff = true )
    : Piece( color, ( color == White )? "WP": "BP" )
    , m_canEnPassant { canDoStuff }
    , m_canDoubleStep { canDoStuff }
    {
    }
    
    // override for legal move of pawn
    virtual bool legalMove( const Point2D& startPoint, const Point2D& endPoint  )
    {
        
        // the pawns most basic move is that it can move one space, straight
        // so, lets do that
        
        // the column/x coordinate of startPoint must be the same as endPoint
        
        // white pawns can only move in a negative direction ( row/y coordinate must be negative )
            // and for the most basic move, it must be negative 1
        
        if ( (startPoint.m_x != endPoint.m_x ) )
        {
            return false ;
        }
        
        
        return true;
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

// I guess we should have a playerClass?
class Player
{
private:
    // a variable to hold the color of the player
    Piece::Color m_color { } ;
    
public:
    
    
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

    std::cout << '\n' ;
    
    
    Point2D myPoint { UserInput::getMoveInputAndConvert() } ;
    std::cout << myPoint.m_y << " " << myPoint.m_x << '\n' ;
    
    
    
    return 0;
}
