#include "head.cpp";
cout << " | "; cout << "\t\t\t                MENU AGENDAMENTOS"; cout << "\t\t\t\t      |\n";
cout << " <-------------------------------------------------------------------------------------------->\n";
cout << " <-----------------------------------> \n";
cout << " | <1>  VER AGENDAMENTOS             |\n";
cout << " |-----------------------------------|\n";
cout << " | <2>  AGENDAR                      |\n";
cout << " |-----------------------------------|\n";
cout << " | <3>  MENU PRINCIPAL               |\n";
cout << " <----------------------------------->";
cout << endl;
cout << "\n Digite sua opção: ";
cin >> clientes;

switch (clientes) {
    case 1:
        agenda(); //chama a função e exibe os dados.
        break;
    case 2:
        marcar(); //chama a função e exibe os dados.
        break;
    case 3:
        system("cls");
        goto menu;
        break;
    default:
        cout<<"Você escolheu uma opção errada:"<<endl;
        cout << endl;
        break;
}
