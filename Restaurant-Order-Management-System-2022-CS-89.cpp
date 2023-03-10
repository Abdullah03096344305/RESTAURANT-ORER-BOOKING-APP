#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <sstream>
#include <time.h>

using namespace std;

void gotoxy(int x, int y);

int idx = 0;
int index = 0;

void topheader();
void time();
string getField(string record, int field);

int showAdminMenu(int opt);
int showUserMenu(int option);

// FUNCTIONS HEADER
void pizzaHeader();
void burgerHeader();
void shawarmaHeader();
void dealHeader();
void drinkHeader();

// function regarding drinks
void displayDrinkOutput(int index);
void readDrinkData();
int DrinkMenu(int drinkchoice, int drinkQuantity);
int calculateDrinkPrice(int drinkchoice, int drinkQuantity);

// function regarding deals
void displayDealOutput(int index);
void readDealData();
int DealMenu(int dealchoice, int dealQuantity);
int calculateDealPrice(int dealchoice, int dealQuantity);

// function regarding shawarmas
void displayShawarmaOutput(int index);
void readShawarmaData();
int ShawarmaMenu(int shawarmachoice, int shawarmaQuantity);
int calculateShawarmaPrice(int shawarmachoice, int shawarmaQuantity);

// function regarding pizza
void displayPizzaOutput(int index);
void readPizzaData();
int pizzaMenu(int pizzachoice, int pizzaQuantity);
int calculatePizzaPrice(int pizzachoice, int pizzaQuantity);

// function regarding burgers
void displayBurgerOutput(int index);
void readBurgerData();
int BurgerMenu(int burgerchoice, int burgerQuantity);
int calculateBurgerPrice(int burgerchoice, int burgerQuantity);

// global arrays

string burger[30];
int burgerprice[30];

string pizza[30];
int pizzaprice[30];

string drinks[30];
int drinksprice[30];

string shawarma[30];
int shawarmaprice[30];

string deals[30];
int dealprice[30];

int psize = sizeof(pizza) / sizeof(pizzaprice);
int bsize = sizeof(burger) / sizeof(burgerprice);
int dsize = sizeof(drinks) / sizeof(drinksprice);
int ssize = sizeof(shawarma) / sizeof(shawarmaprice);
int lsize = sizeof(deals) / sizeof(dealprice);

// global  declared  variables
int dealTotal = 0;
int drinkTotal = 0;
int shawarmaTotal = 0;
int pizzaTotal = 0;
int burgerTotal = 0;

int dealcount = 0;
int burgercount = 0;
int pizzacount = 0;
int shawarmacount = 0;
int drinkcount = 0;

int pizzachoice, pizzaQuantity;
int drinkchoice, drinkQuantity;
int shawarmachoice, shawarmaQuantity;
int dealchoice, dealQuantity;
int burgerchoice, burgerQuantity;

void DeliveryCalculator(int total);

string usernames[100];
string passwords[100];
string AdminUsername;
int AdminPassword;
string ActualAdmin = "Abdullah";
int ActualPassword = 12345;
int usercount = 0;

void addBurger(string comma);
void DeleteBurger(string comma);

void addPizza(string comma);
void DeletePizza(string comma);

void addShawarma(string comma);
void DeleteShawarma(string comma);

void addDrink(string comma);
void DeleteDrink(string comma);

void addDeal(string comma);
void DeleteDeal(string comma);

void AddBurgerToFile(string comma);
void AddPizzaToFile(string comma);
void AddShawarmaToFile(string comma);
void AddDrinkToFile(string comma);
void AddDealToFile(string comma);

void SignUp(string username, string password);
bool SignIn(string username, string password);
void displayUser();
void StoreTofile(string username, string password);
bool isValidUsername(string username);
void adduser(string username, string password);
int takechoice();
void loaddatafromfile();

int validation(int number);
void PrintAllProducts(string comma);

main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 113);
    string comma = ",";
    readBurgerData();
    readShawarmaData();
    readPizzaData();
    readDealData();
    readDrinkData();
    int pTotal = 0;
    int bTotal = 0;
    int sTotal = 0;
    int dTotal = 0;
    int lTotal = 0;

    int total, op, opt, option;

    string username;
    string password;

    loaddatafromfile();
    bool descision;

    int choice = 3;

    while (choice != 0)
    {

        choice = takechoice();
        if (choice == 1)
        {
            system("cls");
            topheader();
            cout << "ENTER USERNAME: ";
            cin >> username;
            cout << "ENTER PASSWORD: ";
            cin >> password;
            descision = isValidUsername(username);
            if (descision == true)
            {
                adduser(username, password);
                StoreTofile(username, password);
                cout << "USER CREATED SUCCESFULLY" << endl;
                getch();
            }
            else
            {
                cout << "USERNAME ALREADY EXIST !!!" << endl;
                getch();
            }
        }
        else if (choice == 2)
        {
            system("cls");
            topheader();
            cout << "ENTER USERNAME: ";
            cin >> username;
            cout << "ENTER PASSWORD: ";
            cin >> password;
            descision = SignIn(username, password);
            if (descision == true)
            {
                system("cls");
                topheader();
                cout << endl;
                cout << "LOGIN SUCCESFULLY" << endl;
                cout << endl;
                cout << "    press   1      if you are Manager " << endl;
                cout << endl;
                cout << "    Press   2      if you want to Place Order Online " << endl;
                cout << endl;
                cout << "    Press   3      if you want to Exit                " << endl;
                cin >> op;
                cout << endl;
                while (op != 3)
                {
                    if (cin.fail())
                    {
                        cout << "Enter only an integer please." << endl;
                    }
                    while (cin.fail())
                    {
                        cin.clear();
                        cin.ignore();
                        cin >> op;
                    }
                    if (op == 1)
                    {
                        cout << "Enter Manager Username: ";
                        cin >> AdminUsername;
                        cout << "Enter Manager Password:";
                        cin >> AdminPassword;
                        if (AdminUsername == ActualAdmin && AdminPassword == ActualPassword)
                        {

                            opt = showAdminMenu(opt);

                            if (opt == 1)
                            {
                                addBurger(comma);
                                AddBurgerToFile(comma);
                            }
                            else if (opt == 2)
                            {
                                DeleteBurger(comma);
                                AddBurgerToFile(comma);
                            }
                            else if (opt == 3)
                            {
                                addPizza(comma);
                                AddPizzaToFile(comma);
                            }
                            else if (opt == 4)
                            {
                                DeletePizza(comma);
                                AddPizzaToFile(comma);
                            }
                            else if (opt == 5)
                            {
                                addShawarma(comma);
                                AddShawarmaToFile(comma);
                            }
                            else if (opt == 6)
                            {
                                DeleteShawarma(comma);
                                AddShawarmaToFile(comma);
                            }
                            else if (opt == 7)
                            {
                                addDeal(comma);
                                AddDealToFile(comma);
                            }
                            else if (opt == 8)
                            {
                                DeleteDeal(comma);
                                AddDealToFile(comma);
                            }
                            else if (opt == 9)
                            {
                                addDrink(comma);
                                AddDrinkToFile(comma);
                            }
                            else if (opt == 10)
                            {
                                DeleteDrink(comma);
                                AddDrinkToFile(comma);
                            }
                            else if (opt == 11)
                            {
                                system("cls");
                                topheader();
                                PrintAllProducts(comma);
                            }
                            else if (opt == 12)
                            {
                                break;
                            }
                        }
                        else
                            cout << "Error! You are not an Admin" << endl;
                    }
                    else if (op == 2)
                    {
                        option = showUserMenu(option);

                        if (option == 1)
                        {
                            system("cls");
                            pizzaHeader();
                            pTotal = pizzaMenu(pizzachoice, pizzaQuantity);
                        }
                        else if (option == 2)
                        {
                            system("cls");
                            burgerHeader();
                            cout << endl;
                            bTotal = BurgerMenu(burgerchoice, burgerQuantity);
                        }
                        else if (option == 3)
                        {
                            system("cls");
                            drinkHeader();
                            cout << endl;

                            cout << endl;
                            dTotal = DrinkMenu(drinkchoice, drinkQuantity);
                        }
                        else if (option == 4)
                        {
                            system("cls");
                            shawarmaHeader();

                            cout << endl;

                            sTotal = ShawarmaMenu(shawarmachoice, shawarmaQuantity);
                        }
                        else if (option == 5)
                        {
                            system("cls");
                            dealHeader();
                            cout << endl;
                            lTotal = DealMenu(dealchoice, dealQuantity);
                        }
                        else if (option == 6)
                        {
                            system("cls");
                            topheader();

                            total = pTotal + bTotal + dTotal + sTotal + lTotal;
                            if (total > 1)
                            {
                                cout << "                     YOUR TOTAL PAYABLE AMOUNT IS " << total << endl;
                            }

                            if (total < 1)
                            {
                                cout << endl;
                                cout << " THERE IS NO TOTAL AMOUNT " << endl;
                                cout << endl;
                                cout << " PLEASE PURCHASE SOMETHING FIRST" << endl;
                            }

                            getch();
                        }
                        else if (option == 7)
                        {
                            system("cls");
                            topheader();
                            DeliveryCalculator(total);
                            getch();
                        }
                        else if (option == 8)
                        {
                            system("cls");
                            topheader();
                            cout << endl;
                            cout << "About Us" << endl;
                            cout << endl;
                            cout << "We know how it feels when one craves their local food thousands of miles away.\n\nSo being Pakistani, we wanted to bring the  taste from the food hub around the world.\n\nTherefore, to make your meals unforgettable, our chef travelled all the way to Lahore\n\n to soak in the culture and the touch of simplicity that it takes to make the customary cuisines and its one-of-a-kind street food.\n\nEnriched Ambiance straight from the Around the world. We make sure to provide our customers with a desi aura to\n\n feed them and their Instagram! So come and savor your experience with us." << endl;
                            getch();
                        }
                        else if (option == 9)
                        {
                            break;
                        }
                    }
                }
            }
            else
            {
                cout << "INVALID INPUT PLEASE TRY AGAIN !! " << endl;
                getch();
            }
        }
        else if (choice == 3)
        {
            displayUser();
        }
    }
}

void pizzaHeader()
{
    cout << endl;
    cout << "PPPPPPPPPPPPPPPPP        IIIIIIIIII     ZZZZZZZZZZZZZZZZZZZ     ZZZZZZZZZZZZZZZZZZZ                    AAA                " << endl;
    cout << "P::::::::::::::::P       I::::::::I     Z:::::::::::::::::Z     Z:::::::::::::::::Z                   A:::A               " << endl;
    cout << "P::::::PPPPPP:::::P      I::::::::I     Z:::::::::::::::::Z     Z:::::::::::::::::Z                  A:::::A              " << endl;
    cout << "PP:::::P     P:::::P     II::::::II     Z:::ZZZZZZZZ:::::Z      Z:::ZZZZZZZZ:::::Z                  A:::::::A             " << endl;
    cout << "  P::::P     P:::::P       I::::I       ZZZZZ     Z:::::Z       ZZZZZ     Z:::::Z                  A:::::::::A            " << endl;
    cout << "  P::::P     P:::::P       I::::I               Z:::::Z                 Z:::::Z                   A:::::A:::::A           " << endl;
    cout << "  P::::PPPPPP:::::P        I::::I              Z:::::Z                 Z:::::Z                   A:::::A A:::::A          " << endl;
    cout << "  P:::::::::::::PP         I::::I             Z:::::Z                 Z:::::Z                   A:::::A   A:::::A         " << endl;
    cout << "  P::::PPPPPPPPP           I::::I            Z:::::Z                 Z:::::Z                   A:::::A     A:::::A        " << endl;
    cout << "  P::::P                   I::::I           Z:::::Z                 Z:::::Z                   A:::::AAAAAAAAA:::::A       " << endl;
    cout << "  P::::P                   I::::I          Z:::::Z                 Z:::::Z                   A:::::::::::::::::::::A      " << endl;
    cout << "  P::::P                   I::::I       ZZZ:::::Z     ZZZZZ     ZZZ:::::Z     ZZZZZ         A:::::AAAAAAAAAAAAA:::::A     " << endl;
    cout << "PP::::::PP               II::::::II     Z::::::ZZZZZZZZ:::Z     Z::::::ZZZZZZZZ:::Z        A:::::A             A:::::A    " << endl;
    cout << "P::::::::P               I::::::::I     Z:::::::::::::::::Z     Z:::::::::::::::::Z       A:::::A               A:::::A   " << endl;
    cout << "P::::::::P               I::::::::I     Z:::::::::::::::::Z     Z:::::::::::::::::Z      A:::::A                 A:::::A  " << endl;
    cout << "PPPPPPPPPP               IIIIIIIIII     ZZZZZZZZZZZZZZZZZZZ     ZZZZZZZZZZZZZZZZZZZ     AAAAAAA                   AAAAAAA " << endl;
    cout << endl;
}

void burgerHeader()
{
    cout << endl;
    cout << " BBBBBBBBBBBBBBBBB        UUUUUUUU     UUUUUUUU     RRRRRRRRRRRRRRRRR                GGGGGGGGGGGGG     EEEEEEEEEEEEEEEEEEEEEE     RRRRRRRRRRRRRRRRR    " << endl;
    cout << " B::::::::::::::::B       U::::::U     U::::::U     R::::::::::::::::R            GGG::::::::::::G     E::::::::::::::::::::E     R::::::::::::::::R   " << endl;
    cout << " B::::::BBBBBB:::::B      U::::::U     U::::::U     R::::::RRRRRR:::::R         GG:::::::::::::::G     E::::::::::::::::::::E     R::::::RRRRRR:::::R  " << endl;
    cout << " BB:::::B     B:::::B     UU:::::U     U:::::UU     RR:::::R     R:::::R       G:::::GGGGGGGG::::G     EE::::::EEEEEEEEE::::E     RR:::::R     R:::::R " << endl;
    cout << "   B::::B     B:::::B      U:::::U     U:::::U        R::::R     R:::::R      G:::::G       GGGGGG       E:::::E       EEEEEE       R::::R     R:::::R " << endl;
    cout << "   B::::B     B:::::B      U:::::D     D:::::U        R::::R     R:::::R     G:::::G                     E:::::E                    R::::R     R:::::R " << endl;
    cout << "   B::::BBBBBB:::::B       U:::::D     D:::::U        R::::RRRRRR:::::R      G:::::G                     E::::::EEEEEEEEEE          R::::RRRRRR:::::R  " << endl;
    cout << "   B:::::::::::::BB        U:::::D     D:::::U        R:::::::::::::RR       G:::::G    GGGGGGGGGG       E:::::::::::::::E          R:::::::::::::RR   " << endl;
    cout << "   B::::BBBBBB:::::B       U:::::D     D:::::U        R::::RRRRRR:::::R      G:::::G    G::::::::G       E:::::::::::::::E          R::::RRRRRR:::::R  " << endl;
    cout << "   B::::B     B:::::B      U:::::D     D:::::U        R::::R     R:::::R     G:::::G    GGGGG::::G       E::::::EEEEEEEEEE          R::::R     R:::::R " << endl;
    cout << "   B::::B     B:::::B      U:::::D     D:::::U        R::::R     R:::::R     G:::::G        G::::G       E:::::E                    R::::R     R:::::R " << endl;
    cout << "   B::::B     B:::::B      U::::::U   U::::::U        R::::R     R:::::R      G:::::G       G::::G       E:::::E       EEEEEE       R::::R     R:::::R " << endl;
    cout << " BB:::::BBBBBB::::::B      U:::::::UUU:::::::U      RR:::::R     R:::::R       G:::::GGGGGGGG::::G     EE::::::EEEEEEEE:::::E     RR:::::R     R:::::R " << endl;
    cout << " B:::::::::::::::::B        UU:::::::::::::UU       R::::::R     R:::::R        GG:::::::::::::::G     E::::::::::::::::::::E     R::::::R     R:::::R " << endl;
    cout << " B::::::::::::::::B           UU:::::::::UU         R::::::R     R:::::R          GGG::::::GGG:::G     E::::::::::::::::::::E     R::::::R     R:::::R " << endl;
    cout << " BBBBBBBBBBBBBBBBB              UUUUUUUUU           RRRRRRRR     RRRRRRR             GGGGGG   GGGG     EEEEEEEEEEEEEEEEEEEEEE     RRRRRRRR     RRRRRRR " << endl;
    cout << endl;
}

void shawarmaHeader()
{
    cout << endl;
    cout << "   _____   _    _             __          __             _____    __  __             " << endl;
    cout << "  / ____| | |  | |     /\\     \\ \\        / /     /\\     |  __ \\  |  \\/  |     /\\     " << endl;
    cout << " | (___   | |__| |    /  \\     \\ \\  /\\  / /     /  \\    | |__) | | \\  / |    /  \\    " << endl;
    cout << "  \\___ \\  |  __  |   / /\\ \\     \\ \\/  \\/ /     / /\\ \\   |  _  /  | |\\/| |   / /\\ \\   " << endl;
    cout << "  ____) | | |  | |  / ____ \\     \\  /\\  /     / ____ \\  | | \\ \\  | |  | |  / ____ \\  " << endl;
    cout << " |_____/  |_|  |_| /_/    \\_\\     \\/  \\/     /_/    \\_\\ |_|  \\_\\ |_|  |_| /_/    \\_\\ " << endl;

    cout << "                                                                                                                                                                                 " << endl;
}

void drinkHeader()
{
    cout << endl;
    cout << "DDDDDDDDDDDDD             RRRRRRRRRRRRRRRRR        IIIIIIIIII     NNNNNNNN        NNNNNNNN     KKKKKKKKK    KKKKKKK        SSSSSSSSSSSSSSS  " << endl;
    cout << "D::::::::::::DDD          R::::::::::::::::R       I::::::::I     N:::::::N       N::::::N     K:::::::K    K:::::K      SS:::::::::::::::S " << endl;
    cout << "D:::::::::::::::DD        R::::::RRRRRR:::::R      I::::::::I     N::::::::N      N::::::N     K:::::::K    K:::::K     S:::::SSSSSS::::::S " << endl;
    cout << "DDD:::::DDDDD:::::D       RR:::::R     R:::::R     II::::::II     N:::::::::N     N::::::N     K:::::::K   K::::::K     S:::::S     SSSSSSS " << endl;
    cout << "  D:::::D    D:::::D        R::::R     R:::::R       I::::I       N::::::::::N    N::::::N     KK::::::K  K:::::KKK     S:::::S             " << endl;
    cout << "  D:::::D     D:::::D       R::::R     R:::::R       I::::I       N:::::::::::N   N::::::N       K:::::K K:::::K        S:::::S             " << endl;
    cout << "  D:::::D     D:::::D       R::::RRRRRR:::::R        I::::I       N:::::::N::::N  N::::::N       K::::::K:::::K          S::::SSSS          " << endl;
    cout << "  D:::::D     D:::::D       R:::::::::::::RR         I::::I       N::::::N N::::N N::::::N       K:::::::::::K            SS::::::SSSSS     " << endl;
    cout << "  D:::::D     D:::::D       R::::RRRRRR:::::R        I::::I       N::::::N  N::::N:::::::N       K:::::::::::K              SSS::::::::SS   " << endl;
    cout << "  D:::::D     D:::::D       R::::R     R:::::R       I::::I       N::::::N   N:::::::::::N       K::::::K:::::K                SSSSSS::::S  " << endl;
    cout << "  D:::::D     D:::::D       R::::R     R:::::R       I::::I       N::::::N    N::::::::::N       K:::::K K:::::K                    S:::::S " << endl;
    cout << "  D:::::D    D:::::D        R::::R     R:::::R       I::::I       N::::::N     N:::::::::N     KK::::::K  K:::::KKK                 S:::::S " << endl;
    cout << "DDD:::::DDDDD:::::D       RR:::::R     R:::::R     II::::::II     N::::::N      N::::::::N     K:::::::K   K::::::K     SSSSSSS     S:::::S " << endl;
    cout << "D:::::::::::::::DD        R::::::R     R:::::R     I::::::::I     N::::::N       N:::::::N     K:::::::K    K:::::K     S::::::SSSSSS:::::S " << endl;
    cout << "D::::::::::::DDD          R::::::R     R:::::R     I::::::::I     N::::::N        N::::::N     K:::::::K    K:::::K     S:::::::::::::::SS  " << endl;
    cout << "DDDDDDDDDDDDD             RRRRRRRR     RRRRRRR     IIIIIIIIII     NNNNNNNN         NNNNNNN     KKKKKKKKK    KKKKKKK      SSSSSSSSSSSSSSS    " << endl;
    cout << endl;
}

void dealHeader()
{
    cout << endl;
    cout << "DDDDDDDDDDDDD             EEEEEEEEEEEEEEEEEEEEEE                    AAA                    LLLLLLLLLLL                     SSSSSSSSSSSSSSS  " << endl;
    cout << "D::::::::::::DDD          E::::::::::::::::::::E                   A:::A                   L:::::::::L                   SS:::::::::::::::S " << endl;
    cout << "D:::::::::::::::DD        E::::::::::::::::::::E                  A:::::A                  L:::::::::L                  S:::::SSSSSS::::::S " << endl;
    cout << "DDD:::::DDDDD:::::D       EE::::::EEEEEEEEE::::E                 A:::::::A                 LL:::::::LL                  S:::::S     SSSSSSS " << endl;
    cout << "  D:::::D    D:::::D        E:::::E       EEEEEE                A:::::::::A                  L:::::L                    S:::::S             " << endl;
    cout << "  D:::::D     D:::::D       E:::::E                            A:::::A:::::A                 L:::::L                    S:::::S             " << endl;
    cout << "  D:::::D     D:::::D       E::::::EEEEEEEEEE                 A:::::A A:::::A                L:::::L                     S::::SSSS          " << endl;
    cout << "  D:::::D     D:::::D       E:::::::::::::::E                A:::::A   A:::::A               L:::::L                      SS::::::SSSSS     " << endl;
    cout << "  D:::::D     D:::::D       E:::::::::::::::E               A:::::A     A:::::A              L:::::L                        SSS::::::::SS   " << endl;
    cout << "  D:::::D     D:::::D       E::::::EEEEEEEEEE              A:::::AAAAAAAAA:::::A             L:::::L                           SSSSSS::::S  " << endl;
    cout << "  D:::::D     D:::::D       E:::::E                       A:::::::::::::::::::::A            L:::::L                                S:::::S " << endl;
    cout << "  D:::::D    D:::::D        E:::::E       EEEEEE         A:::::AAAAAAAAAAAAA:::::A           L:::::L         LLLLLL                 S:::::S " << endl;
    cout << "DDD:::::DDDDD:::::D       EE::::::EEEEEEEE:::::E        A:::::A             A:::::A        LL:::::::LLLLLLLLL:::::L     SSSSSSS     S:::::S " << endl;
    cout << "D:::::::::::::::DD        E::::::::::::::::::::E       A:::::A               A:::::A       L::::::::::::::::::::::L     S::::::SSSSSS:::::S " << endl;
    cout << "D::::::::::::DDD          E::::::::::::::::::::E      A:::::A                 A:::::A      L::::::::::::::::::::::L     S:::::::::::::::SS  " << endl;
    cout << "DDDDDDDDDDDDD             EEEEEEEEEEEEEEEEEEEEEE     AAAAAAA                   AAAAAAA     LLLLLLLLLLLLLLLLLLLLLLLL      SSSSSSSSSSSSSSS    " << endl;
    cout << endl;
}

void DeliveryCalculator(int total)
{
    cout << "              ***** DELIVERY CHARGES *****" << endl;
    if (total > 3000)
    {
        cout << "                                 As Your Bill Amount Is Greater Than 3000 There is No Delivery Charges " << endl;
        cout << endl;
        cout << "                                              Thanks For Purchasing " << endl;
    }
    else if (total == 3000)
    {
        cout << "                                 As Your Bill Amount Is 3000 There is No Delivery Charges " << endl;
        cout << endl;
        cout << "                                              Thanks For Purchasing " << endl;
    }
    else if (total >= 2000 && total < 3000)
    {
        cout << "                                    Delivery Charges are 250" << endl;
        cout << endl;
        cout << "                                              Thanks For Purchasing " << endl;
    }
    else if (total > 1 && total < 2000)
    {
        cout << "                                    Delivery Charges are 350" << endl;
        cout << endl;
        cout << "                                              Thanks For Purchasing " << endl;
    }
    else if (total < 1)
    {
        cout << endl;
        cout << "NO DELIVERY CHARGES" << endl;
        cout << endl;
        cout << "Please Purchase Something First " << endl;
    }
}

void addBurger(string comma)
{

    system("cls");
    topheader();
    // int index = 0;
    cout << "                              Add a BURGER:  ";
    getline(cin.ignore(), burger[burgercount]);
    cout << "                              Add BURGER price:  ";
    cin >> burgerprice[burgercount];
    burgercount++;
    // while (index < burger[burgercount].length())
    // {

    //     if (burger[index] == '!' || name[index] == '@' || name[index] == '#' || name[index] == '$' || name[index] == '%' || name[index] == '^' || name[index] == '&' || name[index] == '*' || name[index] == '(' || name[index] == ')' || name[index] == '-' || name[index] == '+')
    //     {
    //         cout << "error! please input a valid Name";
    //     }
    //     if (name[index] == '1' || name[index] == '2' || name[index] == '3' || name[index] == '4' || name[index] == '5' || name[index] == '6' || name[index] == '7' || name[index] == '8' || name[index] == '9' || name[index] == '0')
    //     {
    //         cout << "error! please input a valid Name";
    //     }

    //     index++;
    // }
}
void AddBurgerToFile(string comma)
{
    fstream file;
    file.open("burgerfile.txt", ios::out);
    for (int index = 0; index < burgercount; index++)
    {
        file << burger[index];
        file << comma;
        file << burgerprice[index] << endl;
    }
    file.close();
}

void DeleteBurger(string comma)
{
    system("cls");
    topheader();
    int position;

    for (int i = 0; i < burgercount; i++)
    {
        cout << endl;
        gotoxy(2, 50 + i);
        cout << i + 1 << ":  ";
        gotoxy(20, 50 + i);
        cout << burger[i];
        gotoxy(60, 50 + i);
        cout << burgerprice[i];
    }
    cout << endl;

    cout << "Enter the INDEX from where you want to delete burger : ";
    cin >> position;
    cout << endl;
    for (int i = position - 1; i < burgercount; i++)
    {
        burger[i] = burger[i + 1];
        burgerprice[i] = burgerprice[i + 1];
    }
    burgercount--;
}

void addPizza(string comma)
{
    system("cls");
    pizzaHeader();

    cout << "                              Add a PIZZA:  ";
    getline(cin.ignore(), pizza[pizzacount]);

    cout << "                              Add PIZZA price:  ";
    cin >> pizzaprice[pizzacount];
    pizzacount++;
}

void AddPizzaToFile(string comma)
{
    fstream file;
    file.open("pizzafile.txt", ios::out);
    for (int index = 0; index < pizzacount; index++)
    {
        file << pizza[index];
        file << comma;
        file << pizzaprice[index] << endl;
    }
    file.close();
}

void DeletePizza(string comma)
{
    system("cls");
    pizzaHeader();
    int position;
    for (int i = 0; i < pizzacount; i++)
    {
        cout << endl;
        gotoxy(2, 50 + i);
        cout << i + 1 << ":  ";
        gotoxy(20, 50 + i);
        cout << pizza[i];
        gotoxy(60, 50 + i);
        cout << pizzaprice[i];
    }
    cout << endl;
    cout << "Enter the INDEX from where you want to delete PIZZA : ";
    cin >> position;
    for (int i = position - 1; i < pizzacount; i++)
    {
        pizza[i] = pizza[i + 1];
        pizzaprice[i] = pizzaprice[i + 1];
    }
    pizzacount--;
}
void addShawarma(string comma)
{
    system("cls");
    shawarmaHeader();

    cout << "                              Add a SHAWARMA:  ";
    getline(cin.ignore(), shawarma[shawarmacount]);

    cout << "                              Add SHAWARMA price:  ";
    cin >> shawarmaprice[shawarmacount];
    shawarmacount++;
}

void AddShawarmaToFile(string comma)
{
    fstream file;
    file.open("shawarmafile.txt", ios::out);
    for (int index = 0; index < shawarmacount; index++)
    {
        file << shawarma[index];
        file << comma;
        file << shawarmaprice[index] << endl;
    }
    file.close();
}
void DeleteShawarma(string comma)
{
    system("cls");
    shawarmaHeader();
    int position;
    for (int i = 0; i < shawarmacount; i++)
    {
        cout << endl;

        gotoxy(2, 50 + i);
        cout << i + 1 << ":  ";
        gotoxy(20, 50 + i);
        cout << shawarma[i];
        gotoxy(60, 50 + i);
        cout << shawarmaprice[i];
    }
    cout << endl;
    cout << "Enter the INDEX from where you want to delete SHAWARMA : ";
    cin >> position;
    cout << endl;
    for (int i = position - 1; i < shawarmacount; i++)
    {
        shawarma[i] = shawarma[i + 1];
        shawarmaprice[i] = shawarmaprice[i + 1];
    }
    shawarmacount--;
}

void addDrink(string comma)
{
    system("cls");
    drinkHeader();

    cout << "                              Add a DRINK:  ";
    getline(cin.ignore(), drinks[drinkcount]);
    cout << "                              Add DRINK price:  ";
    cin >> drinksprice[drinkcount];
    drinkcount++;
}

void AddDrinkToFile(string comma)
{
    fstream file;
    file.open("drinkfile.txt", ios::out);
    for (int index = 0; index < drinkcount; index++)
    {
        file << drinks[index];
        file << comma;
        file << drinksprice[index] << endl;
    }
    file.close();
}

void DeleteDrink(string comma)
{
    system("cls");
    drinkHeader();
    int position;
    for (int i = 0; i < drinkcount; i++)
    {
        gotoxy(0, 20 + i);
        cout << i + 1 << ":  " << drinks[i];
        gotoxy(30, 20 + i);
        cout << drinksprice[i];
    }
    cout << endl;
    cout << "Enter the INDEX from where you want to delete DRINK : ";
    cin >> position;
    cout << endl;
    for (int i = position - 1; i < drinkcount; i++)
    {
        drinks[i] = drinks[i + 1];
        drinksprice[i] = drinksprice[i + 1];
    }
    drinkcount--;
}

void addDeal(string comma)
{
    system("cls");
    dealHeader();

    cout << "                              Add a DEAL:  ";
    getline(cin.ignore(), deals[dealcount]);

    cout << "                              Add DEAL price:  ";
    cin >> dealprice[dealcount];
    dealcount++;
}

void AddDealToFile(string comma)
{
    fstream file;
    file.open("dealfile.txt", ios::out);
    for (int index = 0; index < dealcount; index++)
    {
        file << deals[index];
        file << comma;
        file << dealprice[index] << endl;
    }
    file.close();
}

void DeleteDeal(string comma)
{
    system("cls");
    dealHeader();
    int position;
    for (int i = 0; i < dealcount; i++)
    {
        cout << endl;
        gotoxy(2, 25 + i);
        cout << i + 1 << ":  ";
        gotoxy(20, 25 + i);
        cout << deals[i];
        gotoxy(60, 25 + i);
        cout << dealprice[i];
    }
    cout << endl;
    cout << "Enter the INDEX from where you want to delete DEAL : ";
    cin >> position;
    cout << endl;
    for (int i = position - 1; i < dealcount; i++)
    {
        deals[i] = deals[i + 1];
        dealprice[i] = dealprice[i + 1];
    }
    dealcount--;
}

int showAdminMenu(int opt)
{
    system("cls");
    topheader();
    cout << "    1:          ADD BURGER" << endl;
    cout << endl;
    cout << "    2:          DELETE BURGER" << endl;
    cout << endl;
    cout << "    3:          ADD PIZZA" << endl;
    cout << endl;
    cout << "    4:          DELETE PIZZA" << endl;
    cout << endl;
    cout << "    5:          ADD SHAWARMA" << endl;
    cout << endl;
    cout << "    6:          DELETE SHAWARMA           " << endl;
    cout << endl;
    cout << "    7:          ADD A DEAL              " << endl;
    cout << endl;
    cout << "    8:          REMOVE A DEAL              " << endl;
    cout << endl;
    cout << "    9:          ADD DRINK              " << endl;
    cout << endl;
    cout << "    10:         REMOVE DRINK              " << endl;
    cout << endl;
    cout << "    11:         VIEW ALL PRODUCTS  " << endl;
    cout << endl;
    cout << "    12:         EXIT  " << endl;
    cin >> opt;

    return opt;
}
int showUserMenu(int option)
{
    system("cls");
    topheader();
    cout << "                WOW!  YOU WANT TO PLACE ORDER " << endl;
    cout << endl;
    cout << "            CHOOSE OPTION ACCORDING TO YOUR TASTE " << endl;
    cout << endl;
    cout << "   1:  PIZZA's " << endl;
    cout << endl;
    cout << "   2:  BURGERS" << endl;
    cout << endl;
    cout << "   3:  COLD-DRINKS" << endl;
    cout << endl;
    cout << "   4:  SHAWARMA's " << endl;
    cout << endl;
    cout << "   5:  DEALS              " << endl;
    cout << endl;
    cout << "   6:  YOUR BILL    " << endl;
    cout << endl;
    cout << "   7:  DELIVERY CHARGES   " << endl;
    cout << endl;
    cout << "   8:  About Us  " << endl;
    cout << endl;
    cout << "   9:  EXIT" << endl;
    cin >> option;
    return option;
}

void SignUp(string username, string password)
{
    usernames[usercount] = username;
    passwords[usercount] = password;
    usercount++;
    StoreTofile(username, password);
}

bool SignIn(string username, string password)
{
    bool flag = false;
    for (int i = 0; i < usercount; i++)
    {
        if (usernames[i] == username && passwords[i] == password)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

void displayUser()
{
    system("cls");
    topheader();
    cout << " UserName \t\t Password " << endl;
    for (int index = 0; index < usercount; index++)
    {
        cout << usernames[index] << "   " << passwords[index] << endl;
    }
    getch();
}

void StoreTofile(string username, string password)
{

    fstream file;
    file.open("Users.txt", ios::app);
    file << username << endl;
    file << password << endl;
    file.close();
}

bool isValidUsername(string username)
{
    bool flag = true;
    for (int i = 0; i < usercount; i++)
    {

        if (usernames[i] == username)
        {
            flag = false;
            break;
        }
    }
    return flag;
}

void adduser(string username, string password)
{

    usernames[usercount] = username;
    passwords[usercount] = password;
    usercount++;
}

int takechoice()
{

    int choice;
    system("cls");
    topheader();
    cout << endl;
    cout << "ENTER 1 FOR SIGN UP " << endl;
    cout << "ENTER 2 FOR SIGN IN " << endl;
    cout << "ENTER 3 TO VIEW USER" << endl;
    cout << "ENTER 0 TO EXIT" << endl;
    cin >> choice;
    choice = validation(choice);

    return choice;
}

void loaddatafromfile()
{

    string username;
    string password;
    fstream file;
    int i = 0;
    file.open("Users.txt", ios::in);

    while (!file.eof())
    {
        file >> usernames[i];
        file >> passwords[i];
        i++;
    }
    usercount = i - 1;
    file.close();
}

void time()
{
    gotoxy(110, 5);
    cout << "DATE: " << __DATE__ << endl;
    // gotoxy(110, 6);
    // cout << "TIME: " << __TIME__ << endl;
}

void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void topheader()
{

    cout << endl;
    time();
    cout << "                   AAA                 RRRRRRRRRRRRRRRRR      FFFFFFFFFFFFFFFFFFFFFF           CCCCCCCCCCCCC   " << endl;
    cout << "                  A:::A                R::::::::::::::::R     F::::::::::::::::::::F        CCC::::::::::::C   " << endl;
    cout << "                 A:::::A               R::::::RRRRRR:::::R    F::::::::::::::::::::F      CC:::::::::::::::C   " << endl;
    cout << "                A:::::::A              RR:::::R     R:::::R   FF::::::FFFFFFFFF::::F     C:::::CCCCCCCC::::C   " << endl;
    cout << "               A:::::::::A               R::::R     R:::::R     F:::::F       FFFFFF    C:::::C       CCCCCC   " << endl;
    cout << "              A:::::A:::::A              R::::R     R:::::R     F:::::F                C:::::C                 " << endl;
    cout << "             A:::::A A:::::A             R::::RRRRRR:::::R      F::::::FFFFFFFFFF     C:::::C                 " << endl;
    cout << "            A:::::A   A:::::A            R:::::::::::::RR       F:::::::::::::::F     C:::::C                 " << endl;
    cout << "           A:::::A     A:::::A           R::::RRRRRR:::::R      F:::::::::::::::F     C:::::C                 " << endl;
    cout << "          A:::::AAAAAAAAA:::::A          R::::R     R:::::R     F::::::FFFFFFFFFF     C:::::C                 " << endl;
    cout << "         A:::::::::::::::::::::A         R::::R     R:::::R     F:::::F                C:::::C                 " << endl;
    cout << "        A:::::AAAAAAAAAAAAA:::::A        R::::R     R:::::R     F:::::F                 C:::::C       CCCCCC   " << endl;
    cout << "       A:::::A             A:::::A     RR:::::R     R:::::R   FF:::::::FF                C:::::CCCCCCCC::::C   " << endl;
    cout << "      A:::::A               A:::::A    R::::::R     R:::::R   F::::::::FF                 CC:::::::::::::::C   " << endl;
    cout << "     A:::::A                 A:::::A   R::::::R     R:::::R   F::::::::FF                   CCC::::::::::::C   " << endl;
    cout << "    AAAAAAA                   AAAAAAA  RRRRRRRR     RRRRRRR   FFFFFFFFFFF                      CCCCCCCCCCCCC   " << endl;

    cout << "                                                                                     " << endl;
    cout << endl;
    cout << "                                                     ORDER MANAGEMENT SYSTEM                                      " << endl;
    cout << endl;

    cout << "                                                  A Five Minute Stop for Your Cravings!                           " << endl;
    cout << endl;
}

int pizzaMenu(int pizzachoice, int pizzaQuantity)
{
    displayPizzaOutput(index);
    cout << endl;
    cout << "Press 0 to Exit " << endl;

    int pizzaTotal = calculatePizzaPrice(pizzachoice, pizzaQuantity);

    return pizzaTotal;
}

int calculatePizzaPrice(int pizzachoice, int pizzaQuantity)
{
    while (true)
    {
        cout << endl;
        cout << "Enter Your Choice: ";
        cin >> pizzachoice;
        if (pizzachoice == 0)
        {
            break;
        }
        cout << "Enter Pizza Quantity: ";
        cin >> pizzaQuantity;
        pizzaTotal = pizzaTotal + pizzaQuantity * pizzaprice[pizzachoice - 1];
    }
    return pizzaTotal;
}

string getField(string record, int field)
{
    int commaCount = 1;
    string item;
    for (int x = 0; x < record.length(); x++)
    {
        if (record[x] == ',')
        {
            commaCount = commaCount + 1;
        }
        else if (commaCount == field)
        {
            item = item + record[x];
        }
    }
    return item;
}

void readPizzaData()
{
    string record;
    fstream data;
    data.open("pizzafile.txt", ios::in);
    while (!(data.eof()))
    {
        getline(data, record);
        pizza[pizzacount] = getField(record, 1);

        istringstream(getField(record, 2)) >> pizzaprice[pizzacount];

        pizzacount++;
    }
    pizzacount--;
}

void readBurgerData()
{
    string record;
    fstream data;
    data.open("burgerfile.txt", ios::in);

    while (!(data.eof()))
    {
        getline(data, record);
        burger[burgercount] = getField(record, 1);

        istringstream(getField(record, 2)) >> burgerprice[burgercount];
        burgercount++;
    }
    burgercount--;
}

void readDrinkData()
{
    string record;
    fstream data;
    data.open("drinkfile.txt", ios::in);
    while (!(data.eof()))
    {
        getline(data, record);
        drinks[drinkcount] = getField(record, 1);

        istringstream(getField(record, 2)) >> drinksprice[drinkcount];

        drinkcount++;
    }
    drinkcount--;
}

void readDealData()
{
    string record;
    fstream data;
    data.open("dealfile.txt", ios::in);
    while (!(data.eof()))
    {
        getline(data, record);
        deals[dealcount] = getField(record, 1);

        istringstream(getField(record, 2)) >> dealprice[dealcount];

        dealcount++;
    }
    dealcount--;
}

void readShawarmaData()
{
    string record;
    fstream data;
    data.open("shawarmafile.txt", ios::in);
    while (!(data.eof()))
    {
        getline(data, record);
        shawarma[shawarmacount] = getField(record, 1);

        istringstream(getField(record, 2)) >> shawarmaprice[shawarmacount];

        shawarmacount++;
    }
    shawarmacount--;
}

void displayPizzaOutput(int index)
{
    for (int i = 0; i < pizzacount; i++)
    {

        cout << endl;
        gotoxy(0, 20 + i);
        cout << i + 1 << ":  ";
        gotoxy(18, 20 + i);
        cout << pizza[i];
        gotoxy(60, 20 + i);
        cout << pizzaprice[i];
        cout << endl;
    }
}

int DrinkMenu(int drinkchoice, int drinkQuantity)
{
    displayDrinkOutput(index);
    cout << endl;
    cout << "Press 0 to Exit " << endl;
    int drinkTotal = calculateDrinkPrice(drinkchoice, drinkQuantity);
    return drinkTotal;
}

void PrintAllProducts(string comma)
{
    system("cls");
    topheader();
    cout << "Burger Section" << endl;
    for (int i = 0; i < burgercount; i++)
    {

        cout << endl;
        gotoxy(2, 30 + i);
        cout << i + 1 << ":  ";
        gotoxy(20, 30 + i);
        cout << burger[i];
        gotoxy(70, 30 + i);
        cout << burgerprice[i];
    }
    cout << endl;
    cout << "Deal Section" << endl;
    for (int i = 0; i < dealcount; i++)
    {
        gotoxy(0, 47 + i);
        cout << "Deal  " << i + 1 << ":  ";
        gotoxy(20, 47 + i);
        cout << deals[i];
        gotoxy(70, 47 + i);
        cout << dealprice[i];
    }
    cout << endl;
    cout << "Drink Section" << endl;
    for (int i = 0; i < drinkcount; i++)
    {
        gotoxy(0, 60 + i);
        cout << i + 1 << ":  ";
        gotoxy(20, 60 + i);
        cout << drinks[i];
        gotoxy(70, 60 + i);
        cout << drinksprice[i];
    }
    cout << endl;
    cout << "Pizza Section" << endl;
    for (int i = 0; i < pizzacount; i++)
    {

        cout << endl;
        gotoxy(0, 75 + i);
        cout << i + 1 << ":  ";
        gotoxy(20, 75 + i);
        cout << pizza[i];
        gotoxy(70, 75 + i);
        cout << pizzaprice[i];
        cout << endl;
    }
    cout << endl;
    cout << "Shawarma Section" << endl;
    for (int i = 0; i < shawarmacount; i++)
    {
        cout << endl;
        gotoxy(2, 90 + i);
        cout << i + 1 << ":  ";
        gotoxy(20, 90 + i);
        cout << shawarma[i];
        gotoxy(70, 90 + i);
        cout << shawarmaprice[i];
        cout << endl;
    }
    cout << endl;
}

int calculateDrinkPrice(int drinkchoice, int drinkQuantity)
{
    while (true)
    {
        cout << "Enter Your Choice: ";
        cin >> drinkchoice;
        if (drinkchoice == 0)
        {
            break;
        }
        cout << "Enter DRINK Quantity: ";
        cin >> drinkQuantity;
        drinkTotal = drinkTotal + drinkQuantity * drinksprice[drinkchoice - 1];
    }
    return drinkTotal;
}

void displayDrinkOutput(int index)
{
    for (int i = 0; i < drinkcount; i++)
    {
        gotoxy(0, 20 + i);
        cout << i + 1 << ":  " << drinks[i];
        gotoxy(30, 20 + i);
        cout << drinksprice[i];
    }
    cout << endl;
}

int DealMenu(int dealchoice, int dealQuantity)
{
    displayDealOutput(index);
    cout << endl;
    cout << "Press 0 to Exit " << endl;
    int dealTotal = calculateDealPrice(dealchoice, dealQuantity);
    return dealTotal;
}

int calculateDealPrice(int dealchoice, int dealQuantity)
{
    while (true)
    {
        cout << "Enter Your Choice: ";
        cin >> dealchoice;
        if (dealchoice == 0)
        {
            break;
        }
        cout << "Enter Shawarma Quantity: ";
        cin >> dealQuantity;
        dealTotal = dealTotal + dealQuantity * dealprice[dealchoice - 1];
    }
    return dealTotal;
}

void displayDealOutput(int index)
{
    for (int i = 0; i < dealcount; i++)
    {
        gotoxy(0, 20 + i);
        cout << "Deal  " << i + 1 << ":  " << deals[i];
        gotoxy(90, 20 + i);
        cout << dealprice[i];
    }
    cout << endl;
}

int ShawarmaMenu(int shawarmachoice, int shawarmaQuantity)
{
    displayShawarmaOutput(index);
    cout << endl;
    cout << "Press 0 to Exit " << endl;
    int shawarmaTotal = calculateShawarmaPrice(shawarmachoice, shawarmaQuantity);
    return shawarmaTotal;
}

int calculateShawarmaPrice(int shawarmachoice, int shawarmaQuantity)
{
    while (true)
    {
        cout << "Enter Your Choice: ";
        cin >> shawarmachoice;
        if (shawarmachoice == 0)
        {
            break;
        }
        cout << "Enter Shawarma Quantity: ";
        cin >> shawarmaQuantity;
        shawarmaTotal = shawarmaTotal + shawarmaQuantity * shawarmaprice[shawarmachoice - 1];
    }
    return shawarmaTotal;
}

void displayShawarmaOutput(int index)
{
    for (int i = 0; i < shawarmacount; i++)
    {
        cout << endl;
        gotoxy(2, 10 + i);
        cout << i + 1 << ":  ";
        gotoxy(20, 10 + i);
        cout << shawarma[i];
        gotoxy(60, 10 + i);
        cout << shawarmaprice[i];
        cout << endl;
    }
    cout << endl;
}

int BurgerMenu(int burgerchoice, int burgerQuantity)
{
    displayBurgerOutput(index);
    cout << endl;
    cout << "Press 0 to Exit " << endl;
    int BurgerTotal = calculateBurgerPrice(burgerchoice, burgerQuantity);
    return burgerTotal;
}

int calculateBurgerPrice(int burgerchoice, int burgerQuantity)
{
    while (true)
    {
        cout << "Enter Your Choice: ";
        cin >> burgerchoice;
        if (burgerchoice == 0)
        {
            break;
        }
        cout << "Enter Burger's Quantity: ";
        cin >> burgerQuantity;
        burgerTotal = burgerTotal + burgerQuantity * burgerprice[burgerchoice - 1];
    }
    return burgerTotal;
}

void displayBurgerOutput(int index)
{
    for (int i = 0; i < burgercount; i++)
    {

        cout << endl;
        gotoxy(2, 20 + i);
        cout << i + 1 << ":  ";
        gotoxy(20, 20 + i);
        cout << burger[i];
        gotoxy(60, 20 + i);
        cout << burgerprice[i];
    }
    cout << endl;
}

int validation(int number)
{
    while (cin.fail())
    {
        cin.clear();
        cin.ignore();

        cin >> number;
    }
    return number;
}
