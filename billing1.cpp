#include <iostream>
#include <fstream>

using namespace std;

class shopping 
{
  private:
    int pcode;
    float price;
    float discount;
    string pname;
  
  public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void remove();
    void list();
    void receipt();
};

void shopping::menu() 
{
  m:
  int choice;
  string email;
  string password;

  cout << "\t\t\t\t___________________________________________\n";
  cout << "\t\t\t\t                                           \n";
  cout << "\t\t\t\t            Supermarket Main Menu          \n";
  cout << "\t\t\t\t                                           \n";
  cout << "\t\t\t\t___________________________________________\n";
  cout << "\t\t\t\t                                           \n";

  cout << "\t\t\t\t| 1) Administrator   |\n";
  cout << "\t\t\t\t|                    |\n";
  cout << "\t\t\t\t| 2) Buyer           |\n";
  cout << "\t\t\t\t|                    |\n";
  cout << "\t\t\t\t| 3) Exit            |\n";
  cout << "\t\t\t\t|                    |\n";
  cout << "\t\t\t\t Please select!";

  cin >> choice;

  switch (choice)
  {
    case 1:
      cout << "\t\t\t Please Login \n";
      cout << "\t\t\t Enter Email(default is robby@gmail.com for admin):  \n";
      cin >> email;
      cout << "\t\t\t Password(default is robby@123 for admin):     \n";
      cin >> password;

      if(email == "robby@gmail.com" && password == "robby@123") {
        administrator();
      }else{
        cout << "Invalid email or password";
      }
      break;
    
    case 2:
      buyer();

    case 3:
      exit(0);
    default:
      {
        cout << "Please select from the given options";
      }
      break;
  }
  goto m;
} 

void shopping::administrator() 
{
  m:
  int choice;
  cout << "\n\n\n\t\t\t Administrator menu";
  cout << "\n\t\t\t|____1) Add the product______|";
  cout << "\n\t\t\t|                            |";
  cout << "\n\t\t\t|____2) Modify the product___|";
  cout << "\n\t\t\t|                            |";
  cout << "\n\t\t\t|____2) Delete the product___|";
  cout << "\n\t\t\t|                            |";
  cout << "\n\t\t\t|____4) Back to main menu____|";

  cout << "\n\n\t Please enter your choice ";
  cin >> choice;

  switch (choice)
  {
  case 1:
    add();
    break;

  case 2:
    edit();
    break;

  case 3:
    remove();
    break;

  case 4:
    menu();
    break;
  
  default:
    cout << "Invalid choice!";
  }
  goto m;

}

void shopping::buyer() 
{
  m:
  int choice;
  cout << "\t\t\t Buyer         \n";
  cout << "_____________________\n";
  cout << "                     \n";
  cout << "\t\t\t 1) Buy product ";
  cout << "                     \n";
  cout << "\t\t\t 2) Go back    \n";
  cout << "                     \n";
  cout << "\t\t\t Enter your choice: ";

  cin >> choice;

  switch (choice)
  {
  case 1:
    receipt();
    break;
  
  case 2:
    menu();
    break;

  default:
    cout << "Invalid choice";
  }
  goto m;
}

void shopping::add() 
{
  m:
  fstream data;
  int c;
  int token = 0;
  float p;
  float d;
  string n;

  cout << "\n\n\t\t\t Add new product";
  cout << "\n\n\t Product code of the product";
  cin >> pcode;
  cout << "\n\n\t Name of the product ";
  cin >> pname;

  cout << "\n\n\t Price of the product";
  cin >> price;
  cout << "\n\n\t Discount on the product";
  cin >> discount;

  data.open("database.txt", ios::in);

  if(!data) {
    data.open("database.txt", ios::app | ios::out);
    data << " " << pcode << " " << pname << " " << price << " " << " " << discount << "\n";
    data.close();
  }else{
    data >>c>>n>>p>>d;
    while (!data.eof())
    {
      if(c == pcode) {
        token++;
      }
      data >> c >> n >> p >> d;
    }
    data.close();
    if(token != 0) {
      cout << "Product code already registered";
      goto m;
    }else{
      data.open("database.txt", ios::app | ios::out);
      data << " " << pcode << " " << pname << " " << price << " " << discount << "\n";
      data.close();
    }
  }
  cout << "\n\n\t\t Record inserted";
}

void shopping::edit ()
{
  fstream data, data1;

  int pkey;
  int token = 0;
  int c;
  float p;
  float d;
  string n;

  cout << "\n\t\t\t Modify the record";
  cout << "\n\t\t\t Product code :";
  cin >> pkey;

  data.open("database.txt", ios::in);
  if(!data) {
    cout << "File doesn't exist";
  }else{

    data1.open("database1.txt", ios::app | ios::out);
    data >> pcode >> pname >> price >> discount;
    while (!data.eof())
    {
      if(pkey==pcode) {
        cout << "\n\t\t Product new code :";
        cin >> c;
        cout << "\n\t\t Name of the product: ";
        cin >> n;
        cout << "\n\t\t Price: ";
        cin >> p;
        cout << "\n\t\t Discount: ";
        cin >> d;
        data1 << " " <<c<< " " << n << " " << p << " " << d << "\n";
        cout << "\n\n\t\t Record edited ";
        token++;
      }else{
        data1 << " " << pcode << " " << pname << " " << price << " " << discount << "\n";
      }
      data >> pcode >> pname >> price >> discount;
    }
    data.close();
    data1.close();

    std::remove("database.txt");
    std::rename("database1.txt", "database.txt");

    if(token == 0) {
      cout << "\n\n Record not found sorry!";
    }

  }
}

void shopping::remove()
{
  fstream data, data1;
  int pkey;
  int token = 0;
  cout << "\n\n\t Delete product";
  cout << "\n\n\t Product code: ";
  cin >> pkey;
  data.open("database.txt", ios::in);
  if(!data) 
  {
    cout << "File doesnt exist";
  }
  else{
    data1.open("database1.txt", ios::app | ios::out);
    data >> pcode >> pname >> price >> discount;
    while (!data.eof())
    {
      if (pcode == pkey)
      {
        cout << "\n\n\t Product deleted successfully";
        token ++;
      }else{
        data1 << " " << pcode << " " << pname << " " << price << " " << discount << "\n";
      }
      data >> pcode >> pname >> price >> discount;
    }
    data.close();
    data1.close();

    std::remove("database.txt");
    rename("database1.txt", "database.txt");

    if(token == 0) {
      cout << "\n\n Record not found";
    }
    
  }
}

void shopping::list () 
{
  fstream data;
  data.open("database.txt", ios::in);
  cout << "\n\n|_____________________________\n";
  cout << "ProdNo\t\tName\t\tPrice\n";
  cout << "\n\n|_____________________________\n";
  data >> pcode >> pname >> price >> discount;

  while (!data.eof())
  {
    cout << pcode << "\t\t" << pname << "\t\t" << price << "\n";
    data >> pcode >> pname >> price >> discount;
  }
  data.close();
}

void shopping::receipt ()
{
  cout << "receipt";
}

int main () {
  shopping sh;
  sh.menu();
  return 0;
}