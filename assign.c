#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
//update 12/23
/*
-- 프로그램에서 사용되는 사용자 정의 함수 목록 --
1. swap : 두 포인터 변수의 주소값을 바꾸어줌
2. sorting : 배열의 시작주소와 크기를 입력으로 받아 배열을 오름차순으로 정렬
3. isPrime : 정수를 입력 받아 소수인지 판별하는 함수
4. PrintMenu :  메뉴를 출력하는 함수
5. funcArith : 사칙연산 계산기
6. funcPrime : 소수판별기
7. funcLotto : 로또 번호 생성기
8. funcTree : 트리 생성기
*/
int swap(int *a, int *b);
int sorting(int *arr, int size);
int isPrime(int x);
int PrintMenu();
int funcArith(void);
int funcPrime(void);
int funcLotto(void);
int funcTree(void);

int main()
{
	/* 변수 목록
	@ menu : 어떤 프로그램을 실행할지 알려주는 변수
	*/
	int menu;

	printf("########################################\n");
	printf("############ 환 영 합 니 다 ############\n");
	printf("########################################\n");
	do // main 프로그램을 최소 한 번 실행
	{
		PrintMenu(); // 메뉴 출력
		scanf("%d", &menu); // 사용자에게 메뉴 입력 받음
		switch (menu) // 메뉴에 따라 하나의 프로그램 실행 또는 프로그램 종료 되도록 switch 문 작성
		{
		case 1: // 입력이 1인 경우
			funcArith(); // 사칙연산 계산기 실행
			break;
		case 2: // 입력이 2인 경우
			funcPrime(); // 소수 판별기 실행
			break;
		case 3: // 입력이 3인 경우
			funcLotto(); // 로또 번호 생성기 실행
			break;
		case 4: // 입력이 4인 경우
			funcTree(); // 트리 생성기 실행
			break;
		case 0: // 입력이 0인 경우 프로그램 종료
			printf("전체 프로그램을 종료합니다\n");
		default: // 그 외의 입력인 경우 
			printf("없는 메뉴입니다.\n");
			break;
		}
	} while (menu != 0); // 입력 0으로 종료되지 않는 경우 반복 실행
}

int PrintMenu()
{
	/*
	프로그램 메뉴를 출력해주는 함수
	*/
	printf("\n========== 프 로 그 램 메 뉴 ===========\n");
	printf("1. 사칙연산 계산기\n");
	printf("2. 소수 판별기\n");
	printf("3. 로또 번호 생성기\n");
	printf("4. 크리스마스 트리\n");
	printf("0. 프로그램 종료\n");
	printf("========================================\n");
	printf("메뉴를 선택해주세요 : ");
	return 0;
}

int funcArith()
{
	/*
	** 사칙연산 계산기
	** 사용 변수 목록
	@ cal : 사칙연산의 종류
	@ num1 : 첫 번째 피 연산자
	@ num2 : 두 번째 피 연산자
	*/
	printf("\n\n****************************************\n");
	printf("******* 1. 사칙연산 계산기입니다 *******\n");
	printf("****************************************\n\n");
	int cal, num1, num2;
	while (1)
	{
		printf("\n**************** 메뉴 *****************\n");
		printf("1. 덧셈\n2. 뺄셈\n3. 곱셈\n4. 나눗셈\n0. 이전 메뉴로 돌아가기\n");
		printf("****************************************\n");
		printf("메뉴를 선택하세요 : ");
		scanf("%d", &cal);
		if (cal >= 1 && cal <= 4) // 입력 받은 사칙연산 메뉴가 정상 범위인지 확인
		{
			printf("두 피연산자를 입력하세요 : ");
			scanf("%d%d", &num1, &num2); // 피 연산자 입력
			printf("결과는 다음과 같습니다\n");
			switch (cal) // 사칙 연산 메뉴에 따라 switch 문 실행
			{
				/*
				1 : 덧셈
				2 : 뺄셈
				3 : 곱셈
				4 : 나눗셈
				*/
			case 1: printf("[ %d + %d ] = %d\n", num1, num2, num1 + num2);
				break;
			case 2: printf("[ %d - %d ] = %d\n", num1, num2, num1 - num2);
				break;
			case 3: printf("[ %d * %d ] = %d\n", num1, num2, num1 * num2);
				break;
			case 4:
				if (num2 == 0) // 나눗셈에서 두 번째 피연산자가 0인 경우 예외 처리
					printf("0으로 나눌 수 없습니다.\n");
				else if (num1 % num2 == 0) // 나눗셈 결과가 정수인 경우 정수 결과 출력
					printf("[ %d / %d ] = %d\n", num1, num2, num1 / num2);
				else // 결과가 실수인 경우 실수 결과 출력
					printf("[ %d / %d ] = %.2f\n", num1, num2, num1 / (double)num2);
				break;
			}
		}
		else if (cal == 0) // 사칙 연산 메뉴가 0인 경우 종료 
		{
			printf("\n[ 사칙연산 계산기를 종료합니다 ]\n");
			return 0; // main 함수에서 사칙연산 계산기 함수를 호출한 부분으로 복귀
		}
		else // 사칙 연산 메뉴가 보기에 없는 경우
			printf("잘못 입력했습니다\n");
	}
}

int IsPrime(int x)     // 소수 판별을 받을 매개변수 선언
{
	for (int i = 2; i < x; i++)     // for문 이용, 범위는 2부터 매개변수까지
	{
		if (x % i == 0)     // 2부터 매개변수까지의 수 중 매개변수에 나눴을 때 0일 경우 (i가 x의 약수일 경우)
			return 0;     // 0을 출력 (소수가 아님)
	}
	return 1;     // 2부터 매개변수까지의 수 중 매개변수에 나눴을 때 0인 것이 발견되지 않으면 1을 출력 (소수)
}     // 소수 판별기 함수 선언 (소수일 경우 1을 출력, 아닐경우 0을 출력하는 함수)

int funcPrime()
{
	/*
	** 소수 판별기
	** 사용 변수 목록
	@ num_prime : 소수인지 판별하게 될 변수
	*/
	printf("\n\n****************************************\n");
	printf("******* 2. 소수 판별기 입니다 **********\n");
	printf("****************************************\n");
	int num_prime;
	while (1) // 특정 조건 전까지 무한 반복
	{
		printf("\n1보다 큰 자연수를 입력하세요 (0. 이전 메뉴로 돌아가기) : ");
		scanf("%d", &num_prime);
		if (num_prime == 0) // 입력 받은 수가 0인 경우 함수 종료
		{
			printf("\n[ 소수 판별기를 종료합니다 ]\n");
			return 0;
		}
		else if (num_prime < 0 || num_prime == 1) // 입력 받은 수에 대한 예외 처리
			printf("잘못 입력했습니다\n");
		else
		{
			if (isPrime(num_prime)) // num_prime 이 소수인 경우 조건문 만족
				printf("[ 자연수 %d ]는(은) 소수입니다\n", num_prime);
			else
				printf("[ 자연수 %d ]는(은) 소수가 아닙니다\n", num_prime);
		}
	}
}

int swap(int *a, int *b)
{
	/*
	두 포인터 변수 a, b가 가리키는 위치에 있는 값을 바꿔주는 함수
	*/
	int temp;
	temp = *a; // temp 에 a가 가리키는 위치의 값 저장
	*a = *b;   // a가 가리키는 위치에 b가 가리키는 위치의 값 저장
	*b = temp; // b가 가리키는 위치에 temp값 (원래 a가 가리키는 위치의 값) 저장
	return 0; // 함수 종료
}
int sorting(int *arr, int size)
{
	/*
	배열의 시작주소와 배열의 크기를 입력으로 전달 받는 함수
	배열을 오름차순으로 정렬해주는 함수
	*/
	for (int i = 0; i < size - 1; i++) // 버블 정렬을 size-1 주기만큼 실행
	{
		for (int j = 0; j < size - 1 - i; j++) // 각 주기마다 탐색 횟수 감소
		{
			if (arr[j] > arr[j + 1]) // 오름차순 정렬에 위배되는 경우
				swap(arr + j, arr + j + 1); // swap
		}
	}
	return 0;
}

int funcLotto()
{
	/*
	** 로또 번호 생성기
	** 사용 변수 목록
	@ *lotto : 로또 당첨 번호를 저장할 배열의 기능을 할 포인터 변수
	@ choice : 로또 번호 생성기의 메뉴 정보를 갖는 변수
	@ range : 로또 당첨 번호의 최대 숫자
	@ size : 로또 당첨 번호의 개수
	@ temp : 로또 당첨 번호를 임시로 가지고 있을 변수
	@ flag : 로또 당첨 번호가 중복된 번호인지 체크한 결과를 갖는 변수
	@ range_candidate : 당첨 번호 범위를 임시로 저장할 변수
	@ size_candidate : 당첨 번호 갯수를 임시로 저장할 변수
	*/
	printf("\n\n****************************************\n");
	printf("***** 3. 로또 번호 생성기입니다 ********\n");
	printf("****************************************\n");
	int *lotto, choice, range = 45, size = 6, temp, flag, sorting_flag = 0, range_candidate, size_candidate;
	lotto = (int *)malloc(sizeof(int) * size); // 초기 당첨 번호 개수 6으로 동적할당
	while (1)
	{
		printf("\n---- [%d of %d]로또 번호를 생성하시겠습니까? ---- ", size, range);
		printf("\n1.생성하기\n2.생성된 번호 정렬하기\n3.로또 번호 최대 범위 변경\n");
		printf("4.당첨 번호 갯수 변경\n0.이전 메뉴로 돌아가기\n");
		printf("------------------------------------------------\n");
		printf("메뉴를 선택하세요 : ");

		scanf("%d", &choice);


		if (choice == 0) // 종료 메뉴
		{
			printf("\n로또번호 생성기를 종료합니다 ]\n");
			return 0;
		}
		else if (choice == 1) // 번호 생성 메뉴
		{
			printf("\n<<로또 번호를 생성합니다>> : ");
			srand(time(NULL)); // 난수 seed 생성
			for (int i = 0; i < size; i++) // 당첨 번호의 개수는 size
			{
				temp = rand() % range + 1; // 1~range 범위내에서 랜덤하게 숫자 추출
										   //printf("%d ", temp);
				flag = 0; // 중복 번호 체크 전 0으로 초기화
				for (int j = 0; j < i; j++) // 중복 번호가 있는지 이전 배열의 요소들(i-1까지)에 대해 탐색
				{
					if (lotto[j] == temp) // 같은 것이 있는가?
					{
						flag = 1; // 같은 것이 있음을 나타내도록 flag = 1 로 다시 초기화
						break;   // 탐색 종료
					}
				}
				if (flag) // 같은 것이 있다면
					i--; // 다시 생성해야 되기 때문에, 반복된 횟수를 의미하는 i를 1 감소
				else      // 중복이 없다면
					lotto[i] = temp; // 배열의 i요소에 랜섬 숫자 저장
			}

			for (int i = 0; i < size; i++) // 생성된 번호들을 출력
			{
				printf("%d ", lotto[i]);
			}
			printf("\n");
			sorting_flag = 1; // 정렬이 가능함을 알 수 있도록 sorting_flag = 1 로 초기화
		}
		else if (choice == 2) // 정렬하는 경우 
		{
			if (!sorting_flag) // 정렬이 불가능한 경우
				printf("\n<<생성된 로또 번호가 없습니다.>>\n");
			else
			{
				printf("\n<<번호 정렬>> : ");
				sorting(lotto, size); // 정렬 함수 사용
				for (int i = 0; i < size; i++)
				{
					printf("%d ", lotto[i]); // 정렬된 번호 출력
				}
				printf("\n");
			}

		}
		else if (choice == 3) // 당첨 번호의 범위 변경
		{
			while (1)
			{
				printf("\n<<새로운 최대 범위를 입력하세요 (%d이상 100이하) : ", size); // 최소 범위는 당첨 번호의 갯수
				scanf("%d", &range_candidate);
				if (range_candidate <= size || range_candidate > 100) // 최소 범위보다 작거나 같거나, 최대 범위보다 큰 경우 
					printf("잘못된 입력입니다.\n");
				else // 정상 범위
				{
					range = range_candidate; // 범위 변경
					break;
				}
			}
		}
		else if (choice == 4) // 당첨 번호의 갯수 변경
		{

			while (1)
			{
				printf("\n<<새로운 당첨 번호 갯수를 입력하세요 (1이상 %d이하) : ", range); // 최대 갯수는 당첨 번호의 범위
				scanf("%d", &size_candidate);
				if (size_candidate < 1 || size_candidate >= range) // 잘못된 범위인 경우
					printf("잘못된 입력입니다.\n");
				else // 정상 범위
				{
					size = size_candidate; // 당첨 번호 갯수 변경
					lotto = (int *)realloc(lotto, sizeof(int)*size); // 새로운 갯수로 배열의 크기 재할당
					sorting_flag = 0; // 번호 갯수가 변경 되었으므로, 정렬 불가능 하다는 의미의 값 설정
					break;
				}
			}
		}
		else
			printf("잘못 입력하셨습니다.\n");
	}

}

int funcTree()
{
	/*
	** 트리 생성기
	** 사용 변수 목록
	@ num_tree : 트리의 단 개수
	@ height_tree : 트리의 단 높이
	@ width_tree : 단 개수와 단 높이로 부터 계산된 트리의 넓이
	*/
	int num_tree, height_tree, width_tree;
	while (1)
	{
		printf("트리의 단 개수를 입력하세요 (0. 이전 메뉴로 돌아가기) : ");
		scanf("%d", &num_tree);
		if (num_tree == 0)
		{
			printf("크리스마스 트리 그리기를 종료합니다\n");
			return 0;
		}
		else if (num_tree < 3)
			printf("트리는 3단 이상이어야 합니다\n");
		else
		{
			printf("트리의 단 높이를 입력하세요 : ");
			scanf("%d", &height_tree);
			if (height_tree < 3)
				printf("트리의 단 높이는 3 이상이어야 합니다\n");
			else
			{
				width_tree = num_tree * height_tree - (num_tree - 1) * 2 - 1;
				for (int i = 0; i < num_tree; i++)
				{
					for (int j = 0; j < height_tree; j++)
					{
						for (int k = 0; k < width_tree - (height_tree - 2)*(i)-j; k++)
							printf(" ");
						for (int k = 0; k < 2 * (height_tree - 2) * (i)+2 * j + 1; k++) // i+1 과 i의 차이
							printf("*");
						printf("\n");
					}
				}
				for (int i = 0; i < 2; i++)
				{
					for (int j = 0; j < width_tree - 1; j++)
						printf(" ");
					printf("| |\n");
				}
				printf("\n");
			}
		}
	}
}