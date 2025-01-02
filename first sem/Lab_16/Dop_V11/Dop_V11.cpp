//ïîäêëþ÷åíèå áèáëèîòåê
#include <iostream>
#include <sstream>
#include <Windows.h>
using namespace std;//÷òîáû íå ïèñàòü êàæäûé ðàç std
//ïîäêëþ÷åíèå äâóõ ôóíêöèé äëÿ ìàòðèöû è ñòðîêè ñîîòâåòñòâåííî
int matrix(int** A, int N, int M, int k) {
	return 0;
}
int massiv(char str1, char str) {
	return 0;
}

int main()//îáúÿâëåíèå ãëàâíîé ôóíêöèè
{
	//ïîäêëþ÷åíèå ëîêàëåé äëÿ ðàáîòû ñ ðóññêèìè ñèìâîëàìè 
	setlocale(LC_ALL, "RU");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//äèàëîãîâàÿ ïðîãðàììà ñ ðåøåíèåì íàøèõ çàäà÷
	int choice;
	do
	{
		cout << "Âûáåðèòå âàðèàíò ðàáîòû" << endl;
		cout << "1 - ñ ìàòðèöåé" << endl;
		cout << "2 - ñî ñòðîêîé" << endl;
		cout << "3 - âûõîä" << endl;
		cin >> choice;
		switch (choice)
		{
			//ðàáîòà ñ ìàòðèöåé
		case 1: {
			//èíèöèàëèçàöèÿ ïåðåìåííûõ è ôëàãà
			int** A, N, M;
			bool found = false;
			//ââîä ìàòðèöû
			cout << "Ââåäèòå ÷èñëî ñòðîê: ";
			cin >> N;
			cout << "Ââåäèòå ÷èñëî ñòîëáöîâ: ";
			cin >> M;
			//èíèöèàëèçàöèÿ äèíàìè÷åñêîãî ìàññèâà
			A = new int* [N];
			for (int i = 0; i < N; i++) {
				A[i] = new int[M];
			}
			cout << "Ââåäèòå ìàòðèöó: " << endl;//ââîäèì ýëåìåíòû ìàòðèöû
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < M; j++)
				{
					cout << "A(" << i + 1 << ", " << j + 1 << "): ";
					cin >> A[i][j];
				}
			}
			cout << "Èñõîäíàÿ ìàòðèöà: " << endl;//âûâîäèì èñõîäíóþ ìàòðèöó íà ýêðàí
			for (int i = 0; i < N; i++)
			{
				cout << "[";
				for (int j = 0; j < M; j++)
				{
					cout << " " << A[i][j] << " ";
				}
				cout << "]" << endl;
			}
			int maxElement = A[0][0];//èíèöìàëèçàöèÿ ìàêñèìàëüíîãî ýëåìåíòà 
			int positions[100][2];//ïðåäïîëàãàåì, ÷òî ìàêñèìàëüíûõ ýëåìåíòîâ íå áîëüøå 100
			int posCount = 0;//ñ÷åò÷èê ïîçèöèè ìàêñèìàëüíîãî ýëåìåíòà
			int sum = 0;//èíèíèöèàëèçèðóåì ïåðåìåííóþ, êîòîðàÿ áóäåò ñóììèðîâàòü ýëåìåíòû, êîòîðûå íèæå ãëàâíîå äèàãîíàëè
			//ñ ïîìîùüþ öèêëà íàõîäèì îäèí èëè íåñêîëüêî ìàêñèìàëüíûõ ýëåìåíòîâ è èõ ïîçèöèè
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (A[i][j] > maxElement) {
						maxElement = A[i][j];
						posCount = 0;
						positions[posCount][0] = i;
						positions[posCount][1] = j;
						posCount++;
					}
					else if (A[i][j] == maxElement) {
						positions[posCount][0] = i;
						positions[posCount][1] = j;
						posCount++;
					}
					//íàõîäèì ñóììó ýëåìåíòîâ, êîòîðûå íèæå ãëàâíîé äèàãîíàëè
					if (i > j) {
						sum += A[i][j];
					}
				}
			}
			cout << "Ìàêñèìàëüíûé ýëåìåíò: " << maxElement << endl;//âûâîä ðåçóëüòàòà
			cout << "Ïîçèöèè ìàêñèìàëüíîãî ýëåìåíòà: " << endl;
			for (int i = 0; i < posCount; i++) {
				cout << "(" << positions[i][0] + 1 << ", " << positions[i][1] + 1 << ")" << endl;//âûâîä ðåçóëüòàòà
			}
			cout << "Ñóììà ýëåìåíòîâ íèæå ãëàâíîé äèàãîíàëè: " << sum << endl;//âûâîä ðåçóëüòàòà
			break;
		}
			  //ðàáîòà ñî ñòðîêîé
		case 2: {
			setlocale(LC_ALL, "RU");//ïîäêëþ÷àåì êèðèëëèöó
			char str1[50], str[] = "*";//îáúÿâëåíèå äâóõ ìàññèâîâ
			int n;//îáúÿâëåíèå ïåðåìåííîé, êîòîðàÿ ïîêàçûâàåò ñîäåðæàíèå ñèìâîëîâ â ñòðîêå
			//ââîäèì ñòðîêó
			cout << "Ââåäèòå ñòðîêó: ";
			cin >> str1;
			n = strlen(str1);//íàõîäèì äëèíó ñòðîêè
			//ñîçäàåì öèêë for, êîòîðûé ïðîõîäèò ïî ñèìâîëàì ñòðîêè è èùåò "à"
			for (int i = 0; str1[i] != '\0'; i++) {
				if (str1[i] == 'c')
				{
					//åñëè â ñòðîêå åñòü ñèìâîë "à", òî ïîñëå åãî íåîáõîäèìî âñòàâèòü "!"
					for (int j = n + 1; j != i; j--)
					{
						str1[j + 1] = str1[j];
					}
					str1[i + 1] = '*';
				}
			}
			cout << "Âûâîä ñòðîêè: " << str1 << endl;//âûâîä íîâîé ñòðîêè
			break;
		}
		case 3:
			break;//âûõîä èç ïðîãðàììû
		}
	} while (choice != 3);//ðàáîòàåì ñ äèàëîãîì, ïîêà íå âûáåðåì 3 âàðèàíò 
	return 0;//çàâåðøåíèå ïðîãðàììû
}