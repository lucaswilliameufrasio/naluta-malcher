#include "head.cpp";
cout << " | "; cout << "\t\t\t\t             MENU LOJA"; cout << "\t\t\t\t              |\n";
cout << " <-------------------------------------------------------------------------------------------->\n";
cout << " <-----------------------------------> \n";
cout << " | <1>  RELA��O DE PRODUTOS          |\n";
cout << " |-----------------------------------|\n";
cout << " | <2>  PDV - PONTO DE VENDAS        |\n";
cout << " |-----------------------------------|\n";
cout << " | <3>  CADASTRO DE PRODUTOS         |\n";
cout << " |-----------------------------------|\n";
cout << " | <4>  MENU PRINCIPAL               |\n";
cout << " <----------------------------------->";
cout << endl;
cout << "\n Digite sua op��o: ";
cin >> cadastro;

switch (cadastro) {
    case 1:
        loja(); //chama a fun��o e grava os dados.
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
        cout<<"Voc� escolheu uma op��o errada:"<<endl;
        cout << endl;
        break;
}
