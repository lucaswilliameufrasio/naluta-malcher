#include "head.cpp";
cout << " | "; cout << "\t\t\t\t          MENU CLIENTES"; cout << "\t\t\t\t              |\n";
cout << " <-------------------------------------------------------------------------------------------->\n";
cout << " <-----------------------------------> \n";
cout << " | <1>  RELA�AO DE CLIENTES          |\n";
cout << " |-----------------------------------|\n";
cout << " | <2>  MENU PRINCIPAL               |\n";
cout << " <----------------------------------->";
cout << endl;
cout << "\n Digite sua op��o: ";
cin >> clientes;

switch (clientes) {
    case 1:
        consultar_cliente(); //chama a fun��o e exibe os dados.
        break;
    case 2:
        system("cls");
        goto menu;
        break;
    default:
        cout<<"Voc� escolheu uma op��o errada:"<<endl;
        cout << endl;
        break;

}
