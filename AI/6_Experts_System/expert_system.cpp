#include <bits/stdc++.h>
using namespace std;

void flue(string name)
{
    string res;
    // Asking questions for the  flue
    cout << "HI " << name << " are you ready to take flue test:?(y/n) " << endl;
    cin >> res;
    if (res == "y")
    {
        cout << "Good, go then ........" << endl;
        cout << "Loading question............................................." << endl;
    }
    else
    {
        return;
    }
    int prob = 0;
    cout << "1) Do you have cold? (y/n)" << endl;
    cin >> res;
    prob += ((res == "Y" or res == "y") ? 1 : 0);
    cout << "2) what is your body tempreture ?" << endl;
    int temp = 0;
    cin >> temp;
    if (temp > 100)
    {
        prob++;
    }
    cout << "3)Do you feel weakness in body? (y/n)" << endl;
    cin >> res;
    prob += ((res == "Y" or res == "y") ? 1 : 0);

    cout << "4)Do you feel headache ? (y/n)" << endl;
    cin >> res;
    prob += ((res == "Y" or res == "y") ? 1 : 0);

    if (prob > 2)
    {
        cout << "YES, there are high chances that you are suffering from flue....\n I will suggest you to do following:==\n"
             << endl;
        cout << "1) Contact the doctor and follow proper medication\n";
        cout << "2) Take rest for few days and dont go outside\n";
        cout << "3) Eat healthy food..\n";
    }
    else if (prob <= 2 && prob != 0)
    {
        cout << "Take rest for few days .....\n";
    }
    else    
    {
        cout << "Thank god, Dont worry you are healty....." << endl;
    }
}
void stress(string name)
{
    string res;
    // Asking questions for the  stress
    cout << "HI " << name << " are you ready to take Stress test:?(y/n) " << endl;
    cin >> res;
    if (res == "y")
    {
        cout << "Good then go then ........" << endl;
        cout << "Loading question............................................." << endl;
    }
    else
    {
        return;
    }
    int prob = 0;
    cout << "1) do you feel headache?" << endl;
    cin >> res;
    prob += ((res == "Y" or res == "y") ? 1 : 0);
    cout << "2) Do you feel depressed ?" << endl;
    cin >> res;
    prob += ((res == "Y" or res == "y") ? 1 : 0);
    cout << "3) are you spending your day in the overthinking.....?" << endl;
    cin >> res;
    prob += ((res == "Y" or res == "y") ? 1 : 0);

    if (prob > 2)
    {
        cout << "YES, there are high chances that you have stress....\n I will suggest you to do following:==\n"
             << endl;
        cout << "1) Contact the doctor and follow proper medication\n";
        cout << "2) Do yoga and meditation\n";
        cout << "3) Eat healthy food..\n";
        cout << "4)spend time with friends and travel in the open air...\n";
    }
    else if (prob <= 2 && prob != 0)
    {
        cout << "Do yoga and meditaion .....\n";
    }
    else
    {
        cout << "Thank god, Dont worry you are healty....." << endl;
    }
}
int main()
{

    cout << "Hello Welcome to the Medicure...." << endl;
    string name = "";
    cout << "Enter your good name: ";
    cin >> name;
    cout<<"Hi... "<<name<<" tell me what is your problem, I am here to solve your problem by identifying the system "<<endl;
    cout << "I can check for the flue and the stress so select option acording to your requirement: " << endl;
    int choice;
menu:
    cout << "1) Flue\n 2) Stress" << endl;
    cout << "Check one of the above:" << endl;
    cin >> choice;

    if (choice == 1)
    {
        flue(name);
    }
    else if (choice == 2)
    {
        stress(name);
    }
    else
    {
        cout << "Wrong choice!!!" << endl;
        goto menu;
    }

    cout << "Thak you so much for using medicure ......." << endl;
    return 0;
}