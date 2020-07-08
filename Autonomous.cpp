#include<iostream>
#include<iomanip>
#include "Autonomous.h"

using namespace std;

#define RED "\033[31m"
#define WHITE "\033[0m"
#define GREEN "\033[32m"

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
      cout << RED << "=- Ha um veiculo nesta vaga! -=" << WHITE << endl;
    }
  }
}

float retirarCarro(string placa, Veiculo Andar[], int tam, Relogio Tempo)
{
  float preco;
  float faturamento = 0;

  for(int i = 0; i < tam; i++)
  {
    Veiculo car;
    if(Andar[i].placa == placa)
    {
      preco = Andar[i].preco;
      car = Andar[i];
      Andar[i].preco = 0;
      faturamento = calcularPreco(car,preco,Tempo);
      cout << "=----------------------------=" << GREEN << endl;
      cout << "Veiculo Retirado Com Sucesso!" << WHITE <<endl;
      cout << "=----------------------------=" << endl;
      return faturamento;
    }
    else if( i == tam-1 && Andar[i].placa != placa)
    {
      cout << RED << "=--------------------=" << endl;
      cout << "Carro nao encontrado!" << endl;
      cout << "=--------------------=" << WHITE << endl;
    }
  }
  return faturamento;
}

void mostrarVeiculos(float preco,Veiculo Andar[], int tam)
{
  for(int i = 0; i < tam; i++)
  {
    if(Andar[i].preco != preco)
    {
      if(i < 10)
      {
        cout << "[ " << i << "  ] ";
      }
      else
      {
        cout << "[ "<<i<<" ] ";
      }
    }
    else
    {
      cout << "[ " << GREEN << "X" << WHITE <<"  ] ";
    }
    if((i+1) % 5 == 0)
    {
      cout << endl;
    }
  }
}

void contaTempo(Relogio *Tempo)
{
  Tempo->minutos += 30;
  if(Tempo->minutos > 60)
  {
    Tempo->minutos = Tempo->minutos - 60;
    Tempo->horas++;
    if(Tempo->horas == 24)
    {
      Tempo->horas = 0;
      Tempo->minutos = 0;
    }
  }
}


float calcularPreco(Veiculo car,float preco, Relogio Tempo)
{        
  float timeH;
  float timeM;
  float convertTime;
  float debito;

  if (car.hora > Tempo.horas)
  {
	  timeH =  (24 - car.hora) + Tempo.horas;
	  if (car.minuto > Tempo.minutos)
    {
	    timeH = timeH - 1; 
	  }
	}
  else
  {
    timeH = Tempo.horas - car.hora;
    if(car.minuto > Tempo.minutos)
    {
      timeH = timeH - 1;
    }
	}
	
	if (car.minuto > Tempo.minutos)
  {
		timeM = (60 - car.minuto) + Tempo.minutos;
	}
  else
  {
		timeM = Tempo.minutos - car.minuto;
	}
  convertTime = ((timeH * 60) + timeM)/60;
  debito = preco * convertTime;

  return debito;
};

float faturamentoMedio(Relogio Inicio, Relogio Fim, Caixa faturamento)
{

  float timeH;
  float timeM;
  float convertTime;
  float faturamentoMedio;

  if (Inicio.horas > Fim.horas)
  {
	  timeH =  (24 - Inicio.horas) + Fim.horas;
	  if (Inicio.minutos > Fim.minutos)
    {
	    timeH = timeH - 1; 
	  }
	}
  else
  {
    timeH = Fim.horas - Inicio.horas;
    if(Inicio.minutos > Fim.minutos)
    {
      timeH = timeH - 1;
    }
	}
	
	if (Inicio.minutos > Fim.minutos)
  {
		timeM = (60 - Inicio.minutos) + Fim.minutos;
	}
  else
  {
		timeM = Fim.minutos - Inicio.minutos;
	}
  convertTime = ((timeH * 60) + timeM)/60;
  faturamentoMedio = faturamento.faturamentoTotal/convertTime;

  return faturamentoMedio;
};