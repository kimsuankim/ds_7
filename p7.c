/* (1) 지능형전자시스템전공, (2) 2310131, (3) 김수안, (4) p7.c (5) 2025.05.30 */
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//1-1.버블정렬함수
void bubbleSort(int a[], int size, int *time, int* change){
	int i,j,temp;
	for(i=(size-1);i>=0;i--){//끝에서부터 
		for(j=1;j<=i;j++){
			*time=*time+1; //밑에서 비교 
			if(a[j-1]>a[j]){
				temp = a[j-1];
				a[j-1] = a[j];
				a[j] = temp;
				*change=*change+1; //위에서 교환함 
			}
		}
	}
}

//1-2.선택정렬함수
void selectionSort(int a[], int size, int* time, int* change){
	int i,j;
	int min, temp;
	for(i=0;i<size-1;i++){//a[0]~a[size-1] 
		min=i;
		for(j=i+1;j<size;j++){//a[i+1]~a[size-1]:min다음노드부터 비교 
			*time=*time+1; //밑에서 비교
			if(a[j]<a[min])
				min=j;
		}
		temp = a[i]; //시작노드 
		a[i] = a[min];
		a[min] = temp;
		*change=*change+1; //위에서 교환함 
	}
} 
//1-3.삽입정렬함수
void insertionSort(int a[], int size, int* time, int* change){
	int i,j,index;
	for(i=1;i<size;i++){
		index = a[i];
		j = i;
		*time=*time+1; //밑에서 비교(처음무조건) 
		while((j>0)&&(a[j-1]>index)){ 
			a[j] = a[j-1];
			j = j-1;
			*change=*change+1; //위에서 교환함
			*time=*time+1;//다음거 비교(무조건) 
		}
		a[j] = index;
	}
} 
//출력함수
void printarray(int a[], int size){
	int i;
	for(i=0;i<size;i++){
		printf("%d ", a[i]);
	}
	printf("\n");
} 
//배열 초기화 함수//횟수도 초기화 
void resetarray(int a[], int init[], int size, int* time, int* change){
	int i;
	*time=0; 
	*change=0;
	for(i=0;i<size;i++){
		a[i] = init[i];
	}
}
int main(int argc, char *argv[]) {
	//과제7.기억복원 알고리즘 실험 보고서
	//0.기억조각들의 번호 배열
	int memory[10] = {42,17,8,99,3,67,21,14,88,5};
	int array[10]; //바뀌는것 
	int time;
	int change; //비교, 교환 횟수 
	//1.세가지 정렬알고리즘
	//1-1.버블정렬
	printf("---------1.버블정렬----------\n");
	resetarray(array,memory,10,&time, &change); //초기화 
	printf("정렬 전 배열: ");
	printarray(array, 10);
	bubbleSort(array, 10,&time,&change);
	printf("%d ",change);
	printf("정렬 후 배열: ");
	printarray(array, 10);
	printf("비교 횟수: %d\n",time);
	printf("교환 횟수: %d\n",change);
	//1-2.선택정렬
	printf("---------2.선택정렬----------\n");
	resetarray(array,memory,10, &time, &change); //초기화 
	printf("정렬 전 배열: ");
	printarray(array, 10);
	selectionSort(array, 10, &time, &change);
	printf("정렬 후 배열: ");
	printarray(array, 10);
	printf("비교 횟수: %d\n",time);
	printf("교환 횟수: %d\n",change);
	//1-3.삽입정렬 
	printf("---------3.삽입정렬----------\n");
	resetarray(array,memory,10,&time, &change); //초기화 
	printf("정렬 전 배열: ");
	printarray(array, 10);
	insertionSort(array, 10, &time, &change);
	printf("정렬 후 배열: ");
	printarray(array, 10);
	printf("비교 횟수: %d\n",time);
	printf("교환 횟수: %d\n",change);
	//2.출력: 정렬전배열, 정렬후배열, 비교횟수, 교환횟수
	
	//수행결과비교및 기억배열에 적합한 알고리즘 선택 
	return 0;
}
