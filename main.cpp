//Linked Lists
//create node, print list, insert, search, delete
#include <iostream>

using namespace std;

struct node
{
    int data;
    node* link;
};

node* new_node()
{
    node *temp = new node;
    temp->data = 0;
    temp->link=NULL;
    return temp;
}

void print_list(node* c)
{
    while(c!=NULL)
    {
        cout << c->data << " ";
        c = c->link;
    }
    cout << endl;
}

void insert_in_order(node*& head, int target)
{
    node *c = head;
    node *t;
    node *p = NULL;
    while (c!=NULL && target > c->data)
    {
        p = c;
        c = c->link;
    }
    t = new_node();
    t->data = target;
    t->link = c;

    //used to insert at beginning
    if (p==NULL)
        head = t;
    else
        p->link = t;
}

void search_LL(node*& head, int target)
{
    node *c = head;
    while (c!=NULL && c->data!=target)
    {
        c = c->link;
    }
    if (c==NULL)
        cout << target << " was not found in list" << endl;
    else
        cout << target << " was found in list" << endl;
}

void delete_node(node *&head, int target)
{
    node *c = head;
    node *p = NULL;
    while (c!=NULL && target!=c->data)
    {
        p = c;
        c = c->link;
    }
    if (p!=NULL)
        p->link = c->link;
    else
        head = c->link;
    delete c;
}

int main()
{
    node *head = NULL;
    insert_in_order(head, 7);
    insert_in_order(head, 4);
    insert_in_order(head, 9);
    print_list(head);
    search_LL(head, 3);
    search_LL(head, 9);
    delete_node(head, 9);
    print_list(head);
    return 0;
}
