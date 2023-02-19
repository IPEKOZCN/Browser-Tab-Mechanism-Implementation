#include "Browser.h"

/* your browser implementation here */
#include "Browser.h"

Browser::Browser() {
    windows.append(Window());
}

void Browser::newWindow() {
    // TODO
    windows.prepend(Window());
    
}

void Browser::closeWindow() {
    // TODO
    if(windows.isEmpty())
    {
        return;
    }
    else
    {
        windows.removeNodeAtIndex(0);
    }
}

void Browser::switchToWindow(int index) {
    // TODO
    windows.moveToIndex(index,0);
}

Window &Browser::getWindow(int index) {
    return windows.getNodeAtIndex(index) -> data;
}

void Browser::moveTab(Window &from, Window &to) {
    // TODO
    to.newTab(from.getActiveTab());
    from.closeTab();
}

void Browser::mergeWindows(Window &window1, Window &window2) {
    // TODO
    window2.changeActiveTabTo(0);
    
    while(!window2.isEmpty())
    {
        window1.newTab(window2.getActiveTab());
   
        window2.closeTab();
    }
}

void Browser::mergeAllWindows() {
    // TODO
    int w_size = windows.getSize();
    int i = 1;
    for(i=1;i<w_size;i++)
    {
        mergeWindows(windows.getNodeAtIndex(0)->data,(windows.getNodeAtIndex(i))->data);
    }
}

void Browser::closeAllWindows() {
    // TODO
    int w_size = windows.getSize();
    int i = 0;
    for(i=0;i<w_size;i++)
    {
        this->closeWindow();
    }
}

void Browser::closeEmptyWindows() {
    // TODO
    int i = 0;
    while(i!=(windows.getSize()))
    {	
    	if(((windows.getNodeAtIndex(i))->data).isEmpty())
        {
         	windows.removeNodeAtIndex(i);
         	i=0;
        }
        else
        {
        i++;
        }
        
    }
}

void Browser::print() {
    Node<Window> *head = windows.getFirstNode();
    if(head == NULL) {
        std::cout << "The browser is empty" << std::endl;
    } else {
        (head -> data).print();
        head = head -> next;
        while(head != windows.getFirstNode()) {
            (head -> data).print();
            head = head -> next;
        }
    }
}
