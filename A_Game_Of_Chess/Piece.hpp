//
//  Piece.hpp
//  A_Game_Of_Chess
//
//  Created by Greyson Chavez on 1/13/24.
//

#ifndef Piece_hpp
#define Piece_hpp

#include <iostream>
#include <string>

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
    Piece& operator=( const Piece& piece ) ;
    
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
//    virtual bool legalMove( const Point2D& startPoint, const Point2D& endPoint  )
//    {
//        
//        // the pawns most basic move is that it can move one space, straight
//        // so, lets do that
//        
//        // the column/x coordinate of startPoint must be the same as endPoint
//        
//        // white pawns can only move in a negative direction ( row/y coordinate must be negative )
//            // and for the most basic move, it must be negative 1
//        
//        if ( (startPoint.m_x != endPoint.m_x ) )
//        {
//            return false ;
//        }
//        
//        
//        return true;
//    }
    
    
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



#endif /* Piece_hpp */
