// tip-tap.cpp: ������� ���� �������.
// �������� �������, ��.121702, ������� ��������-������.
#include "stdafx.h"
#include <iostream>
#include "Game.h"              //���������� ������((( ���� ����� ������ :))

int kod,size,x,y,num;
void print(char **matrix, int size);
void main()
{ 
  setlocale(0,""); 
  char **matrix;
  std::cout<<"��������:"<<std::endl<<"����� ���� -1"<<std::endl<<"����� -0"<<std::endl;
  std::cin>> kod;                                            
  if(kod == 1)
  {  
	 std::cout<<"����� ����:"<<std::endl;
	 std::cout<<"������� ������ ����=";
	 std::cin>>size;
	 if(size < 3)
	 {
       std::cout<<"������������� ����. ������� ��� ���= "<<std::endl;
	   std::cin>>size;
	 }
	 if(size > 5)
	 {
	  std::cout<<"������������� ����, ��� �� �� ��������� ����� :(("<<std::endl;
	 }
     Game game(size);
	 while(game.Pobeda() == 0)
	 {  
		std::cout<<std::endl;
		std::cout<<"������� ����� ������=";
		std::cin>>x;                                            
		x--;
		std::cout<<"������� ����� �������=";
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
		  else std::cout<<"������ ������"<<std::endl<<std::endl;
	    }
        else std::cout<<"������������ ������"<<std::endl<<std::endl;

		if (game.Pobeda() == 1) {
			std::cout<<"���! ������� 1 �����"<<std::endl;
			break;
		}
		if (game.Pobeda() == -1) {
			std::cout<<"���! ������� 2 �����"<<std::endl;
			break;
		}
		if (game.Pobeda() == 2) {
			std::cout<<"����� :("<<std::endl;
			break;
		}
	 }
  }
  if( kod == 0) return;
    
    system("pause");

}
//����� ��������� � �������� � ���������
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
