// Problem-Link : https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1

Node *mergeTwoLists(Node *l1, Node *l2){
    Node *dummy = new Node(-1);
    Node *temp = dummy;
    
    while(l1!=nullptr && l2!=nullptr){
        if(l1->data <= l2->data){
            temp->bottom = l1;
            l1 = l1->bottom;
        }else{
            temp->bottom = l2;
            l2 = l2->bottom;
        }
        temp = temp->bottom;
    }
    if(l1!=nullptr)
        temp->bottom = l1;
    if(l2!=nullptr)
        temp->bottom = l2;
    
    return dummy->bottom;
}

    
Node *flatten(Node *root)
{
    Node *l1 = root, *l2;
    if(root->next==nullptr)
        return root;
        
    l2 = root->next;
    while(l2!=nullptr){
        l1 = mergeTwoLists(l1, l2);
        l2 = l2->next;
    }
    
    root = l1;
    return root;
}
