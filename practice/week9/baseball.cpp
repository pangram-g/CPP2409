#include <iostream>
#include <string>
using namespace std;

// 주어진 세자리 숫자가 다른지 확인하는 함수
bool checkNumber(int Number)
{
	bool same = false;
	int Fnum, Snum, Tnum;
	Fnum = Number / 100;						  // 입력한 숫자에서 백의 자리 추출
	Snum = (Number - (Fnum * 100)) / 10;		  // 입력한 숫자에서 십의 자리 추출
	Tnum = (Number - (Fnum * 100) - (Snum * 10)); // 입력한 숫자에서 일의 자리 추출
	// 입력한 숫자에서 추출한 숫자가 전부 다른지 확인
	if ((Fnum != Snum) && (Snum != Tnum) && (Tnum != Fnum))
	{
		same = true;
	}
	return same;
}

int main()
{
	int randomNum; // 맞춰야 하는 3자리수의 숫자 저장 변수
	int firstNum;  // 정답의 첫번째 자리수
	int secondNum; // 정답의 두번째 자리수
	int thirdNum;  // 정답의 세번째 자리수

	while (1)
	{
		randomNum = rand() % 900 + 100; // 랜덤한 3자리수 생성

		bool same = false; // 모든 수가 다를 경우 true를 갖는 변수

		// TODO 1: 3자리 숫자의 자릿수를 추출하고, 모든 수가 다른지 체크하는 코드블록 작성
		firstNum = randomNum / 100;									  // 백의 자리 추출
		secondNum = (randomNum - (firstNum * 100)) / 10;			  // 십의 자리 추출
		thirdNum = (randomNum - (firstNum * 100) - (secondNum * 10)); // 일의 자리 추출
		// 추출한 숫자가 전부 다른지 확인
		same = checkNumber(randomNum);

		if (same == true)
		{
			break;
		}
	}

	int turn = 0;
	while (1)
	{
		cout << turn + 1 << "번째 시도입니다. " << endl;

		int userNumber;	 // 사용자가 입력한 세자리수 저장 변수
		int guessFirst;	 // 추측한 숫자의 첫번째 자리수
		int guessSecond; // 추측한 숫자의 두번째 자리수
		int guessThird;	 // 추측한 숫자의 세번째 자리수

		// 사용자에게 세자리 수를 입력받는 코드 블록
		while (1)
		{
			cout << "세자리 수를 입력해주세요: ";
			cin >> userNumber;

			bool same = false; // 모든 수가 다를 경우 true를 갖는 변수
			// TODO 1: 3자리 숫자의 자릿수를 추출하고, 모든 수가 다른지 체크하는 코드블록 작성
			guessFirst = userNumber / 100;										 // 입력한 숫자에서 백의 자리 추출
			guessSecond = (userNumber - (guessFirst * 100)) / 10;				 // 입력한 숫자에서 십의 자리 추출
			guessThird = (userNumber - (guessFirst * 100) - (guessSecond * 10)); // 입력한 숫자에서 일의 자리 추출
			// 입력한 숫자에서 추출한 숫자가 전부 다른지 확인
			same = checkNumber(userNumber);
			/*if ((guessFirst != guessSecond) && (guessSecond != guessThird) && (guessThird != guessFirst))
			{
				same = true;
			}*/
			// 중복숫자 있을시 다시 하라는 문구 출력
			if (same == false)
			{
				cout << "입력한 숫자에 중복된 숫자가 있습니다. 다시입력하세요" << endl;
			}

			if (to_string(userNumber).length() != 3)
			{
				cout << "입력된 숫자가 3자리 수가 아닙니다. 다시 입력하세요." << endl;
				continue;
			}

			if (same == true)
			{
				break;
			}
		}

		int strike = 0; // 스트라이크 갯수를 저장하는 변수
		int ball = 0;	// 볼 갯수를 저장하는 변수

		// TODO 2: 정답과 추측한 숫자의 자릿수와 숫자를 비교하며 힌트를 주기 위한 코드블록 작성
		// 스트라이크 인지 확인
		// else 볼인지 확인
		if (firstNum == guessFirst)
			strike++;
		else if (firstNum == guessSecond || firstNum == guessThird)
			ball++;
		if (secondNum == guessSecond)
			strike++;
		else if (secondNum == guessFirst || secondNum == guessThird)
			ball++;
		if (thirdNum == guessThird)
			strike++;
		else if (thirdNum == guessFirst || thirdNum == guessSecond)
			ball++;
		cout << userNumber << "의 결과 : " << strike << " 스트라이크, " << ball << "볼 입니다." << endl;

		if (strike == 3)
		{
			cout << "정답을 맞췄습니다. 축하합니다.";
			break;
		}

		turn += 1;
	}

	return 0;
}
