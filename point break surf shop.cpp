// point break surf shop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;
#define costOfExtraSmallSurfboard 100.00;
#define costOfSmallSurfboard 175.00;//defining the constants of surfboard price
#define costOfMediumSurfboard 190.00;
#define costOfLargeSurfboard 200.00;

void ShowUsage();//made functions

void MakePurchase(int& iTotalExtraSmall, int& iTotalSmall, int& iTotalMedium, int& iTotalLarge);

void DisplayPurchase(const int iTotalExtraSmall, const int iTotalSmall, const int iTotalMedium, const int iTotalLarge);

void DisplayTotal(const int iTotalExtraSmall, const int iTotalSmall, const int iTotalMedium, const int iTotalLarge);

int main()
{
    char choice, size; // variable
    int quantity;
    int totalQuantityExtraSmall, totalQuantitySmall, totalQuantityMedium, totalQuantityLarge;
    totalQuantityExtraSmall = 0;
    totalQuantitySmall = 0;//setting quantities to 0
    totalQuantityMedium = 0;
    totalQuantityLarge = 0;

    cout << "**********************************************************" << endl;//header
    cout << "*****Welcome to my Johnny Utah's PointBreak Surf Shop*****" << endl;
    cout << "**********************************************************" << endl;
    cout << endl << endl;
    ShowUsage(); //calling the menu function
    cout << "Please enter selection: ";
    cin >> choice;//user input for main menu

    while (tolower(choice) != 'q')//first 'while' loop, loop unil answer is not 'q' 
                                  // tolower converts 'q' to its lowercase equivalent
    {
        if (tolower(choice) == 's') // if choice is 's' call funchion 'showusage'
        {
            ShowUsage();
        }

        else if (tolower(choice) == 'p') // if choice is 'p' call function 'makepurchase'
        {
            MakePurchase(totalQuantityExtraSmall, totalQuantitySmall, totalQuantityMedium, totalQuantityLarge);
            cout << endl;
        }
        else if (tolower(choice) == 'c') // if choice is 'c' call the function 'displaypurchase'
        {
            if (totalQuantityExtraSmall == 0 && totalQuantitySmall ==0 && totalQuantityMedium  ==0 && totalQuantityLarge ==0)
            {                   // if the quantity of all 3 sizes is 0, display 'no purchase made yet
                cout << "No purchase made yet." << endl;
            }

            else
            {
                DisplayPurchase(totalQuantityExtraSmall, totalQuantitySmall, totalQuantityMedium, totalQuantityLarge);
            }
        }
        else if (tolower(choice) == 't') //if choice is 't' call the function 'displaytotal'
        {

            if (totalQuantityExtraSmall == 0 && totalQuantitySmall == 0 && totalQuantityMedium == 0 && totalQuantityLarge ==0)
            {
                cout << "No purchase made yet." << endl; // if the quantity of all 3 sizes is 0, display 'no purchase made yet
            }

            else
            {
                DisplayTotal(totalQuantityExtraSmall, totalQuantitySmall, totalQuantityMedium, totalQuantityLarge);
            }

        }
        else
        {
            cout << "Invalid choice!" << endl;//if a correct letter is not entered diplay message
        }
        cout << "Please enter selection:";//asking user to input choice again
        cin >> choice; //user input again
    }
    cout << "Thank you" << endl;

}
void ShowUsage()//define the function 'showsusage'
{
    cout << "To show program usage 'S'" << endl;//display the menu of choices.
    cout << "To purchase a surfboard press 'P'";
    cout << endl;
    cout << "To display current purchase press 'C'";
    cout << endl;
    cout << "To display total amount due press 'T'";
    cout << endl;
    cout << "To quit the program press 'Q'" << endl;
}

void MakePurchase(int& iTotalExtraSmall, int& iTotalSmall, int& iTotalMedium, int& iTotalLarge)//Define the function 'makepurchase'
{
    int quantity = 0;//declare and initialize the required variables

    char size = '\0';
    
    cout << "Please enter the quantity and type ";//ask the user to enter the quantity and size of the surfboard
    cout << "(XS=xxxsmall S=small, M=medium, L=large) of ";
    cout << "surfboard you would like to purchase:";
    cin >> quantity >> size;

    //if the surfboard's size is small add its quantity to the total of small surfboards
    if (tolower(size) == 'xs')
    {
        iTotalExtraSmall = iTotalExtraSmall + quantity;
    }
    else if (tolower(size) == 's')
    {
        iTotalSmall = iTotalSmall + quantity;
    }

    //if the surfboard's size is medium then add its quantity to the total of medium surfboards

    else if (tolower(size) == 'm')
    {
        iTotalMedium = iTotalMedium + quantity;
    }

    //if the surfboard's size is large then add its quantity to the total of large surfboards

    else if (tolower(size) == 'l')
    {
        iTotalLarge = iTotalLarge + quantity;
    }

}
void DisplayPurchase(const int iTotalExtraSmall, const int iTotalSmall, const int iTotalMedium, const int iTotalLarge)//define the function 'displaypurchase'
{
    //if the total quantity of small surfboards is more than 0 display its quantity
    if (iTotalExtraSmall > 0)
    {
        cout << "The total number of xxxsmall ";
        cout << "surfboards is " << iTotalExtraSmall;
        cout << endl;
    }
        
    if (iTotalSmall > 0)
    {
        cout << "The total number of small ";
        cout << "surfboards is " << iTotalSmall;
        cout << endl;
    }
    //if the total quantity of medium surfboards is more than 0 display its quantity
    if (iTotalMedium > 0)
    {
        cout << "The total number of medium ";
        cout << "surfboards is " << iTotalMedium;
        cout << endl;
    }

    //if the total quantity of large surfboards is more than 0 display its quantity
    if (iTotalLarge > 0)
    {
        cout << "The total number of large ";
        cout << "surfboards is " << iTotalLarge;
        cout << endl;
    }

}

void DisplayTotal(const int iTotalExtraSmall, const int iTotalSmall, const int iTotalMedium, const int iTotalLarge)//define the function 'displaytotal'
{
    double surfboard_amount_xsmall, surfboard_amount_small, surfboard_amount_medium, surfboard_amount_large, totalAmtDue; //local variables

    surfboard_amount_xsmall = 0;
    surfboard_amount_small = 0;// set to 0
    surfboard_amount_medium = 0;
    surfboard_amount_large = 0;
    totalAmtDue = 0;
        
    cout << fixed << setprecision(2);//set precision for the double values to two decimal places

    //if the total quantity of small surfboards is more than 0 display its quantity and total
    if (iTotalExtraSmall > 0)
    {
        //calculate the total of small surfboards by multiplying its total quantity with its price
        surfboard_amount_xsmall = iTotalExtraSmall *

            costOfExtraSmallSurfboard;

        cout << "The total number of xxxsmall surfboards ";
        cout << "is " << iTotalExtraSmall;
        cout << " at a total of $";
        cout << surfboard_amount_xsmall << endl;

        //add the total of small surfboards to the total amount

        totalAmtDue = totalAmtDue +

            surfboard_amount_xsmall;
    }
    if (iTotalSmall > 0)
    {
        //calculate the total of small surfboards by multiplying its total quantity with its price
        surfboard_amount_small = iTotalSmall *

            costOfSmallSurfboard;

        cout << "The total number of small surfboards ";
        cout << "is " << iTotalSmall;
        cout << " at a total of $";
        cout << surfboard_amount_small << endl;

        //add the total of small surfboards to the total amount

        totalAmtDue = totalAmtDue +

            surfboard_amount_small;
    }

    //if the total quantity of medium surfboards is more than 0 display its quantity and total
    if (iTotalMedium > 0)
    {

        //calculate the total of the medium surfboards by multiplying its total quantity with its price value
        surfboard_amount_medium = iTotalMedium *

            costOfMediumSurfboard;

        cout << "The total number of medium ";
        cout << "surfboards is " << iTotalMedium;
        cout << " at a total of $";
        cout << surfboard_amount_medium << endl;

        //add the total of medium surfboards to the total amount

        totalAmtDue = totalAmtDue +

            surfboard_amount_medium;

    }

    //if the total quantity of large surfboards is more than 0 display its quantity and total
    if (iTotalLarge > 0)
    {
        //calculate the total of the large surfboards by multiplying its total quantity with its price value

        surfboard_amount_large = iTotalLarge *

            costOfLargeSurfboard;

        cout << "The total number of large ";
        cout << "surfboards is " << iTotalLarge;
        cout << " at a total of $";
        cout << surfboard_amount_large << endl;

        //add the total of large surfboards to the total amount

        totalAmtDue = totalAmtDue +

            surfboard_amount_large;

    }
        //display the total amount due
    cout << "Amount due: $" << totalAmtDue << endl;
    
}
    
    
    
    
    
  

