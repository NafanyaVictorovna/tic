#include "stdafx.h"
#include "Game.h"
#include <iostream>

 Game::Game() {}
 Game::Game(int size){
n = size; 
k = 1;
tab = new char * [n];
for (i = 0; i < n; i++)
tab[i] = new char [n];
for(i=0;i<n;i++){
	for(j=0;j<n;j++)
        tab[i][j] =' ';                        
}
}

///перегрузка для получения значения       
char* Game::operator [](int num)      ///- номер элемента
{
   if(tab[i][j] != ' ')
	   return *tab; 
   if(tab[i][j] == ' ')
      tab[i][j] = k % 2 ? 'x' : 'o'; 
   return *tab;
} 


///функция хода, просит строку и столбец, и записывает туда что-то.функция проверки на возможность хода и занятость клетки 
 bool Game::Hod(int x,int y)
 {
	 if (tab[x][y] == ' ') {
		tab[x][y] = k % 2 ? 'x' : 'o';
		k++;     
		return true;
	 }
	 return false;
 }
int Game::getSize()
 {
	 return n;
 }
 char **Game::getPtrTab()
 {
	 return tab;
 }
 ///функция победы, по идее считатет кто победит
 int Game::Pobeda()
 {
  int kom = 0;               ///счётчик, для определения количества одинаковых символов в строке/столбце/диагонали
  int kh;                    ///количестов ходов

 while(k>(2*n-1) && k <= n*n)
 { 
	   for(i=0;i<n;i++) { 
	kh = 0;
	for(j=0;j<n;j++){
		if(tab[i][j] == 'x')
		{
           kom = 1; 
		   kh++;	
	   }	

        if(tab[i][j] == 'o')
		{
	       kom = -1;
		   kh--;
		} 
		 if(tab[i][j] == ' ')
	   {
		   kh = 0;
	   } 
	} 
	if(kh == n)
	return 1;
	if(kh == -1*n)
	return -1;
	   }

	   for(j=0;j<n;j++){ 
    kh = 0;
	for(i=0;i<n;i++){
		if(tab[i][j] == 'x')
		{
           kom = 1; 
		   kh++;	
	    }	
        if(tab[i][j] == 'o')
		{
	       kom = -1;
		   kh--;
		} 
	    if(tab[i][j] == ' ')
	    {
		   kh = 0;
	    } 
	}   
	if(kh == n)
	return 1;
	if(kh == -1*n)
	return -1;
	   }
    for(i=0;i<n;i++){
		if(tab[i][i] == 'x')
		{
			kom = 1;
		    kh++;
		}
       if(tab[i][i] == 'o')
	   {
		   kom = -1;
	       kh--;
	   }

	if(kh == n)
	return 1;
	if(kh == -1*n)
	return -1;
	}
	     for(i=n;i<-1;i--){
		if(tab[i][i] == 'x')
		{
			kom = 1;
		    kh++;
		}
       if(tab[i][i] == 'o')
	   {
		   kom = -1;
	       kh--;
	   }
	   if(tab[i][j] == ' ')
	   {
		   kh = 0;
	   } 
	
	if(kh == n)
	return 1;
	if(kh == -1*n)
	return -1;
		 }
	 if(kom != 0 && k == n*n)
		return 2;
	
	else 
		return 0;
	                                           
	   }
	   
 }
 Game::~Game()          
 {
  for(i=0;i<n;i++)
	 delete [] tab[i];               ///освобождаем память занимаемую матрицей
   delete [] tab;
 }