#include <iostream>

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
// correct
ForwardList::Node* createNode(const ForwardList::value_type& data, ForwardList::Node* next)
{
    ForwardList::Node* node = new ForwardList::Node();
    node->Data = data;
    node->Next = next;
    return node;
}
// correct
void destroyNode(ForwardList::Node** ptr)
{
    ForwardList::Node* node = *ptr;
    delete node;
    *ptr = nullptr;
}
// 1+
ForwardList* initForwardList()
{
    ForwardList* flist = new ForwardList();
    flist->Head = nullptr;
    flist->Tail = nullptr;
    return flist;
}
// 2+
void destroy(ForwardList** flist)
{
    ForwardList* list = *flist;
    ForwardList::Node* head = list->Head;
    while (head)
    {
        ForwardList::Node* tmp = head->Next;
        delete head;
        head = tmp;
    }
    delete list;
    *flist = nullptr;
}

// 3+
ForwardList::Node* pushFront(ForwardList* const flist, const ForwardList::value_type& data)
{
    ForwardList::Node* node = createNode(data, flist->Head);
    flist->Head = node;
    return node;
}

// 4+
ForwardList::Node* popFront(ForwardList* const flist)
{
    if (flist->Head == nullptr)
        return nullptr;
    else
    {
        ForwardList::Node* temp = flist->Head->Next;
        destroyNode(&flist->Head);
        flist->Head = temp;
        return temp;
    }
}

// 5+
ForwardList::Node* insertAfter(ForwardList* const flist,
    ForwardList::Node* const flag, const ForwardList::value_type& data)
{
    if (flag == nullptr)
        return nullptr;
    else
    {
        ForwardList::Node* newNode = createNode(data, flag->Next);
        flag->Next = newNode;
        return newNode;
    }
}

// 6+
ForwardList::Node* eraseAfter(ForwardList* const flist, ForwardList::Node* const flag)
{
    if (flag->Next == nullptr)
        return nullptr;
    else
    {
        ForwardList::Node* temp = flag->Next;
        flag->Next = flag->Next->Next;
        destroyNode(&temp);
        return temp;
    }
}

// 7+
ForwardList::Node* reverse(ForwardList* const flist)
{
    ForwardList::Node* temp = 0;
    ForwardList::Node* null = nullptr;
    if (flist->Head == nullptr)
        return flist->Head;
    else
    {
        while (flist->Head != nullptr)
        {
            temp = flist->Head;
            flist->Head = flist->Head->Next;
            temp->Next = null;
            null = temp;
        }
        flist->Head = null;
        return temp;
    }
}

// 8+
size_t size(const ForwardList* const list)
{
    size_t size = 0;
    ForwardList::Node* head = list->Head;
    while (head)
    {
        ++size;
        head = head->Next;
    }
    return size;
}
// 9+
void print(const ForwardList* const ls)
{
    ForwardList::Node* tmp = ls->Head;
    while (tmp)
    {
        std::cout << tmp->Data << std::endl;
        tmp = tmp->Next;
    }
}

int main()
{
    ForwardList* l = initForwardList();
    pushFront(l, 3);
    pushFront(l, 2);
    pushFront(l, 1);
    insertAfter(l, l->Head->Next->Next, 4);
    reverse(l);
    eraseAfter(l, l->Head->Next->Next);
    popFront(l);
    size_t i = size(l);
    std::cout << "size = " << i << std::endl;
    print(l);
    destroy(&l);
    system("pause");
return 0;
}
