/*

Задача 1.

Написать функцию с одним целочисленным параметром n, которая проверяет,
 является ли число совершенным (число называется совершенным, если оно
  равно сумме всех своих делителей, кроме себя самого)

Задача 2. 

Написать рекурсивную функцию с одним целочисленным параметром n, 
вычисляющую сумму цифр в десятичной записи числа

Задача 3. 

Написать функцию, которая упорядочит по неубыванию
 элементы целочисленного массива А из n элементов
 (А и n  - параметры функции). Использовать сортировку
 выбором (select sort), в которой максимальный элемент 
 меняется местами с последним в массиве.

Задача 4.

Продемонстрировать работу функции из задачи 3 на массивах: 

 - упорядоченном по возрастанию

- элементы в обратном порядке

- первая половина массива возрастает, вторая - убывает

- элементы в произвольном порядке, отличном от рассмотренных

Для каждого из вариантов посчитать количество 
выполненных операций сравнения элементов массива. 

Задача 5.

Написать функцию, циклически сдвигающую 
элементы массива вправо на 2 элемента.
 Параметрами функции является массив
 и количество элементов в нем. Массива А из 5 
 элементов 1 2 3 4 5 после работы функции 
 должен быть превращен в массив 4 5 1 2 3

*/

//#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void task1(int );
int  task2(int );
void task3(int*, int);
void task4(int*, int);
void task5(int*, int);

int main()
	{
	task1(23123);
	task1(28);

	int res = -1;
	res = task2(1);
	printf("\n summa chisel %d", res);
	res = task2(11);
	printf("\n summa chisel %d", res);
	res = task2(123456789);
	printf("\n summa chisel %d", res);

	printf("\n");
	{
	int mas_ch[5] = {5,45,25,15,90};
	task3(mas_ch,5); }
	{
	int mas_ch[10] = {1,99,5,45,25,15,90,33,33,33};
	task3(mas_ch,10);}

	printf("\n");
	{
	int mas_ch[10] = {1,45,225,2215,2290,22222,33333,44444,55555,66666};
	task4(mas_ch,10); }
	{
	int mas_ch[10] = {10,9,8,7,6,5,4,3,2,1};
	task4(mas_ch,10); }
	{
	int mas_ch[10] = {1,2,3,4,5,10,9,8,7,6};
	task4(mas_ch,10); }
	{
	int mas_ch[10] = {1,99,5,45,25,15,90,33,33,33};
	task4(mas_ch,10);}

	{
	int mas_ch[10] = {1,99,5,45,25,15,90,33,34,35};
	task5(mas_ch,10);}


	return 0;
	}

void task1(int chislo){
	printf("\nchislo %d", chislo);
	int mas_del[500];
	int ii = 0;
	int sum_del = 0;

	for (int i = 1; i<chislo; i++ )
		{
			if (chislo%i==0) {mas_del[ii]= i; ii++; }
			//printf("\n%d",i);}
		}
	
	for (int i = 0; i<ii; i++){
		sum_del+=mas_del[i];
	}

	printf("\nsumma %d",sum_del);
	if (sum_del == chislo) {printf("\nsumma ravna chislu \n"); return;}
	if (sum_del != chislo) {printf("\nsumma ne ravna chislu \n"); return;}

}

int  task2(int chislo ){
	if (chislo<10) {return chislo;}
	int lowest_grade = chislo%10;
	return  lowest_grade + task2(chislo/10);
}

void task3(int* mas_int, int dlin){
	printf("\nmassiv do sort\n");
	for (int i = 0; i<dlin; i++){ printf("%d ", mas_int[i]);}

	int inx_mx = -1;
	int c = -1;
	for (int i = 0; i < dlin - 1; i++) {
		inx_mx = i;
		for (int j = i + 1; j < dlin; j++) {
			if (mas_int[j] < mas_int[inx_mx]) {
				inx_mx = j;
			}
		}

		c = mas_int[i], mas_int[i] = mas_int[inx_mx], mas_int[inx_mx] = c;
	}//-

	printf("\nmassiv posle sort\n");
	for (int i = 0; i<dlin; i++){ printf("%d ", mas_int[i]);}
	printf("\n");

}

void task4(int* mas_int, int dlin){
	printf("\nmassiv do sort\n");
	for (int i = 0; i<dlin; i++){ printf("%d ", mas_int[i]);}

	int inx_mx = -1;
	int c = -1;
	int count_comparison= 0;
	int count_pere= 0;

	for (int i = 0; i < dlin - 1; i++) {
		inx_mx = i;
		for (int j = i + 1; j < dlin; j++) {
			count_comparison++;
			if (mas_int[j] < mas_int[inx_mx]) {
				inx_mx = j;
			}
		}
		count_pere+=3;
		c = mas_int[i], mas_int[i] = mas_int[inx_mx], mas_int[inx_mx] = c;
	}//-

	printf("\nmassiv posle sort\n");
	for (int i = 0; i<dlin; i++){ printf("%d ", mas_int[i]);}
	printf("\nsravn %d perestan %d",count_comparison,count_pere);
	printf("\n");

}

void task5(int* mas, int dlin){
	if (dlin<2) {printf("killed"); return;}
	printf("\nmassiv do shifta\n");
	for (int i = 0; i<dlin; i++){ printf("%d ", mas[i]);}

	{
	int copy1 = mas[0];
	int copy2 = mas[1];
	mas[0] = mas[dlin-2];
	mas[1] = mas[dlin-1];
	//for (int i = 0; i<dlin; i++){ printf("%d ", mas[i]);}

	for (int i = dlin; i>4-1; i--) {	mas[i] = mas[i-2];	}
	//for (int i = 0; i<dlin; i++){ printf("\n%d ", mas[i]);}
	mas[2] = copy1;
	mas[3] = copy2;

	printf("\nmassiv posle shifta\n");
	for (int i = 0; i<dlin; i++){ printf("%d ", mas[i]);}

	}

}
