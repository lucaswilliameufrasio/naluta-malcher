pdv:
#include "head.cpp";
cout << " | "; cout << "\t\t\t\t    MENU LOJA"; cout << "\t\t\t\t      |\n";
cout << " <---------------------------------------------------------------------------->\n";
cout << " | "; cout << "\t\t\t      PDV - PONTO DE VENDAS"; cout << "\t\t\t      |\n";
cout << " <---------------------------------------------------------------------------->\n";
cout << " <-----------------------------------> \n";
cout << " | <1>  VENDA PARA CLIENTE           |\n";
cout << " |-----------------------------------|\n";
cout << " | <2>  CAIXA                        |\n";
cout << " |-----------------------------------|\n";
cout << " | <3>  MENU PRINCIPAL               |\n";
cout << " <----------------------------------->";
cout << endl;
cout << "\n Digite sua opção: ";
cin >> cadastro;

switch (cadastro) {
    case 1:
        venda_cliente(); //chama a função e grava os dados.
        system("cls");
        goto pdv;
        break;
    case 2:
        caixa();
        system("cls");
        goto pdv;
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
