#pragma once
#ifndef GAME_H
#define GAME_H
ref class Game
{
	private:
      char **tab;                 /// ������� �������� ����
	  int i,j,n,k;       ///i, j -������� �������; n - ������ ���� ����; k - �������� ����
	  bool c;
    public:
    Game();                              ///����������� �� ���������
    Game(int);            ///�����������, ������� �������������� ������� ���� ���������
	bool Hod(int x, int y);   ///�����, ��� �������� �������� ����, ���������� ������� ����� �����
	int Pobeda();      ///�����, ������������ ������ ������(1 ��� 2) 
	                       ///��������� ������, ����� �������, � ����� ���������
	char* operator [](int); ///���������� ��������� [] ��� ������ ������� ��������� ���������� ��� ��������� � �� �������(x/o)
	int Game::getSize(); /// ��������� ������� �������� ����
	char **Game::getPtrTab(); ///������� �������� ���� � ���������, ������������� �����
	~Game();                   ///����������

};
#endif;

