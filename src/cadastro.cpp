#include "head.cpp";
cout << " | "; cout << "\t\t\t\t           MENU CADASTRO"; cout << "\t\t\t\t      |\n";
cout << " <-------------------------------------------------------------------------------------------->\n";
cout << " <-----------------------------------> \n";
cout << " | <1>  CADASTRAR DE CLIENTES        |\n";
cout << " |-----------------------------------|\n";
cout << " | <2>  MENU PRINCIPAL               |\n";
cout << " <----------------------------------->";
cout << endl;
cout << "\n Digite sua opção: ";
cin >> cadastro;

switch (cadastro) {
    case 1:
        cadastro_cliente(); //chama a função e grava os dados.
        break;
    case 2:
        system("cls");
        goto menu;
        break;
    default:
        cout<<"Você escolheu uma opção errada:"<<endl;
        cout << endl;
        break;
}
