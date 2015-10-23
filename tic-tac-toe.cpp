// tip-tap.cpp: главный файл проекта.
// Царкевич Наталья, гр.121702, задание крестики-нолики.
#include "stdafx.h"
#include <iostream>
#include "Game.h"              //перегрузка лагает((( один минус только :))

int kod,size,x,y,num;
void print(char **matrix, int size);
void main()
{ 
  setlocale(0,""); 
  char **matrix;
  std::cout<<"Выберите:"<<std::endl<<"Новая игра -1"<<std::endl<<"Выход -0"<<std::endl;
  std::cin>> kod;                                            
  if(kod == 1)
  {  
	 std::cout<<"Новая игра:"<<std::endl;
	 std::cout<<"введите размер поля=";
	 std::cin>>size;
	 if(size < 3)
	 {
       std::cout<<"бессмысленная игра. Введите ещё раз= "<<std::endl;
	   std::cin>>size;
	 }
	 if(size > 5)
	 {
	  std::cout<<"Бессмысленная игра, вам же не интересно будет :(("<<std::endl;
	 }
     Game game(size);
	 while(game.Pobeda() == 0)
	 {  
		std::cout<<std::endl;
		std::cout<<"введите номер строки=";
		std::cin>>x;                                            
		x--;
		std::cout<<"введите номер столбца=";
		std::cin>>y;
		y--;
		std::cout<<std::endl;
		if ( x >= 0 && x < size && y >= 0 && y < size)
		{
		  if(game.Hod(x,y))
		    {
		     matrix = game.getPtrTab();
		     print(matrix, game.getSize());
		     }
		  else std::cout<<"клетка занята"<<std::endl<<std::endl;
	    }
        else std::cout<<"Неправильные данные"<<std::endl<<std::endl;

		if (game.Pobeda() == 1) {
			std::cout<<"Ура! победил 1 игрок"<<std::endl;
			break;
		}
		if (game.Pobeda() == -1) {
			std::cout<<"Ура! победил 2 игрок"<<std::endl;
			break;
		}
		if (game.Pobeda() == 2) {
			std::cout<<"Ничья :("<<std::endl;
			break;
		}
	 }
  }
  if( kod == 0) return;
    
    system("pause");

}
//вывод нумерации и таблички с символами
void print(char **matrix, int size)
{
int i,j;
for (i = 0; i <= size; i++)
std::cout<<i<<" ";
std::cout<<std::endl;
for(i = 0; i < size; i++)
{
std::cout<<i + 1<<" ";
for(j = 0; j < size; j++)
std::cout<<matrix[i][j]<<" ";
std::cout<<std::endl;
}
}
