#include <iostream>

using namespace std;

typedef struct
{
  string placa;
  int tipo;
  float preco;
  int horaInicial, minutoInicial;
}Veiculo;

typedef struct 
{
  int horas;
  int minutos;
}Relogio;

typedef struct
{
  //Andar 1
  Veiculo Andar1Carros[20]; // 20 carros, 30 camionetes
  Veiculo Andar1Camionetes[30];

  //Andar 2
  Veiculo Andar2[25]; // 25 carros

  //Andar 3
  Veiculo Andar3[10]; // 10 camionetes

  //Andar 4
  Veiculo Andar4[15]; // 15 super esportivos

  //Andar 5
  Veiculo Andar5[20]; // 20 camionetes
}Estacionamento;

void ContaTempo(Relogio *Tempo);
void IniciaVeiculo(Veiculo *car, Relogio *tempo, int tipo);
int main()
{
    Relogio Dia;

    Dia.horas = 8;
    Dia.minutos = 0;

    Veiculo car;
    Estacionamento AutonomousParking;

    int opc = 0;
    while(opc != 3)
    {

    
      ContaTempo(&Dia);  
      cout << "Hora atual: " << Dia.horas << ":" << Dia.minutos << endl; 

      cout << "1 - Estacionar Veiculo, 2 - Retirar Veiculo, 3- Fechar Expediente:";
      cin >> opc;
      


      if(opc == 1)
      {
        int tipo;
        cout << "Qual o tipo do veiculo[1-Carro, 2-Camionete, 3-Super-Esportivo]: ";
        cin >> tipo;
        IniciaVeiculo(&car, &Dia, tipo);

      }
      else if(opc == 2)
      {
        int andar;
        cout << "Qual Andar deseja acessar: ";
        cin >> andar;
        switch (andar)
        {
          case 1:
          break;
          case 2:
          break;
          case 3:
          break;
          case 4:
          break;
          case 5:
          break;
        }
      }
     
    }

  return 0;
}

void ContaTempo(Relogio *Tempo)
{
  Tempo->minutos += 10;
  if(Tempo->minutos >= 60)
  {
    Tempo->minutos -= 60;
    Tempo->horas++;
  }
  if(Tempo->horas >= 24)
  {
    Tempo->horas -= 24;
  }
}

void IniciaVeiculo(Veiculo *car, Relogio *tempo, int tipo)
{
  car->horaInicial = tempo->horas;
  car->minutoInicial = tempo->minutos;

  cout << "Qual sua placa: ";
  cin >> car->placa;

  cout << endl;  
  cout << "=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*" << endl;  
  cout << "Carro: " << car->placa << endl;
  cout << "Hora de entrada: "<< car->horaInicial << ":" << car->minutoInicial << endl;
  cout << "Cobrança iniciada." << endl;
  cout << "=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*" << endl << endl;  
 
}