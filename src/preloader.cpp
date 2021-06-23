    char l = 219;
    cout << "\n\n\n\n\n\n\n\n\n\n\n" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Yellow);
    printf("          %c--------------------------------------------------------------------------------------------%c \n",201,187,188,187);
    printf("          |                            Aguarde enquanto carrega o sistema                              |\n");
    printf("          %c--------------------------------------------------------------------------------------------%c",200,188);                                                                //for loading bar
    cout << endl;
    cout << "                                              ";
    for ( int i = 0; i < 23 ; i++)
    {
        Sleep(200);
        cout << l;
         }
    cout << endl;
    system ("cls");
