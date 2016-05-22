// Airplane.cpp: определяет точку входа для консольного приложения.
// (c) All rights reserved by Maxim Skirdov
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int inDataH [4][5];
	int inDataV [6][3];
	int optimalControl[4][6];
	int inData1 [4][6];
	int inData2 [4][6];
	int inData [4][6];
	int amountFuel [4][6];

	inDataH[0][0]=31;
	inDataH[0][1]=34;
	inDataH[0][2]=35;
	inDataH[0][3]=38;
	inDataH[0][4]=42;

	inDataH[1][0]=34;
	inDataH[1][1]=35;
	inDataH[1][2]=36;
	inDataH[1][3]=41;
	inDataH[1][4]=45;

	inDataH[2][0]=37;
	inDataH[2][1]=38;
	inDataH[2][2]=39;
	inDataH[2][3]=42;
	inDataH[2][4]=47;

	inDataH[3][0]=39;
	inDataH[3][1]=41;
	inDataH[3][2]=43;
	inDataH[3][3]=46;
	inDataH[3][4]=48;

	inDataV[0][0]=16;
	inDataV[0][1]=17;
	inDataV[0][2]=18;

	inDataV[1][0]=18;
	inDataV[1][1]=19;
	inDataV[1][2]=21;

	inDataV[2][0]=20;
	inDataV[2][1]=21;
	inDataV[2][2]=24;

	inDataV[3][0]=22;
	inDataV[3][1]=23;
	inDataV[3][2]=26;

	inDataV[4][0]=24;
	inDataV[4][1]=25;
	inDataV[4][2]=27;

	inDataV[5][0]=26;
	inDataV[5][1]=28;
	inDataV[5][2]=29;

	for (int k= 0; k < 4; k++){
		for (int m = 0; m < 6; m++){
			inData[k][m] = 0;
			inData1[k][m] = 0;
			inData2[k][m] = 0;
			optimalControl[k][m] = 0;}}

	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 5; j++){
			inData1[i][j+1] =inDataH[i][j];}}

	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 6; j++){
			inData2[i+1][j] = inDataV[j][i];}}

	for (int i = 1; i < 6; i++){
		inData[0][i] = inData[0][i-1] + inData1[0][i];
		optimalControl[0][i] = 1;}

	for (int i = 1; i < 5; i++){
		inData[i][0] = inData[i-1][0] + inData2[i][0];
		optimalControl[i][0] = 2;}

	for (int i = 1; i < 4; i++){
		for (int j = 1; j < 6; j++){
			if (inData[i][j-1] + inData1[i][j] > inData[i-1][j] + inData2[i][j]){
				inData[i][j] = inData[i-1][j] + inData2[i][j];
				optimalControl[i][j] = 2;}
			else{
				inData[i][j] = inData[i][j-1] + inData1[i][j];
				optimalControl[i][j] = 1;}}}
cout << endl;

	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 6; j++){
			cout << inData[i][j] << "  ";}
		cout << endl;}
	cout << endl;

	char way[24];
	int k = 0;
	int i = 0;
	int j = 0;

	for (i; i < 3;){
		for (j; j < 5;){
			if (optimalControl[i+1][j] == 2 && optimalControl[i][j+1] == 1 && optimalControl[i+1][j+1] == 2){
				j++;
				way[k]= 'H';
				k++;}
			else {
				i++;
				break;}}
		way[k]= 'V';
		k++;}
	const int l=k-1;

	for (int i = 0; i <= k-1; i++){
		cout << way[i] << " ";}
	cout << endl;
	int point[12][2];
	point[0][0] = 0;

	for (int i = 0; i < 9; i++){
		point[i][0]=0;
		point[i][1]=0;}

	for (int i = 1; i < 9; i++){
		if (way[i-1]=='H'){
			point[i][1] = point[i-1][1] + 1;
			point[i][0] = point[i-1][0];}
		else{
			point[i][0] = point[i-1][0] + 1;
			point[i][1] = point[i-1][1];}}

	for (int i = 0; i < 8; i++){
		cout <<"(" << point[i][0] << ";" << point[i][1] << ")" << endl;}
	cout << endl;
	_getch();
	return 0;
}

