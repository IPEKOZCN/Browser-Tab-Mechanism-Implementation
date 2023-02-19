#include "Window.h"
Window::Window() {
    this->activeTab = 0;
    tabs.append(Tab());
}

Tab Window::getActiveTab() {
    //TODO
    Tab a;
   if(tabs.isEmpty())
   {    
       return a;
   }
   else
   {
       return (tabs.getNodeAtIndex(activeTab))->data;
   }
 
}

bool Window::isEmpty() const {
    // TODO
    
    return tabs.isEmpty();
    //std::cout<<"size="<<tabs.getSize();
 
}

void Window::newTab(const Tab &tab) {
    // TODO
   
    if(tabs.isEmpty())
    {
        tabs.prepend(tab);
        activeTab = 0;
    }
    else
    {
        tabs.insertAfterNode(tab, tabs.getNodeAtIndex(activeTab));
        activeTab++;
    }
    
}

void Window::closeTab() {
    // TODO
    
        tabs.removeNodeAtIndex(activeTab);
        if(tabs.isEmpty())
        {
            activeTab = -1;
        }
        else
        {
           if(tabs.getSize() == activeTab)
           {
               activeTab--;
           }
        }

}

void Window::moveActiveTabTo(int index) {
    
    if(index>=tabs.getSize())
    {
        tabs.moveToIndex(activeTab,tabs.getSize()-1);
        activeTab = tabs.getSize()-1;
    }
    else
    {   
        if(activeTab>=0)
        {
        tabs.moveToIndex(activeTab, index);
        activeTab = index;
        }
    }
}

void Window::changeActiveTabTo(int index) {
    // TODO
    if(index<0)
    {
        return;
    }
    if(index >= tabs.getSize())
    {
        return;
    }
    else
    {
        activeTab = index;
    }
    
}

void Window::addTab(Node<Tab> &tab) {
    // TODO
    tabs.append(tab.data);
    if(tabs.getSize() == 1)
    {
        activeTab = 0;
    }
    //std::cout<<"size="<<tabs.getSize();
    //std::cout<<activeTab<<" ";
    //std::cout<<tabs.getSize();
}

void Window::print() {
    if(tabs.isEmpty()) std::cout << "Window is empty" << std::endl;
    else std::cout << "The active tab is tab " << activeTab << std::endl;
    tabs.print();
}
