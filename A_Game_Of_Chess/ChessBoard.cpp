//
//  ChessBoard.cpp
//  A_Game_Of_Chess
//
//  Created by Greyson Chavez on 1/13/24.
//

#include "ChessBoard.hpp"

ChessBoard::ChessBoard()
{
    newBoard() ;
}

void ChessBoard::newBoard()
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


