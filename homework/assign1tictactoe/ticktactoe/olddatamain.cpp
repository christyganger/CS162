char getMove(char boardcurrent[firstsize][secondsize])
{
    int movecol;
    int moverow;
    char xo;
    bool doneenterrow = false;
    bool doneentercol = false;
    cout << "getmove works" << "\n";
    /*cout << "Please enter col" << "\n";
    cin >> movecol;
     if (cin.fail())
        {
            cin.clear();
            cin.ignore(2000, '\n');
            cin >> movecol;
        }
    while (!doneentercol)
        {
            switch(movecol)
            {
                case 3:
                    movecol = 10;
                    doneentercol = true;
                    break;
                case 2:
                    movecol = 6;
                    doneentercol = true;
                    break;
                case 1:
                    movecol = 2;
                    doneentercol = true;
                    break;
                default:
                    cout << "Incorrect Columb number, 1-3 please." << "\n";
                     cin >> movecol;
                     if (cin.fail())
                    {
                    cin.clear();
                    cin.ignore(2000, '\n');
                    }
                    break;

            }
        }
    cout << movecol << " entered" << "\n";
    cout << "Now please enter row" << "\n";
    cin >> moverow;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(2000, '\n');
        cin >> movecol;
    }
   while (!doneenterrow)
    {
        switch(moverow)
        {
            case 3:
                moverow = 8;
                doneenterrow = true;
                break;
            case 2:
                moverow = 5;
                doneenterrow = true;
                break;
            case 1:
                moverow = 2;
                doneenterrow = true;
                break;
            default:
                cout << "Incorrect row number, 1-3 please." << "\n";
                cin >> moverow;
                if (cin.fail())
                {
                cin.clear();
                cin.ignore(2000, '\n');
                }
                break;

        }
    }
    cout << moverow << " entered" << "\n";
    cout << "Now please enter X or O" << "\n";
    cin >> xo;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(2000, '\n');
        cout << "please enter a character X or O" << "\n";
        cin >> xo;
    }
    cout << xo << " entered" << "\n";
*/
    boardcurrent[moverow][movecol] = xo;
    showBoard(boardcurrent);
    return '1';
}
bool checkWin(char boardcurrent[firstsize][secondsize])
{
    cout << "check win works" << "\n";
    return true;
}
bool checkDraw(char boardcurrent[firstsize][secondsize])
{
    cout << "check draw works" << "\n";
    return true;
}
