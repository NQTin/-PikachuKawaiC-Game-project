#include "header.h"
#include "board.cpp"
#include "showing.cpp"

int main(){
	int row, col;
	
	cout << "Input number of rows (even number, 3<x<11): ";
	while(true){
		cin >> row;
		if( row > 3 && row < 11 && row%2 == 0 )
			break;
		else
			cout << "Invalid value, please try again: ";
	}
	
	cout << "Input number of columns (even number, 3<x<15): ";
	while(true){
		cin >> col;
		if( col > 3 && col < 15 && col%2 == 0 )
			break;
		else
			cout << "Invalid value, please try again: ";
	}

	//KHOI TAO MANG TOAN BO LA -1
	int **board;
	board = new int *[row + 2];
	for(int i = 0; i < row + 2; i++){
		board[i] = new int [col + 2];
	}
	for(int i = 0; i < row + 2; i++)
		for(int j = 0; j < col + 2; j++)
			board[i][j] = -1;
	
	srand(time(0));
	//mang cang nho thi cang can it ky tu, cu the mang 4x4 co toi da 6 ky tu khac nhau
	int totalDifferentCharacter = 4 + min((row*col)/2 - 6, 22);
	int characterBlock[totalDifferentCharacter];
	//so luong ky tu con lai trong mang, sau khi noi dung 2 ky tu thi bien nay tu giam di 2
	int totalCharacter = row*col;
	for(int i = 0; i < totalDifferentCharacter; i++){
		characterBlock[i] = 0;
	}
	for(int count = 0; count < row*col;){
		//thuat toan tim ra 2 toa do bat ky, neu chung khac nhau va chua co gia tri thi se duoc them gia tri ngau nhien vao
		int y1 = rand()%row + 1;
		int x1 = rand()%col + 1;
		int y2 = rand()%row + 1;
		int x2 = rand()%col + 1;
		if( (y1 != y2 || x1 != x2) && board[y1][x1] == -1 && board[y2][x2] == -1){
			int character = rand()%totalDifferentCharacter;
			characterBlock[character]+=1;
			board[y1][x1] = character;
			board[y2][x2] = character;
			//cu them duoc gia tri vao 2 toa do thi count tu +2, neu cham nguong so luong toa do cua bang choi thi vong for tu thoat ra
			count+=2;
		}
	}
	while(true){
		drawingBoard(board, row, col);
		if( !testingBoard(board, row, col, totalCharacter) ){
			cout << "Error." << endl;
			break;
		}
		matching(board, row, col, characterBlock, totalCharacter);
		if(totalCharacter == 0){
			cout << "###" << endl;
			break;
		}
	}

	cout << "Congratulate!";
	
	deleteBoard(board, col);
	
	return 0;
}
