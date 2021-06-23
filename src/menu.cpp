menu:
#include "head.cpp";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);
    cout << " <-----------------------------------> \n";
    cout << " | <1>  CLIENTES                     |\n";
    cout << " |-----------------------------------|\n";
    cout << " | <2>  CADASTRO                     |\n";
    cout << " |-----------------------------------|\n";
    cout << " | <3>  AGENDAMENTOS                 |\n";
    cout << " |-----------------------------------|\n";
    cout << " | <4>  PARTIDAS                     |\n";
    cout << " |-----------------------------------|\n";
    cout << " | <5>  LOJA                         |\n";
    cout << " |-----------------------------------|\n";
    cout << " | <0>  Sair                         |\n";
    cout << " <----------------------------------->";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Red);
    cout<<"                   SISTEMA EM C++ INTEGRADO COM MYSQL"<<endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Yellow);
    cout << "\n Sua escolha: ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color_Def);

    cin >> a;
    cout << endl;
    switch(a)
    {

        case 1:
        system("cls");
        #include "clientes.cpp";
        system("cls");
        goto menu;
        break;

        case 2:
        system("cls");
        #include "cadastro.cpp";
        system("cls");
        goto menu;
        break;

        case 3:
        system("cls");
        #include "agendamento.cpp";
        system("cls");
        goto menu;
        break;

        case 4:
        system("cls");
        #include "head.cpp";
        cout << " | "; cout << "\t\t\t\t  MENU PARTIDAS"; cout << "\t\t\t\t      |\n";
        cout << " %c----------------------------------------------------------------------------%c\n";
        cout << endl;
        cout << endl;
        break;

        case 5:
        system("cls");
        #include "loja.cpp";
        system("cls");
        goto menu;
        break;
        consultar_cliente();    //function calling
        break;

        case 0:
            cout<<"Tenha um bom dia! "<<endl;
            cout<<endl;
            cout<<"Copyright(C) 2017. BSI 2017 - [Tadeu & Lucas] & [Natalia & Malcher]"<<endl;
            cout<<endl;
            cout<<"_________________________________________"<<endl;

            system ("pause");
        break;

        default:
        cout<<"Você escolheu uma opção errada:"<<endl;
        cout << endl;
        break;
                 }



