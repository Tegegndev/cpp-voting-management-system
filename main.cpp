/*
FUNDAMENTALS OF PROGRAMMING II
GROUP 7

TITLE : DEPARTMENTAL VOTING SYSTEM 

Group Members:
    1. Tegegn Wukianos  -  UGR/99552/17
    2. Tsadiku Siltanu - UGR/99575/17
    3. Temesgen gebeyehu UGR/107195/17
    4. Azmach Atoma      UGR/99579/17
    5. Zebenay Yitayew    UGR/99491/17
    6. Wondwosen Kebede  UGR/100769/17
*/

#include <iostream>
#include <string>
using namespace std;

struct department {
    int id;
    string dept_name;
    int vote_count;
};

struct user {
    int id;
    string name;
    bool is_voted = false;
};

const int max_departments = 5; 
const int max_users = 6;

department department_list[max_departments] = {
    {1, "Information Technology", 0},
    {2, "Information System", 0},
    {3, "Computer Science", 0},
    {4, "Mechanical", 0},
    {5, "Electrical", 0}
};

user users_list[max_users] = {
    {1, "Tegegn Wukianos"},
    {2, "Tsadiku Siltanu"},
    {3, "Temesgen Gebeyehu"},
    {4, "Azmach Atoma"},
    {5, "Zebenay Yitayew"},
    {6, "Wondwosen Kebede"}
};

void show_depts() {
    cout << "\n--- Available Departments ---\n";
    for (int i = 0; i < max_departments; i++) {
        cout << department_list[i].id << ". " << department_list[i].dept_name << endl;
    }
}

void show_ranking() {
    cout << "\n--- Current Vote Count ---\n";
    for (int i = 0; i < max_departments; i++) {
        cout << department_list[i].dept_name << " -> " << department_list[i].vote_count << " votes" << endl;
    }
}

void cast_vote() {
    int id_input;
    cout << "\nPlease enter your Voter ID (1-6): ";
    cin >> id_input;

    int found_index = -1;
    for (int i = 0; i < max_users; i++) {
        if (users_list[i].id == id_input) {
            found_index = i;
            break;
        }
    }

    if (found_index == -1) {
        cout << "Error: ID not found in the group list.\n";
        return;
    }

    if (users_list[found_index].is_voted) {
        cout << "Sorry " << users_list[found_index].name << ", you have already voted!\n";
        return;
    }

    cout << "Welcome, " << users_list[found_index].name << "!\n";
    show_depts();

    int choice;
    cout << "Choose Department ID (1-5): ";
    cin >> choice;

    if (choice < 1 || choice > 5) {
        cout << "Invalid choice. Please pick from 1 to 5.\n";
        return;
    }

    department_list[choice - 1].vote_count++;
    users_list[found_index].is_voted = true;

    cout << "Thank you! Your vote for " << department_list[choice - 1].dept_name << " is saved.\n";
}

void show_winner() {
    int highest_votes = -1;
    string winner_name = "";

    for (int i = 0; i < max_departments; i++) {
        if (department_list[i].vote_count > highest_votes) {
            highest_votes = department_list[i].vote_count;
            winner_name = department_list[i].dept_name;
        }
    }

    if (highest_votes <= 0) {
        cout << "\nNo votes yet. We cannot announce a winner.\n";
    } else {
        cout << "\n========================================";
        cout << "\nTHE WINNER IS: " << winner_name;
        cout << "\nWITH TOTAL VOTES: " << highest_votes;
        cout << "\n========================================\n";
    }
}

int main() {
    int menu_choice;

    while (true) {
        cout << "\n****************************************";
        cout << "\n      DEPT. VOTING SYSTEM - GROUP 7     ";
        cout << "\n****************************************\n";
        cout << "1. List Departments\n";
        cout << "2. Vote Now\n";
        cout << "3. Show Rankings\n";
        cout << "4. Show Winner\n";
        cout << "5. Exit\n";
        cout << "----------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> menu_choice;

        if (menu_choice == 1) {
            show_depts();
        } else if (menu_choice == 2) {
            cast_vote();
        } else if (menu_choice == 3) {
            show_ranking();
        } else if (menu_choice == 4) {
            show_winner();
        } else if (menu_choice == 5) {
            cout << "Exiting system... Goodbye!\n";
            break;
        } else {
            cout << "Wrong input. Please try again.\n";
        }
    }

    return 0;
}

/*
WE WROTE THIS CODE FOR OURSELF  IF YOU MIGHT THINK THAT IT IS AI GENERATED  PLEASE EMAIL ME AT tegegnw1997@gmail.com
 WITH YOUR QUESTION REGARDING TO THIS PROJECT BEFORE DEDUCTING OUR MARK THANK YOU

 REFERNCES WE HAVE USED:
 1. https://www.geeksforgeeks.org/
 2. https://www.youtube.com/
 3. https://www.w3schools.com/
 4. https://freecodecamp.org/
*/
