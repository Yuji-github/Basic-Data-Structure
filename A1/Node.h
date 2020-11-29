/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.h
 * Author: Yugi
 *
 * Created on 8 August 2020, 1:42 pm
 */

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string> //NULL

class Node
{
    public:
     //typedef
        typedef std::string data_type;
        
     //constructon
       Node();
       Node(const data_type& new_data, Node* new_next = NULL, Node* new_prev = NULL);
       
     //deconstructon
       ~Node();
               
       //setter
       void set_data(const data_type& new_data);
       void set_next(Node* next_item);
       void set_prev(Node* prev_item);
       
       
       //getter
       data_type get_data() const;
       data_type get_data();
       const Node* get_prev() const;
       Node* get_prev();
       const Node* get_next() const;
       Node* get_next();
       
       
    private:
     data_type data;     
     Node* next;
     Node* prev;
};

#endif /* NODE_H */
