#include <iostream>
#include <fstream>

#define N 80

using namespace std;

int main() {
	setlocale(0, "");
	cout << "________________________________________________________________________" << endl
		<< "|Version #5.                                                           |" << endl
		<< "|The type of conversion is:                                            |" << endl
		<< "|Convert all lowercase Latin letters of the input string to uppercase, |" << endl
		<< "|and decimal digits to inverse, the remaining characters of the input  |" << endl
		<< "|string are passed directly to the output string.                      |" << endl
		<< "|The work was performed by Anna Karpekina, a student of group 9383.    |" << endl
		<< "|______________________________________________________________________| " << endl;
	char arr[N], res[N];
	cout << "Input string: ";
	cin.getline(arr, N);
	__asm{
	mov edi, 0; 
	mov esi, 0; 

	start:
	mov al, arr[edi]  ; ��������� ������� ������ str1 �� ������� edi � al
	cmp al, 'z'    ; ���� ������ ��� z,
	jg write
	cmp al, 'a'    ; ���� ������ ��� a,
	jl check_ten   ; �� ���������, �������� �� ������ ������,
	sub al, 0x20   ; ����� ��������� ��������� ����� � �������� ��������
	jmp write

	check_ten:
	cmp al, 0x30   ; ���� ������ ��� 0,
	jl write       ; �� ���������� ������ � �������� ������
	cmp al, 0x39   ; ���� ������ ��� 9,
	jg write       ; �� ���������� ������ � �������� ������
	mov ah, 0x69   ; �����s���� � ah 9
	sub ah, al     ; �������� �� 9 ���� �����
	mov al,ah
	jmp write
	

	write:
	mov res[esi], al; �������� ������� ������ � �������� ������
	cmp al, 0        ; ���� ��� �������� ������� ������,
	je end_func      ; �� �����������
	inc edi          ; ����� ����������� �������
	inc esi
	jmp start        ; � ������������ � ���������� ������

	end_func:
	}
	cout << res;
	ofstream output;
	output.open("out.txt");
	output << res;
	output.close();
	return 0;
}