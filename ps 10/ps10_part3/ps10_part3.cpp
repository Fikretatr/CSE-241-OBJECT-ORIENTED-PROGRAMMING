#include <iostream>
using namespace std;

//document class
class Document
{
    //delcare variables for document
    private:
    string text;
    public:
    //default constructor
    Document()
    {
        text="";
    }
  
    //paramterized constructor
    Document(string t)
    {
        text=t;
    }
    //setter for text
    string getText()
    {
        return text;
    }
    //getter for text
    void setText(string t)
    {
        text=t;
    }
    //overloading of = operator
    void operator=(Document d)
    {
        text=d.text;
    }
};
//emial class inheriting from document
class Email:public Document
{
    //variables for email
    private:
    string sender;
    string recipient;
    string title;
    public:
    //default constructor
    Email():Document()
    {
        sender="";
        recipient="";
        title="";
    }
    //parameterized constructor
     Email(string tt,string s,string r,string t):Document(tt)
    {
        sender=s;
        recipient=r;
        title=t;
    }
    //setter for sender
    void setSender(string s)
    {
        sender=s;
    }
    //setter for title
    void setTitle(string t)
    {
        title=t;
    }
    //setter for receipient
    void setRecipient(string r)
    {
        recipient=r;
    }
    //getter for title
    string getTitle()
    {
        return title;
    }
    //accessor for sender
    string getSender()
    {
        return sender;
    }
    //accessor for recipient
    string getRecipient()
    {
        return recipient;
    }
    //overloading of == operator
     void operator=(Email e)
    {
        Document:setText(e.getText());
        sender=e.sender;
        recipient=e.recipient;
        title=e.title;
    }
};
//class file
class File:public Document
{
    //instance variales for file
    private:
string pathname;
public:
//default contructor
File():Document()
{
      pathname="";
}
//parameterized constructor
File(string t,string p):Document(t)
{
      pathname=p;
}
//accessor for pathname
string getPathname()
{
      return pathname;
}
//setter for pathname
void setPathName(string p)
{
      pathname=p;
}
//overloading operaor=
   void operator=(File f)
    {
        Document:setText(f.getText());
        pathname=f.pathname;
    }
};

bool ContainsKeyword(Document& docObject, string keyword)
   {
       if (docObject.getText().find(keyword) != string::npos)
       return true;
       return false;
   }

int main()
{
    //instantitae variables of type email and file
   Email e1("Which exam do we have today?","Math","Physics","Bio"),e2("We have C++","Math","Bio","Exam??");
   File f1("C++ Notes","C:/Doc/C++"),f2("C Notes","C;/Doc/C");
   
   //check if e1 cotians keyword
   if(ContainsKeyword(e1,"C++"))
   cout<<"e1 contains c++"<<endl;
   else
   cout<<"e1 doesn't contain c++"<<endl;

   //check if e2 contains keyword
   if(ContainsKeyword(e2,"C++"))
   cout<<"e2 contains c++"<<endl;
   else
   cout<<"e2 doesn't contain c++"<<endl;

   //check if f1 contains keyword
   if(ContainsKeyword(f1,"C++"))
   cout<<"f1 contains c++"<<endl;
   else
   cout<<"f1 doesn't contain c++"<<endl;

   //check if f2 contains c++
   if(ContainsKeyword(f2,"C++"))
   cout<<"f2 contains c++"<<endl;
   else
   cout<<"f2 doesn't contain c++"<<endl;

   return 0;
}