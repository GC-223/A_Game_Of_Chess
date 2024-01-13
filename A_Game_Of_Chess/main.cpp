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

#include "ChessBoard.hpp"
#include "Piece.hpp"




struct Point2D
{
    // this is what column we are in
    int m_x { } ;
    
    // this is what row we are in
    int m_y { } ;
} ;

namespace UserInput
{

    // function to validate input from a user
    bool validateInput( const std::string& inputPosition )
    {
        if ( inputPosition.length() != 2 || ( inputPosition[0] < 'a' || inputPosition[0] > 'h' ) || ( inputPosition[1] < '1' || inputPosition[1] > '8' ) )
        {
            std::cout << "Error! Invalid Position!\n" ;
            
            return false ;
        }
        else
        {
            return true ;
        }
    }


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
            
            if ( !std::cin )
            {
                // make sure to cleare any error flags and then also ignore everything left over that we don't want to use
                std::cin.clear() ;
                std::cin.ignore( 100000, '\n' ) ;
            }
            
            validPosition = validateInput( position ) ;
           
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










int main(int argc, const char * argv[]) 
{
    
    
    
    ChessBoard myBoard { } ;
        
    std::cout << myBoard <<'\n' ;

    std::cout << '\n' ;
    
    
    Point2D myPoint { UserInput::getMoveInputAndConvert() } ;
    std::cout << myPoint.m_y << " " << myPoint.m_x << '\n' ;
    
    
    
    return 0;
}
