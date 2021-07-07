#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void MainMenu();//Function for menu 

class ImageEditor{//A class which represents the whole image editor
    
    public:
		ImageEditor();//constructor
		ImageEditor(const ImageEditor &other);//copy constructor
		~ImageEditor();//destructor
        void ReadFile(string fileName);//member functions for reading image file.
        void WriteToFile(string fileName);//member function for writing image data to file. 
        void convert();//member function for convert grayscale
        void ImgMenu();//member function in order for user to enter a file name.
        void SaveMenu();//member function in order for saving the current state of the image data.
        void Scripts();//this member function just crate scrips menu
		void Scripts(vector<ImageEditor> &images);//this member function contains the elements and functions(add) of the script menu.
		ImageEditor operator+(const ImageEditor &other);//this memeber function for operator overloading "+".
		void operator=(const ImageEditor &other);//this memeber function for assignment operator "="
		string getFileName(){return filename;};//get function return file name
		
		
    private:
		string filename;//This variable holds filename
        int ***pixels;//create dynamic arrays for image storage
		float coefficients[3];//This array stores input coefficients
        string type;//This variable holds PPM format For Example:P3-P6
        int HEIGHT,WIDTH, MAX_V;//These variables holds picture raster's sizes
};


int main(){//Main menu function					 
	
	MainMenu();//Call menu function

 	return 0;
    
}

ImageEditor::ImageEditor(){//Constructor 
	WIDTH = 0;
	HEIGHT = 0;
	MAX_V = 0;
	pixels = NULL;//Constructor
}

ImageEditor::ImageEditor(const ImageEditor &other){//Copy constructor
	if(other.pixels == NULL) return;
	
	filename = other.filename;
	type = other.type;
	HEIGHT = other.HEIGHT;
	WIDTH = other.WIDTH;
	MAX_V = other.MAX_V;

	for(int i = 0; i < 3; i++){
		coefficients[i] = other.coefficients[i];
	}
	//new allocation
	pixels = new int**[WIDTH];
	for(int i = 0; i < WIDTH; i++){
		pixels[i] = new int*[HEIGHT];
		for(int j=0;j<HEIGHT;j++){
			pixels[i][j] = new int[3];
		}
	}
	//coping other pixels to pixels
	for (int i = 0; i < WIDTH; i++)
    { 
    	for (int j = 0; j < HEIGHT; j++)
        {
            for (int k = 0; k < 3; k++)
            {   
				pixels[i][j][k] = other.pixels[i][j][k]; 
            }
        }
    }//copy constructor//copy constructor
}

ImageEditor::~ImageEditor(){//Destructor
	for(int i=0;i<WIDTH;i++){
		for(int j = 0;j<HEIGHT;j++)
		delete[] pixels[i][j];//Delete is an operator that is used to destroy array and non-array(pointer) objects 
		delete[] pixels[i];	 //which are created by new expression.
		
	}
	delete[] pixels;//pixels destroyed
}

ImageEditor ImageEditor::operator+(const ImageEditor &other){//Function for operator overloading "+".
	ImageEditor newImage(*this);//create newImage object 

	for (int i = 0; i < WIDTH; i++)
    { 
    	for (int j = 0; j < HEIGHT; j++)
        {
            for (int k = 0; k < 3; k++)
            {   
				newImage.pixels[i][j][k] = newImage.pixels[i][j][k] + other.pixels[i][j][k];//addition
				if(newImage.pixels[i][j][k] > MAX_V) newImage.pixels[i][j][k] = 255;//255 scale is preserved after add
            }
        }
    }
	newImage.filename = "newImage.ppm";//the new name of the created object.
	cout<<"Modified image name is newImage.ppm"<<endl;//the user to know the name of the newly created object
	return newImage;//return the newly created object//function for assignment operator "="
}

void ImageEditor::operator=(const ImageEditor &other){//Function for assignment operator "="
	
	if(other.pixels == NULL) return;
	filename = other.filename;
	type = other.type;
	HEIGHT = other.HEIGHT;
	WIDTH = other.WIDTH;
	MAX_V = other.MAX_V;

	pixels = new int**[WIDTH];//new allocation
	for(int i = 0; i < WIDTH; i++){
		pixels[i] = new int*[HEIGHT];//new allocation
		for(int j=0;j<HEIGHT;j++){
			pixels[i][j] = new int[3];//new allocation
		}
	}

	//assigned other pixels to pixels
	for (int i = 0; i < WIDTH; i++)
    { 
    	for (int j = 0; j < HEIGHT; j++)
        {
            for (int k = 0; k < 3; k++)
            {   
				pixels[i][j][k] = other.pixels[i][j][k]; //assigned other pixels to pixels
            }
        }
    }
}

void ImageEditor::ReadFile(string fileName){//Function read image file.
    ifstream myFile (fileName);
    string temp;
    if(!myFile.is_open()){//Check that file is opened 
        cout<<"File not Found"<<endl;
        exit(1);//if there is a problem, exit the program
    }
    getline(myFile,temp) ;//This function reads full line
    
    while(temp[0]=='#'){	//If there is commend in the text , discard it(#).
    	getline(myFile,temp);//ppm file commend control.
    }

    type=temp;//Reading format ppm (P3)
    myFile >> WIDTH >> HEIGHT >> MAX_V;//Reading sizes and Max value of colour scale(max value = 255)
    //in this place create dynamic array
	pixels = new int**[WIDTH];//allocate process
	for(int i = 0; i < WIDTH; i++){
		pixels[i] = new int*[HEIGHT];//allocate process
		for(int j=0;j<HEIGHT;j++){
			pixels[i][j] = new int[3];//allocate process
		}
	}

    //This loops process between image raster
    for (int i = 0; i < WIDTH; i++)
    { 
    	for (int j = 0; j < HEIGHT; j++)
        {
            for (int k = 0; k < 3; k++)
            {   
                int a;
                myFile >> a;
				pixels[i][j][k] = a; //Image data stores in this place
            }
        }
    }
}
  
void ImageEditor::WriteToFile(string fileName){//This function for writing image data to file.
    ofstream output (fileName);

    output<< type << endl;//Writing format ppm (P3)
    output << WIDTH << " " << HEIGHT << endl;//Writing sizes and Max value of colour scale(max value = 255)
	output << MAX_V << endl;//Writing max value 
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

void MainMenu(){//This function contains elements of Menu

	vector<ImageEditor> images;//this vector store the images objects if there are two picked image (not for image data)
	cout<<"How many images do you want?"<<endl;
	cout<<"1-One image\n2-Two images"<<endl<<"choice:";
	int count;//this count is number of images
	cin>>count;
	while (count>2 || count<1)//user can not choose more than 2 images(control loop)
	{
		cout<<"invalid choice"<<endl;
		cout<<"How many images do you want?"<<endl;
		cout<<"1-one image\n2-two images"<<endl<<"choice:";
		cin>>count;
	}
	
	if(count == 1){
		ImageEditor myImage;//create a object
		images.push_back(myImage);
	} 
	else if(count == 2){
		ImageEditor myImage;//create a object
		ImageEditor myImage2;//create a object
		images.push_back(myImage);
		images.push_back(myImage2);
	}
	
	int choice;//Input variable

	while (1)
	{
		
		cout << " MAIN MENU\n";//Menu Name
		cout << " 0 - Exit \n";//Menu Option
		cout << " 1 - Open An Image(D) \n";//Menu Option
		cout << " 2 - Save Image Data(D) \n";//Menu Option
		cout << " 3 - Scripts(D) \n";//Menu Option
		cout << " Enter your choice and press return: ";//Menu Option
		cin>>choice;
		switch (choice)
	{

	//-case 0 exit---------------------------	
	
	case 0:

		for(int i=0;i<images.size();i++){
			images[i].~ImageEditor();//destructer is used before exiting the program.
		}
		exit(0);//Exits the program without saving the image data.
		break;

	//-case 1 open imageMenu--------------------------

	case 1:
		
		if(count == 2){//if there are 2 image
			cout<<"First Image"<<endl;
			images[0].ImgMenu();//uses open an image function for the first image
			cout<<"Second Image"<<endl;
			images[1].ImgMenu();//uses open an image function for the second image
		}
			else//if there ise 1 image
		{
			images[0].ImgMenu();//if there ise 1 image , open 1 image 	
		}
			break;

	//-case 2 save imageMenu---------------------------

	case 2:
		
		if(count >= 2){

			for (int i = 0; i <images.size(); i++)//display images
			{
				cout<<i+1<<"-"<<images[i].getFileName()<<endl ;
			}

			cout<<"Enter the name of the image you want to save: ";
			string name;
			cin>>name;
			for (int i = 0; i <images.size(); i++){
				if(name == images[i].getFileName()) 
				images[i].SaveMenu();//first,second or newimage picture will be saved
			}
		}

		else{
			images[0].SaveMenu();//if there is just 1 picture, it will be saved
		}
			break;

	//case 3 Scripts-------------------------------

	case 3:
		if(count >= 2){//if there are 2 image 
			
			for (int i = 0; i <images.size(); i++)//display images
			{
				cout<<i+1<<"-"<<images[i].getFileName()<<endl ;
			}

			cout<<"Enter the name of the image you want to modify: ";
			string name;//this is hold file name 
			cin>>name; 
			for (int i = 0; i <images.size(); i++)
			{
				if(name == images[i].getFileName()) //control which image will be modify?
				images[i].Scripts(images);//first,second or newimage picture will be modify
			}
		}else{
			images[0].Scripts();//for 1 image, use scripts function
		}

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

void ImageEditor::ImgMenu(){//This function contains elements of open an image menu
	int choice;//Input variable
	string file_name;
	cout << "OPEN AN IMAGE MENU\n";//Menu Option
	cout << "0-UP\n";//Menu Option
	cout << "1-Enter The Name Of The Image File\n";//Menu Option
	cin>>choice;//Take input variable
		switch (choice){
			case 0:

				return;
				break ;
			case 1:
				cout<<"Enter File Name:";
				cin>>file_name;
				filename = file_name;
				ReadFile(file_name);//Function read image file.
				
				break;
			default:
				cout << "Not a Valid Choice. \n";
				cout << "Choose again.\n";
				cin >> choice;
			break;

		}
}

void ImageEditor::SaveMenu(){//This function in order for saving the current state of the image data.
	int choice;//Input variable
	string file_name;
	cout << "SAVE IMAGE DATA MENU\n";//Menu Option
	cout << "0-UP\n";//Menu Option
	cout << "1-Enter A File Name\n";//Menu Option
	cin>>choice;
		switch (choice){
			case 0://up option
				return;
			break ;
			case 1://Enter a file name option
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

void ImageEditor::Scripts(){//This function just crate scrips menu
	int choice;//Input variable
	while(1){
			cout << "CONVERT TO GRAYSCALE MENU\n";//Menu Option
			cout << "0-UP\n";//UP Option
			cout << "1- Convert to Grayscale\n";//Menu Option
			cin>>choice;
			switch (choice){
				case 0:
					return;
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

void ImageEditor::Scripts(vector<ImageEditor> &images){//This function contains the elements and functions of the script menu.
	int choice;//Input variable
	ImageEditor temp;
	ImageEditor newImage;
	string name;
	while(1){
			cout << "CONVERT TO GRAYSCALE AND ADDITION MENU\n";//Menu Option
			cout << "0-UP\n";//UP Option
			cout << "1- Convert to Grayscale\n";//Menu Option
			cout << "2- Add two images\n";//Menu Option
			cin>>choice;
			switch (choice){
				case 0:
					return;
				break ;
					
				case 1:
					convert();//grayscale function
				break ;

				case 2:
					cout<<"Enter the name of the image you want to add: ";
					cin>>name;
					for (int i = 0; i <images.size(); i++)
					{
						if(name == images[i].getFileName()) //file name control
							temp = images[i];
					}
					newImage = *this + temp;//OVERLOADİNG "+" AND "="
					images.push_back(newImage);//created image goes to images vector
					break;
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
	
	if(pixels[3]==NULL){//If array is empty exiting the program.
		exit(1);
	}

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
	coefficients[0]= c_r;//store red channel
	coefficients[1]= c_g;//store green channel
	coefficients[2]= c_b;//store blue channel
	
	/*we can convert each color to grayscale using the following formula:

	RED = (c_r * RED) + (c_g * GREEN) + (c_b * BLUE)
	GREEN = (c_r * RED) + (c_g * GREEN) + (c_b * BLUE)
	BLUE = (c_r * RED) + (c_g * GREEN) + (c_b * BLUE)
	
	*/

	//apply this formula with this loops
	for(int i=0;i<WIDTH;i++){
		for(int j=0;j<HEIGHT;j++){
			float result = 0;//this variable formula's result
			for(int k=0;k<3;k++){
				result = result + (pixels[i][j][k] * coefficients[i]);//formula equation
			}
			for(int k=0;k<3;k++){
				if(result <= 255)// If the new values are greater than 255, then that means they are saturated. Leave them as 255.
					pixels[i][j][k] = result;//formula result equal pixels vector
				else pixels[i][j][k] = MAX_V;//max_v 255
			}
		}
	}
}

