// SurfShop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// to easily put the banner into main when need be
void Banner()
{
    cout << setfill('*') << setw(70) << '*' << endl;
    cout << setfill('*') << setw(11) << '*';
    cout << " Welcome to my Johnny Utah's PointBreak Surf Shop ";
    cout << setfill('*') << setw(9) << '*' << endl;
    cout << setfill('*') << setw(70) << '*' << endl;
    cout << endl;
}

// Holds the text that prompts users to enter their choice
void ShowUsage()
{
    cout << "To show program usage 'S'" << endl;
    cout << "To purchase a surfboard press 'P'" << endl;
    cout << "To display current purchases press 'C'" << endl;
    cout << "To display total amount due press 'T'" << endl;
    cout << "To quit the program press 'Q'" << endl;  
}

// if the user chose 'P' it takes them here where they will be asked for the amount they wish to purchase and the size. It is recorded for future use.
void MakePurchase(int& iTotalSmall, int& iTotalMedium, int& iTotalLarge, int& iTotalXXXS)
{
    char purchase;
    int quantity = 0;
    cout << "Please enter the quanity and type (S=small, M=medium, L=large, X=XXXS(for squirrels) of surfboard you would like to purchase: ";
    cin >> quantity >> purchase;

    if (cin.fail())
        exit(EXIT_FAILURE); // This is here because the program kept flooding the output over and over when the user chose an option that didnt fit. I couldn't figure out how to break off and ask them again so I exited instead

    
    if (purchase == 's' || purchase == 'S')
        iTotalSmall = iTotalSmall + quantity;
    else if (purchase == 'm' || purchase == 'M')
        iTotalMedium = iTotalMedium + quantity;
    else if (purchase == 'l' || purchase == 'L')
        iTotalLarge = iTotalLarge + quantity;
    else if (purchase == 'x' || purchase == 'X')
        iTotalXXXS = iTotalXXXS + quantity;



        
    

}

// If the user chooses 'C' it takes them here where it displays the size and quantity of the surfboard(s) they wish to purchase.
void DisplayPurchase(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, const int iTotalXXXS)
{
    const int nothing = 0;
    if (iTotalSmall > nothing)
        cout << "The total number of small surfboards is: " << iTotalSmall << endl;
    if (iTotalMedium > nothing)
        cout << "The total number of medium surfboards is: " << iTotalMedium << endl;
    if (iTotalLarge > nothing)
        cout << "The total number of large surfboards is: "  << iTotalLarge << endl;
    if (iTotalXXXS > nothing)
        cout << "The total number of XXXS surfboards is " << iTotalXXXS << endl;
    if ((iTotalSmall == nothing) && (iTotalMedium == nothing) && (iTotalLarge == nothing) && (iTotalXXXS == nothing))
        cout << "No purchases made yet" << endl;
    
}

// This takes the amount of surfboards they want to purchase and displays it with the cost per size, and the total cost of the order.
void DisplayTotal(const int iTotalSmall, const int iTotalMedium, const int iTotalLarge, const int iTotalXXXS)
{
    const int nothing = 0;
    const float xxxs = 50.00;
    const float small = 175.00;
    const float medium = 190.00;
    const float large = 200.00;
    float XXXStotal = iTotalXXXS * xxxs;
    float smalltotal = iTotalSmall * small;
    float mediumtotal = iTotalMedium * medium;
    float largetotal = iTotalLarge * large;
    float grandtotal = smalltotal + mediumtotal + largetotal + XXXStotal;

    if (iTotalXXXS > nothing)
        cout << "The total number of XXXS surfboards is: " << iTotalXXXS << " at a total of $" << fixed << setprecision(2) << XXXStotal << endl;
    if (iTotalSmall > nothing)
        cout << "The total number of small surfboards is: " << iTotalSmall << " at a total of $" << fixed << setprecision(2) << smalltotal << endl;
    if (iTotalMedium > nothing)
        cout << "The total number of medium surfboards is: " << iTotalMedium << " at a total of $" << fixed << setprecision(2) << mediumtotal << endl;
    if (iTotalLarge > nothing)
        cout << "The total number of large surfboards is: " << iTotalLarge << " at a total of $" << fixed << setprecision(2) << largetotal << endl;
    if ((iTotalSmall == nothing) && (iTotalMedium == nothing) && (iTotalLarge == nothing) && (iTotalXXXS == nothing))
        cout << "No purchases made yet." << endl;
   
    if ((iTotalSmall > nothing) || (iTotalMedium > nothing) || (iTotalLarge > nothing) || (iTotalXXXS > nothing))
        cout << "Amount due $" << fixed << setprecision(2) << grandtotal << endl;


}

int main()
{
    int iTotalSmall = 0;
    int iTotalMedium = 0;
    int iTotalLarge = 0;
    int iTotalXXXS = 0;
    char option;
    string purchase;
    // calling to the void functions to print them out
    Banner();
    ShowUsage();

 // loop to display the options until the user quits the program, and displays the correct function for the option they pick.
    do {
        cout << "Please enter selection: ";
        cin >> option;
        if (option == 's' || option == 'S')
        {
            system("cls");
            Banner();
            ShowUsage();
        }

        else if (option == 'p' || option == 'P')
            MakePurchase(iTotalSmall, iTotalMedium, iTotalLarge, iTotalXXXS);
        else if (option == 'c' || option == 'C')
            DisplayPurchase(iTotalSmall, iTotalMedium, iTotalLarge, iTotalXXXS);
        else if (option == 't' || option == 'T')
            DisplayTotal(iTotalSmall, iTotalMedium, iTotalLarge, iTotalXXXS);
        else if (option == 'q' || option == 'Q')
        {
            cout << "Thank You";
            // exit(EXIT_SUCCESS);
            break;
        }
    } while (1);
    

}
