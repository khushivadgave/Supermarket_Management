#include<iostream>
#include<fstream>
using namespace std;

class shopping{
	private:
		int pcode;
		float price;
		float dis;
		string pname;
		
	public:
		void menu();
		void administrator();
		void buyer();
		void add();
		void edit();
		void rem();
		void list();
		void receipt();
		
};
void shopping::menu(){
	m:
	int choice;
	string email;
	string password;
	
	cout<<"\t\t\t\t_______________________________________\n";
	cout<<"\t\t\t\t                                       \n";
    cout<<"\t\t\t\t         SUPERMARKET MAIN MENU         \n";
    cout<<"\t\t\t\t                                       \n";
    cout<<"\t\t\t\t_______________________________________\n";
    cout<<"\t\t\t\t                                       \n";
    cout<<"\t\t\t\t| 1) Administrator   |\n";
    cout<<"\t\t\t\t|                    |\n";
    cout<<"\t\t\t\t| 2) Buyer           |\n";
    cout<<"\t\t\t\t|                    |\n";
    cout<<"\t\t\t\t| 3) Exit            |\n";
    cout<<"\t\t\t\t|                    |\n";
    cout<<"\t\t\t\t Please select!";
    cin>>choice;
    switch(choice){
    	case 1:
    		cout<<"\t\t\t Please Login\n";
    		cout<<"\t\t\t Enter Email \n";	
    		cin>>email;
        	cout<<"\t\t\t Password    \n";
        	cin>>password;
        	
        	if(email=="abc@gmail.com" && password=="1234")
			{
				administrator();
			}
			else
			{
				cout<<"Invalid email or password";
			}
			break;
			 
		case 2:
			{
				buyer();
			}
		case 3:
			{
				exit(0);
			}
		default:
			cout<<"Invalid choice";	
			
	}
	goto m;
	
}
void shopping::administrator()
{
	m:
	int choice;
	cout<<"\n\n\n\t\t\t Administrator menu";
	cout<<"\n\t\t\t|_____1) Add the product_____|";
	cout<<"\n\t\t\t|                            |";
	cout<<"\n\t\t\t|_____2) Modify the product__|";
	cout<<"\n\t\t\t|                            |";
	cout<<"\n\t\t\t|_____3) Delete the product__|";
	cout<<"\n\t\t\t|                            |";
	cout<<"\n\t\t\t|_____4) Back to main menu___|";
	
	cout<<"\n\n\t Please enter your choice";
	cin>>choice;
	
	switch(choice){
		
		case 1:
			add();
			break;
		case 2:
			edit();
			break;
		case 3:
			rem();
			break;
		case 4:
			menu();
			break;
			
		default :
			cout<<"Invalid choice!";
		}
		goto m;
}
void shopping::buyer()
{
	m:
	int choice;
	cout<<"\t\t\t    Buyer         \n";
	cout<<"\t\t\t__________________\n";
	cout<<"                        \n";
    cout<<"\t\t\t 1) Buy product   \n";
    cout<<"                        \n";
    cout<<"\t\t\t 2) Go back       \n";
    cout<<"\t\t\t Enter your choice\n";
    cin>>choice;
    switch(choice){
    	case 1:
    		receipt();
    		break;
    	case 2:
    		menu();
    		break;
    	default:
    		cout<<"invalid choice";
    	}
    	goto m;
}
void shopping::add()
{ 
    m:
	fstream data;
	int c;
	int token=0;
	float p;
	float d;
	string n;
	
	cout<<"\n\n\t\t\t Add new product";
	cout<<"\n\n\t Product code of the product";
	cin>>pcode;
	cout<<"\n\n\t Name of the product";
	cin>>pname;
	cout<<"\n\n\t Price of the product";
	cin>>price;
	cout<<"\n\n\t Discount on the product";
	cin>>dis;
	
	data.open("database.txt" ,ios::in);//reading file
	
	if(!data)
	{
		data.open("database.txt",ios::app|ios::out);//writing in the file
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
		data.close();
	}
	else
	{
		data>>c>>n>>p>>d;//reading
		while(!data.eof())
		{
			if(c==pcode)
			{
				token++;
			}
			data>>c>>n>>p>>d;
		}
	  data.close();	
	
	if(token==1)//if the user enter the code which is already exist then again it starts from main menu
	goto m;
	else{//if the code is unique then we can write in the file
		data.open("database.txt",ios::app|ios::out);//writing in the file
		data<<"    "<<pcode<<"    "<<pname<<"    "<<price<<"    "<<dis<<"\n";
		data.close();
	}
}
	cout<<"\n\n\t\t Record inserted !";
}
    		
void shopping::edit()	
{
	fstream data,data1;
	int pkey;
	int token=0;
	int c;
	float p;
	float d;
	string n;
	cout<<"\n\t\t\t Modify the record";
	cout<<"\n\t\t\t Product code:";
	cin>>pkey;
	data.open("database.txt",ios::in);
	if(!data)
	{
		cout<<"\n\nFile doesn't exist!";
	}
	else
	{
		data1.open("database1.txt",ios::app|ios::out);//we will edit the data in this file and then we will rename it by original name i.e database
	    data>>pcode>>pname>>price>>dis;
	    while(!data.eof()){
	    	if(pkey==pcode)
	    	{
	    		cout<<"\n\t\t Product new code:";
	    		cin>>c;
	    		cout<<"\n\t\t Name of the product :";
	    		cin>>n;
	    		cout<<"\n\t\t Price :";
	    		cin>>p;
	    		cout<<"\n\t\t Discount";
	    		cin>>d;
	    		data<<" "<<" "<<n<<" "<<p<<" "<<d<<"\n";
	    		cout<<"\n\n\t\t Record edited";
	    		token++;
	    		
			}
			else
			{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
			}
			data>>pcode>>pname>>price>>dis;//we use this so that the while loop can iterate
		}
		data.close();
		data1.close();
		remove("database.txt");
		rename("database1.txt","database.txt");
		if(token==0){
			cout<<"\n\n Record not found sorry!";
		}
	}
}

void shopping::rem()
{
	fstream data,data1;
	int pkey;
	int token=0;
	cout<<"\n\n\t Delete product";
	cout<<"\n\n\t Enter the Product code:";
	cin>>pkey;
	data.open("database.txt",ios::in);
	if(!data)
	{
		cout<<"File doesnt exist";
	}
	else
	{
		data1.open("database1.txt",ios::app|ios::out);
		data>>pcode>>pname>>price>>dis;
		while(!data.eof()){
			if(pcode==pkey)
			{
				cout<<"\n\n\t Product deleted successfully";
				token++;
			}
			else
			{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
			}
			data>>pcode>>pname>>price>>dis;
		}
		data.close();
		data1.close();
		remove("database.txt");
		rename("database1.txt","database.txt");
		if(token==0)
		{
			cout<<"\n\n Record not found";
		}
	}
}    
    
void shopping::list()
{
	fstream data;
	data.open("database.txt",ios::in);
	cout<<"\n\n|________________________________________________________________\n";
	cout<<"ProNo\t\tName\t\tPrice\n";
	cout<<"\n\n|________________________________________________________________\n";
	data>>pcode>>pname>>price>>dis;
	while(!data.eof())
	{
		cout<<pcode<<"\t\t\t"<<pname<<"\t\t\t"<<price<<"\n";
		data>>pcode>>pname>>price>>dis;
	}
	data.close();
}   

void shopping::receipt() {
	list();
    const int MAX_PRODUCTS = 100;
    int arrc[MAX_PRODUCTS]; // Array to store selected product codes
    int arrq[MAX_PRODUCTS]; // Array to store quantity of each product
    int totalProducts = 0;

    

    int productCode, quantity;
    char choice;

    cout << "Enter the product code and quantity (separated by a space):\n";
    do {
        cin >> productCode >> quantity;
        arrc[totalProducts] = productCode;
        arrq[totalProducts] = quantity;
        totalProducts++;

        cout << "Do you want to add another product? (y/n): ";
        cin >> choice;
    } while (choice == 'y' && totalProducts < MAX_PRODUCTS);

    
    ifstream data("database.txt");
    if (!data.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    float totalAmount = 0;

    
    cout << "_______________________________________________________\n";
    cout << "ProductNo\t\tProduct Name\t\tProduct Quantity\t\tPrice\t\tAmount\t\tAmount with discount\n";

   
    for (int i = 0; i < totalProducts; ++i) {
        bool productFound = false;

        data.clear();
        data.seekg(0);

        while (data >> pcode >> pname >> price >> dis) {
            if (pcode == arrc[i]) {
                float amount = price * arrq[i];
                float discountedAmount = amount - (amount * dis / 100);
                totalAmount += discountedAmount;

                
                cout << pcode << "\t\t" << pname << "\t\t" << arrq[i] << "\t\t" << price << "\t\t" << amount << "\t\t" << discountedAmount << endl;

                productFound = true;
                break;
            }
        }

        if (!productFound) {
            cout << "Product with code " << arrc[i] << " not found in the database." << endl;
        }
    }

    data.close();

    
    cout << "_______________________________________________________\n";
    cout << "Total Amount: " << totalAmount << endl;
}

int main()
{
			system("cls");

	shopping s;
	s.menu();
}

	
	


