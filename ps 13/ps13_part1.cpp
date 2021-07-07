#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

class NameNotFound
{
public:
	NameNotFound(string sName):name(sName){}
	string getName(){return name;}
private:
	string name;
};

int getProductID(int ids[],string names[],int numProducts,string target)throw (NameNotFound);

	int main()
	{
		int ProductIds[20];
		string products[20],search;
		int totalProducts;
		char ans;
		cout<<"Enter the number of products: ";
		cin>>totalProducts;
		for(int i=0;i<totalProducts;i++){
			cout<<"Enter the products id of item"<< i<<":";
			cin>>ProductIds[i];
			cin.ignore(1000,'\n');
			cout<<"Enter product name of item"<<i<<":";
			getline(cin,products[i]);

		}
		try{
			do{
				cout<<"Enter the name you want to search the products: ";
				getline(cin,search);

				int pit = getProductID(ProductIds,products,totalProducts,search);
				cout<<"the id is:"<<pit	<<endl;
				cout<< "Do you want to search another product.Press y to proceed:";
				cin>>ans;
				cin.ignore(1000,'\n');

			}while(ans=='y'||ans=='Y');
		}
		catch (NameNotFound e){
			cout<<e.getName()<<"product is not found in products list"<<endl;
			exit(1);
		}
	}
int getProductID(int ids[],string names[],int numProducts,string target)throw(NameNotFound)
{

	for(int i=0;i<numProducts;i++){
		if(names[i]==target)
			return ids[i];

	}
	throw NameNotFound(target);
}
