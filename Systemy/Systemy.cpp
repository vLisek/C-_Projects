// Filip Lisowski 4I

#include <windows.h>
#include <iostream>
#include <cstdlib>

using namespace std;

// Zmienna typu uchwyt (handle) umożliwiająca korzystanie z funkcji związanych z oknem konsoli. W tym przypadku pomocna przy zmianie kolorów tekstu.
HANDLE hOut;

// Funkcja zamieniająca liczbę dziesiętną na liczbę w systemie dwójkowym
void DecimalToBinary(int Decimal) {
    int Binary[32];
    int i = 0;

    while (Decimal > 0) {
        Binary[i] = Decimal % 2;
        Decimal /= 2;
        i++;
    }

    for (int j = i - 1; j >= 0; j--) {
        cout << Binary[j];
    }

    cout << endl;
}

// Funkcja zamieniająca liczbę dziesiętną na liczbę w systemie ósemkowym
void DecimalToOctal(int Decimal) {
    int Octal[32];
    int i = 0;

    if (Decimal == 0) {
        cout << "0" << endl;
    }

    while (Decimal > 0) {
        Octal[i] = Decimal % 8;
        Decimal /= 8;
        i++;
    }

    for (int j = i - 1; j >= 0; j--) {
        cout << Octal[j];
    }

    cout << endl;
}

// Funkcja zamieniająca liczbę dziesiętną na liczbę w systemie szesnastkowym
void DecimalToHex(int Decimal) {
    char Hex[32];
    int i = 0;

    if (Decimal == 0) {
        cout << "0" << endl;
    }

    while (Decimal > 0) {
        int reszta = Decimal % 16;
        if (reszta < 10) {
            Hex[i] = reszta + '0';
        }
        else {
            Hex[i] = reszta - 10 + 'A';
        }
        Decimal /= 16;
        i++;
    }

    for (int j = i - 1; j >= 0; j--) {
        cout << Hex[j];
    }

    cout << endl;
}

// Funkcja wyświetlająca logo programu.
void ProgramsLogo() {
	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << endl;
	cout << " ::::    ::: :::    ::: ::::    ::::        ::::::::   ::::::::  ::::    ::: :::     ::: " << endl;
	cout << " :+:+:   :+: :+:    :+: +:+:+: :+:+:+      :+:    :+: :+:    :+: :+:+:   :+: :+:     :+: " << endl;
	cout << " :+:+:+  +:+ +:+    +:+ +:+ +:+:+ +:+      +:+        +:+    +:+ :+:+:+  +:+ +:+     +:+ " << endl;
	cout << " +#+ +:+ +#+ +#+    +:+ +#+  +:+  +#+      +#+        +#+    +:+ +#+ +:+ +#+ +#+     +:+ " << endl;
	cout << " +#+  +#+#+# +#+    +#+ +#+       +#+      +#+        +#+    +#+ +#+  +#+#+#  +#+   +#+  " << endl;
	cout << " #+#   #+#+# #+#    #+# #+#       #+#      #+#    #+# #+#    #+# #+#   #+#+#   #+#+#+#   " << endl;
	cout << " ###    ####  ########  ###       ###       ########   ########  ###    ####     ###     " << endl << endl;
	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);
	cout << " ________________________________________________________________________________________" << endl << endl;
	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
}

// Funkcja odpowiadająca za wyświetlanie ekranu ładowania.
void Loading() {
	system("cls");
	for (int i = 1; i <= 50; i++) {
		system("cls");
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		cout << "\n\t\t     NumConv by Filip Lisowski";
		cout << "\n\n\t\t       Trwa ładowanie... " << 2 * i << "% \n\t ";
		for (int j = 1; j <= i; j++) {
			cout << "|";
		}
		if (i > 1 && i < 20) {
			cout << "\n\n\t\t     Creating Temporary Files";
		}
		else if (i > 20 && i < 40) {
			cout << "\n\n\t\t     Accessing Main Memory";
		}
		else if (i > 40 && i < 48) {
			cout << "\n\n\t\t     Accessing Cache";
		}
		else {
			cout << "\n\n\t\tGotowe. Naciśnij Enter by kontynuować ";
		}
		Sleep(150 - i * 3);
	}
	system("PAUSE > 0");
	system("cls");
}

// Funkcja wyświetlająca komunikat jeśli użytkownik wpisał poprawną liczbę.
void BlinkingTrueNumber() {
	for (int i = 0; i < 4; ++i) {
		system("cls");
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t Wprowadziłeś prawidłową liczbę! =)";
		Sleep(600);
		system("cls");
		Sleep(300);
	}
}

// Funkcja wyświetlająca komunikat jeśli użytkownik wybrał złą opcję.
void BlinkingFalseOption() {
	for (int i = 0; i < 4; ++i) {
		system("cls");
		SetConsoleTextAttribute(hOut, FOREGROUND_RED);
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t Wybrałeś złą opcję! Spróbuj ponownie. =(";
		Sleep(600);
		system("cls");
		Sleep(300);
	}
}

// Funkcja wyświetlająca komunikat jeśli użytkownik wpisał złą liczbę.
void BlinkingFalseNumber() {
	for (int i = 0; i < 4; ++i) {
		system("cls");
		SetConsoleTextAttribute(hOut, FOREGROUND_RED);
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t Wprowadziłeś błędną liczbę! Spróbuj ponownie. =(";
		Sleep(600);
		system("cls");
		Sleep(300);
	}
}

int main() {
	// Wyświetlanie polskich znaków.	
	setlocale(LC_CTYPE, "Polish");

	// Zmienna przechowująca liczbę, która ma zostać zmieniona.
	int Decimal = 0;
	

	// Kod ten maksymalizuje okno konsoli do pełnej wielkości ekranu. Pozwala to na lepszą widoczność i wygodne korzystanie z aplikacji.
	HWND console = GetConsoleWindow();
	ShowWindow(console, SW_MAXIMIZE);


	// Pobieranie uchwytu (handle) do standardowego urządzenia wyjściowego, które w tym przypadku oznacza ekran konsoli.
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);


	// Kod ten powiększa czcionkę wyświetlaną w konsoli o 1.5 raza większą niż domyślna.
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFOEX fontInfo;
	fontInfo.cbSize = sizeof(fontInfo);
	GetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);
	fontInfo.dwFontSize.X *= 1.8; // Powiększenie czcionki na osi X
	fontInfo.dwFontSize.Y *= 1.8; // Powiększenie czcionki na osi Y
	SetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);

	Loading();

	// Ekran powitalny.
	ProgramsLogo();
	cout << " Witaj w fascynującym świecie NumConv! \n\n";
	cout << " Odkryj potęgę przeliczania liczb w różnych systemach liczbowych!NumCode to magiczne \n";
	cout << " narzędzie, które zamienia liczby na ich tajemnicze odpowiedniki. \n\n\n";
	cout << " Naciśnij Enter aby kontynuować... ";
	system("PAUSE > 0");
	system("cls");
	
	// Wprowadzenie liczby, która ma zostać zmieniona z zastosowaniem blokady dla wprowadzania liczb z przedziału 1 - 9999.
	ProgramsLogo();
	cout << " Proszę podaj mi liczbę z przedziału od 1 do 9999." << endl << endl;
	cout << " Pamiętaj, że liczba powinna być całkowita i mieścić się w zakresie od 1 do 9999. " << endl;
	cout << " Jeśli wprowadzisz liczbę spoza tego przedziału, poproszę Cię o ponowne wpisanie" << endl;
	cout << " właściwej liczby." << endl << endl << endl;
	cout << " Naciśnij Enter aby kontynuować... ";
	system("PAUSE > 0");
	system("cls");
	do {
		ProgramsLogo();
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << " Wprowadź liczbę: ";
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		cin >> Decimal;

		// Warunek: Użytkownik wprowadził liczbę z zakresu 1 - 9999. Przechodzi dalej.
		if (Decimal >= 1 && Decimal <= 9999) {
			BlinkingTrueNumber();
			break;
		}

		// Blokada: Użytkownik wprowadził błędną liczbę.
		else {
			BlinkingFalseNumber();
		}
	} 
	while (true);
	
	
	// Pętla, która będzie wyświetlać listę pól do wyboru.
	do {
		system("cls");
		ProgramsLogo();
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		cout << " ------------------------------ " << endl;
		cout << " |            ";
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		cout << "MENU";
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		cout << "            | " << endl;
		cout << " ------------------------------ " << endl << endl;
			SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			cout << " [1] ";
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "- Wprowadź nową liczbę." << endl;
				SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				cout << " [2] ";
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "- Zamień podaną liczbę na system binarny (dwójkowy)." << endl;
					SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					cout << " [3] ";
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << "- Zamień podaną liczbę na system oktalny (ósemkowy)." << endl;
						SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
						cout << " [4] ";
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
						cout << "- Zamień podaną liczbę na system heksadecymalny (szesnastkowy)." << endl;
							SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
							cout << " [5] ";
							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
							cout << "- Zakończ program" << endl << endl;
		
		// Zmienna przechowująca liczbę, która odpowiada za wybieranie pozycji w programie.
		int Option;

		// Zmienna przechowująca liczbę, która odpowiada za wybieranie pozycji na wyjściu z programu.
		int ExitOption;
		
		// Wprowadzenie liczby, która odpowiada za wybieranie pozycji w programie.
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		cout << " Wpisz pozycję, którą wybierasz: ";
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		cin >> Option;
		
		// Warunek wielokrotnego wyboru.
		
		switch (Option) {
			
			// Ponowne wpisanie liczby.
			case 1:
				system("cls");
				do {
					ProgramsLogo();
					SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
					cout << " Wprowadź liczbę: ";
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cin >> Decimal;

					// Warunek: Użytkownik wprowadził liczbę z zakresu 1 - 9999. Przechodzi dalej.
					if (Decimal >= 1 && Decimal <= 9999) {
						BlinkingTrueNumber();
						break;
					}

					// Blokada: Użytkownik wprowadził błędną liczbę.
					else {
						BlinkingFalseNumber();
					}
				} 
				while (true);
				break;
				
				
			// Wywołanie i wyświetlenie funkcji zamieniającej liczbę decymalną na binarną.
			
			case 2:
				system("cls");
				ProgramsLogo();
				SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				cout << " ----------------------------- " << endl;
				cout << " |            ";
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "BIN";
				SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				cout << "            | " << endl;
				cout << " ----------------------------- " << endl << endl;
				SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				cout << " Twoja liczba ";
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "(" << Decimal << ")";
				SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				cout << " w systemie binarnym (dwójkowym): ";
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				DecimalToBinary(Decimal);
				cout << "\n\n Naciśnij Enter aby kontynuować... ";
				system("PAUSE > 0");
				system("cls");
				break;
				
			// Wywołanie i wyświetlenie funkcji zamieniającej liczbę decymalną na oktalną.
			case 3:
				system("cls");
				ProgramsLogo();
				SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				cout << " ----------------------------- " << endl;
				cout << " |            ";
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "OCT";
				SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				cout << "            | " << endl;
				cout << " ----------------------------- " << endl << endl;
				SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				cout << " Twoja liczba ";
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "(" << Decimal << ")";
				SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				cout << " w systemie oktalnym (ósemkowym): ";
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				DecimalToOctal(Decimal);
				cout << "\n\n Naciśnij Enter aby kontynuować... ";
				system("PAUSE > 0");
				system("cls");
				break;
				
			// Wywołanie i wyświetlenie funkcji zamieniającej liczbę decymalną na heksadecymalną.
			case 4:
				system("cls");
				ProgramsLogo();
				SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				cout << " ----------------------------- " << endl;
				cout << " |            ";
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "HEX";
				SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				cout << "            | " << endl;
				cout << " ----------------------------- " << endl << endl;
				SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				cout << " Twoja liczba ";
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "(" << Decimal << ")";
				SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				cout << " w systemie heksadecymalnym (szesnastkowym): ";
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				DecimalToHex(Decimal);
				cout << "\n\n Naciśnij Enter aby kontynuować... ";
				system("PAUSE > 0");
				system("cls");
				break;
				
			// Zamykanie programu.
			case 5:
				system("cls");
				ProgramsLogo();
				cout << " Właśnie próbujesz wyłączyć aplikację. Dziękuję za skorzystanie z programu!";
				cout << "\n\n Naciśnij Enter aby kontynuować... ";
				system("PAUSE > 0");
				system("cls");
				cout << "\n\n\t\t\t\t\t\t\t\t NumConv by Lisek \n\n\n";
				return 0;
			
			// Wartość defaultowa - jeśli użytkownik wprowadzi liczbę spoza zakresu (1 - 5) wyświetli, że wprowadził błędne dane.
			default:
				system("cls");
				BlinkingFalseOption();
				break;
			}
		}
		while (true);
	return 0;
}
