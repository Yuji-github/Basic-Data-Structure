/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LinkedList.cpp
 * Author: Yugi
 * 
 * Created on 8 August 2020, 1:41 pm
 */

#include "LinkedList.h"
#include "Node.h"

#include <string>
#include <iostream>
#include <cstdlib>

    LinkedList::LinkedList()
    {
        head = NULL;
        tail = NULL;
        length = 0;
    }
    
    LinkedList::LinkedList(const data_type& data)
    {
        if (head == NULL)
        {
            Node* new_node = new Node(data); 
            head = new_node; 
            length = 1;
        }
        else
        {
            Node* new_node = new Node(data);
            tail = new_node; 
            length = 1;
        }
    }
    
    LinkedList::~LinkedList()
    {
       while(head != NULL)
       {
           remove_from_head();
       }
       tail = NULL; 
       head = NULL; 
       current = NULL;
    }

    void LinkedList::add_to_head(const data_type& data)
    {
       if(length == 0)
       {
           head = new Node(data);
           tail = head;
           length = 1;
       }

       else
       {
          Node* temp = new Node(data);
          head->set_prev(temp);
          temp->set_next(head);
          head = temp;
          length++;
          temp = NULL;
       }
    }
     
    void LinkedList::add_to_tail(const data_type& data)
    {
       if (length == 0)
       {
          tail = new Node(data);
          tail = head;
          length = 1;
       }

       else
       {
          Node* temp = new Node(data);
          tail->set_next(temp);
          temp->set_prev(head);
          tail = temp;
          length++;
          temp = NULL;
       }
    }
     
    void LinkedList::remove_from_head()
    {
       if(length == 0)
       {
           return;
       }

       else if(length == 1)
       {
           head = NULL;
           tail = NULL;
           //delete head;
           length--;
           return;
       }
       else
       {
            Node* temp = head; 
         
            //step 2 moving tail-point to tail_temp
            head = head -> get_next();

            //step 2.5 cut off the lines 
            if (head != NULL)
            {
                head->set_prev(NULL); // cut off new head previous pointer as NULL
            }
            else 
            {
                tail = NULL; //head is located NULL Node which is after the tail
            }

            // step 3 delete temp
            delete(temp); 

            //step 4 decrease node_count 
            length--; 

            temp = NULL; //Do Not Delete 
       }
    }
     
    void LinkedList::remove_from_tail()
    {
       if(length == 0)
       {
           return;
       }

       else if(length == 1)
       {
           head = NULL;
           tail = NULL;
           //delete tail;
           length--;
           return;
       }

       else
       {
           Node* temp = tail;
           tail = temp->get_prev();
           tail->set_next(NULL);
           temp->set_prev(NULL);
           //delete temp;
           length--;
           temp = NULL;
       }
    }
     
    void LinkedList::forward()
    {
       current = current->get_next();
    }

    void LinkedList::back()
    {
       current = current->get_prev();
    }

    void LinkedList::move_to_head()
    {
       current = head;
    }

     void LinkedList::move_to_tail()
    {
       current = tail;
    }

    void LinkedList::add(const data_type& data)
    {
      std::string list = data;//"The black cat was sitting on the black mat that was on the black floor");
      std::string word;
      do
      {
        word = list.substr(0, list.find_first_of(" "));
        
        if (word != (" "))
        {
          add_to_tail(word); // word = "the"
        }
        list = list.erase(0, list.find_first_of(" ")); // erase "the"
        list = list.substr(list.find_first_of(" ")+1, list.length()-1);
      }
      while(!list.empty());
    }

    void LinkedList::remove(const data_type& data)
    {
      std::string word = data;
      
      if(current->get_data() == head->get_data())
        {
            head = current->get_next(); 
            current->set_next(NULL);
            current = NULL;
            length--;
        }
        else if (current->get_data() == tail->get_data())
        {
            tail = current-> get_prev(); 
            current -> set_prev(NULL);
            current = NULL; 
            length--;
        }
        else
        {
        for (current = head; current != NULL; current = current->get_next())
        {
        Node* temp;
            for (temp = head; temp != NULL; temp = temp->get_next())
            {
                if(temp->get_data()== word)
                {
                    temp->get_prev()->set_next(temp->get_next());
                    temp->get_next()->set_prev(temp->get_prev());
                    temp->set_prev(NULL);
                    temp->set_next(NULL);
                    length--;
                }
            }
        temp = NULL;
        }
        }
    }
    
    int LinkedList::count(const data_type& data)
    {
       int count = 0;
       for (current = head; current != NULL; current = current->get_next())
       {
            if(current->get_data()== data)
            {
                count++;
            }
            continue;
       }
       return count;
    }
    
    LinkedList::data_type LinkedList::get_current() const
    {
        return current->get_data();
    }
    
    std::size_t LinkedList::size() const
    {
        return length;
    }
     
    void LinkedList::operator += (LinkedList& list)
    {
        list.move_to_head();//list is set on head
        int stop = list.size();
        for(int count = 0; count < stop; count++)
        {
            add_to_tail(list.get_current());
            list.forward();
        }
    }

    //friends function
 std::ostream& operator << (std::ostream& cout, LinkedList& list)
 {
        list.move_to_head();//list is set on head
        int stop = list.size();
        for(int count = 0; count < stop; count++)
        {
            cout << (list.get_current() + " ");
            list.forward();
        }
        return cout;
 }