#include <iostream>
#include <fstream>
#include <windows.h>
#include <cstring>
#include <unistd.h>
#include <iomanip>
#include <cstdlib>
#include <locale.h>
#include <ctime>
#include <sstream>
#include <mysql.h>
#include <conio.h>

// definição de cores do sistema
#define Color_Red 12
#define Color_Def 15
#define Color_Yellow 14
#define Color_Green 10

using namespace std;

#include "conexao.txt"; //usado para armazenar os dados de conexão

// variáveis globais
int a;
int choice, clientes, cadastro;
char again;
char x[20];
MYSQL *conn;

//Funções de conexão com o banco
void conexao_banco();

//Funções da Loja
void cadproduto();
void venda_avulsa();
void caixa();
void venda_cliente();
void pdv();
void loja();

//Funções do Cliente
void cadastro_cliente();
void consultar_cliente();

//Funções do agendamento de jogo
void agenda();
void marcar();

int main()
{
    conexao_banco();
    system("color F");
    system("MODE CON cols=120");
    #include "preloader.cpp";
    setlocale(LC_ALL, "");
    menuprinc:
    #include "menu.cpp";
}

void conexao_banco()
{
    conn = mysql_init(NULL);
    mysql_real_connect(conn, HOST, USER, PASS, DB, 0, NULL, 0);
}

void cadproduto()
{
    string nome;
    string telefone;
    char menuretorna;
    cout << endl;
    cin.ignore();
    cout << " Nome do Produto: ";
    getline(cin, nome);
    cout << " Valor: ";
    getline(cin, telefone);

    int a;
    cout << endl;
    cout << " Pressione 1 para SALVAR ou 2 para CANCELAR: ";
    cin >> a;

    if(a == 1){
        conexao_banco();
        string instrument="INSERT INTO produto (nome_produto, valor_produto) VALUES ('"+nome+"', '"+telefone+"');";
        mysql_query(conn, instrument.c_str());

        cout << " Registro feito..." << endl;
        cout << "__________________________________" << endl;
        cout << endl;
    }

    else if (a == 2)
	{
        cout<<" Registro NÃO salvo"<<endl;
        cout<<"____________________________________"<<endl;
        cout<<endl;
    }

	if (menuretorna == 3)
	{
    cout << " Digite 3 para retornar ao MENU CADASTRO: ";
    cin >> menuretorna;
	}
}

void agenda()
{

    char menuretorna;

    do
    {
        MYSQL_RES *resultado;
        MYSQL_ROW row;
        conexao_banco();

        string mes, dia;

        cin.ignore();
        cout << "\n -----" << endl;
        cout << "o mês: ";
        getline(cin, mes);
            cout << " Digite o dia: ";
        getline(cin, dia);
        string vazio = "\0";

        conexao_banco();
        if (dia == vazio) {
            string instrument="SELECT * FROM agendamento JOIN cliente WHERE agendamento.cliente = cliente.id_cliente AND mes = '"+mes+"'";
            mysql_query(conn, instrument.c_str());
            resultado = mysql_use_result(conn);
            cout << "\n Dia |" << setw(9) << "Cliente" << setw(48) << "| Horário" << endl;
            cout << " ---------------------------------------------------------------------------" << endl;
            while ((row = mysql_fetch_row(resultado)) != NULL)
            {
                cout << " " << right << setw(4) << row[3] << " | " << setw(45) << left << row[7]
                     << " | Das " << row[4] << " às " << row[5]<< endl;
                cout << " ---------------------------------------------------------------------------" << endl;
            }
            mysql_free_result(resultado);
            mysql_close(conn);
        }
        else {
            string instrument="SELECT * FROM agendamento JOIN cliente WHERE agendamento.cliente = cliente.id_cliente AND mes = '"+mes+"' AND dia = '"+dia+"'";
            mysql_query(conn, instrument.c_str());
            resultado = mysql_use_result(conn);
            cout << "\n Dia |" << setw(9) << "Cliente" << setw(48) << "| Horário" << endl;
            cout << " ---------------------------------------------------------------------------" << endl;
            while ((row = mysql_fetch_row(resultado)) != NULL)
            {
                cout << " " << right << setw(4) << row[3] << " | " << setw(45) << left << row[7]
                     << " | Das " << row[4] << " às " << row[5]<< endl;
                cout << " ---------------------------------------------------------------------------" << endl;
            }
            mysql_free_result(resultado);
            mysql_close(conn);
        }
        cout << "\n Digite Y para repetir ou N para retornar ao MENU: ";
        cin >> menuretorna;
    }
    while (menuretorna=='y' || menuretorna=='Y');

}

void consultar_cliente()
{

    char menuretorna;       //for enter more data

    do
    {
        MYSQL_RES *resultado;
        MYSQL_ROW row;
        conexao_banco();
        mysql_query(conn, "SELECT * FROM cliente ORDER BY nome");
        resultado = mysql_use_result(conn);
        cout << "\n Código |" << setw(5) << "Nome" << setw(50) << "| Telefone" << endl;
        cout << " ---------------------------------------------------------------------------" << endl;
        while ((row = mysql_fetch_row(resultado)) != NULL)
        {
            cout << " " << right << setw(6) << row[0] << " | " << setw(43) << left << row[1] << " | " << row[2] << endl;
            cout << " ---------------------------------------------------------------------------" << endl;
        }
        mysql_free_result(resultado);
        mysql_close(conn);

        cout << "\n Digite Y para repetir ou N para retornar ao MENU: ";
        cin >> menuretorna;
    }
    while (menuretorna=='y' || menuretorna=='Y');
}

void cadastro_cliente()
{
    string nome;
    string telefone;
    char menuretorna;       //for enter more data

    cout << endl;
    cin.ignore();
    cout << " Nome: ";
    getline(cin, nome);
    cout << " Número de Celular: ";
    getline(cin, telefone);

    int a;                            //for choice
    cout << endl;
    cout << " Pressione 1 para SALVAR ou 2 para CANCELAR: ";
    cin >> a;

    if(a == 1){
        conexao_banco();
        string instrument="INSERT INTO cliente (nome, telefone) VALUES ('"+nome+"', '"+telefone+"');";
        mysql_query(conn, instrument.c_str());

        cout << " Registro feito..." << endl;
        cout << "__________________________________" << endl;
        cout << endl;
    }

    else if (a == 2)
	{
        cout<<" Registro NÃO salvo"<<endl;
        cout<<"____________________________________"<<endl;
        cout<<endl;
    }

	if (menuretorna == 3)
	{
    cout << " Digite 3 para retornar ao MENU CADASTRO: ";
    cin >> menuretorna;
	}
}

void marcar()
{
    string nome;
    string mes;
    string dia;
    string inicio;
    string fim;
    char menuretorna;       //for enter more data
    int escolha;

    cout << "\n ----------- Para agendar um jogo é necessário o código do cliente -----------" << endl;
    cout << " -----------    0 - Relação de Clientes   |   1 - Agendar Jogo     -----------" << endl;
    cin.ignore();
    cout << "\n Sua opção: ";
    cin >> escolha;

    switch (escolha) {
        case 0:
            system("cls");
            consultar_cliente();
            system("cls");
            marcar();
        break;

        case 1:
            cout << endl;
            cin.ignore();
            cout << " Código Cliente: ";
            getline(cin, nome);
            cout << " Mês: ";
            getline(cin, mes);
            cout << " Dia: ";
            getline(cin, dia);
            cout << " Hora Início: ";
            getline(cin, inicio);
            cout << " Hora Fim: ";
            getline(cin, fim);



            int a;                            //for choice
            cout << endl;
            cout << " Pressione 1 para SALVAR ou 2 para CANCELAR: ";
            cin >> a;

            if(a == 1){
                conexao_banco();
                string instrument="INSERT INTO agendamento (cliente, mes, dia, hora_inicio, hora_fim) VALUES ('"+nome+"', '"+mes+"', '"+dia+"', '"+inicio+"', '"+fim+"');";
                mysql_query(conn, instrument.c_str());

                cout << " Registro feito..." << endl;
                cout << "__________________________________" << endl;
                cout << endl;
            }

            else if (a == 2)
			{
                cout<<" Registro NÃO salvo"<<endl;
                cout<<"____________________________________"<<endl;
                cout<<endl;
            }
			if (menuretorna == 3)
			{
            cout << " Digite 3 para retornar ao MENU CADASTRO: ";
            cin >> menuretorna;
			}

        break;
    }


    }

void loja ()
{
    char menuretorna;

    do
    {
        MYSQL_RES *resultado;
        MYSQL_ROW row;
        conexao_banco();
        string instrument="SELECT * FROM produto";
        mysql_query(conn, instrument.c_str());
        resultado = mysql_use_result(conn);
        cout << "\n Código |" << setw(10) << "Produto" << setw(53) << "| Valor" << endl;
        cout << " ---------------------------------------------------------------------------" << endl;
        while ((row = mysql_fetch_row(resultado)) != NULL)
        {
            cout << " " << right << setw(6) << row[0] << " | " << setw(54) << left << row[1]
                 << " | R$" << setw(8) << row[2] << endl;
            cout << " ---------------------------------------------------------------------------" << endl;
        }
        mysql_free_result(resultado);
        mysql_close(conn);

        cout << "\n Digite Y para repetir ou N para retornar ao MENU: ";
        cin >> menuretorna;
    }
    while (menuretorna=='y' || menuretorna=='Y');
}

void venda_cliente ()
{
    string cliente;
    string produto;
    string qtd;
    char menuretorna;
    int escolha;

    cout << "\n ----------- Para fazer uma venda é necessário o código do cliente -----------" << endl;
    cout << " -----------     0 - Relação de Clientes   |   1 - Fazer Venda     -----------" << endl;
    cin.ignore();
    cout << "\n Sua opção: ";
    cin >> escolha;

    switch (escolha) {
        case 0:
            system("cls");
            consultar_cliente();
        break;

        case 1:
            cout << endl;
            cin.ignore();
            cout << " Código Cliente: ";
            getline(cin, cliente);

            MYSQL_RES *resultado;
            MYSQL_ROW row;
            conexao_banco();
            string instrument="SELECT * FROM produto";
            mysql_query(conn, instrument.c_str());
            resultado = mysql_use_result(conn);
            cout << "\n Código |" << setw(10) << "Produto" << setw(35) << "| Valor" << endl;
            cout << " ---------------------------------------------------------------------------" << endl;
            while ((row = mysql_fetch_row(resultado)) != NULL)
            {
                cout << " " << right << setw(6) << row[0] << " | " << setw(36) << left << row[1]
                     << " | R$" << setw(8) << row[2] << endl;
                cout << " ---------------------------------------------------------------------------" << endl;
            }
            mysql_free_result(resultado);

            cout << " Código Produto: ";
            getline(cin, produto);
            cout << " Quantidade: ";
            getline(cin, qtd);

            int a;                            //for choice
            cout << endl;
            cout << " Pressione 1 para SALVAR ou 2 para CANCELAR: ";
            cin >> a;

            if(a == 1){
                string instrument="INSERT INTO pdv (pdv_cliente, pdv_produto, pdv_quantidade, pdv_status) VALUES ('"+cliente+"', '"+produto+"', '"+qtd+"', 1);";
                mysql_query(conn, instrument.c_str());

                cout << " Registro feito..." << endl;
                cout << "__________________________________" << endl;
                cout << endl;
            }

            else if (a == 2)
			{
                cout<<" Registro NÃO salvo"<<endl;
                cout<<"____________________________________"<<endl;
                cout<<endl;
            }

			//if(menuretorna == 3)
			//{
            //cout << " Digite 3 para retornar ao MENU PDV: ";
            //cin >> menuretorna;
			//}

        break;
    }
}

void caixa ()
{
    caixa:
    string fechando;       //for enter more data

    system("cls");
    #include "head.cpp";
    cout << " | "; cout << "\t\t\t\t    MENU LOJA"; cout << "\t\t\t\t      |\n";
    cout << " <---------------------------------------------------------------------------->\n";
    cout << " | "; cout << "\t\t\t      PDV - PONTO DE VENDAS"; cout << "\t\t\t      |\n";
    cout << " <---------------------------------------------------------------------------->\n";
    cout << "\n ------------------------ RELAÇÃO DE VENDAS EM ABERTO ------------------------" << endl;
    cout << endl;
    MYSQL_RES *resultado;
    MYSQL_ROW row;
    conexao_banco();
    string instrument="SELECT pdv.pdv_cliente, cliente.nome, cliente.id_cliente, pdv_status FROM pdv JOIN cliente WHERE pdv.pdv_cliente = cliente.id_cliente AND pdv_status = 1 GROUP BY pdv.pdv_cliente";
    mysql_query(conn, instrument.c_str());
    resultado = mysql_use_result(conn);

    while ((row = mysql_fetch_row(resultado)) != NULL)
    {
        cout << " Código do Cliente: " << row[2] << " | " << row[1] << endl;
        cout << " ---------------------------------------------------------------------------" << endl;
    }
    mysql_free_result(resultado);

    cout << "\n De qual cliente deseja? (Digite o código): ";
    cin >> fechando;

    mysql_close(conn);

    system("cls");
    #include "head.cpp";
    cout << " | "; cout << "\t\t\t\t    MENU LOJA"; cout << "\t\t\t\t      |\n";
    cout << " <---------------------------------------------------------------------------->\n";
    cout << " | "; cout << "\t\t\t      PDV - PONTO DE VENDAS"; cout << "\t\t\t      |\n";
    cout << " <---------------------------------------------------------------------------->\n";
    cout << "\n ------------------------------ FINALIZAR VENDA ------------------------------" << endl;
    cout << endl;

    MYSQL_RES *fechar;
    MYSQL_ROW rrow;
    conexao_banco();
    string fechamento="SELECT cliente.nome, produto.nome_produto, pdv.pdv_quantidade, produto.valor_produto, (pdv.pdv_quantidade * produto.valor_produto) AS MULTI FROM pdv, produto, cliente WHERE cliente.id_cliente = pdv.pdv_cliente AND pdv.pdv_produto = produto.id_produto AND pdv_status = 1 AND pdv.pdv_cliente = '"+fechando+"'";
    mysql_query(conn, fechamento.c_str());
    fechar = mysql_use_result(conn);

    cout  << " " << setw(48) << left << "\n Produto" << setw(7) << "| Qtd" << setw(10) << " | $ Unt" << setw(8) << " | Total" << endl;
    cout << " -----------------------------------------------------------------------------" << endl;
    while ((rrow = mysql_fetch_row(fechar)) != NULL)
    {
        cout  << " " << setw(40) << left << rrow[1] << setw(8) << right << " | " << left << setw(6) << rrow[2] << left << "| R$" << left << setw(5) << rrow[3] << setw(6) << left << " | R$" << rrow[4] << endl;
        cout << " -----------------------------------------------------------------------------" << endl;
    }
    mysql_free_result(fechar);

    MYSQL_RES *total;
    MYSQL_ROW tot;
    conexao_banco();
    string totalgeral="SELECT SUM(produto.valor_produto * pdv.pdv_quantidade) AS SOMA FROM produto, pdv, cliente WHERE cliente.id_cliente = pdv.pdv_cliente AND pdv.pdv_produto = produto.id_produto AND pdv_status = 1 AND pdv.pdv_cliente = '"+fechando+"'";
    mysql_query(conn, totalgeral.c_str());
    total = mysql_use_result(conn);

    while ((tot = mysql_fetch_row(total)) != NULL)
    {
        cout << setw(67) << right << " VALOR TOTAL | "<< left << "R$ " << tot[0] << endl;

    }
    mysql_free_result(total);

    int confirmacao;
    cout << "\n Confirma o pagamento? (1 - Sim  |   0 - Não): ";
    cin >> confirmacao;

    if (confirmacao == 1) {
        string instrument="UPDATE pdv SET pdv_status = 2 WHERE pdv_cliente = '"+fechando+"'";
        mysql_query(conn, instrument.c_str());
        cout << "-------------------------------------------------" << endl;
        cout << "        PAGAMENTO REALIZADO COM SUCESSO!" << endl;
        cout << "-------------------------------------------------" << endl;
        Sleep(4000);
        system("cls");
    }

    mysql_close(conn);
}

