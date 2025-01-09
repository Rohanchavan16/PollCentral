
#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include "fileHandling.cpp"

using namespace std;

class adminC
{
private:
    FileWritting writter;

public:
    string password = "DYPATIL";
    void reset();
    void deleteAllVoters();

    void startSetup();
    void addVoters();
    void seeResult();
};

void adminC::seeResult()
{
    cout << endl;
    ifstream in("DATA/Result.txt");
    int voteCount;
    string line; // name of candidate
    in >> voteCount;
    getline(in, line);
    while (!in.eof())
    {
        cout << endl
             << "      " << line << " get total " << voteCount << " Votes." << endl;
         in >> voteCount;
         getline(in, line);
    }
}

void adminC::addVoters()
{
    cout << "       Now we are going to add new voters in voter list  " << endl
         << endl;

    cout << "       Enter how many Voters you want to add  : ";
    int n;
    cin >> n;
    cout << endl
         << endl;
    string VoterName, ID;
    int date, month, year = 0;
    for (int i = 0; i < n; i++)
    {
        cin.ignore();
        // number  of charatcter discards in the stream
        cout << "       Enter the name of the Voter " << i + 1 << ": ";
        getline(cin, VoterName);
        cout << "       Enter the Voter ID of " << VoterName << ": ";
        getline(cin, ID);
        cout << "       BIRTHDATE DETAILS==>Enter the Date " << VoterName << ":";
        cin >> date;
        if (date > 31)
        {
            cout << "        Enter valid date" << endl;
            break;
        }
        cout << "       BIRTHDATE DETAILS==>Enter the Month" << VoterName << ":";
        cin >> month;
        if (month > 12)
        {
            cout << "Enter valid month" << endl;
        }
        cout << "       BIRTHDATE DETAILS==>Enter the Year" << VoterName << ":";
        cin >> year;
        if (year > 2005)
        {
            cout << "      Applicant age is less than 18....!" << endl;

            cout << "\n        New voter cant be  added into the voter list" << endl;
            break;
        }
        else{
            cout << "\n        New voters has been added into the voter list" << endl;
        }
        writter.appendNewLine("DATA/VoterDetails.txt", ID + " " + VoterName + " " + to_string(date) + "-" + to_string(month) + "-" + to_string(year) + "\n");
        cout << "-------------------------------------------------------------------------------\n"
             << endl;
    }
}

void adminC::reset()
{
    writter.write("DATA/Result.txt", " ");
    writter.write("DATA/AlredyVoted.txt", " ");
}

void adminC::startSetup()
{ // candidate and also isAlredyVoted removed
    reset();
   

    cout << endl;
    cout << "       Enter how many Candidates: ";
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << "       You have only one candidiate-----! Can't form Election" << endl;
    }
    else
    {
        string candidateName, party, symbol;
        for (int i = 0; i < n; i++)
        {
            cin.ignore();
            cout << "       Enter the name of the candidate " << i + 1 << ": ";
            getline(cin, candidateName);
            cout << "       Enter the party name of the candidate " << candidateName << ": ";
            getline(cin, party);
            cout << "       Enter the symbol of the party " << party << ": ";
            getline(cin, symbol);
            writter.appendNewLine("DATA/Result.txt", "0 " + candidateName + " of party " + party + " (" + symbol + ")\n");
            cout << endl;
        }
    }
    if (n == 1)
    {
        cout << "       CANDIDATE ENROLLMENT COMPELETE USUCCESSFULL" << endl;
    }
    else
    {
        cout << "" << endl;
        cout << "       CONGRATULATIONS.......   " << endl
             << endl;
        cout << "       CANDIDATE ENROLLMENT COMPELETE SUCCESSFULL" << endl;
    }
}

void adminC::deleteAllVoters()
{
    writter.write("DATA/VoterDetails.txt", " ");
}
