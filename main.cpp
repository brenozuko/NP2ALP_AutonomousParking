#include <iostream>
#include<iomanip>

//Breno Costa Zukowski Marques RA: 2840482011010
//Jean Luca Dos Santos Silva RA: 2840482011044

#define RED "\033[31m"
#define WHITE "\033[0m"


using namespace std;

struct Veiculo
{
  string placa;
  int tipo;
  float preco;
  int hora;
  int minuto;


    void inserir(int sth, int stm) //Método de inserção em struct, técnica aprendida no YouTube
    {
      hora = sth;
      minuto = stm;
    }

    void mostrarHora()
    {
      cout << "Hora de entrada: ";
      cout << setfill('0') << setw(2) << hora;
      cout <<  ":";
      cout << setfill('0') << setw(2) << minuto << endl;
    }
  
};

struct Relogio
{
  int horas;
  int minutos;


  void insere(int sthoras, int stminutos)
  {
      horas = sthoras;
      minutos = stminutos;
  }

  void mostrarHora()
  {
      cout << "Hora atual: ";
      cout << setfill('0') << setw(2) << horas;
      cout <<  ":";
      cout << setfill('0') << setw(2) << minutos << endl;
  }
};



void mostrarVeiculos(float preco,Veiculo Andar[], int tam);
void inserirCarro(Veiculo car, Veiculo Andar[], int indice, int tam);
void retirarCarro(string placa, Veiculo Andar[], int tam);
void gerarRelatorio(Veiculo Andar[], Relogio Tempo);
void contaTempo(Relogio *Tempo);

int main()
{
  //Andar 1
  Veiculo CarrosAndar1[20];
  Veiculo CamionetesAndar1[30];
  //Andar 2
  Veiculo Andar2[25];
  //Andar 3
  Veiculo Andar3[10];
  //Andar 4
  Veiculo Andar4[15];
  //Andar 5
  Veiculo Andar5[20];

  int opc, tipo,pos;
  int hora,minuto;
  int andar;
  Relogio Expediente;
  Veiculo Automovel; //Variavel que vai assumir qualquer tipo de Veiculo

  cout <<  "HORÁRIO DE INÍCIO DO EXPEDIENTE [hh:mm]: ";
  cin >> hora;
  cin.get();
  cin >> minuto;
  Expediente.insere(hora,minuto);


  
  while(true)
  {

    contaTempo(&Expediente); 
    Expediente.mostrarHora();

      
    cout << "1 - Estacionar um Veiculo, 2 - Retirar um Veiculo, 3-Gerar relatório, 4-Ver Veiculos de um Andar: ";
    cin >> opc;

    if(opc == 1)
    {
      cout << "Qual o tipo de seu Veiculo [1-Carro,2-Camionete,3-Super-Esportivo]: ";
      cin >> tipo;
      
      cout << "Qual a placa de seu carro: ";
      cin >> Automovel.placa;



      switch(tipo) //Este switch serve para definir os atributos especificos de cada tipo de Veiculo
      {
        case 1:
          Automovel.preco = 5;
          Automovel.tipo = 1;
          Automovel.inserir(Expediente.horas,Expediente.minutos);
          Automovel.mostrarHora();
          
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
          retirarCarro(placaVerifica, CarrosAndar1, 20);
        }
        else
        {
         retirarCarro(placaVerifica, CamionetesAndar1, 30);  
        }
      }
      else if(andar == 2)
      {
        retirarCarro(placaVerifica, Andar2, 25);
      }
      else if(andar == 3)
      {
        retirarCarro(placaVerifica, Andar3, 10);
      }
      else if(andar == 4)
      {
        retirarCarro(placaVerifica, Andar4, 15);
      }
      else if(andar == 5)
      {
        retirarCarro(placaVerifica, Andar5, 20);
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
          mostrarVeiculos(7, CamionetesAndar1, 20);
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
    string pause;
    cout << RED << endl;
    cout << "=--------------------=" << endl;
    cout << "para sair digite -1: " << endl;;
    cout << "=--------------------=" << WHITE<< endl;
    cin >> pause;
    if(pause == "-1")
    {
      break;
    }
    system("clear");
  }
  return 0;
}

void inserirCarro(Veiculo car, Veiculo Andar[], int indice, int tam)
{
  for(int i = 0; i < tam; i++)
  {
    if(i == indice && Andar[i].preco != car.preco)
    {
      Andar[i] = car;
    }
    else if(i == indice && Andar[i].preco == car.preco)
    {
      cout << "=- Ha um veiculo nesta vaga! -="<< endl;
    }
  }
}

void retirarCarro(string placa, Veiculo Andar[], int tam)
{

  for(int i = 0; i < tam; i++)
  {
    if(Andar[i].placa == placa)
    {
      Andar[i].preco = 0;
      cout << "Veiculo Retirado."<<endl;
    }
  }
}

void mostrarVeiculos(float preco,Veiculo Andar[], int tam)
{
  for(int i = 0; i < tam; i++)
  {
    if(Andar[i].preco != preco)
    {
      cout << "[ "<<i<<"  ]  ";
    }
    else
    {
      cout << "[ X ] ";
    }
    if((i+1) % 5 == 0)
    {
      cout << endl;
    }
  }
}

void contaTempo(Relogio *Tempo)
{
    Tempo->minutos += 10;
        if(Tempo->minutos > 59)
        {
            Tempo->minutos = 00;
            Tempo->horas++;
            if(Tempo->horas == 24)
            {
               Tempo->horas = 00;
               Tempo->minutos = 00;
            }
        }
}




