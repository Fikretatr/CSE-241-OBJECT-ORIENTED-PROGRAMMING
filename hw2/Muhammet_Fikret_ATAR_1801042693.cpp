#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class ImageEditor{//A class which represents the whole image editor
    
    public:
        void ReadFile(string fileName);//member functions for reading image file.
        void WriteToFile(string fileName);//member function for writing image data to file. 
        void convert();//member function for convert grayscale
        void MainMenu();//member function for menu function
        void ImgMenu();//member function in order for user to enter a file name.
        void SaveMenu();//member function in order for saving the current state of the image data.
        void Scripts();//member function in order for convert
		
    private:
        vector<vector<vector<int>>> pixels;//This vector stores sach sample in the raster is represented as an ASCII decimal number
		vector<float> coefficients;//This vector stores input coefficients
        string type;//This variable holds PPM format For Example:P3-P6
        int HEIGHT,WIDTH, MAX_V;//These variables holds picture raster's sizes
};
//Main menu function
int main(){
  						  
    ImageEditor myImage;//create a object
	myImage.MainMenu();//Call menu function

 	return 0;
    
}

void ImageEditor::ReadFile(string fileName){//Function read image file.
    ifstream myFile (fileName);
   	vector<vector<vector<int>>>place_holder;//If open function is called for the second time, this vector holds the last opened file.
    string temp;
    if(!myFile.is_open()){//Check that file is opened 
        cout<<"File not Found"<<endl;
        exit(1);//if there is a problem, exit the program
    }
    getline(myFile,temp) ;//This function reads full line
    
    while(temp[0]=='#'){	//If there is commend in the text , discard it(#).
    	getline(myFile,temp);
    }

    type=temp;//Reading format ppm (P3)
    myFile >> WIDTH >> HEIGHT >> MAX_V;//Reading sizes and Max value of colour scale(max value = 255)

    //This loops process between image raster
    for (int i = 0; i < WIDTH; i++)
    {
        vector<vector<int>> tempv;//This vector temporarily holds the readings 
        for (int j = 0; j < HEIGHT; j++)
        {
            vector<int> temp;
            for (int k = 0; k < 3; k++)
            {   
                int a;
                myFile >> a;
                temp.push_back(a);//Filling temp vector with push_back function 
            }
            tempv.push_back(temp);//Filling tempv vector with push_back function 
        }
        
        place_holder.push_back(tempv);//If open function is called for the second time,place_holde holds the last opened file values.

    }
    	pixels=place_holder;//Pixels vector is assigned whole image file.
 }
  
void ImageEditor::WriteToFile(string fileName){//This function for writing image data to file.
    ofstream output (fileName);

    output<< type << endl;//Writing format ppm (P3)
    output << WIDTH << " " << HEIGHT << endl;//Writing sizes and Max value of colour scale(max value = 255)
	output << MAX_V << endl;
	//This loops process between image raster
     for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < HEIGHT; j++)
        {
            for (int k = 0; k < 3; k++)
            {   
               output << pixels[i][j][k]<<" ";//values sperate with space
            }
        }
        output << endl;
    }
    
 }


//Elements of menu -------------------------
void ImageEditor::MainMenu(){//member function for menu function
	int choice;//Input variable
	cout << " MAIN MENU\n";//Menu Name
	cout << " 0 - Exit \n";//Menu Option
	cout << " 1 - Open An Image(D) \n";//Menu Option
	cout << " 2 - Save Image Data(D) \n";//Menu Option
	cout << " 3 - Scripts(D) \n";//Menu Option
	cout << " Enter your choice and press return: ";//Menu Option
	cin>>choice;
	while(1){
	switch (choice)
{
//-case 0 exit---------------------------	
case 0:
	exit(0);//Exits the program without saving the image data
	break;
//-case 1 open imageMenu-----------------
case 1:
	ImgMenu();
		break;
//-case 2 save imageMenu---------------------------
case 2:
	SaveMenu();
		break;
//case 3 Scripts-------------------------------
case 3:
	Scripts();
	break;
//-default-------------------------------
default:
		cout << "Not a Valid Choice. \n";
		cout << "Choose again.\n";
		cin >> choice;//Input variable
			break;
		}
	}
}

//menu element open image function
void ImageEditor::ImgMenu(){
	int choice;//Input variable
	string file_name;
	cout << "OPEN AN IMAGE MENU\n";//Menu Option
	cout << "0-UP\n";//Menu Option
	cout << "1-Enter The Name Of The Image File\n";//Menu Option
	cin>>choice;//Take input variable
		while(1){
		switch (choice){
			case 0:
				MainMenu();//Call Menu Function
				break ;
			case 1:
				cout<<"Enter File Name:";
				cin>>file_name;
				ReadFile(file_name);//Function read image file.
				ImgMenu();//again calling ImgMenu function
				break;
			default:
				cout << "Not a Valid Choice. \n";
				cout << "Choose again.\n";
				cin >> choice;
			break;

		}
	}
}

//menu element save image function
void ImageEditor::SaveMenu(){//This function in order for saving the current state of the image data.
	int choice;//Input variable
	string file_name;
	cout << "SAVE IMAGE DATA MENU\n";//Menu Option
	cout << "0-UP\n";//Menu Option
	cout << "1-Enter A File Name\n";//Menu Option
	cin>>choice;
		while(1){
		switch (choice){
			case 0://up option
				MainMenu();//calling main menu function
			break ;
			case 1://Enter a file name option
				if(pixels.size()==0){//If vector is empty close the program.
				exit(1);
				}
				cout<<"Enter File Name:";
				cin>>file_name;
				WriteToFile(file_name);//This function for writing image data to file.
				SaveMenu();
			break ;
			default:
				cout << "Not a Valid Choice. \n";
				cout << "Choose again.\n";
				cin >> choice;
				break;	
		}
	}
}
//menu element scripts function
void ImageEditor::Scripts(){//This function just crate scrips menu
	int choice;//Input variable
	while(1){
			cout << "CONVERT TO GRAYSCALE MENU\n";//Menu Option
			cout << "0-UP\n";//UP Option
			cout << "1- Enter Coefficients For RED GREEN And BLUE Channels\n";//Menu Option
			cin>>choice;
			switch (choice){
				case 0:
					MainMenu();
				break ;
					
				case 1:
					convert();
				break ;

				default:
				cout << "Not a Valid Choice. \n";
				cout << "Choose again.\n";
				cin >> choice;
				break;
		}	
	}
}

void ImageEditor::convert(){//This function take channels and convert grayscale
	float c_r, c_g, c_b;//These numbers are coefficients (c_r, c_g, c_b) for RED, GREEN and BLUE channels
	
	if(pixels.size()==0){//If vector is empty close the program.
		exit(1);
	}

	vector<float> coefficients;//create coefficients vector
	vector<int> pixel; //create pixel vector

	cout<< "Please enter coefficients for Red, Green and Blue:"<<endl;
	/*
	Example input:
	0.33 0.10 0.2
	Range must be [0,1)
	*/
	cin>>c_r>>c_g>>c_b;//getting the coefficients (c_r,c_g, c_b)

	if(((c_r<1&&c_r>=0)&&(c_g<1&&c_g>=0)&&((c_b<1)&&(c_b>=0)))==0){//User can enter three float numbers which are in the range [0,1)
		exit(1);
	}
	coefficients.push_back(c_r);//store red channel
	coefficients.push_back(c_g);//store green channel
	coefficients.push_back(c_b);//store blue channel
	
	/*we can convert each color to grayscale using the following formula:

	RED = (c_r * RED) + (c_g * GREEN) + (c_b * BLUE)
	GREEN = (c_r * RED) + (c_g * GREEN) + (c_b * BLUE)
	BLUE = (c_r * RED) + (c_g * GREEN) + (c_b * BLUE)
	
	*/

	//aply this formula with this loops
	for(int i=0;i<WIDTH;i++){
		for(int j=0;j<HEIGHT;j++){
			float result = 0;//this variable formula's result
			pixel = pixels[i][j];
			for(int i=0;i<pixel.size();i++){
				result = result + (pixel[i] * coefficients[i]);//formula equation
			}
			for(int k=0;k<3;k++){
				if(result <= 255)// If the new values are greater than 255, then that means they are saturated. Leave them as 255.
					pixels[i][j][k] = result;//formula result equal pixels vector
				else pixels[i][j][k] = MAX_V;//max_v 255
			}
		}
	}
}

