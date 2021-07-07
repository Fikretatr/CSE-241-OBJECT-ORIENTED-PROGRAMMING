#include<iostream>
using namespace std;

const int DEEP_DISH = 1;
const int HAND_TOSSED = 2;
const int PAN = 3;
const int SMALL = 1;
const int MEDIUM = 2;
const int LARGE = 3;

class Pizza{ /*created pizza class*/
    public:
        void setType(int newType);
        void setSize(int newSize);
        void setNumOfToppings(int num);
        int getType(){return type;};
        int getSize(){return size;};
        int getNumOfToppings(){return numOftoppings;};
        void outputDescription( );
        double computePrice();
    private:
        int type,size,numOftoppings;
};


int main(){
    Pizza myPizza;
    int type,size,numoftoppings;
    cout<<"enter Pizza type:"<<endl;
    cout<<"1-Deep Dish"<<endl<<"2-Hand Tossed"<<endl<<"3-Pan Pizza"<<endl;
    cout<<"Choice: ";
    cin>>type;

    cout<<"enter Pizza Size:"<<endl;
    cout<<"1-Small"<<endl<<"2-Medium"<<endl<<"3-Large"<<endl;
    cout<<"Choice: ";
    cin>>size;

    cout<<"choose toppings"<<endl;
    cout<<"1-Peperronni"<<endl<<"2-Cheese"<<endl;
    cout<<"Choice: ";
    cin>>numoftoppings;

    myPizza.setSize(size);  /*take size*/
    myPizza.setType(type);  /*take type*/
    myPizza.setNumOfToppings(numoftoppings);    /*take numoftoppings*/

    myPizza.outputDescription();     /*that outputs a textual description of the pizza object.*/
    return 0;
}

void Pizza::setType(int newType){
    type = newType;
}

void Pizza::setSize(int newSize){
    size = newSize;
}

void Pizza::setNumOfToppings(int num){
    numOftoppings = num;
    if(numOftoppings<3)
    numOftoppings +=1;
    else cout<< "no more toppings left"<<endl;
}

double Pizza::computePrice(){
    switch (size)
    {
    case SMALL:
        return 10;  /*return prize*/
        break;
    case MEDIUM:
        return 14;  /*return prize*/
        break;
    case LARGE:
        return 17;  /*return prize*/
        break;
    default:
        cout<<"wrong ACCOUNT";
        break;
    }
    return -1;
}

void Pizza::outputDescription( ){
    switch (type)
    {
    case DEEP_DISH:
        switch (size)
        {
        case SMALL:
            cout<<"Order is: One small Deep Dish Pizza with " << numOftoppings<<" Toppings"<<endl;
            cout<<"Small pizza =$"<< computePrice()<<"+ $"<<2*numOftoppings<<"per topping \nTotal:"<<computePrice()+2*numOftoppings<<endl;
            break;
        case MEDIUM:
            cout<<"Order is: One Medium Deep Dish Pizza with " << numOftoppings<<" Toppings"<<endl;
            cout<<"Medium pizza =$"<< computePrice()<<"+ $"<<2*numOftoppings<<"per topping \nTotal:"<<computePrice()+2*numOftoppings<<endl;
            break;
        case LARGE:
            cout<<"Order is: One Large Deep Dish Pizza with " << numOftoppings<<" Toppings"<<endl;
            cout<<"Medium pizza =$"<< computePrice()<<"+ $"<<2*numOftoppings<<"per topping \nTotal:"<<computePrice()+2*numOftoppings<<endl;
            break;
        default:
            cout<<"wrong account";
            break;
        }
       break;
    /*-----------------------------------------------------------------------*/
        case HAND_TOSSED:
        switch (size)
        {
        case SMALL:
            cout<<"Order is: One small Hand Tossed Pizza with " << numOftoppings<<" Toppings"<<endl;
            cout<<"Small pizza =$"<< computePrice()<<"+ $"<<2*numOftoppings<<"per topping \nTotal:"<<computePrice()+2*numOftoppings<<endl;
            break;
        case MEDIUM:
            cout<<"Order is: One Medium Hand Tossed Pizza with " << numOftoppings<<" Toppings"<<endl;
            cout<<"Medium pizza =$"<< computePrice()<<"+ $"<<2*numOftoppings<<"per topping \nTotal:"<<computePrice()+2*numOftoppings<<endl;
            break;
        case LARGE:
            cout<<"Order is: One Large Hand Tossed Pizza with " << numOftoppings<<" Toppings"<<endl;
            cout<<"Large =$"<< computePrice()<<"+ $"<<2*numOftoppings<<"per topping \nTotal:"<<computePrice()+2*numOftoppings<<endl;
            break;
        default:
            cout<<"wrong account";
            break;
        }
        break;
    /*-----------------------------------------------------------------------*/
        case PAN:
        switch (size)
        {
        case SMALL:
            cout<<"Order is: One small Pan Pizza with " << numOftoppings<<" Toppings"<<endl;
            cout<<"Small pizza =$"<< computePrice()<<"+ $"<<2*numOftoppings<<"per topping \nTotal:"<<computePrice()+2*numOftoppings<<endl;
            break;
        case MEDIUM:
            cout<<"Order is: One Medium Pan Pizza with " << numOftoppings<<" Toppings"<<endl;
            cout<<"Medium pizza =$"<< computePrice()<<"+ $"<<2*numOftoppings<<"per topping \nTotal:"<<computePrice()+2*numOftoppings<<endl;
            break;
        case LARGE:
            cout<<"Order is: One Large Pan Pizza with " << numOftoppings<<" Toppings"<<endl;
            cout<<"Large pizza =$"<< computePrice()<<"+ $"<<2*numOftoppings<<"per topping \nTotal:"<<computePrice()+2*numOftoppings<<endl;
            break;
        default:
            cout<<"wrong account";
            break;
        }
        break;

        default:

            cout<<"wrong account";
           
        break;
    }
}

