#include<iomanip>

using namespace std;

#ifndef _AUTONOMOUS_
#define _AUTONOMOUS_

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

struct Caixa
{
  float faturamentoTotal = 0;
  float faturamentoMedio = 0;
  int qtdCarros = 0;
  int qtdCamionetes = 0;
  int qtdSport = 0;
};

void mostrarVeiculos(float preco,Veiculo Andar[], int tam);
void inserirCarro(Veiculo car, Veiculo Andar[], int indice, int tam);
float retirarCarro(string placa, Veiculo Andar[], int tam, Relogio Tempo);
float calcularPreco(Veiculo car,float preco, Relogio Tempo);
float faturamentoMedio(Relogio Inicio, Relogio Fim, Caixa faturamento);
void contaTempo(Relogio *Tempo);

#endif
