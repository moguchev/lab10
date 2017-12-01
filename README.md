# lab10
#include <iostream>
#include <list>

struct ForwardList
{
    using value_type = int;

    struct Node
    {
        value_type Data;
        Node* Next;
    };

    Node* Head;
    Node* Tail;
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ForwardList::Node* createNode(const ForwardList::value_type& data, ForwardList::Node* next)
{
    ForwardList::Node* node = new ForwardList::Node();
    node->Data = data;
    node->Next = next;
    return node;
}
////////////////////////////
void destroyNode(ForwardList::Node** ptr)
{
    ForwardList::Node* node = *ptr;
    delete node;
    *ptr = nullptr;
}
//1
ForwardList* initForwardList()
{
    ForwardList* ls = new ForwardList();
    ls->Head = nullptr;
    ls->Tail = nullptr;
    return ls;
}
//2
void destroy(ForwardList** ls)
{
    ForwardList* list = *ls;

    ForwardList::Node* head = list->Head;
    while (head)
    {
        ForwardList::Node* tmp = head->Next;
        delete head;
        head = tmp;
    }
    delete list;

    *ls = nullptr;
}
//3
ForwardList::Node* pushFront(ForwardList* const list, const ForwardList::value_type& data)
{
    ForwardList::Node* tmp = createNode(data, list->Head);
    if (list->Tail == nullptr)
        list->Tail = tmp;
    list->Head = tmp;
    return tmp;
}
//4
void popFront(ForwardList* const list)
{
    ForwardList::Node* tmp = list->Head->Next;
    destroyNode(&list->Head);
    list->Head = tmp;        
}
//_
