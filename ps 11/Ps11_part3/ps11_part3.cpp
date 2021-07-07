#include<iostream>

using namespace std;



struct nodeType

{

int info;

struct nodeType* link;



};



nodeType* insertInLinkedList(nodeType* headPtr,int info)

{

if(headPtr==NULL)

{

nodeType* temp=(nodeType*)malloc(sizeof(nodeType));

temp->info=info;

temp->link=NULL;

headPtr=temp;



}

else

{

nodeType* temp=(nodeType*)malloc(sizeof(nodeType));

temp->info=info;

temp->link=headPtr;

headPtr=temp;



}



return headPtr;

}





void displayLinkedList(nodeType* headPtr)

{

nodeType* temp=headPtr;

while(temp!=NULL)

{

cout<<temp->info<<" ";

temp=temp->link;

}

}





nodeType* reverseLinkedList(nodeType* headPtr)

{

nodeType* p=NULL;

nodeType* q=NULL;

nodeType* r=headPtr;

if(headPtr->link==NULL)

return headPtr;



while(r)

{



p=q;

q=r;

r=r->link;

q->link=p;



}

return q;

}





int main()

{

nodeType* headPtr=NULL;

int n;

int num;

cout<<"enter the number of linked list element"<<endl;

cin>>n;



cout<<"enter "<<n<<" elements"<<endl;

for(int i=0;i<n;i++)

{

cin>>num;

headPtr=insertInLinkedList(headPtr,num);

}

cout<<"linked list element:-"<<endl;

displayLinkedList(headPtr);

cout<<"\nlinked list element in reverse order:-"<<endl;

headPtr=reverseLinkedList(headPtr);



displayLinkedList(headPtr);





return 0;

}