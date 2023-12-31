#include "../headers/prompt.h"

void clearScreen() { //https://cplusplus.com/forum/general/273223///
#ifdef _WIN32
    system("CLS"); // For Windows
#else
    
    system("clear"); // For Linux/Unix
#endif
}

string prompt::getSelection() const{ //TESTED//
    return this->selection;
}

string redo(const string& action, Home* userHome){ //for undos from the user//
    string newVal = "";

    if(action == "Name" || action == "1"){
        cout << "Enter new title: ";
        getline(cin,newVal);

    }
    else if(action == "Description" || action == "2"){
        cout << "Enter new description: ";
        getline(cin,newVal);

    }
    else if(action =="Priority" || action == "3"){
        cout << "Enter new priority ('High', 'Medium', 'Low'): ";
        getline(cin,newVal);

        while(newVal != "high" && newVal != "High" && newVal != "medium" && newVal != "Medium" && newVal != "low" && newVal != "Low"){
            cout << "Enter a valid priority ('High', 'Medium', 'Low': ";
            getline(cin,newVal);
        }

    }
    else if(action == "Full Due Date" || action == "4"){
        do{
            cout << "Enter new date(in format mm/dd/yy): ";
            getline(cin,newVal);
        }while(newVal.size()!= 8 ||newVal.at(2) != '/' || newVal.at(5) != '/' || !(isdigit(newVal.at(0))) || !(isdigit(newVal.at(1))) || !(isdigit(newVal.at(3))) || !(isdigit(newVal.at(4))) || !(isdigit(newVal.at(6))) || !(isdigit(newVal.at(7))));

    }
    else if(action == "Full Assigned Date" || action == "5"){ //assigned date//
        do{
            cout << "Enter new assigned date(in format mm/dd/yy): ";
            getline(cin,newVal);
        }while(newVal.at(2) != '/' || newVal.at(5) != '/' || !(isdigit(newVal.at(0))) || !(isdigit(newVal.at(1))) || !(isdigit(newVal.at(3))) || !(isdigit(newVal.at(4))) || !(isdigit(newVal.at(6))) || !(isdigit(newVal.at(7))));

    }
    
    

    return newVal;

    clearScreen();
}
    
    



void prompt::setSelection(const string& payload){ //ONLY FOR TESTING//
    this->selection = payload;

}

void prompt::printSeparator(int length) {
    for (int i = 0; i < length; ++i) {
        cout << "=";
    }
    cout << endl;
}

void prompt::displayHorizontalLine(int length = 30, char symbol = '-') {
    cout << setfill(symbol) << setw(length) << "" << setfill(' ') << endl;
}



void prompt::setSelection(){ //TESTED//
    

    string userChoice = "";
    getline(cin,userChoice);
    
    while (userChoice != "1" && userChoice != "2" && userChoice != "3" && userChoice != "4" && userChoice != "5" && userChoice != "Task--"){ 
        cout << "INVALID enter (1-5) or 'Task--' to exit terminal:";
        getline(cin,userChoice);
    }
        
    this->selection = userChoice;

    clearScreen();
}

void prompt::printMainMenu(){ //TESTED//

    printLogos("printMainMenu");

    cout << "==============================================" << endl;
    cout << "             Task++ Menu Options             " << endl;
    cout << "==============================================" << endl;
    cout << "1) Make a New Task" << endl;
    cout << "2) Make a New Task List" << endl;
    cout << "3) View Tasks In Your Week" << endl;
    cout << "4) View Overall Lists & Tasks" << endl;
    cout << "5) View Tasks by Priority" << endl;
    cout << "==============================================" << endl;
    cout << "(Type 'Task--' to exit the terminal)" << endl;
    cout << "==============================================" << endl;
    cout << "Select an option (Enter corresponding numerical value): ";
    this->setSelection();
  
}

void prompt::newTaskPrompt(Home* userHome) const {
    vector<string> userData;
    string title = "", desc = "", priority = "", dueDate = "", assignedDate = "", userListChoice = "",assignToList = "", confirmation = "";
    string chooseToAssignDate = "";

    printLogos("newTaskPrompt");
    
    cout << endl << "             Input Information as prompted!             " << endl;
    cout << "========================================================" << endl;
        
    cout << "Enter the name of the new task: ";
    getline(cin, title);
    
    while(priority != "High" && priority != "Medium" && priority != "Low" && priority != "high" && priority != "medium" && priority != "low"){
        cout << "Enter the priority of the new task (\"High\", \"Medium\", \"Low\"): ";
        getline(cin,priority);
    }

    cout << "Would you like to assign a due date(\"Yes\" or \"No\"): ";
    getline(cin,chooseToAssignDate);

    while(chooseToAssignDate != "Yes" && chooseToAssignDate !="yes" && chooseToAssignDate != "no" && chooseToAssignDate != "No"){
        cout << "INVALID enter \"Yes\" or \"No\": ";
        getline(cin,chooseToAssignDate);
    }

    if(chooseToAssignDate =="yes" || chooseToAssignDate == "Yes"){
        do{
            cout << "Enter the Due Date of the task in the format MM/DD/YY: "; //checks in input is in correct format at all the indices//
            getline(cin,dueDate);
        }while(dueDate.size() < 8 || (dueDate.at(2) != '/' && dueDate.at(2) != '-') || (dueDate.at(5) != '-' && dueDate.at(5) != '/') || !(isdigit(dueDate.at(0))) || !(isdigit(dueDate.at(1))) || !(isdigit(dueDate.at(3))) || !(isdigit(dueDate.at(4))) || !(isdigit(dueDate.at(6))) || !(isdigit(dueDate.at(7))));
    }
    
    do{
        cout << "Enter the Assigned Date of the task in the format MM/DD/YY: "; //checks in input is in correct format at all the indices//
        getline(cin,assignedDate);
    }while(assignedDate.size() != 8 || (dueDate.at(2) != '/' && dueDate.at(2) != '-') || (dueDate.at(5) != '-' && dueDate.at(5) != '/') || !(isdigit(assignedDate.at(0))) || !(isdigit(assignedDate.at(1))) || !(isdigit(assignedDate.at(3))) || !(isdigit(assignedDate.at(4))) || !(isdigit(assignedDate.at(6))) || !(isdigit(assignedDate.at(7))));

    cout << "Enter the description of the new task: ";
    getline(cin, desc);
    
    if(userHome->listEmpty() == false){ //if list is empty user will get option to add to list//
        do{
            cout << "Enter Y for yes or N for no to assign task to a task list: ";
            getline(cin,assignToList);
        }while(assignToList != "Y" && assignToList != "N" && assignToList != "y" && assignToList != "n"); //checks if user properly enter y or n, to see if they want to assign it to a list//

        
        if(assignToList == "Y"){ 

            userHome->viewLists(); 
            cout << "Select list: ";
            getline(cin,userListChoice);

            while(userHome->findTaskList(userListChoice) == nullptr){ //checks if list exist//
                userHome->viewLists();
                cout << "Select a existing list (Listed above): ";
                getline(cin,userListChoice);
                
            }
        }
    }

    int rev = 0;

    do{
        if(rev == 0){
            cout << "Enter \"1\" to confirm or \"2\" to redo: ";
            rev++;
        }
        else{
            cout << "INVALID enter \"1\" to confirm or \"2\" to redo: ";
        }
        getline(cin,confirmation);
        

    }while(confirmation != "1" && confirmation != "2");

    
    
    string userAction = "";
    string newVal = ""; //declaring outside so it doesnt delete out of scope//
    string userStay = "2";
    if(confirmation == "2"){
        
        while(userStay == "2"){
            cout << "1) Edit title" << endl;
            cout << "2) Edit description" << endl;
            cout << "3) Edit priority" << endl;
            cout << "4) Edit due date" << endl;
            cout << "5) Edit assigned" << endl;
            

            cout << "Select an option (Enter corresponding numerical value): ";
            getline(cin,userAction);

            while(userAction != "1" && userAction != "2" && userAction != "3" && userAction != "4" && userAction != "5"){
                    
                cout << "Select an action (1-5): ";
                getline(cin,userAction);
            }            
            newVal = redo(userAction,userHome);
            
            int rev2 = 0;

            do{
                if(rev2 == 0){
                    cout << "Enter \"1\" to confirm or \"2\" to redo: ";
                    rev++;
                }
                else{
                    cout << "INVALID enter \"1\" to confirm or \"2\" to redo: ";
                }
                getline(cin,userStay);
            }while(userStay!= "1" && userStay != "2");
        }
    }

    if(confirmation == "2"){
        if(userAction == "1"){title = newVal;}
        else if(userAction == "2"){desc = newVal;}
        else if(userAction == "3"){priority = newVal;}
        else if(userAction == "4"){dueDate = newVal;}
        else if(userAction == "5"){assignedDate = newVal;}
    }

    userData.push_back(title);
    userData.push_back(priority);
    userData.push_back(dueDate);
    userData.push_back(assignedDate);
    userData.push_back(desc);
    userData.push_back(userListChoice);
    
    userHome->createNewTask(userData);

    clearScreen();
}

void prompt::newListPrompt(Home* h) const { //WORKS//

    printLogos("newListPrompt");

    string listTitle = "", listDescription = "", confirmation = "";
    cout << endl << "           Input Information as prompted!           " << endl;
    cout << "====================================================" << endl;
    cout << "Enter List Title: ";
    getline(cin, listTitle);
    cout << "Enter Description: ";
    getline(cin, listDescription);

    int rev = 0;

    do{
        if(rev == 0){
            cout << "Enter \"1\" to confirm or \"2\" to redo: ";
            rev++;
        }
        else{
            cout << "INVALID enter \"1\" to confirm or \"2\" to redo: ";
        }
        getline(cin,confirmation);
        

    }while(confirmation != "1" && confirmation != "2");

    string userAction = "";
    string newVal = ""; //declaring outside so it doesnt delete out of scope//

    if(confirmation == "2"){
        
        string userStay = "2"; //to go into loop if user wants to keep redoing//
        
        while(userStay == "2"){
            cout << "1) Edit title" << endl;
            cout << "2) Edit description" << endl;
            cout << "Select an option (Enter corresponding numerical value): ";

            getline(cin,userAction);

            if(userAction != "1" && userAction != "2"){
                cout << "Select an action (1-2): ";
                getline(cin,userAction);
            }

                newVal = redo(userAction,h);

            int rev2 = 0;

            do{
                if(rev2 == 0){
                    cout << "Enter \"1\" to confirm or \"2\" to redo: ";
                    rev++;
                }
                else{
                    cout << "INVALID enter \"1\" to confirm or \"2\" to redo: ";
                }
                getline(cin,userStay);
            }while(userStay != "1" && userStay != "2");


        }
    }

    if(confirmation == "2"){
        if(userAction == "1"){
            listTitle = newVal;
            
        }
        else{
            listDescription = newVal;

        }
    }

    h->createNewList({listTitle,listDescription});
 
}

void prompt::taskEditorPrompt(Home* userHome, Task* userTask, TaskList* taskList){
    vector<string> userChanges;
    string targetTask = "", action = "", newVal = "";
    string choice = "";
    string toLeave = "";
    string confirmation = "";

    
    printLogos("taskEditorPrompt");
    
    printSeparator(55);
    cout << "Edit your task below!" << endl;

    cout << "1) Edit Title: " << userTask->getName() << endl; // Target task name
    cout << "2) Edit Priority: " << userTask->getPriority() << endl; // Target task priority
    cout << "3) Edit Due Date: " << userTask->getFullDueDate() << endl; // Target task FULL due date
    cout << "4) Edit Assigned Date: " << userTask->getFullAssignedDate() << endl; // Target task assigned date
    cout << "5) Edit Description: " << userTask->getDescription() << endl; // Target task description

    targetTask = userTask->getName();

    printSeparator(55);

    do {
        cout << "Select an option (Enter corresponding numerical value): ";
        getline(cin, choice);
    } while (choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5");

    displayHorizontalLine();

    if (choice == "1") {
        action = "Name";
        cout << "Enter the new name: ";
        getline(cin, newVal);

    } 
    else if (choice == "2") {
        action = "Priority";
        do {
            cout << "Enter the new priority (\"High\", \"Medium\", \"Low\"): "; // Check for valid priority
            getline(cin, newVal);
        } while (newVal != "High" && newVal != "Medium" && newVal != "Low" && newVal != "high" && newVal != "medium" && newVal != "low");

    } 

    else if (choice == "3") {
        action = "Full Due Date";

        do {
            cout << "Enter the new date (format mm/dd/yy): ";
            getline(cin, newVal);
        } while (newVal.size() != 8 || newVal[2] != '/' || newVal[5] != '/' || !isdigit(newVal[0]) || !isdigit(newVal[1]) || !isdigit(newVal[3]) || !isdigit(newVal[4]) || !isdigit(newVal[6]) || !isdigit(newVal[7]));

    } 

    else if (choice == "4") {
        action = "Full Assigned Date";

        do {
            cout << "Enter the new assigned date (format mm/dd/yy): ";
            getline(cin, newVal);
        } while (newVal.size() != 8 || newVal[2] != '/' || newVal[5] != '/' || !isdigit(newVal[0]) || !isdigit(newVal[1]) || !isdigit(newVal[3]) || !isdigit(newVal[4]) || !isdigit(newVal[6]) || !isdigit(newVal[7]));
    } 

    else if (choice == "5") {
        action = "Description";
        cout << "Enter the new description: ";
        getline(cin, newVal);
    }

    displayHorizontalLine();

    int rev = 0;

    do{ //confirm or redo//
        if(rev == 0){
            cout << "Enter \"1\" to confirm or \"2\" to redo: ";
            rev++;
        }
        else{
            cout << "INVALID enter \"1\" to confirm or \"2\" to redo: ";
        }
        getline(cin,confirmation);
        

    }while(confirmation != "1" && confirmation != "2");

    if(confirmation == "2"){
        string userStay = "2"; //to go into loop if user wants to keep redoing//
        
        
        while(userStay == "2"){
            cout << "1) Edit title" << endl;
            cout << "2) Edit priority" << endl;
            cout << "3) Edit due date" << endl;
            cout << "4) Edit assigned date" << endl;
            cout << "5) Edit description" << endl;

            cout << "Select an option (Enter corresponding numerical value): ";
            getline(cin,action);

            if(action != "1" && action != "2" && action != "3" && action != "4" && action != "5"){

                cout << "Select an action (1-5): ";
                getline(cin,action);
            }

            if(action == "1"){
                action = "Name";
            }

            else if(action == "5"){
                action = "Priority";
            }

            else if(action == "2"){
                action = "Full Due Date";
            }

            else if(action == "3"){
                action = "Full Assigned Date";
            }

            else{
                action = "Description";
            }


            newVal = redo(action,nullptr);
        
            int rev2 = 0;

            do{
                if(rev2 == 0){
                    cout << "Enter \"1\" to confirm or \"2\" to redo: ";
                    rev++;
                }
                else{
                    cout << "INVALID enter \"1\" to confirm or \"2\" to redo: ";
                }
                getline(cin,userStay);
            }while(userStay!= "1" && userStay != "2");
        }
    }

    taskList->editTask(targetTask, action, newVal);

    cout << "New " << action << ": " << newVal << endl;

    do{
        cout << "Type \"Task--\" to leave: ";
        getline(cin,toLeave);
    }while(toLeave != "Task--");

    clearScreen();

}

void printSeparator(int length) {
    for (int i = 0; i < length; ++i) {
        cout << "=";
    }
    cout << endl;
}

void prompt::listEditorPrompt(Home* h) {
    string choice = "";
    string action = "";
    string payload = "";
    string userList = "";
    string toLeave = "";
    string confirmation = "";

    printLogos("listEditorPrompt");
    
    displayHorizontalLine(50);

    h->viewLists();
    cout << "Select a list to edit: ";
    getline(cin,userList);

    while(h->findTaskList(userList) == nullptr){
        h->viewLists();
        cout << "Enter a valid list: ";
        getline(cin,userList);
    }

    cout << "Edit the List Below!" << endl;

    displayHorizontalLine(50); // Print a separator

    cout << "1) " << userList << endl;
    cout << "2) " << h->findTaskList(userList)->getListDescription() << endl;

    do {
        cout << "Enter \"1\" to edit your list name or \"2\" to edit your list description: ";
        getline(cin, choice);
    } while (choice != "1" && choice != "2");

    if (choice == "1") {
        action = "Title";
        cout << "Enter new Title: ";
        getline(cin, payload);
    } 
    else {
        action = "Description";
        cout << "Enter new description: ";
        getline(cin, payload);
    }


    int rev = 0;

    do{ //confirm or redo//
        if(rev == 0){
            cout << "Enter \"1\" to confirm or \"2\" to redo: ";
            rev++;
        }
        else{
            cout << "INVALID enter \"1\" to confirm or \"2\" to redo: ";
        }
        getline(cin,confirmation);
        

    }while(confirmation != "1" && confirmation != "2");

    if(confirmation == "2"){
        string userStay = "2"; //to go into loop if user wants to keep redoing//
        
        while(userStay == "2"){
            cout << "1) Edit title" << endl;
            cout << "2) Edit description" << endl;
            cout << "Select an option (Enter corresponding numerical value): ";

            getline(cin,action);

            if(action != "1" && action != "2"){
                cout << "Select an action (1-2): ";
                getline(cin,action);
            }

            if(action == "1"){
                action = "Name";
            }

            else if(action  == "2"){
                action = "Description";
            }
            

                payload = redo(action,h);

            int rev2 = 0;

            do{
                if(rev2 == 0){
                    cout << "Enter \"1\" to confirm or \"2\" to redo: ";
                    rev++;
                }
                else{
                    cout << "INVALID enter \"1\" to confirm or \"2\" to redo: ";
                }
                getline(cin,userStay);
            }while(userStay != "1" && userStay != "2");
        }
    }

    h->editList(userList,action,payload);

    cout << "New " << action << ": " << payload << endl;

    do{
        cout << "Type \"Task--\" to leave: ";
        getline(cin,toLeave);
    }while(toLeave != "Task--" && toLeave != "task--");

    
    
}


void prompt::viewWeekly(View* mainView, Home* userHome) {
    string choice = "";

    printLogos("viewWeekly");

    mainView->viewWeekly(*userHome);

    if(userHome->isEmpty()){
        return;
    }

    cout << "Would you like to select a task to edit? (Enter 'Yes' or 'No'): ";
    getline(cin, choice);

    while (choice != "yes" && choice != "Yes" && choice != "no" && choice != "No") {
        cout << "Enter a valid choice ('Yes' or 'No'): ";
        getline(cin, choice);
    }

    if (choice == "no" || choice == "No") {
        return;
    }

    string taskChoice = "";
    Task* tempTask = nullptr;
    TaskList* tempTaskList = nullptr;

    int rev = 0;

    
    while (tempTask == nullptr) {
        if (rev == 0){
            cout << "Select a task: ";
            rev++;
        } 
        else{
            cout << "Select a valid task: ";
        }

        getline(cin, taskChoice);

        if(userHome->findParentList(taskChoice) != nullptr){
            tempTaskList = userHome->findParentList(taskChoice);
            tempTask = tempTaskList->findTask(taskChoice);
        }
    }

        cout << endl;

        string userOption = "0";

        printSeparator(23); // Print a line separator
        cout << "   Edit Options" << endl;
        printSeparator(23); // Print a line separator

        cout << "1) Edit a task" << endl << endl;
        cout << "2) Delete a task" << endl << endl;
        cout << "3) Switch complete status " << endl << endl;
        cout << "4) Back out" << endl;

        printSeparator(23); // Print a line separator

        int rev2 = 0; // Counter for loop to choose output//

    do {
        if (rev2 == 0) {
            cout << "Select an option (Enter corresponding numerical value): ";
            rev2++;
        } 
        else {
            cout << "Select a valid option (Enter 1-4): ";
        }
        getline(cin, userOption);

        } while (userOption != "1" && userOption != "2" && userOption != "3" && userOption != "4");

    if (userOption == "4") {
        cout << "See ya!" << endl;
        return;
    } 

    else if (userOption == "3") {
        string status = "";
        if (tempTask->getCompleteStatus() == true) { // If task is already marked as complete//
           status = "uncomplete";
        }
        else{
            status = "complete";
        }

        tempTask->switchCompleteStatus();
        cout << "Task successfully switched to " << status << endl;
    } 
    else if (userOption == "2") {
        tempTaskList->removeTask(taskChoice);
        cout << "Task successfully deleted" << endl;
    } 
    else {
        clearScreen(); // Assuming this function clears the screen
        taskEditorPrompt(userHome, tempTask, tempTaskList);
    }

        tempTaskList = nullptr;
        tempTask = nullptr;
}

void prompt::viewPriority(View* mainView, Home* userHome){
    string userDifficulty = "";
    string choice = "";

    printLogos("viewPriority");

    cout << "Which priority tasks would you like to view (\"Completed\",\"Uncompleted\",\"All\"): ";
    getline(cin,userDifficulty);

    while(userDifficulty != "Completed" && userDifficulty != "Uncompleted" && userDifficulty != "All" && userDifficulty != "completed" && userDifficulty != "uncompleted" && userDifficulty!= "all"){
        cout << "Select ('Completed', 'Uncompleted', 'All'): ";
        getline(cin,userDifficulty);
    }

    mainView->viewPriority(*userHome,userDifficulty); //Uncompleted, Completed, All//

    if(userHome->isEmpty()){
        return;
    }
    
    cout << "Would you like to select a task to edit? ('Yes' or 'No'): ";
    getline(cin, choice);

    while (choice != "yes" && choice != "Yes" && choice != "no" && choice != "No") {
        cout << "Enter a valid choice ('Yes' or 'No'): ";
        getline(cin, choice);
    }

    if (choice == "no" || choice == "No") {
        cout << "See ya!" << endl;
        return;
    }

    cout << endl;

    string taskChoice = "";
    Task* tempTask = nullptr;
    TaskList* tempTaskList = nullptr;

    int rev = 0;

    while (tempTask == nullptr) {

        if (rev == 0) {
            cout << "Select a task: ";
            rev++;
        } 
        else {
            cout << "Select a valid task: ";
        }

        getline(cin, taskChoice);

        if (userHome->findParentList(taskChoice) != nullptr) {
            tempTaskList = userHome->findParentList(taskChoice);
            tempTask = tempTaskList->findTask(taskChoice);
        }
    }

    cout << endl;

    string userOption = "0";

    printSeparator(23); // Print a line separator
    cout << "   Edit Options" << endl;
    printSeparator(23); // Print a line separator

    cout << "1) Edit a task" << endl << endl;
    cout << "2) Delete a task" << endl << endl;
    cout << "3) Mark a task as complete" << endl << endl;
    cout << "4) Back out" << endl;

    printSeparator(23); // Print a line separator

    int rev2 = 0; // Counter for loop to choose output//

    do {
        if (rev2 == 0) {
            cout << "Select an option (Enter corresponding numerical value): ";
            rev2++;
        } 
        else {
            cout << "Select a valid option (Enter 1-4): ";
        }
        getline(cin, userOption);

    } while (userOption != "1" && userOption != "2" && userOption != "3" && userOption != "4");

    if (userOption == "4") {
        cout << "See ya!" << endl;
        return;
    } 
    else if (userOption == "3") {
        if (tempTask->getCompleteStatus() == true) { // If task is already marked as complete//
            cout << "Task is already complete" << endl;
            return;
        }

        tempTask->switchCompleteStatus();
        cout << "Task successfully marked as complete" << endl;
    } 
    else if (userOption == "2") {
        tempTaskList->removeTask(taskChoice);
        cout << "Task successfully deleted" << endl;
    } 
    else {
        clearScreen(); // Assuming this function clears the screen
        taskEditorPrompt(userHome, tempTask, tempTaskList);
    }

    tempTaskList = nullptr;
    tempTask = nullptr;
 
    //fill out with prompt
}

void prompt::viewOverall(View* mainView, Home* userHome){

    printLogos("viewOverall");

    mainView->viewOverall(*userHome);

    if(userHome->isEmpty()){
        return;
    }

    string choice = "";

   cout << "Would you like to select a task or list to edit? ('Yes' or 'No'): ";
    getline(cin, choice);

    while (choice != "yes" && choice != "Yes" && choice != "no" && choice != "No") {
        cout << "Enter a valid choice (Yes or No): ";
        getline(cin, choice);
    }

    if (choice == "no" || choice == "No") {
        cout << "See ya!" << endl;
        return;
    }

    cout << "Would you like to edit a task or list: (enter 'Task' or 'List'): ";

    getline(cin,choice);

    while(choice != "Task" && choice != "task" && choice != "List" && choice != "list"){
        cout << "INVALID enter ('Task' or 'List'): ";
        getline(cin,choice);
    }

    cout << endl;

    string taskChoice = "";
    Task* tempTask = nullptr;
    TaskList* tempTaskList = nullptr;

    int rev = 0;

    if(choice == "task" || choice == "Task"){
        while (tempTask == nullptr) {

            if (rev == 0) {
                cout << "Select a task: ";
                rev++;
            } 
            else {
                cout << "Select a valid task: ";
            }

            getline(cin, taskChoice);

            if (userHome->findParentList(taskChoice) != nullptr) {
                tempTaskList = userHome->findParentList(taskChoice);
                tempTask = tempTaskList->findTask(taskChoice);
            }
        }

        cout << endl;

        string userOption = "0";

        printSeparator(23); // Print a line separator
        cout << "   Edit Options" << endl;
        printSeparator(23); // Print a line separator

        cout << "1) Edit a task" << endl << endl;
        cout << "2) Delete a task" << endl << endl;
        cout << "3) Mark a task as complete" << endl << endl;
        cout << "4) Back out" << endl;

        printSeparator(23); // Print a line separator

        int rev2 = 0; // Counter for loop to choose output//

        do {
            if (rev2 == 0) {
                cout << "Select an option (Enter corresponding numerical value): ";
                rev2++;
            } 
            else {
                cout << "Select a valid option (Enter 1-4): ";
            }
            getline(cin, userOption);

        } while (userOption != "1" && userOption != "2" && userOption != "3" && userOption != "4");

        if (userOption == "4") {
            cout << "See ya!" << endl;
            return;
        } 

        else if (userOption == "3") {
            if (tempTask->getCompleteStatus() == true) { // If task is already marked as complete//
                cout << "Task is already complete" << endl;
                return;
            }

            tempTask->switchCompleteStatus();
            cout << "Task successfully marked as complete" << endl;
        } 
        else if (userOption == "2") {
            tempTaskList->removeTask(taskChoice);
            cout << "Task successfully deleted" << endl;
        } 
        else {
            clearScreen(); // Assuming this function clears the screen
            taskEditorPrompt(userHome, tempTask, tempTaskList);
        }
    }

    else{
        string userList = "";

        printSeparator(23); // Print a line separator
        cout << "   Edit List Options" << endl;
        printSeparator(23); // Print a line separator

        cout << "1) Edit a list" << endl << endl;
        cout << "2) Delete a list" << endl << endl;
        cout << "3) Back out" << endl;
        printSeparator(23); // Print a line separator
        
        cout << "Choose a option (1-3): ";
        getline(cin,choice);

        while(choice != "1" && choice != "2" && choice != "3"){
            cout << "INVALID enter (1-3): ";
            getline(cin,choice);
        }
        if (choice == "1"){
            listEditorPrompt(userHome);

        }

        else if(choice == "3"){
            cout << "See ya!" << endl;
        }
        else if(choice == "1"){
            listEditorPrompt(userHome);
            
        }
        
        else if(choice =="2"){
            userHome->viewLists();

            cout << "Enter a list to delete: ";
            getline(cin,userList);
            cout << endl;

            while(userHome->findTaskList(userList) == nullptr){
                userHome->viewLists();
                cout << "INVALID enter existing list: ";
                getline(cin,userList);
            }

            if(choice == "2"){
                userHome->deleteList(userList);
                cout << "List successfully deleted" << endl;
            }
        }
    }

    tempTaskList = nullptr;
    tempTask = nullptr;

}



void prompt::printLogos(const string& logoChoice) const{
    

    if(logoChoice == "printMainMenu"){
        cout << R"(
       ______           __                
      /_  __/___ ______/ /__     __    __ 
       / / / __ `/ ___/ //_/  __/ /___/ /_
      / / / /_/ (__  ) ,<    /_  __/_  __/
     /_/  \__,_/____/_/|_|    /_/   /_/   
)";
    cout << endl;
        

    }
    else if(logoChoice == "newTaskPrompt"){
        cout << R"(
         _   __                ______           __      
        / | / /__ _      __   /_  __/___ ______/ /__    
       /  |/ / _ \ | /| / /    / / / __ `/ ___/ //_/    
      / /|  /  __/ |/ |/ /    / / / /_/ (__  ) ,<       
     /_/ |_/\___/|__/|__/    /_/  \__,_/____/_/|_|     

========================================================)";
        

    }
    else if(logoChoice == "taskEditorPrompt"){
        cout << R"(
     ______           __      ______    ___ __            
    /_  __/___ ______/ /__   / ____/___/ (_) /_____  _____
     / / / __ `/ ___/ //_/  / __/ / __  / / __/ __ \/ ___/
    / / / /_/ (__  ) ,<    / /___/ /_/ / / /_/ /_/ / /    
   /_/  \__,_/____/_/|_|  /_____/\__,_/_/\__/\____/_/
                                                   
)";
    cout << endl;
                        
    }

    else if(logoChoice == "newListPrompt"){
        cout << R"(
         _   __                __    _      __ 
        / | / /__ _      __   / /   (_)____/ /_
       /  |/ / _ \ | /| / /  / /   / / ___/ __/
      / /|  /  __/ |/ |/ /  / /___/ (__  ) /_  
     /_/ |_/\___/|__/|__/  /_____/_/____/\__/  

====================================================)";
        

    }
    else if(logoChoice == "taskEditorPrompt"){
        cout << R"(
     ______           __      ______    ___ __            
    /_  __/___ ______/ /__   / ____/___/ (_) /_____  _____
     / / / __ `/ ___/ //_/  / __/ / __  / / __/ __ \/ ___/
    / / / /_/ (__  ) ,<    / /___/ /_/ / / /_/ /_/ / /    
   /_/  \__,_/____/_/|_|  /_____/\__,_/_/\__/\____/_/     
        )";
    cout << endl;
        

    }
    else if(logoChoice == "listEditorPrompt"){
        cout << R"(
        __    _      __     ______    ___ __            
       / /   (_)____/ /_   / ____/___/ (_) /_____  _____
      / /   / / ___/ __/  / __/ / __  / / __/ __ \/ ___/
     / /___/ (__  ) /_   / /___/ /_/ / / /_/ /_/ / /    
    /_____/_/____/\__/  /_____/\__,_/_/\__/\____/_/     
    )";
        

    }
    else if(logoChoice == "viewWeekly"){
        cout << R"(
     _    ___                 _       __          __   __     
    | |  / (_)__ _      __   | |     / /__  ___  / /__/ /_  __
    | | / / / _ \ | /| / /   | | /| / / _ \/ _ \/ //_/ / / / /
    | |/ / /  __/ |/ |/ /    | |/ |/ /  __/  __/ ,< / / /_/ / 
    |___/_/\___/|__/|__/     |__/|__/\___/\___/_/|_/_/\__, /  
                                                     /____/   
    )";
        


    }
    else if(logoChoice == "viewPriority"){
        cout << R"(
    _    ___                 ____       _            _ __       
    | |  / (_)__ _      __   / __ \_____(_)___  _____(_) /___  __
    | | / / / _ \ | /| / /  / /_/ / ___/ / __ \/ ___/ / __/ / / /
    | |/ / /  __/ |/ |/ /  / ____/ /  / / /_/ / /  / / /_/ /_/ / 
    |___/_/\___/|__/|__/  /_/   /_/  /_/\____/_/  /_/\__/\__, /  
                                                        /____/   
    )";


    }
    else if(logoChoice == "viewOverall"){
        cout << R"(
     _    ___                 ____                        ____
    | |  / (_)__ _      __   / __ \_   _____  _________ _/ / /
    | | / / / _ \ | /| / /  / / / / | / / _ \/ ___/ __ `/ / / 
    | |/ / /  __/ |/ |/ /  / /_/ /| |/ /  __/ /  / /_/ / / /  
    |___/_/\___/|__/|__/   \____/ |___/\___/_/   \__,_/_/_/   
                                                          
    )";

    }
    else{
        

    }

}


