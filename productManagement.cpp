#include<iostream>
#include<fstream>

using namespace std;


void createProduct(){

    ofstream productFile;
    productFile.open("product.txt", ios::app);
    int productID;
    string productName;
    int productPrice;
    int productQuantity;

    cout << "Enter Product ID: ";
    cin >> productID;
    cout << "Enter Product Name: ";
    cin >> productName;
    cout << "Enter Product Price: ";
    cin >> productPrice;
    cout << "Enter Product Quantity: ";
    cin >> productQuantity;
    productFile << productID << " " << productName << " " << productPrice << " " << productQuantity << endl;
    productFile.close();

    cout << "Product Created Successfully!" << endl;


}  




int DeleteProductById(){
    int productID;
    cout << "Enter Product ID: ";
    cin >> productID;
    ifstream productFile;
    productFile.open("product.txt");
    ofstream tempFile;
    tempFile.open("temp.txt");
    int productID1;
    string productName;
    int productPrice;
    int productQuantity;
    while(productFile >> productID1 >> productName >> productPrice >> productQuantity){
        if(productID1 != productID){
            tempFile << productID1 << " " << productName << " " << productPrice << " " << productQuantity << endl;
        }
    }
    tempFile.close();
    productFile.close();
    remove("product.txt");
    rename("temp.txt", "product.txt");
    cout << "Product Deleted Successfully!" << endl;
    return 0;
}


void readFromFile(){
    ifstream productFile;
    productFile.open("product.txt");
    string line;
    while(getline(productFile, line)){
        cout << line << endl;
    }
    productFile.close();

}




void DisplayById(){

ifstream productFile;
productFile.open("product.txt");
int productID;

cout<<"Enter Your Product ID: ";
cin>>productID;

int productID1,productPrice,productQuantity;
string productName;
    
while (productFile >> productID1 >> productName >> productPrice >> productQuantity)
{
    if(productID ==productID1){
        cout<<"product with " << productID <<" has found !!!"<<endl<<endl;
        cout<<productID1 << " "<<productName<<" "<<productPrice<<" "<<productQuantity<<" ";
    }
    else{
        cout<<" product not product "<<endl;
    }

}
}





void updateProduct(){   
ifstream productFile;
ofstream tempFile;
productFile.open("product.txt");

tempFile.open("temp.txt");
int productID,productID1,productPrice,ProductQuantity,productPriceNew,productQuntityNew;;
string productName,ProductNameNew;    ;


cout<<"Enter Your Product ID: ";
cin>>productID;

while (productFile >> productID1 >>productName >>productPrice >>ProductQuantity){

    if(productID !=productID1){
        
    tempFile<< productID1 << " " << productName << " " << productPrice << " " << ProductQuantity << endl;
    }
    else{
        cout<<"Enter New Product Name: ";
        cin>>ProductNameNew;
        cout<<"Enter New Product Price: ";
        cin>>productPriceNew;
        cout<<"Enter New Product Quantity: ";
        cin>>productQuntityNew;
        tempFile<< productID << " " << ProductNameNew << " " << productPriceNew << " " << productQuntityNew << endl;
    }

}

tempFile.close();
productFile.close();
remove("product.txt");
rename("temp.txt","product.txt");
cout<<" Product updated successfully"<<endl;


}


int main(){

int choice;

do{
  cout<<"\n\n\n\n";

  cout<<"\t****************************\n";
  cout<<"\t*         MENU             *\n";
  cout<<"\t****************************\n";
  cout<<"\t*   1. CREATE PRODUCT      *\n";
  cout<<"\t*   2. VIEW ALL PRODUCT    *\n";
  cout<<"\t*   3. VIEW BY ID          *\n";
  cout<<"\t*   4. UPDATE PRODUCT      *\n";
  cout<<"\t*   5. DELETE PRODUCT      *\n";
  cout<<"\t****************************\n";
  cout<<"\n\n\n\n";

cout<<"\tEnter your choice: ";
cin>>choice;

switch (choice)
{
case 1:
    cout<<"\n\t\t\t Hello create product function \n";
    createProduct(); // create product function
   cin>>choice;
    break;
case 2:

    cout<<"\n\t\t\t Hello read from file function \n";
    readFromFile(); // read from file function
    cin>>choice;
    break;

 case 3:
         DisplayById();
    break;
 case 4:
   updateProduct();
 break;      
case 5:
    cout<<"\n\t\t\t Hello delete product by id function \n";
    DeleteProductById(); // delete product by id function
    cout<<"\n\t\t Enter product id to delete: ";
    cin>>choice;
    break;    

default:
    break;
}

}

while (choice>=1 && choice<=5);







    return 0;
}