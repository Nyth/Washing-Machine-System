#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
using namespace std;
float coin,bal1,bal2,price[2]={4.00,7.00};  //bal=balance
string temp[]={"cold","warm","hot"};    //option for temperature
string mode[]={"soft","gentle","strong"};  //option for mode
string weight[]={"Below 10Kg","Above 10Kg"};  //option for weight
string name;
char ans;
int optiontemp,optionmode,optionweight;

void pay(); //function coin insert
void choose ( float [] ); //funtion choosing service
void temperature ( string [] );  //funtion for choosing temperature
void washingmode( int,int ); //funtion for choosing washing mode
void selWeight( string [] );  //fuction of weight selection
void summary (string ,float , int , int , int); // summary of our customer option
int i,j;


int main()
{


	do
	{
		cout << "Enter Your Name : ";
		cin >> name;

		cout << "		^_^  Hi !! Welcome to The Razi Automatic Laundry Services  ^_^" << endl;
		cout << endl ;
		cout << endl ;
		cout << "			 *****************************************"  << endl;
		cout << "			|  RM 4.00 -  Washing and Rinse           |" << endl
			 << "			|-----------------------------------------|" << endl
			 << "			|  RM 7.00 -  Washing , Rinse and Drying  |" << endl
			 << "			 *****************************************"  << endl
			 << endl
			 << endl ;
			do
			{
				pay();
				choose(price);
			}while(coin!= *(price+0)  &&  coin!= *(price+1) );	//using pointer to assign array
			do
			{
				selWeight(weight);
			}while(optionweight!=1 && optionweight!=2);
				temperature(temp);
				washingmode(optionweight , optionmode);
				summary (name , coin ,  optionweight , optiontemp , optionmode);
		 // the program will loop if user enter the wrong selction of weight.

				cout << "Do You Want to Continue (Y/N): " ;
				cin >>  ans;

	}while(ans=='Y' || ans=='y');
	cout << endl;
	// this loop ask user if want to continue if Y, the program will proceed.
	//if N, the whole programe will loop and ask user to input everything again.

 return 0;

 }

 void pay() // input function (insert coin)
 {
 	cout << "Please Enter Your Coin : RM ";
 	cin >> coin;

 	return;
 }
 void choose(float price[]) // price selection function.
 {

	cout << endl;
 		if (7.00-coin==3.00) // to assign coin = RM 4.00
 		{
 			cout << "You Have Selected package RM 4.00 . Service provided are washing and rinsing ." << endl;
		}
		else if (7.00-coin==0) // to assign coin = RM 7.00
		{
			cout << "You Have Selected package RM 7.00 . Service provided are washing , rinsing and drying." << endl;
		}
		else
		{
				if(coin<price[0]) // if coin less than RM 4.00
				{
					bal1=price[1]-coin;
					bal2=price[0]-coin;
					cout << "Please Insert RM " << bal1 << " or RM " << bal2 << " to use our RM7.00 / RM4.00 service . ( ^_^ )" << endl;
				}
				else if (coin>price[0]) // if coin more than RM 4.00
				{
					bal1=price[1]-coin;
					cout << "Please Insert RM " << bal1 << " to use our RM7.00 service" << endl;
				}

		}
	cout << endl;

	return;
 }
 void selWeight(string weight[]) // weight selection function
 {
 	do
 	{

 		cout << endl;
 		cout << "Choose your load weight " << endl;
		cout << endl;
		for(i=0;i<2;i++)
		{
			cout << i+1 <<" . " << *(weight+i) <<endl; // to call the array that been initial before
		}
		cout << endl;
		cout<< "Please select your weight ? ";
		cin >> optionweight; //input weight selection
		cout << endl ;
		}while(optionweight!=1 && optionweight!=2);
	return;
 }

void temperature( string temp[]) // temperature selection function
 {
 	cout << endl;
	cout << "Please choose your water temperature. " ;
	cout << endl;
	cout << endl;

	for(i=0;i<3;i++)
	{
		cout << i+1 << " . " << *(temp+i) << endl; // to display the array values initialize before
	}
	cout << endl;
	cout << "Enter you option : ";
	cin	 >> optiontemp ; //inpit temperature selection
	cout << endl;

	return ;
 }

void washingmode(int optionweight, int optiontemp) // washing mode selection function
{
	cout << endl;
	for(i=0;i<3;i++)
	{
		cout << i+1 << " . " << *(mode+i) << endl; //to display the  value of mode array that been initialize before
	}
	cout << endl;
	cout << " Please Select your washing mode. " ;
	cin >> optionmode;  // input wahing mode selection
	cout << endl;

	return;
}

void summary( string name,float coin, int optionweight, int optiontemp, int optionmode) // summary of  customer's selection
{
	if(coin==7.00)
	{
		cout << name << "  You selected our RM 7.00 services,this is your option . " << endl;

	}
	else if(coin==4.00)
	{
		cout << name << "  You selected our RM 4.00 services,this is your option . " << endl;

	}

		cout << "You have selected weight " << weight[optionweight - 1]
			 << " , " << temp[optiontemp - 1 ] << " temperature "
			 << " and " << mode [ optionmode - 1 ]
			 << " washing mode."
			 << endl;
		cout << endl;
    return;
}

























