#include <iostream>
#include <fstream>
#include <conio.h>
#include <vector>
#include "admin.cpp"

using namespace std;

FileWritting writter;

void admin()
{
    adminC ad;

    cout << "       Enter the Admin password: ";
    string p;
    cin >> p;

    if (p != ad.password)
    {
        return;
    }

    int ch = 122242;
    while (ch != 0)
    {
        system("cls");
        cout << "***************************************************************************************************" << endl;
        cout << "                                   THIS IS AN ADMIN PAGE\n"
             << endl;
        cout << "       1. See Result                    2. Enrollment of Candidates      3. delete all voters   " << endl;
        cout << "       4. RESET()                       5. Add new voters\n"
             << endl;
        cout << "                                        0: Back" << endl;
        cout << "---------------------------------------------------------------------------------------------------" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:

        {
            system("cls");
            cout << "*********************************************************" << endl;
            cout << "       This is the final result of the election-- " << endl;
            ad.seeResult();
            cout << endl
                 << "\n       Press any key to continue..";
            getch();
            break;
        }
        case 2:
        {
            system("cls");
            cout << "\n                   THIS IS AN ENROLLMENT PAGE" << endl;
            cout << "------------------------------------------------------------------\n"
                 << endl;
            cout << "           This is a Enrollment page for elected candidate " << endl;

            cout << "       All condidates who want to stand in election  fill up the Enrollment form  \n"
                 << endl;

            ad.startSetup();

            cout << endl
                 << "       Press any key to continue..";
            getch();
            break;
        }

        case 3:
        {
            system("cls");
            ad.deleteAllVoters();
            cout << "       All voters details are deleted from the voter list " << endl;
            cout << endl
                 << "       Press any key to continue..";
            getch();
            break;
        }
        case 4:
        {

            ad.reset();
            system("cls");
            cout << "\n\n       System has been Reset() Successfully." << endl
                 << endl;
            cout << endl
                 << "       Press any key to continue..";
            getch();
            break;
        }
        case 5:
        { // cout<<"How many candidate you want to added in voter list \n\n"<<endl;
            system("cls");
            cout << "  *****************************************************************" << endl;
            ad.addVoters();
            cout << endl
                 << "       Press any key to continue..";
            getch();
            break;
        }
        case 0:
            cout << "Exiting";
        default:
            cout << "Invalid-Input";
            break;
        }
    }
}












bool is_empt(std::ifstream &pFile)
{
    return pFile.peek() == std::ifstream::traits_type::eof();



}

string searchVoter(string id)
{
    ifstream inVoter("DATA/VoterDetails.txt");
    string ID, name, dob;
    while (!inVoter.eof())
    {
        inVoter >> ID;
        inVoter >> name;
        inVoter >> dob;
        if (id == ID)
        {
            return "Voter Id: " + id + ", Name: " + name + ", DOB: " + dob;
        }
    }
    if (inVoter.eof())
        return "";
    inVoter.close();
    return "";
}

bool isAlredyVoted(string id)
{
    ifstream dt("DATA/AlredyVoted.txt");
    string ID;
    getline(dt, ID);
    while (!dt.eof())
    {
        if (ID.compare(id) == 0)
        {
            return true;
        }
        getline(dt, ID);
    }

    return false;
}
















void voting()
{
    ifstream res("DATA/Result.txt");
    if (!res)
    {
        cout << "Result file is not in DATA folder" << endl;
        return;
    }
    if (is_empt(res))
    {
        // is empty is boolien is_function
        cout << "Setup first" << endl;
        return;
    }

    int ch = 10;
//   vector is  standard container which offers fixed time access to individual elements in any order.
    vector<int> vote;
    vector<string> candidate;
    int voteCount;
    string line;

    res >> voteCount;
    getline(res, line);
    while (!res.eof())
    {
        vote.push_back(voteCount);
        candidate.push_back(line);
        res >> voteCount;
        getline(res, line);
    }

    while (ch != 0)
    {
        system("cls");
        cout << "                   WELCOME TO THE VOTING PAGE " << endl;
        cout << "-----------------------------------------------------------------------------------------------" << endl;
        cout << endl;
        cout << "         1. Give VOTE                        0. End Voting              Helpline No:7499099201"         << endl;
        cin >> ch;
        system("cls");


        if (ch == 0)
        {
            writter.write("DATA/Result.txt", "");
            for (int i = 0; i < candidate.size(); i++)//size returns number of elemnt
            {
                string s = to_string(vote[i]) + candidate[i] + "\n";
                writter.appendNewLine("DATA/Result.txt", s);
            }
        }
        else if (ch == 1)
        {
            cout << endl
                 << "       Enter your Voter-ID: ";
            string id;
            cin >> id;
            if (searchVoter(id) == "")
            {
                cout << "\n\n       Voter Not Found \n      Enter valid voter-ID" << endl;
                continue;
            }
            cout << endl;
            cout << "       " << searchVoter(id);
            if (isAlredyVoted(id))
            {
                cout << endl
                     << "\n       You have already voted." << endl;
                cout << endl
                     << "       Press any key to continue..";
                getch();
                continue;
            }
            int v;
            cout << "\n\n";
            for (int i = 0; i < candidate.size(); i++)
            {
                cout << "\n\n"
                     << "       "
                     << i + 1 << "." << candidate[i];
            }

            cout << "\n------------------------------------------------------------------" << endl;
            cout << endl
                 << "\n       Choose Your Vote: ";
            cin >> v;
            vote[v - 1]++;//vote count increased
            writter.appendNewLine("DATA/AlredyVoted.txt", id + "\n");
            cout << "------------------------------------------------------------------\n"
                 << endl;
        }

        else
        {
            cout << "Invalid Input" << endl;
        }
    }
    res.close();
}

int main()
{
    int ch = 100;
    while (ch != 0)
    {
        cout << "*********************************************************************" << endl;
        cout << "                      WELCOME TO ONLINE VOTING\n " << endl;
        cout << "       1.ADMIN PAGE      2.START VOTING        0.EXIT THE PAGE" << endl;
        cout << "----------------------------------------------------------------------\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            system("cls");
            admin();
            break;
        case 2:
            system("cls");
            voting();
            break;
        case 0:
            cout << "Exiting..";
            exit(0);
        default:
            break;
        }
        system("cls");
    }
}