#include "LinkedList.h"

/* your linked list implementation here */
#include <iostream>

#include "Node.h"
template<class T>
LinkedList<T>::LinkedList()
{
    /* TODO */
    head = NULL;
    size = 0;
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T> &obj)
{
    /* TODO */
    
    head = NULL;
    size = 0;
    Node<T> *curr = obj.getFirstNode();
    if(!curr)
    {
        return;
    }
    this->append(curr->data);
    curr = curr -> next;
    while(curr != obj.getFirstNode())
    {
        this -> append(curr -> data);
        curr = curr -> next;
    }
   
}

template<class T>
LinkedList<T>::~LinkedList()
{
    /* TODO */
    this->removeAllNodes();
    
   
}

template<class T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &rhs)
{
    /* TODO */
    
    if(this==&rhs) return *this;
    
    this->removeAllNodes();
    size = 0;
       if(!rhs.getFirstNode())
       {
       head = NULL;
       }
       else
        {
       Node<T> *tracker = rhs.getFirstNode();
       head = new Node<T>((rhs.getFirstNode())->data);
       size++;
       Node<T> *helper = head;
       while(tracker -> next != rhs.getFirstNode())
       {
           tracker = tracker -> next;
           helper -> next = new Node<T>(tracker->data, helper, NULL);
           helper = helper -> next;
           size++;
       }
       helper -> next = head;
       head -> prev = helper;
        }
        return *this;
}

template<class T>
int LinkedList<T>::getSize() const
{
    /* TODO */
    return size;
}

template<class T>
bool LinkedList<T>::isEmpty() const
{
    /* TODO */
   if(head == NULL)
   {
       return true;
   }
   else
   {
       return false;
   }
}

template<class T>
bool LinkedList<T>::containsNode(Node<T> *node) const
{
    /* TODO */
  
    Node<T> *curr = head;
    if(curr == NULL)
    {
        return false;
    }
    else
    {
        do
        {
            if(curr == node)
            {
                return true;
            }
            curr = curr -> next;
        }
        while(curr != head);
    }
    return false;
}

template<class T>
Node<T> *LinkedList<T>::getFirstNode() const
{
    /* TODO */
    if(head)
    {
        return head;
    }
    return NULL;
    
   
}

template<class T>
Node<T> *LinkedList<T>::getLastNode() const
{
    /* TODO */
    if(head)
    {
        return head -> prev;
    }
   return NULL;
}

template<class T>
Node<T> *LinkedList<T>::getNode(const T &data) const
{
    /* TODO */
   
    Node<T> *curr = head;
    if(curr == NULL)
    {
        return NULL;
    }
    do
    {
        if(curr->data == data)
        {
            return curr;
        }
        curr = curr ->  next;
    }
    while(curr != head);
    return NULL;
}

template<class T>
Node<T> *LinkedList<T>::getNodeAtIndex(int index) const
{
   
   Node<T> *curr = head;
    int i;
    if((index<0) || index>=size)
    {
        return NULL;
    }
    for(i=0;i<index;i++)
    {
        curr = curr -> next;
    }
    return curr;
}

template<class T>
void LinkedList<T>::append(const T &data)
{
    /* TODO */
    
    if(isEmpty())
    {
        head = new Node<T>(data);
        head -> next = head;
        head -> prev = head;
        size++;
    }
    else
    {
        Node<T> *temp = new Node<T>(data);
        
        temp -> next = head;
        temp -> prev = head -> prev;
        head -> prev -> next = temp;
        head -> prev = temp;
        size++;
    }
}

template<class T>
void LinkedList<T>::prepend(const T &data)
{
    /* TODO */
   
    Node<T>* curr = new Node<T>(data);
    if(isEmpty())
    {
        head = curr;
        head -> next = head;
        head -> prev = head;
        size++;
    }
    else
    {
        curr -> next = head;
        curr -> prev = head -> prev;
        head -> prev -> next = curr;
        head -> prev = curr;
        head = curr;
        size++;
    }
}


template<class T>
void LinkedList<T>::insertAfterNode(const T &data, Node<T> *node)
{
     if(containsNode(node))
    {   
        Node<T>* curr = new Node<T>(data);
        curr -> next = node -> next;
        curr -> prev = node;
        node -> next -> prev = curr;
        node -> next = curr;
        size++;
    }
}

template<class T>
void LinkedList<T>::insertAtIndex(const T &data, int index)
{
    
    if(index<size && index>=0)
    {   
        Node<T> *temp = getNodeAtIndex(index);
        Node<T>* insert = new Node<T>(data);
        
        insert -> next = temp;
        insert -> prev = temp -> prev;
        temp -> prev -> next = insert;
        temp -> prev = insert;
        size++;
        if(index == 0)
        {
            head = insert;
        }
    }

}

template<class T>
int LinkedList<T>::getIndex(Node<T> *node) const
{
     
    int index = 0;
    if(containsNode(node))
    {
        Node<T>* curr = head;
        do
        {
            if(curr == node)
            {
                return index;
            }
            curr = curr -> next;
            index++;
        }
        while(curr != head);
    }
    return -1;
}

template<class T>
void LinkedList<T>::moveToIndex(int currentIndex, int newIndex)
{
    /* TODO */
    
    if(currentIndex>= size || currentIndex == newIndex)
    {
        return;
    }
    if(newIndex>= size)
    {
       newIndex = size -1;
    }
    Node<T> *curr = getNodeAtIndex(currentIndex);
    Node<T> *newplace = getNodeAtIndex(newIndex);
    if(currentIndex == 0)
    {
        head = head->next;
    }
    curr -> prev -> next = curr -> next;
    curr -> next -> prev = curr -> prev;
    if(newIndex<currentIndex)
    {
        curr -> next = newplace;
        curr -> prev = newplace -> prev;
        newplace ->prev -> next = curr;
        newplace -> prev =curr;
    }
    else
    {
        curr -> next = newplace -> next;
        curr -> prev = newplace;
        newplace -> next -> prev = curr;
        newplace -> next = curr;
    }
    if(newIndex == 0)
    {
        head = curr;
    }
    
}
template<class T>
void LinkedList<T>::removeNode(Node<T> *node)
{
      
    if(containsNode(node))
   {
       if(size == 1)
       {
           size--;
           delete node;
           head = NULL;
       }
       else
       {
           node -> prev -> next = node -> next;
           node -> next -> prev = node -> prev;
           if(node == head)
           {
            head = head -> next;
           }
           delete node;
           size = size - 1;
       }
   }
   
}

template<class T>
void LinkedList<T>::removeNode(const T &data)
{
    /* TODO */
    
    Node<T> *curr = head;
    if(head)
    {
    do
    {
        if(curr -> data == data)
        {   
           if(curr == head && size == 1)
            {
                Node<T> *temp = curr;
                removeNode(temp);
                return;
            }
            else
            {
                if(curr == head)
                {
                    Node<T> *temp = curr;
                    curr = curr -> next;
                    removeNode(temp);
                }
                else
                {
                    Node<T> *temp = curr;
                    curr = curr -> next;
                    removeNode(temp);
                }
            }
        }
        else
        {
            curr = curr -> next;
        }
        
    }
    while(curr != head);
    }
}

template<class T>
void LinkedList<T>::removeNodeAtIndex(int index)
{
    if(index<size && index>=0)
    {   
        Node<T>* curr = head;
        int i = 0;
        if(size == 1 && index == 0)
        {
            delete curr;
            head = NULL;
            size--;
            return;
        }
        
        for(i=0;i<index;i++)
        {
            curr = curr -> next;
        }
        curr -> prev -> next = curr -> next;
        curr -> next -> prev = curr-> prev;
        if(index == 0)
        {
            head = head -> next;
        }
        delete curr;
        size--;
    }
}

template<class T>
void LinkedList<T>::removeAllNodes()
{
    /* TODO */
    
    Node<T> *curr = head;
    if (curr)
    {
        do
        {
            Node<T> *temp = curr;
            curr = curr->next;
            delete temp;
        } while (curr != head);
        size = 0;
    }
    head = NULL;
}

template<class T>
void LinkedList<T>::print() const
{
    if (isEmpty()) {
        std::cout << "The list is empty." << std::endl;
        return;
    }

    Node<T> *node = this->getFirstNode();

    do {
        std::cout << *node << std::endl;
        node = node->next;
    }
    while (node != this->getFirstNode());
}
