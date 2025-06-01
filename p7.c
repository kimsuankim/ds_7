/* (1) ���������ڽý�������, (2) 2310131, (3) �����, (4) p7.c (5) 2025.05.30 */
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//1-1.���������Լ�
void bubbleSort(int a[], int size, int *time, int* change){
	int i,j,temp;
	for(i=(size-1);i>=0;i--){//���������� 
		for(j=1;j<=i;j++){
			*time=*time+1; //�ؿ��� �� 
			if(a[j-1]>a[j]){
				temp = a[j-1];
				a[j-1] = a[j];
				a[j] = temp;
				*change=*change+1; //������ ��ȯ�� 
			}
		}
	}
}

//1-2.���������Լ�
void selectionSort(int a[], int size, int* time, int* change){
	int i,j;
	int min, temp;
	for(i=0;i<size-1;i++){//a[0]~a[size-1] 
		min=i;
		for(j=i+1;j<size;j++){//a[i+1]~a[size-1]:min���������� �� 
			*time=*time+1; //�ؿ��� ��
			if(a[j]<a[min])
				min=j;
		}
		temp = a[i]; //���۳�� 
		a[i] = a[min];
		a[min] = temp;
		*change=*change+1; //������ ��ȯ�� 
	}
} 
//1-3.���������Լ�
void insertionSort(int a[], int size, int* time, int* change){
	int i,j,index;
	for(i=1;i<size;i++){
		index = a[i];
		j = i;
		*time=*time+1; //�ؿ��� ��(ó��������) 
		while((j>0)&&(a[j-1]>index)){ 
			a[j] = a[j-1];
			j = j-1;
			*change=*change+1; //������ ��ȯ��
			*time=*time+1;//������ ��(������) 
		}
		a[j] = index;
	}
} 
//����Լ�
void printarray(int a[], int size){
	int i;
	for(i=0;i<size;i++){
		printf("%d ", a[i]);
	}
	printf("\n");
} 
//�迭 �ʱ�ȭ �Լ�//Ƚ���� �ʱ�ȭ 
void resetarray(int a[], int init[], int size, int* time, int* change){
	int i;
	*time=0; 
	*change=0;
	for(i=0;i<size;i++){
		a[i] = init[i];
	}
}
int main(int argc, char *argv[]) {
	//����7.��ﺹ�� �˰��� ���� ����
	//0.����������� ��ȣ �迭
	int memory[10] = {42,17,8,99,3,67,21,14,88,5};
	int array[10]; //�ٲ�°� 
	int time;
	int change; //��, ��ȯ Ƚ�� 
	//1.������ ���ľ˰���
	//1-1.��������
	printf("---------1.��������----------\n");
	resetarray(array,memory,10,&time, &change); //�ʱ�ȭ 
	printf("���� �� �迭: ");
	printarray(array, 10);
	bubbleSort(array, 10,&time,&change);
	printf("%d ",change);
	printf("���� �� �迭: ");
	printarray(array, 10);
	printf("�� Ƚ��: %d\n",time);
	printf("��ȯ Ƚ��: %d\n",change);
	//1-2.��������
	printf("---------2.��������----------\n");
	resetarray(array,memory,10, &time, &change); //�ʱ�ȭ 
	printf("���� �� �迭: ");
	printarray(array, 10);
	selectionSort(array, 10, &time, &change);
	printf("���� �� �迭: ");
	printarray(array, 10);
	printf("�� Ƚ��: %d\n",time);
	printf("��ȯ Ƚ��: %d\n",change);
	//1-3.�������� 
	printf("---------3.��������----------\n");
	resetarray(array,memory,10,&time, &change); //�ʱ�ȭ 
	printf("���� �� �迭: ");
	printarray(array, 10);
	insertionSort(array, 10, &time, &change);
	printf("���� �� �迭: ");
	printarray(array, 10);
	printf("�� Ƚ��: %d\n",time);
	printf("��ȯ Ƚ��: %d\n",change);
	//2.���: �������迭, �����Ĺ迭, ��Ƚ��, ��ȯȽ��
	
	//�������񱳹� ���迭�� ������ �˰��� ���� 
	return 0;
}
