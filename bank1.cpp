#include<iostream>
#include<windows.h>
using namespace std;
class BankAccount 
{
protected:
    char name;
    int accNo;
    double balance;

public:
    void getDetails() 
	{
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, 10);
        cout << "Enter Account Holder Name: ";
        cin >> name;
		Beep(1000,100);
        cout << "Enter Account Number: ";
        cin >> accNo;
		Beep(1000,100);
        cout << "Enter Initial Balance: ";
        cin >> balance;
        Beep(1000,100);
    }
	void line()
	{
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, 13);
		for(int a=1;a<=80;a++)
		{
			cout<<"-";
		}
		cout<<endl;
	}
    void displayDetails()
	{
		line();
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, 11);
		cout << "\nAccount Holder: " << name;
        cout << "\nAccount Number: " << accNo;
        cout << "\nBalance: Rs." << balance << endl;
    	line();
	}

    void deposit(double amount)
	{
		line();
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, 1);
        balance += amount;
        cout << "\nRs." << amount << " deposited successfully."<<endl;
    	line();
	}
    void withdraw(double amount) 
	{
        if (amount <= balance) 
		{
			line();
			HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(h, 1);
            balance -= amount;
            Beep(1200, 150);
			Beep(1400, 150);
			cout << "\nRs." << amount << " withdrawn successfully."<<endl;
			line();
        } 
		else
		{
			line();
			Beep(500,500);
			HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(h, 1);
            cout <<"\nInsufficient Balance!"<<endl;
            line();
        }
    }

    void showBalance() 
	{
		line();
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h, 1);
        cout << "\nCurrent Balance: Rs." << balance << endl;
    	line();
	}
	virtual void intrest()=0;
};
class ABCbank : public BankAccount 
{
public:
	void intrest()
	{
		line();
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h,11);
		cout<<"Your interest is: Rs."<<(balance*2)/365<<endl;
		line();
	}
};
int main() 
{
    ABCbank acc;
    int choice;
    double amount;
    acc.getDetails();
    do 
	{
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(h,12);
        cout<<"\n\n===== BANK MENU =====";
        SetConsoleTextAttribute(h,14);
		cout<<"\n1. Deposit";
        cout<<"\n2. Withdraw";
        cout<<"\n3. Display Account Details";
        cout<<"\n4. Show Balance";
        cout<<"\n5. Show interest";
        cout<<"\n6. Exit";
        SetConsoleTextAttribute(h,12);
        cout<<"\n======================";
        SetConsoleTextAttribute(h,3);
        cout<<"\nEnter your choice: ";
        cin >> choice;
        Beep(2000,50);
        SetConsoleTextAttribute(h,12);
		cout<<"======================\n";
        switch(choice) 
		{
            case 1:
            	{
            		SetConsoleTextAttribute(h,6);	
	                cout << "Enter amount to deposit: ";
    	            cin >> amount;
        	        acc.deposit(amount);
            	    Beep(800, 150);
					Beep(1400, 150);
                	break;
				}
            case 2:
            	{
				 	SetConsoleTextAttribute(h,6);
                	cout << "Enter amount to withdraw: ";
	                cin >> amount;
    	            acc.withdraw(amount);
        	        break;
				}
	        case 3:
	        	{
        	    	SetConsoleTextAttribute(h,6);
            	    acc.displayDetails();
                	break;
				}
            case 4:
            	{
    	        	SetConsoleTextAttribute(h,6);
        	        acc.showBalance();
            	    break;
				}
			case 5:
				{
					SetConsoleTextAttribute(h,6);
					acc.intrest();
					break;
				}
            case 6:
            	{
	            	SetConsoleTextAttribute(h,15);
    	            cout << "\nWe sincerely appreciate your business!!!";
        	        SetConsoleTextAttribute(h,0);
            	    break;
               	}	
            default:
            	{
            		SetConsoleTextAttribute(h,4);
                	cout << "\n Sorry invalid Choice";
        		}
        }
    } while(choice != 6);
return 0;
}
