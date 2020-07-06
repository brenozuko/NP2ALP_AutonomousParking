#include <iostream>
#include "Autonomous.h"
#include<iomanip>

//Breno Costa Zukowski Marques RA: 2840482011010
//Jean Luca Dos Santos Silva RA: 2840482011044

using namespace std;

#define RED "\033[31m"
#define WHITE "\033[0m"
#define GREEN "\033[32m"
#define BLACK "\033[30m"
#define YELLOW "\033[33m"
#define BLUE   "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define GRAY    "\033[37m"

int main()
{
  Veiculo CarrosAndar1[20];
  Veiculo CamionetesAndar1[30];
  Veiculo Andar2[25];
  Veiculo Andar3[10];
  Veiculo Andar4[15];
  Veiculo Andar5[20];

  int lotacao = 0; //variavel para identificar a super lotacao de veiculos
  int opc, tipo,pos;
  int hora,minuto;
  int andar;

  Relogio InicioExpediente;
  Relogio Expediente;
  Veiculo Automovel; //Variavel que vai assumir qualquer tipo de Veiculo
  Caixa Fluxo; 

  cout <<  "HORÁRIO DE INÍCIO DO EXPEDIENTE [hh:mm]: ";
  cin >> hora;
  cin.get();
  cin >> minuto;
  Expediente.insere(hora,minuto); //Método responsável por receber os valores de hora e minuto, passando-os para a Struct.
  InicioExpediente.insere(hora,minuto);

  while(true)
  {

    contaTempo(&Expediente); 
    Expediente.mostrarHora();

    cout << GREEN << "1 - Estacionar um Veiculo, 2 - Retirar um Veiculo, 3-Gerar relatório, 4 - Ver Veiculos de um Andar, 5 - Opção Especial: " << WHITE;
    cin >> opc;

    if(opc == 1)
    {
      cout << "Qual o tipo de seu Veiculo [1-Carro,2-Camionete,3-Super-Esportivo]: ";
      cin >> tipo;
      
      cout << "Qual a placa de seu carro: ";
      cin >> Automovel.placa;

      lotacao += 1;

      switch(tipo) //Este switch serve para definir os atributos especificos de cada tipo de Veiculo
      {
        case 1:
          Automovel.preco = 5;
          Automovel.tipo = 1;
          Fluxo.qtdCarros += 1;
          Automovel.inserir(Expediente.horas,Expediente.minutos); //Métodos de Struct utilizados para inserir dados
          Automovel.mostrarHora(); //Métodos de struct utilizados para mostrar dados

          //Escolha do andar especifico para cada tipo de Veiculo
          cout << "Em qual andar deseja Estacionar [1 ou 2]: ";
          cin >> andar;
          while(andar != 1 && andar != 2)
          {
            cout << "Em qual andar deseja Estacionar [1 ou 2]: ";
            cin >> andar;
          }
          
          cout << "Vagas Carros - Andar "<< andar << endl;
          if(andar == 1)
          {
            mostrarVeiculos(5, CarrosAndar1, 20); 
            cout << "Em qual posicao deseja adicionar: ";
            cin >> pos;
            inserirCarro(Automovel, CarrosAndar1, pos, 20);
          }
          else if(andar == 2)
          {
            mostrarVeiculos(5, Andar2, 25);
            cout << "Em qual posicao deseja adicionar: ";
            cin >> pos;
            inserirCarro(Automovel, Andar2,pos, 25);
          }
        break;
        case 2:
          Automovel.preco = 7;
          Automovel.tipo = 2;
          Fluxo.qtdCamionetes += 1;
          Automovel.inserir(Expediente.horas,Expediente.minutos);
          Automovel.mostrarHora();
                   
          cout << "Em qual andar deseja Estacionar [1, 3 ou 5]: ";
          cin >> andar;
          while(andar != 1 && andar != 3 && andar != 5)
          {
            cout << "Em qual andar deseja Estacionar [1, 3 ou 5]: ";
            cin >> andar;
          }
          
          cout << "Vagas Camionetes - Andar "<< andar << endl;
          if(andar == 1)
          {
            mostrarVeiculos(7, CamionetesAndar1, 30);
            cout << "Em qual posicao deseja adicionar: ";
            cin >> pos;
            inserirCarro(Automovel, CamionetesAndar1, pos, 30);
          }
          else if(andar == 3)
          {
            mostrarVeiculos(7, Andar3, 10);
            cout << "Em qual posicao deseja adicionar: ";
            cin >> pos;
            inserirCarro(Automovel, Andar3, pos, 10);
          }
          else if(andar == 5)
          {
            mostrarVeiculos(7, Andar5, 20);
            cout << "Em qual posicao deseja adicionar: ";
            cin >> pos;
            inserirCarro(Automovel, Andar5, pos, 20);
          }
        break;
        case 3:
          Automovel.preco = 10;
          Automovel.tipo = 3;
          Fluxo.qtdSport += 1;
          Automovel.inserir(Expediente.horas,Expediente.minutos);
          Automovel.mostrarHora();
          andar = 4;
          
          cout << "Vagas Super-Esportivos - Andar "<< andar << endl;
          if(andar == 4)
          {
            mostrarVeiculos(10, Andar4, 15);
            cout << "Em qual posicao deseja adicionar: ";
            cin >> pos;
            inserirCarro(Automovel, Andar4, pos, 15);
          }
        break;
      }
    }
    else if(opc == 2)
    {
      string placaVerifica;  
      cout << "De qual Andar deseja retirar um Veiculo: ";
      cout << "[1º Andar (1), 2º Andar(2), 3° Andar(3), 4° Andar(4), 5°Andar(5): ";
      cin >> andar;

      if(andar == 1)
      {
        int opt;  
        cout << "Carro(1) ou camionete(2): " << endl;
        cin >> opt;

        cout << "Qual a placa de seu carro: ";
        cin >> placaVerifica;

        if(opt == 1)
        {
          Fluxo.faturamentoTotal += retirarCarro(placaVerifica, CarrosAndar1, 20, Expediente);
        }
        else
        {
          Fluxo.faturamentoTotal += retirarCarro(placaVerifica, CamionetesAndar1, 30, Expediente);
        }
      }
      else if(andar == 2)
      {
        cout << "Qual a placa de seu carro: ";
        cin >> placaVerifica;
        Fluxo.faturamentoTotal += retirarCarro(placaVerifica, Andar2, 25, Expediente); 
      }
      else if(andar == 3)
      {
        cout << "Qual a placa de seu carro: ";
        cin >> placaVerifica;
        Fluxo.faturamentoTotal += retirarCarro(placaVerifica, Andar3, 10, Expediente);
      }
      else if(andar == 4)
      {
        cout << "Qual a placa de seu carro: ";
        cin >> placaVerifica;
        Fluxo.faturamentoTotal += retirarCarro(placaVerifica, Andar4, 15, Expediente);
      }
      else if(andar == 5)
      {
        cout << "Qual a placa de seu carro: ";
        cin >> placaVerifica;
        Fluxo.faturamentoTotal += retirarCarro(placaVerifica, Andar5, 20, Expediente);
      }
    }
    else if(opc == 3)
    {
      cout << RED << "=- Relatorio -=" << WHITE << endl;
      cout << "Total de Carros Atendidos: " << Fluxo.qtdCarros << endl;
      cout << "Total de Camionetes Atentidas: " << Fluxo.qtdCamionetes << endl;
      cout << "Total de Super-Esportivos Atentidos: " << Fluxo.qtdSport << endl;
      cout << fixed << setprecision(2);
      cout << "Total de faturamento: R$" << Fluxo.faturamentoTotal << endl;
      cout << "Média de faturamento por hora: R$ " << faturamentoMedio(InicioExpediente, Expediente, Fluxo) << endl;
      if(lotacao - 120 > 0)
      {
      cout << "Veiculo nao atendidos por super-lotacao: " << lotacao - 120 << endl;
      }
      else
      {
        cout << "Veiculos nao atendidos por super-lotacao: " << 0 << endl;
      }
    }
    else if(opc == 4)
    {
      cout << "Qual andar deseja acessar[1°,2°,3°,4° ou 5°]: ";
      cin >> andar;
      if(andar == 1)
      {
        int escolha;
        cout << "Acessar [1-Carros, 2-Camionetes]: ";
        cin >> escolha;
        if(escolha == 1)
        {
          mostrarVeiculos(5, CarrosAndar1, 20);
        }
        else if(escolha == 2)
        {
          mostrarVeiculos(7, CamionetesAndar1, 30);
        }
      }
      else if(andar == 2)
      {
        mostrarVeiculos(5, Andar2, 25);
      }
      else if(andar == 3)
      {
        mostrarVeiculos(7, Andar3, 10);
      }
      else if(andar == 4)
      {
        mostrarVeiculos(10, Andar4, 15);
      }
      else if(andar == 5)
      {
        mostrarVeiculos(10, Andar4, 15);
      }
    }
    else if(opc == 5)
    {
      string easteregg = "DA UM 10 AE LUSKINHA ";
      int j = 0;
      cout << endl;
      for(int i = 0; i < easteregg.length(); i++, j++)
      {
        if(j % 2 == 0)
        {
          cout << GREEN;
        }
        else if(j % 3 == 0)
        {
          cout << YELLOW;
        }
        else
        {
          cout << BLUE;
        }
        cout << easteregg[i];
      }
      cout << GREEN <<  ":)" << endl;
    }
    
    string pause;
    cout << RED << endl;
    cout << "=----------------------------------------------------=" << endl;
    cout << "para sair digite -1 ou qualquer tecla para continuar: " << endl;;
    cout << "=----------------------------------------------------=" << WHITE << endl;
    cin >> pause;
    if(pause == "-1")
    {
      break;
    }
    system("clear");
  }
  return 0;
}