/* Problem Link : https://practice.geeksforgeeks.org/problems/implement-stack-using-array/1

        Push :  T.C = O(1)
        Pop  :  T.C = O(1)
*/

//Function to push an integer into the stack.

void MyStack :: push(int x)
{
    arr[++top] = x;
}

//Function to remove an item from top of the stack.
int MyStack :: pop()
{
    if(top==-1)
        return -1;
        
    int topElementOfStack = arr[top--];

    return topElementOfStack;
}