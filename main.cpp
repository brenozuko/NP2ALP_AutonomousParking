#include <iostream>
#include<iomanip>
using namespace std;

typedef struct
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
  
}Veiculo;

typedef struct  {
int horas;
int minutos;


void insere(int sthoras, int stminutos){
    horas = sthoras;
    minutos = stminutos;
}

void mostrarHora(){
    cout << "Hora atual: " << horas << ":" << minutos << endl; 
}

} Relogio;



void mostrarVeiculos(float preco,Veiculo Andar[], int tam);
void inserirCarro(Veiculo car, Veiculo Andar[], int indice, int tam);
void retirarCarro(Veiculo car, Veiculo Andar[], int indice, int tam);
void calcularPreco(Veiculo car, int h, int m);
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

 cout << "Horário de início do expediente [hh:mm]: ";
 cin >> hora;
 cin.get();
 cin >> minuto;
   


  
  while(true)
  {
      
    Expediente.insere(hora,minuto);
    contaTempo(&Expediente);
    Expediente.mostrarHora();

      
    cout << "1 - Estacionar um Veiculo, 2 - Retirar um Veiculo";
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
          Automovel.inserir(hora,minuto);
          
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
          Automovel.inserir(hora,minuto);

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
          Automovel.inserir(hora,minuto);
          cout << "Em qual andar deseja Estacionar [4]: ";
          cin >> andar;
          while(andar != 4)
          {
            cout << "Em qual andar deseja Estacionar [4]: ";
            cin >> andar;
          }
          
          cout << "Vagas Super-Esportivos - Andar "<< andar << endl;
          if(andar == 4)
          {
            mostrarVeiculos(5, CarrosAndar1, 20);
            cout << "Em qual posicao deseja adicionar: ";
            cin >> pos;
            inserirCarro(Automovel, Andar4,pos,15);
          }
          
        break;
      }
    }
    else if(opc == 2){

      cout << "Qual a placa de seu carro: ";
      cin >> Automovel.placa;

      cout << "Horário de saída [hh:mm]: ";
      cin >> hora;
      cin.get();
      cin >> minuto;
        
    }
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
  }
}

void retirarCarro(Veiculo car, Veiculo Andar[], int indice, int tam)
{

  for(int i = 0; i < tam; i++)
  {
    if(i == indice && Andar[i].preco == car.preco)
    {
      Andar[i].preco = 0;
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

void contaTempo(Relogio *Tempo) {
    Tempo->minutos += 10;
        if(Tempo->minutos > 59){
            Tempo->minutos = 00;
            Tempo->horas++;
            if(Tempo->horas == 24){
               Tempo->horas = 00;
               Tempo->minutos = 00;
            }
        }
}


