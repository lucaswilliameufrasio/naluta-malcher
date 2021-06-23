#include "head.cpp";
cout << " | "; cout << "\t\t\t\t             MENU LOJA"; cout << "\t\t\t\t              |\n";
cout << " <-------------------------------------------------------------------------------------------->\n";
cout << " <-----------------------------------> \n";
cout << " | <1>  RELAÇÃO DE PRODUTOS          |\n";
cout << " |-----------------------------------|\n";
cout << " | <2>  PDV - PONTO DE VENDAS        |\n";
cout << " |-----------------------------------|\n";
cout << " | <3>  CADASTRO DE PRODUTOS         |\n";
cout << " |-----------------------------------|\n";
cout << " | <4>  MENU PRINCIPAL               |\n";
cout << " <----------------------------------->";
cout << endl;
cout << "\n Digite sua opção: ";
cin >> cadastro;

switch (cadastro) {
    case 1:
        loja(); //chama a função e grava os dados.
        break;
    case 2:
        system("cls");
        #include "pdv.cpp";
        break;
    case 3:
        cadproduto();
        break;
    case 4:
        system("cls");
        goto menu;
        break;
    default:
        cout<<"Você escolheu uma opção errada:"<<endl;
        cout << endl;
        break;
}
