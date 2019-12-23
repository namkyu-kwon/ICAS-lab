#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
//update 12/23
/*
-- ���α׷����� ���Ǵ� ����� ���� �Լ� ��� --
1. swap : �� ������ ������ �ּҰ��� �ٲپ���
2. sorting : �迭�� �����ּҿ� ũ�⸦ �Է����� �޾� �迭�� ������������ ����
3. isPrime : ������ �Է� �޾� �Ҽ����� �Ǻ��ϴ� �Լ�
4. PrintMenu :  �޴��� ����ϴ� �Լ�
5. funcArith : ��Ģ���� ����
6. funcPrime : �Ҽ��Ǻ���
7. funcLotto : �ζ� ��ȣ ������
8. funcTree : Ʈ�� ������
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
	/* ���� ���
	@ menu : � ���α׷��� �������� �˷��ִ� ����
	*/
	int menu;

	printf("########################################\n");
	printf("############ ȯ �� �� �� �� ############\n");
	printf("########################################\n");
	do // main ���α׷��� �ּ� �� �� ����
	{
		PrintMenu(); // �޴� ���
		scanf("%d", &menu); // ����ڿ��� �޴� �Է� ����
		switch (menu) // �޴��� ���� �ϳ��� ���α׷� ���� �Ǵ� ���α׷� ���� �ǵ��� switch �� �ۼ�
		{
		case 1: // �Է��� 1�� ���
			funcArith(); // ��Ģ���� ���� ����
			break;
		case 2: // �Է��� 2�� ���
			funcPrime(); // �Ҽ� �Ǻ��� ����
			break;
		case 3: // �Է��� 3�� ���
			funcLotto(); // �ζ� ��ȣ ������ ����
			break;
		case 4: // �Է��� 4�� ���
			funcTree(); // Ʈ�� ������ ����
			break;
		case 0: // �Է��� 0�� ��� ���α׷� ����
			printf("��ü ���α׷��� �����մϴ�\n");
		default: // �� ���� �Է��� ��� 
			printf("���� �޴��Դϴ�.\n");
			break;
		}
	} while (menu != 0); // �Է� 0���� ������� �ʴ� ��� �ݺ� ����
}

int PrintMenu()
{
	/*
	���α׷� �޴��� ������ִ� �Լ�
	*/
	printf("\n========== �� �� �� �� �� �� ===========\n");
	printf("1. ��Ģ���� ����\n");
	printf("2. �Ҽ� �Ǻ���\n");
	printf("3. �ζ� ��ȣ ������\n");
	printf("4. ũ�������� Ʈ��\n");
	printf("0. ���α׷� ����\n");
	printf("========================================\n");
	printf("�޴��� �������ּ��� : ");
	return 0;
}

int funcArith()
{
	/*
	** ��Ģ���� ����
	** ��� ���� ���
	@ cal : ��Ģ������ ����
	@ num1 : ù ��° �� ������
	@ num2 : �� ��° �� ������
	*/
	printf("\n\n****************************************\n");
	printf("******* 1. ��Ģ���� �����Դϴ� *******\n");
	printf("****************************************\n\n");
	int cal, num1, num2;
	while (1)
	{
		printf("\n**************** �޴� *****************\n");
		printf("1. ����\n2. ����\n3. ����\n4. ������\n0. ���� �޴��� ���ư���\n");
		printf("****************************************\n");
		printf("�޴��� �����ϼ��� : ");
		scanf("%d", &cal);
		if (cal >= 1 && cal <= 4) // �Է� ���� ��Ģ���� �޴��� ���� �������� Ȯ��
		{
			printf("�� �ǿ����ڸ� �Է��ϼ��� : ");
			scanf("%d%d", &num1, &num2); // �� ������ �Է�
			printf("����� ������ �����ϴ�\n");
			switch (cal) // ��Ģ ���� �޴��� ���� switch �� ����
			{
				/*
				1 : ����
				2 : ����
				3 : ����
				4 : ������
				*/
			case 1: printf("[ %d + %d ] = %d\n", num1, num2, num1 + num2);
				break;
			case 2: printf("[ %d - %d ] = %d\n", num1, num2, num1 - num2);
				break;
			case 3: printf("[ %d * %d ] = %d\n", num1, num2, num1 * num2);
				break;
			case 4:
				if (num2 == 0) // ���������� �� ��° �ǿ����ڰ� 0�� ��� ���� ó��
					printf("0���� ���� �� �����ϴ�.\n");
				else if (num1 % num2 == 0) // ������ ����� ������ ��� ���� ��� ���
					printf("[ %d / %d ] = %d\n", num1, num2, num1 / num2);
				else // ����� �Ǽ��� ��� �Ǽ� ��� ���
					printf("[ %d / %d ] = %.2f\n", num1, num2, num1 / (double)num2);
				break;
			}
		}
		else if (cal == 0) // ��Ģ ���� �޴��� 0�� ��� ���� 
		{
			printf("\n[ ��Ģ���� ���⸦ �����մϴ� ]\n");
			return 0; // main �Լ����� ��Ģ���� ���� �Լ��� ȣ���� �κ����� ����
		}
		else // ��Ģ ���� �޴��� ���⿡ ���� ���
			printf("�߸� �Է��߽��ϴ�\n");
	}
}

int isPrime(int x)
{
	/*
	���� x�� ���� �Ҽ����� Ȯ���ϴ� �Լ�
	*/
	for (int i = 2; i < x; i++)
	{
		if (x % i == 0) // 2���� x���� ������ �������°� "�ϳ���" ���� ��� 
			return 0; // �Ҽ��� �ƴ��� �ǹ��ϴ� "0" �� return
	}
	return 1; // ������ �������°� "�ϳ���" ���� ��� �Ҽ����� ��Ÿ���� "1" return
}

int funcPrime()
{
	/*
	** �Ҽ� �Ǻ���
	** ��� ���� ���
	@ num_prime : �Ҽ����� �Ǻ��ϰ� �� ����
	*/
	printf("\n\n****************************************\n");
	printf("******* 2. �Ҽ� �Ǻ��� �Դϴ� **********\n");
	printf("****************************************\n");
	int num_prime;
	while (1) // Ư�� ���� ������ ���� �ݺ�
	{
		printf("\n1���� ū �ڿ����� �Է��ϼ��� (0. ���� �޴��� ���ư���) : ");
		scanf("%d", &num_prime);
		if (num_prime == 0) // �Է� ���� ���� 0�� ��� �Լ� ����
		{
			printf("\n[ �Ҽ� �Ǻ��⸦ �����մϴ� ]\n");
			return 0;
		}
		else if (num_prime < 0 || num_prime == 1) // �Է� ���� ���� ���� ���� ó��
			printf("�߸� �Է��߽��ϴ�\n");
		else
		{
			if (isPrime(num_prime)) // num_prime �� �Ҽ��� ��� ���ǹ� ����
				printf("[ �ڿ��� %d ]��(��) �Ҽ��Դϴ�\n", num_prime);
			else
				printf("[ �ڿ��� %d ]��(��) �Ҽ��� �ƴմϴ�\n", num_prime);
		}
	}
}

int swap(int *a, int *b)
{
	/*
	�� ������ ���� a, b�� ����Ű�� ��ġ�� �ִ� ���� �ٲ��ִ� �Լ�
	*/
	int temp;
	temp = *a; // temp �� a�� ����Ű�� ��ġ�� �� ����
	*a = *b;   // a�� ����Ű�� ��ġ�� b�� ����Ű�� ��ġ�� �� ����
	*b = temp; // b�� ����Ű�� ��ġ�� temp�� (���� a�� ����Ű�� ��ġ�� ��) ����
	return 0; // �Լ� ����
}
int sorting(int *arr, int size)
{
	/*
	�迭�� �����ּҿ� �迭�� ũ�⸦ �Է����� ���� �޴� �Լ�
	�迭�� ������������ �������ִ� �Լ�
	*/
	for (int i = 0; i < size - 1; i++) // ���� ������ size-1 �ֱ⸸ŭ ����
	{
		for (int j = 0; j < size - 1 - i; j++) // �� �ֱ⸶�� Ž�� Ƚ�� ����
		{
			if (arr[j] > arr[j + 1]) // �������� ���Ŀ� ����Ǵ� ���
				swap(arr + j, arr + j + 1); // swap
		}
	}
	return 0;
}

int funcLotto()
{
	/*
	** �ζ� ��ȣ ������
	** ��� ���� ���
	@ *lotto : �ζ� ��÷ ��ȣ�� ������ �迭�� ����� �� ������ ����
	@ choice : �ζ� ��ȣ �������� �޴� ������ ���� ����
	@ range : �ζ� ��÷ ��ȣ�� �ִ� ����
	@ size : �ζ� ��÷ ��ȣ�� ����
	@ temp : �ζ� ��÷ ��ȣ�� �ӽ÷� ������ ���� ����
	@ flag : �ζ� ��÷ ��ȣ�� �ߺ��� ��ȣ���� üũ�� ����� ���� ����
	@ range_candidate : ��÷ ��ȣ ������ �ӽ÷� ������ ����
	@ size_candidate : ��÷ ��ȣ ������ �ӽ÷� ������ ����
	*/
	printf("\n\n****************************************\n");
	printf("***** 3. �ζ� ��ȣ �������Դϴ� ********\n");
	printf("****************************************\n");
	int *lotto, choice, range = 45, size = 6, temp, flag, sorting_flag = 0, range_candidate, size_candidate;
	lotto = (int *)malloc(sizeof(int) * size); // �ʱ� ��÷ ��ȣ ���� 6���� �����Ҵ�
	while (1)
	{
		printf("\n---- [%d of %d]�ζ� ��ȣ�� �����Ͻðڽ��ϱ�? ---- ", size, range);
		printf("\n1.�����ϱ�\n2.������ ��ȣ �����ϱ�\n3.�ζ� ��ȣ �ִ� ���� ����\n");
		printf("4.��÷ ��ȣ ���� ����\n0.���� �޴��� ���ư���\n");
		printf("------------------------------------------------\n");
		printf("�޴��� �����ϼ��� : ");

		scanf("%d", &choice);


		if (choice == 0) // ���� �޴�
		{
			printf("\n�ζǹ�ȣ �����⸦ �����մϴ� ]\n");
			return 0;
		}
		else if (choice == 1) // ��ȣ ���� �޴�
		{
			printf("\n<<�ζ� ��ȣ�� �����մϴ�>> : ");
			srand(time(NULL)); // ���� seed ����
			for (int i = 0; i < size; i++) // ��÷ ��ȣ�� ������ size
			{
				temp = rand() % range + 1; // 1~range ���������� �����ϰ� ���� ����
										   //printf("%d ", temp);
				flag = 0; // �ߺ� ��ȣ üũ �� 0���� �ʱ�ȭ
				for (int j = 0; j < i; j++) // �ߺ� ��ȣ�� �ִ��� ���� �迭�� ��ҵ�(i-1����)�� ���� Ž��
				{
					if (lotto[j] == temp) // ���� ���� �ִ°�?
					{
						flag = 1; // ���� ���� ������ ��Ÿ������ flag = 1 �� �ٽ� �ʱ�ȭ
						break;   // Ž�� ����
					}
				}
				if (flag) // ���� ���� �ִٸ�
					i--; // �ٽ� �����ؾ� �Ǳ� ������, �ݺ��� Ƚ���� �ǹ��ϴ� i�� 1 ����
				else      // �ߺ��� ���ٸ�
					lotto[i] = temp; // �迭�� i��ҿ� ���� ���� ����
			}

			for (int i = 0; i < size; i++) // ������ ��ȣ���� ���
			{
				printf("%d ", lotto[i]);
			}
			printf("\n");
			sorting_flag = 1; // ������ �������� �� �� �ֵ��� sorting_flag = 1 �� �ʱ�ȭ
		}
		else if (choice == 2) // �����ϴ� ��� 
		{
			if (!sorting_flag) // ������ �Ұ����� ���
				printf("\n<<������ �ζ� ��ȣ�� �����ϴ�.>>\n");
			else
			{
				printf("\n<<��ȣ ����>> : ");
				sorting(lotto, size); // ���� �Լ� ���
				for (int i = 0; i < size; i++)
				{
					printf("%d ", lotto[i]); // ���ĵ� ��ȣ ���
				}
				printf("\n");
			}

		}
		else if (choice == 3) // ��÷ ��ȣ�� ���� ����
		{
			while (1)
			{
				printf("\n<<���ο� �ִ� ������ �Է��ϼ��� (%d�̻� 100����) : ", size); // �ּ� ������ ��÷ ��ȣ�� ����
				scanf("%d", &range_candidate);
				if (range_candidate <= size || range_candidate > 100) // �ּ� �������� �۰ų� ���ų�, �ִ� �������� ū ��� 
					printf("�߸��� �Է��Դϴ�.\n");
				else // ���� ����
				{
					range = range_candidate; // ���� ����
					break;
				}
			}
		}
		else if (choice == 4) // ��÷ ��ȣ�� ���� ����
		{

			while (1)
			{
				printf("\n<<���ο� ��÷ ��ȣ ������ �Է��ϼ��� (1�̻� %d����) : ", range); // �ִ� ������ ��÷ ��ȣ�� ����
				scanf("%d", &size_candidate);
				if (size_candidate < 1 || size_candidate >= range) // �߸��� ������ ���
					printf("�߸��� �Է��Դϴ�.\n");
				else // ���� ����
				{
					size = size_candidate; // ��÷ ��ȣ ���� ����
					lotto = (int *)realloc(lotto, sizeof(int)*size); // ���ο� ������ �迭�� ũ�� ���Ҵ�
					sorting_flag = 0; // ��ȣ ������ ���� �Ǿ����Ƿ�, ���� �Ұ��� �ϴٴ� �ǹ��� �� ����
					break;
				}
			}
		}
		else
			printf("�߸� �Է��ϼ̽��ϴ�.\n");
	}

}

int funcTree()
{
	/*
	** Ʈ�� ������
	** ��� ���� ���
	@ num_tree : Ʈ���� �� ����
	@ height_tree : Ʈ���� �� ����
	@ width_tree : �� ������ �� ���̷� ���� ���� Ʈ���� ����
	*/
	int num_tree, height_tree, width_tree;
	while (1)
	{
		printf("Ʈ���� �� ������ �Է��ϼ��� (0. ���� �޴��� ���ư���) : ");
		scanf("%d", &num_tree);
		if (num_tree == 0)
		{
			printf("ũ�������� Ʈ�� �׸��⸦ �����մϴ�\n");
			return 0;
		}
		else if (num_tree < 3)
			printf("Ʈ���� 3�� �̻��̾�� �մϴ�\n");
		else
		{
			printf("Ʈ���� �� ���̸� �Է��ϼ��� : ");
			scanf("%d", &height_tree);
			if (height_tree < 3)
				printf("Ʈ���� �� ���̴� 3 �̻��̾�� �մϴ�\n");
			else
			{
				width_tree = num_tree * height_tree - (num_tree - 1) * 2 - 1;
				for (int i = 0; i < num_tree; i++)
				{
					for (int j = 0; j < height_tree; j++)
					{
						for (int k = 0; k < width_tree - (height_tree - 2)*(i)-j; k++)
							printf(" ");
						for (int k = 0; k < 2 * (height_tree - 2) * (i)+2 * j + 1; k++) // i+1 �� i�� ����
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