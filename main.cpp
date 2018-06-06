// Author Anirudh Yadav @coderMogly
// Licence: Use it as you wish



#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <list>
#include <bits/stdc++.h>
#include "graph.h"
#include "edge.h"
#include "vertex.h"
#include "point.h"
#include <fstream>
#include <math.h>
#include "game.h"

using namespace std;



int main(){
	int size = 0;
	cout<<"WELCOME TO THE GAME OF HEX"<<endl;
	cout<<"Enter the size of the board you want to play on:";
	cin>>size;
	graph board = graph(size);  // initializing the board.
	cout<<"The player choosing CROSS will get the first chance."<<endl<<"The aim of player 1(CROSS) is to make a horizontal connection"<<endl;
	cout<<"The player choosing ZERO will get the second chance."<<endl<<"The aim of player 2(ZERO) is to make a vertical connection"<<endl;
	cout<<"This is your board"<<endl;
	print_board(board);			//printing the board using a function in game.cpp
	cout<<"each node is represented by a tuple (row,column). row(1-size). column(1-size)"<<endl;
	int temp_row1=0;
	int temp_col1=0;
	int temp_row2=0;
	int temp_col2=0;
	while(true){
		startp1:
		//asking p 1 for the input
		cout<<"Player 1 Enter the row of your choice:"<<endl;
		cin>>temp_row1;
		cout<<"Player 1 Enter the column of your choice:"<<endl;
		cin>>temp_col1;
		
		point new_point = point(temp_row1, temp_col1);
		vertex new_ver = vertex(new_point);
		
		//checking legality of the move.
		if((temp_row1<1||temp_row1>size)||(temp_col1<1||temp_col1>size)){
			cout<<"Player 1 illegal move"<<endl;
			goto startp1;
		}
		if(board.who_owner(new_ver)!= BLANK){
			cout<<"Player 1 illegal move"<<endl;
			goto startp1;
		}
		board.update_owner(new_ver, CROSS);  // updating the owner of the board
		
		//checking if the game is complete
		bool fin = game_finish(board);			
		print_board(board);
		if(fin){
			cout<<"Player 1 the throne is yours"<<endl<<"Player 2 you know nothing"<<endl;
			break;
		}
		
		
		startp2:
		//Same routine for player 2 as done for player 1
		cout<<"Player 2 Enter the row of your choice:"<<endl;
		cin>>temp_row2;
		cout<<"Player 2 Enter the column of your choice:"<<endl;
		cin>>temp_col2;
		point new_point1 = point(temp_row2, temp_col2);
		vertex new_ver1 = vertex(new_point1);
		if((temp_row2<1||temp_row2>size)||(temp_col2<1||temp_col2>size)){
			cout<<"Player 1 illegal move"<<endl;
			goto startp2;
		}
		if(board.who_owner(new_ver1)!= BLANK){
			cout<<"Player 2 illegal move"<<endl;
			goto startp2;
		}
		board.update_owner(new_ver1, ZERO);
		fin = game_finish(board);
		print_board(board);
		if(fin){
			cout<<"Player 2 the throne is yours"<<endl<<"player 1 you know nothing"<<endl;
			break;
		}
	}
}