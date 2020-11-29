/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.cpp
 * Author: Yugi
 * 
 * Created on 8 August 2020, 1:42 pm
 */

#include "Node.h"
    //constructon
    Node::Node()
    {
        next = NULL; 
        prev = NULL; 
        data = "";
    }

    Node::Node(const data_type& new_data, Node* new_next, Node* new_prev) 
    {
        data = new_data;
        next = new_next;
        prev = new_prev;
    }
    
    //deconstructon
    Node::~Node()
    {
        data = "";
        next = NULL;
        prev = NULL;
    }
      
    //setter
    void Node::set_data(const data_type& new_data)
    {
        data = new_data;
    }

    void Node::set_next(Node* next_item)
    {
        next = next_item;
    }

    void Node::set_prev(Node* prev_item)
    {
        prev = prev_item;
    }

    //getter
    Node::data_type Node::get_data() const
    {
        return data;
    }
    
    Node::data_type Node::get_data() 
    {
        return data;
    }

    const Node* Node::get_prev() const
    {
        return prev;
    }

    Node* Node::get_prev()
    {
        return prev;
    }

    const Node* Node::get_next() const
    {
        return next;
    }

    Node* Node::get_next()
    {
        return next;
    }