//                                           User signed in successfully ;)llllll
#include <iostream>
using namespace std;
int n; // VARIABLES
const int MAX_PRO = 50;
const int MAX_USERS = 50;

string proID[MAX_PRO];
string proName[MAX_PRO];
float proprice[MAX_PRO];
int proQuantity[MAX_PRO];

string Usernames[MAX_USERS];
string Passwords[MAX_USERS];
string userUsernames[MAX_USERS];
string userPasswords[MAX_USERS];


int proCount = 0;
int employeeCount = 0;
int userCount = 0;

bool checkpassword(string password); // FUNCTION HEADERS
bool checkusername(string username);
void adminmenu();
void updateProduct();
void deleteProduct();
void userSignup();
bool userLogin();
void viewProduct();
void signup();
bool login(string username, string password);
void searchProduct();
void addProduct();
void bill();
void userMenu();
void menu();

int main()
{
    menu();
   return 0;
}
// ----------------------------------------------------------------

//  ADMIN SIGNUP ANG SIGN IN 
void signup()

{
    string username, password;
    string confirmPassword;

    if (userCount >= MAX_USERS)
    {
        cout << "\nCannot add more users (Limit Reached)...";
        return;
    }

    bool flag = false;
    while (!flag)
    {
        cout << "\nEnter Username: ";
        cin >> username;
        if (!checkusername(username))
        {
            cout << "Invalid Username. try again.." << endl;
            cout << "  (First Letter Must be Capital)" << endl;
            continue;
        }
        bool exists = false;
        for (int i = 0; i < userCount; i++)
        {
            if (Usernames[i] == username)
            {
                exists = true;
                break;
            }
        }
        if (exists)
        {
            cout << "Username already exists. Pleease choose another.\n";
        }
        else
        {
            flag = true; // username valid + unique
        }
    }

    flag = false;
    while (!flag)

    {
        cout << "\nEnter Password: ";
        cin >> password;

        if (checkpassword(password))
        {
            flag = true;
        }

        else
        {
            cout << "\nInvalid Password." << endl;
            cout << "Password Should Have special Characters" << endl;
        }
    }

    flag = false;
    while (!flag)

    {
        cout << "\nconfirm Password: ";
        cin >> confirmPassword;

        if (password == confirmPassword)
        {
            cout << " Signed up successfully";
            flag = true;
        }
        else
        {
            cout << "Password is not same :(" << endl;
        }
    }
    Usernames[userCount] = username;
    Passwords[userCount] = password;
    userCount++;
}
// END OF SIGN UP FUNCTION

// -----------------------------------------------------------------

bool login(string username, string password) // LOGIN FUNCTION
{
    bool isFound = false;
    string username2, password2;
    int idx = -1;

    if (userCount == 0)
    {
        cout << "\nNo admin found! You need to Sign up first.\n";
        return false;
    }
    cout << "\n\n\n \t\t\t  ============================================================== \n   ";
    cout << "       \t\t\t\t       LOG IN PAGE FOR ADMIN                      ";
    cout << " \n\t\t\t  ==============================================================" << endl;

    while (true)
    {
        cout << "\nEnter Username: ";
        cin >> username2;

        cout << "\nEnter Password: ";
        cin >> password2;

        // idx = -1;

        for (int i = 0; i < userCount; i++)
        {
            if (Usernames[i] == username2 && password2 == Passwords[i])
            {
                return true;
                cout << "\n   ====================================== \n   | \t  Admin Logged in Successfully.       |\n   ======================================";

                return true;
            }
        }
        cout << "\nInvalid Username or Password!\n";
        return false;
    }
}

// ----------------------------------------------------------------

// USRE/ EMPLOYEE SIGN UP AND SIGN IN
void userSignup()
{
    string username, password;
    string confirmPassword;

    if (userCount >= MAX_USERS)
    {
        cout << "\nCannot add more users (Limit Reached)...";
        return;
    }

    bool flag = false;
    while (!flag)
    {
        cout << "\nEnter Username: ";
        cin >> username;
        if (!checkusername(username))
        {
            cout << "Invalid Username. try again.." << endl;
            cout << "  (First Letter Must be Capital)" << endl;
            continue;
        }
        bool exists = false;
        for (int i = 0; i < userCount; i++)
        {
            if (userUsernames[i] == username)
            {
                exists = true;
                break;
            }
        }
        if (exists)
        {
            cout << "Username already exists. Pleease choose another.\n";
        }
        else
        {
            flag = true; // username valid + unique
        }
    }

    flag = false;
    while (!flag)

    {
        cout << "\nEnter Password: ";
        cin >> password;

        if (checkpassword(password))
        {
            flag = true;
        }

        else
        {
            cout << "\nInvalid Password." << endl;
            cout << "Password Should Have special Characters" << endl;
        }
    }

    flag = false;
    while (!flag)

    {
        cout << "\nconfirm Password: ";
        cin >> confirmPassword;

        if (password == confirmPassword)
        {
            cout << " Signed up successfully";
            flag = true;
        }
        else
        {
            cout << "Password is not same :(" << endl;
        }
    }
    userUsernames[userCount] = username;
    userPasswords[userCount] = password;
    userCount++;
}

// ----------------------------------------------------------------

bool userLogin()
{
    // ***** CASE 1: NO USER ACCOUNT *****
    if (userCount == 0)
    {
        cout << "\nNo user found! You need to Sign up first.\n";
        return false;
    }

    string u, p;
    int idx = -1;

    cout << "\n\n\n \t\t\t  ============================================================== \n   ";
    cout << "       \t\t\t\t        LOG IN PAGE FOR USER                      ";
    cout << " \n\t\t\t  ==============================================================" << endl;

    // ***** USERNAME CHECK *****
    cout << "\nEnter Username: ";
    cin >> u;

    for (int i = 0; i < userCount; i++)
    {
        if (userUsernames[i] == u)
        {
            idx = i;
            break;
        }
    }

    if (idx == -1)
    {
        cout << "\nIncorrect Username.\n";
        return false;
    }

    while (true)
    {
        cout << "Enter Password: ";
        cin >> p;

        if (p == userPasswords[idx])
        {
            cout << "\nUser Logged in Successfully!\n";
            return true;
        }
        else
        {
            cout << "Password does not match! Try again...\n";
        }
    }
}

// ----------------------------------------------------------------

void menu()
{
    string username, password;

    int choice;

    /*
    string role;
    cout<<"enter role (admin or user): ";
    cin>> role;
     if (role== admin){
         cout << "\n\n1. Sign up as ADMIN " << endl;
         cout << "2. Login as Admin" << endl;
         cout << "3. Exit" << endl;
     }

     else {
     }
         */
    while (true)
    {

        cout << "\n\n1. Sign up as User" << endl;
        cout << "2. Login as User" << endl;
         cout << "3. Sign up as Admin" << endl;
        cout << "4. Login as Admin" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            userSignup();
        }
        else if (choice == 2)
        {
            if (userLogin())
            {
                userMenu();
            }
        }

  if (choice == 3)
        {
            signup();
        }
        else if (choice == 4)
        {
            if (login(username, password))
            {
                adminmenu();
            }
        }


        else if (choice ==5)
        {
            cout << "Program Exited." << endl;
             break;   
        }
        else
        {
            cout << "Invalid choice, try again!" << endl;
        }
    }
}

// ----------------------------------------------------------------

void userMenu()
{
    int choice = 0;
    while (choice != 6)
    {
        cout << "\n------ USER MENU ------\n";
        cout << "1. Add Product\n";
        cout << "2. Search Product\n";
        cout << "3. View Product\n";
        cout << "4. Calculate Bill\n";
        cout << "5. Logout\n";
        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {
            addProduct();
        }
        else if (choice == 2)
        {
            searchProduct();
        }
        else if (choice == 3)
        {
            viewProduct();
        }
        else if (choice == 4)
        {
            bill();
        }
        else if (choice == 5)
        {
            cout << "\nLogging out...\n";
            break;
        }
        else
        {
            cout << "\nInvalid Choice!\n";
        }
    }
}

// ----------------------------------------------------------------

void adminmenu() // MAIN MENU FOR ADMIN FUNCTION
{
    int choice = 0;

    while (choice != 9)
    {
          cout << "\n|--------------WELCOME ADMIN--------------|" << endl;
        cout << "" << endl;
        cout << "1. Add New Product" << endl;
        cout << "2. View Product" << endl;
        cout << "3. Search Product" << endl;
        cout << "4. Update Product" << endl;
        cout << "5. Delete Product" << endl;
        cout << "6. Add Employee" << endl;
        cout << "7. View Employee" << endl;
        cout << "8. Exit\n";
        cout << "Enter your choice: " << endl;
        cin >> choice;

        if (choice == 1)
        {
            addProduct();
        }
        else if (choice == 2)
        {
            viewProduct();
        }
        else if (choice == 3)
        {
            searchProduct();
        }
        else if (choice == 4)
        {
            updateProduct();
        }
        else if (choice == 5)
        {
            deleteProduct();
        }
        else if (choice == 6)
        {
            // addemployee function to be added
            break;
        }
        else if (choice == 7)
        {
           // view employee function to be added
            break;
        }
                else if (choice == 8)
        {
            cout << "Program Exited." << endl;
            break;
        }
        else
        {
            cout << "Invalid choice, try again!" << endl;
            menu();
        }
    }
}

// ----------------------------------------------------------------

void searchProduct() // FUNCTION TO search Product
{
    if (proCount == 0)
    {
        cout << "RECORD NOT FOUND :(" << endl;
        return;
    }
    bool found = false;
    string id;
    cout << "Enter Product ID to search: ";
    cin >> id;
    for (int i = 0; i < proCount; i++)
    {
        if (proID[i] == id)
        {
            found = true;
            cout << "Product Found:" << endl;
            cout << "ID: " << proID[i] << endl;
            cout << "Name: " << proName[i] << endl;
            cout << "Price: " << proprice[i] << endl;
             cout << "Quantity: " << proQuantity[i] << endl;
        }
    }
    if (!found)
    {
        cout << "No Product with ID " << id << " Found :(" << endl;
    }
    int temp;
    cout << "Enter any number to return to main menu: ";
    cin >> temp;
    cout << "____________________________________" << endl;
}

// --------------------------------------------------------------

void bill() // FUNCTION TO CALCULATE BILL
{
    float total = 0;
    int qty[MAX_PRO];
    float finalPrice[MAX_PRO];

    
    if (proCount == 0)
    {
        cout << "RECORD NOT FOUND :(" << endl;
        return;
    }
    for (int i = 0; i < proCount; i++)
    {
         cout << "\n\n\n \t\t\t  ============================================================== \n   ";
    cout << "       \t\t\t\t                BILL                             ";
    cout << " \n\t\t\t  ==============================================================" << endl;
        cout << "Product ID = " << proID[i]<< endl;
        cout << "Price of " <<proName[i] << " = " << proprice[i] << " rs" << endl;
        cout << "Available Quantity"  << " = " << proQuantity[i] << endl;

        cout << "Enter the quantity of " <<proName [i] << " : " << endl;
        cin >> qty[i];
        
        finalPrice[i] = qty[i] * proprice[i];
    }

    for (int i = 0; i < proCount; i++)
    {
        total = total + finalPrice[i];
    }
    cout << endl
         << "Total Bill: " << total << " rs" << endl;
    int temp;
    cout << endl
         << "Enter any number to return to main menu: ";
    cin >> temp;
    cout << "____________________________________" << endl;
}

// ----------------------------------------------------------------

void addProduct() // FUNCTION TO ADD PRODUCT
{
    cout << "How many Products you want to Enter: ";
    cin >> n;
    if (n > MAX_PRO)
    {
        cout << "Cannot Add More Than 50 Products, TRY AGAIN!";
    }

    for (int i = 0; i < n; i++)
    {
        cout << "Product " << i + 1 << endl;
        cout << "Enter Product ID: ";
        cin >> proID[proCount];

        cout << "Enter product name: ";
        cin >> proName[proCount];

        cout << "Enter product price: ";
        cin >> proprice[proCount];
    
         cout << "Enter product quantity: ";
        cin >> proQuantity[proCount];
        cout << endl;

        proCount++;
        cout << "PRODUCTS ADDED SUCCESSFULLY :)" << endl;
        cout << "            __________________________" << endl;
    }
    int temp;
    cout << "Enter any number to return to main menu: ";
    cin >> temp;
    cout << "____________________________________" << endl;
}

// -----------------------------------------------------------------

void viewProduct() // FUNCTION TO VIEW PRODUCT
{
    if (proCount == 0)
    {
        cout << "RECORD NOT FOUND :(" << endl;
        return;
    }
    cout << "\n\n\n \t\t\t  ============================================================== \n   ";
    cout << "       \t\t\t\t            PRODUCT LIST                          ";
    cout << " \n\t\t\t  ==============================================================" << endl;
    cout << "Total products: " << proCount << endl;

    for (int i = 0; i < proCount; i++)
    {
        cout << "Product " << i + 1 << ":";
        cout << "ID: " << proID[i] << endl;
        cout << "Name: " << proName[i] << endl;
        cout << "Price: " << proprice[i] << endl;
        cout << "Quantity: " << proQuantity[i] << endl;
        cout << endl;
    }
    int temp;
    cout << "Enter any number to return to main menu: ";
    cin >> temp;
    cout << "____________________________________" << endl;
}

// ----------------------------------------------------------------

void updateProduct() // FUNCTION TO update Product
{
    if (proCount == 0)
    {
        cout << "RECORD NOT FOUND :(" << endl;
        return;
    }
    string id;
    cout << "Enter Product ID to update: ";
    cin >> id;
    bool found = false;

    for (int i = 0; i < proCount; i++)
    {
        if (proID[i] == id)
        {
            found = true;
            cout << "\nProduct Found" << endl;
            cout << "Current name: " << proName[i] << endl;
            cout << "Current price: " << proprice[i];
            cout << endl;
            cout << "Enter new name: ";
            cin >> proName[i];
            cout << "Enter new Price: ";
            cin >> proprice[i];

            cout << endl
                 << "UPDATED SUCCESSFULLY :)";
        }
    }
    if (!found)
    {
        cout << "No Product with ID " << id << " found :(" << endl;
    }
    int temp;
    cout << "Enter any number to return to main menu: ";
    cin >> temp;
    cout << "____________________________________" << endl;
}

// -----------------------------------------------------------------

void deleteProduct() // FUNCTION TO delete Product
{
    if (proCount == 0)
    {
        cout << "RECORD NOT FOUND :(" << endl;
        return;
    }
    string id;
    cout << "Enter Product ID to Delete: ";
    cin >> id;

    bool found = false;
    for (int i = 0; i < proCount; i++)
    {
        if (proID[i] == id)
        {
            found = true;

            for (int j = i; j < proCount - 1; j++)
            {
                proID[j] = proID[j + 1];
                proName[j] = proName[j + 1];
                proprice[j] = proprice[j + 1];
            }

            proCount--;

            cout << endl
                 << "PRODUCT DELETED SUCCESSFULLY :)" << endl;
        }
    }
    if (!found)
    {
        cout << "RECORD NOT FOUND :(" << endl;
    }
    int temp;
    cout << "Enter any number to return to main menu: ";
    cin >> temp;
    cout << "____________________________________" << endl;
}
// ------------------------------------------------------------------------


bool checkusername(string username) // FUNCTION TO CHECK FIRST LETTER IS CAPITAL OR NOT
{
    int i = 0;
    bool isFound = false;
    for (int i = 0; i < 1; i++)
    {
        if (username[i] >= 'A' && username[i] <= 'Z')
        {
            isFound = true;
        }
    }
    return isFound;
}
// -----------------------------------------------------------------

// FUNCTION TO CHECK PASSWORD INCLUDES SPECIAL CHARACTER
bool checkpassword(string password)
{
    bool isFound = false;
    for (int i = 0; password[i] != '\0'; i++)
    {
        if ((password[i] >= '!' && password[i] <= '/') || (password[i] >= ':' && password[i] <= '@') || (password[i] >= '[' && password[i] <= '`') || (password[i] >= '{' && password[i] <= '~'))
        {
            return true;
        }
    }
    return false;
}
// ----------------------------------------------------------------