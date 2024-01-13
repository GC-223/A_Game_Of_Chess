////
////  linked_list_lol.cpp
////  A_Game_Of_Chess
////
////  Created by Greyson Chavez on 1/9/24.
////
//
//#include <iostream>
//
//
//
//// a linked list has a node
//
//// a node has two parts
//    // 1. data
//    // 2. a pointer to the next node
//
//
//// for a linked list we need to know the start node/address of the start node
//// we need to know the length of the list
//
//struct Node
//{
//    int m_data { } ;
//    
//    Node* m_nextNode { nullptr } ;
//} ;
//
//
//class LinkedList
//{
//private:
//    
//    // just a pointer to the head of the list
//    Node* m_head ;
//    
//public:
//    // constructor
//    LinkedList( int data )
//    {
//        m_head = new Node{ data } ;
//    }
//    
//    // we are going to need a destructor
//    ~LinkedList()
//    {
//        // loop through the linkedList
//        while ( m_head->m_nextNode != nullptr )
//        {
//            // and then what if we copy the next node
//            Node* nextNode { m_head->m_nextNode } ;
//            
//            delete m_head ;
//            
//            m_head = nextNode ;
//        }
//        
//        delete m_head ;
//        
//    }
//    
//    // lets overload the output operator so we can print
//    friend std::ostream& operator<<( std::ostream& out, const LinkedList& LL )
//    {
//        Node* tempNode = LL.m_head ;
//        
//        int counter { 0 } ;
//        
//        while ( tempNode != nullptr )
//        {
//            
//            if ( counter > 0 )
//            {
//                out << ", " ;
//            }
//            
//            out << tempNode->m_data ;
//            
//            tempNode = tempNode->m_nextNode ;
//            
//            ++counter ;
//        }
//        
//        return out ;
//    }
//    
//    // a function to append onto the end of a linked list
//    void append( int data )
//    {
//        Node* tempNode { m_head } ;
//        
//        // want to loop until tempNode is a nullPtr
//        while ( tempNode->m_nextNode != nullptr )
//        {
//            tempNode = tempNode->m_nextNode ;
//        }
//        
//        tempNode->m_nextNode = new Node { data } ;
//        
//        
//    }
//    
//    // a function to push onto the beginning
//    void push( int data )
//    {
//        Node* newNode = new Node { data } ;
//        
//        // this node points at m_data
//        newNode->m_nextNode = m_head ;
//        
//        m_head = newNode ;
//    }
//    
////    // function to insert at beginning
////    void insertFront( int data )
////    {
////        Node* newHead = new Node { data } ;
////        
////        // now we want to make newHead point to head and currentHead replaced with newHead
////        
////        Node* tempNode { m_head } ;
////        
////        m_head = newHead ;
////    }
//    
//} ;
//
//
//int main()
//{
//    
//    int myInt { '1' } ;
//    
//    std::cout << static_cast<int>(myInt) << '\n' ;
//    
//    int intArray [ 6 ] ;
//
//
//
//    
//    return 0 ;
//}
