/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LinkedList.h
 * Author: Yugi
 *
 * Created on 8 August 2020, 1:41 pm
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <iostream>
#include <string> //NULL
#include <cstdlib>

class LinkedList
{
    public:
    //typedef
      typedef Node::data_type data_type;
      
      //construction
      LinkedList();
      LinkedList(const data_type& data);
      
      //deconstruction
      ~LinkedList();
      
      void add_to_head(const data_type& data);
      void add_to_tail(const data_type& data);
      void remove_from_head();
      void remove_from_tail();
      void forward();
      void back();
      void move_to_head();
      void move_to_tail();
      void add(const data_type& data);
      void remove(const data_type& data);
      int count(const data_type& data);
      
      data_type get_current() const;
      std::size_t size() const;
      void operator += (LinkedList& list);
      
      
    private:
        Node* head;
        Node* tail;
        Node* current;
        std::size_t length;
};
//friends function
 std::ostream& operator << (std::ostream& cout, LinkedList& list);

#endif /* LINKEDLIST_H */
