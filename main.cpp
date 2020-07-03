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


void passaTempo(){
    while(horas <= 24){   
        minutos += 10;
        if(minutos > 59){
            minutos = 00;
            horas++;
            if(horas == 24){
                horas = 00;
                minutos = 00;
                break;
            }
        }
        cout << horas << ":" << minutos << endl;
    }
}

} Relogio;



void mostrarVeiculos(float preco,Veiculo Andar[], int tam);
void inserirCarro(Veiculo car, Veiculo Andar[], int indice, int tam);
void retirarCarro(Veiculo car, Veiculo Andar[], int indice, int tam);
void calcularPreco(Veiculo car, int h, int m);

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
  Veiculo Automovel; //Variavel que vai assumir qualquer tipo de Veiculo
  while(true)
  {
    cout << "1 - Estacionar um Veiculo, 2 - Retirar um Veiculo";
    cin >> opc;

    if(opc == 1)
    {
      cout << "Qual o tipo de seu Veiculo [1-Carro,2-Camionete,3-Super-Esportivo]: ";
      cin >> tipo;
      
      cout << "Qual a placa de seu carro: ";
      cin >> Automovel.placa;

      cout << "Horário de entrada [hh:mm]: ";
      cin >> hora;
      cin.get();
      cin >> minuto;



      switch(tipo) //Este switch serve para definir os atributos especificos de cada tipo de Veiculo
      {
        case 1:
          Automovel.preco = 5;
          Automovel.tipo = 1;
          Automovel.inserir(hora,minuto);
          
          //Escolha do andar especifico para cada tipo de Veiculo
          cout << "Em qual andar deseja Estacionar [1 ou 2]: ";
          cin >> andar;

          cout << "Vagas Carros - Andar "<< andar << endl;
          mostrarVeiculos(5, CarrosAndar1, 20);

          cout << "Em qual posicao deseja adicionar: ";
          cin >> pos;
          
          inserirCarro(Automovel, CarrosAndar1,pos, 20);
          while(andar != 1 && andar != 2)
          {
            cout << "Em qual andar deseja Estacionar [1 ou 2]: ";
            cin >> andar;
          }
          
        break;
        case 2:
          Automovel.preco = 7;
          Automovel.tipo = 2;
          Automovel.inserir(hora,minuto);

          cout << "Vagas Camionetes Andar "<<andar << endl;
          mostrarVeiculos(Automovel.preco, CarrosAndar1, 30);

          cout << "Em qual posicao deseja adicionar o Veiculo: ";
          cin >> pos;

          inserirCarro(Automovel, CarrosAndar1, pos, 30);
          cout << "Em qual andar deseja Estacionar [1, 3 ou 5]: ";
          cin >> andar;
          while(andar != 1 && andar != 3 && andar != 5)
          {
            cout << "Em qual andar deseja Estacionar [1, 3 ou 5]: ";
            cin >> andar;
          }

        break;
        case 3:
        cout 
          Automovel.preco = 10;
          Automovel.tipo = 3;
          Automovel.inserir(hora,minuto);
          cout << Automovel.hora << ":" << Automovel.minuto << endl;



          cout << "Em qual andar deseja Estacionar [4]: ";
          cin >> andar;
          while(andar != 4)
          {
            cout << "Em qual andar deseja Estacionar [4]: ";
            cin >> andar;
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

