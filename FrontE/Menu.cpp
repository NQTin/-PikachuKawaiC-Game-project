#include "Menu.h"
void getEvents(int &line, int &col,int &roundSelect, int &Choice)
{
    char button = getch();
    switch (roundSelect)
    {
        case 1:
        {
            switch(button)
            {
                case KeyUp:
                {
                    Choice--;
                    if (Choice == 0)
                        Choice = 3;
                    break;                  
                }
                case KeyDown:
                {
                    Choice++;
                    if (Choice == 4)
                        Choice = 1;
                    break;
                }
                case Space:
                {
                    if (Choice == 1)
                    {
                        roundSelect++; 
                        Choice = 1;
                    }
                    else if (Choice = 2)
                    {
                        roundSelect = 3; //Credit
                    }
                    else exit(0);
                    break;
                }
                case Esc:
                {
                    exit(0);
                    break;
                }
            }
        break;
        }
        case 2:
        {
            switch(button)
            {
                case KeyUp:
                {
                    Choice--;
                    if (Choice == 0)
                        Choice = 4;
                    break;                  
                }
                case KeyDown:
                {
                    Choice++;
                    if (Choice == 5)
                        Choice = 1;
                    break;
                }
                case Space:
                { 
                    switch (Choice)
                    {
                        case (1):
                        {
                            line = 4;
                            col = 4;
                            break;
                        }
                        case (2):
                        {
                            line = 6;
                            col = 6;
                            break;
                        }
                        case (3):
                        {
                            line = 10;
                            col = 10;
                            break;
                        }
                    }
                    break;
                }
                case Esc:
                {
                    roundSelect--;
                }
            break;
            }
        break;
        }
    }
}
void generateMenu (int &line, int &col, int &roundSelect, int &Choice)
{
    roundSelect = 1;
    Choice = 1;

    cout << "_|_|_|    _|  _|                            _|                 "<< endl;                                                                                                                                                                               
    cout << "_|    _|      _|  _|      _|_|_|    _|_|_|  _|_|_|    _|     _| "<< endl;
    cout << "_|_|_|    _|  _|_|      _|    _|  _|        _|    _|  _|     _| "<< endl;
    cout << "_|        _|  _|  _|    _|    _|  _|        _|    _|  _|     _| "<< endl;
    cout << "_|        _|  _|    _|    _|_|_|    _|_|_|  _|    _|    _|_|_|  \n\n";
    cout << "\t Press any button to continue!!";

    Sleep(100);
    system("cls");
    cout << "\t\t Pikachu" << endl; 
    printMenu(roundSelect, Choice);
    while (true)
    {
        getEvents(line, col, roundSelect, Choice);
        system("cls");
        printMenu(roundSelect, Choice);
    }
}

void printMenu(int roundSelect, int Choice)
{
    
    switch (roundSelect)
    {
        case 1:
        {
            if (Choice == 1)
            {
                cout << "\t\t <<Play>>" << endl;
                cout << "\t\t  Credit" << endl;
                cout << "\t\t  Quit" << endl;
            }
            else if (Choice == 2)
            {
                cout << "\t\t Play" << endl;
                cout << "\t\t<<Credit>>" << endl;
                cout << "\t\t Quit" << endl;
            }
            else if (Choice == 3)
            {
                cout << "\t\t Play" << endl;
                cout << "\t\t Credit" << endl;
                cout << "\t\t<<Quit>>" << endl;
            }
            break;
        }
        case 2:
        {
            if (Choice == 1)
            {
                cout << "\t\t<<Easy>>" << endl;
                cout << "\t\t Normal" << endl;
                cout << "\t\t Hard" << endl;
                cout << "\t\t Crazy" << endl;
                
            }
            else if (Choice == 2)
            {
                cout << "\t\t Easy" << endl;
                cout << "\t\t<<Normal>>" << endl;
                cout << "\t\t Hard" << endl;
                cout << "\t\t Crazy" << endl;
            }
            else if (Choice == 3)
            {
                cout << "\t\t Easy" << endl;
                cout << "\t\t Normal" << endl;
                cout << "\t\t<<Hard>>" << endl;
                cout << "\t\t Crazy" << endl;
            }
            else if (Choice == 4)
            {
                cout << "\t\t Easy" << endl;
                cout << "\t\t Normal" << endl;
                cout << "\t\t Hard" << endl;
                cout << "\t\t<<Crazy>>" << endl;
            }
            break;
        }
        case 3:
        {
            cout << "credit";
        }
    }

}
  