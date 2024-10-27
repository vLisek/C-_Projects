// Filip Lisowski

#include <windows.h>
#include <iostream>
#include <cstdlib>

using namespace std;

// Zmienna typu uchwyt (handle) umożliwiająca korzystanie z funkcji związanych z oknem konsoli. W tym przypadku pomocna przy zmianie kolorów tekstu.
HANDLE hOut;

// Funkcja odpowiedzialna za przeliczanie podanej przez użytkownika kwoty na inną walutę.
void CurrencyToCurrency(int& UsersAmount, int& UsersCurrency) {

	// Wyświetlanie polskich znaków.
	setlocale(LC_CTYPE, "Polish");

	// Zmienna przechowująca liczbę odpowiadającą za wybieranie pozycji w menu.
	int CurrencySelection;

	// Pierwszy warunek: Użytkownik wybrał walutę PLN.
	if (UsersCurrency == 1) {
		do {
			cout << " Na jaką walutę chcesz przeliczyć podaną kwotę w PLN?" << endl;
				SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED);
				cout << " [1] ";
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "- Euro" << endl;
					SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED);
					cout << " [2] ";
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << "- Dolar" << endl;
						SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED);
						cout << " [3] ";
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
						cout << "- Anuluj" << endl << endl;
							cout << " Wybierz: ";
							SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED);
							cin >> CurrencySelection;
							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);

			// Pierwszy warunek: Użytkownik wybrał konwersję PLN -> EUR.
			if (CurrencySelection == 1) {
				system("cls");
				UsersAmount = UsersAmount * 0.21;
				cout << " Twoja liczba po przeliczeniu z PLN na EUR wynosi: ";
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED);
				cout << UsersAmount << " EUR" << endl;
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				UsersCurrency = 2;
				return;
			}

			// Drugi warunek: Użytkownik wybrał konwersję PLN -> USD.
			else if (CurrencySelection == 2) {
				system("cls");
				UsersAmount = UsersAmount * 0.24;
				cout << " Twoja liczba po przeliczeniu z PLN na USD wynosi: ";
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED);
				cout << UsersAmount << " USD" << endl;
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				UsersCurrency = 3;
				return;
			}

			// Trzeci warunek: Użytkownik anulował wykonywanie akcji.
			else if (CurrencySelection == 3) {
				system("cls");
				break;
			}

			// Blokada: Użytkownik wybrał złą opcję w menu.
			else {
				system("cls");
				SetConsoleTextAttribute(hOut, FOREGROUND_RED);
				cout << " Wybrałeś złą opcję! Spróbuj ponownie." << endl << endl;
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			}
		} 
		while (true);
	}

	// Drugi warunek: Użytkownik wybrał walutę EUR.
	if (UsersCurrency == 2) {
		do {
			cout << " Na jaką walutę chcesz przeliczyć podaną kwotę w EUR?" << endl;
				SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED);
				cout << " [1] ";
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "- Złoty" << endl;
					SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED);
					cout << " [2] ";
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << "- Dolar" << endl;
						SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED);
						cout << " [3] ";
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
						cout << "- Anuluj" << endl << endl;
							cout << " Wybierz: ";
							SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED);
							cin >> CurrencySelection;
							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);

			// Pierwszy warunek: Użytkownik wybrał konwersję EUR -> PLN.
			if (CurrencySelection == 1) {
				system("cls");
				UsersAmount = UsersAmount * 4.66;
				cout << " Twoja liczba po przeliczeniu z EUR na PLN wynosi: ";
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED);
				cout << UsersAmount << " PLN" << endl;
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				UsersCurrency = 1;
				return;
			}

			// Drugi warunek: Użytkownik wybrał konwersję EUR -> USD.
			else if (CurrencySelection == 2) {
				system("cls");
				UsersAmount = UsersAmount * 1.11;
				cout << " Twoja liczba po przeliczeniu z EUR na USD wynosi: ";
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED);
				cout << UsersAmount << " USD" << endl;
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				UsersCurrency = 3;
				return;
			}

			// Trzeci warunek: Użytkownik anulował wykonywanie akcji.
			else if (CurrencySelection == 3) {
				system("cls");
				break;
			}

			// Blokada: Użytkownik wybrał złą opcję w menu.
			else {
				system("cls");
				SetConsoleTextAttribute(hOut, FOREGROUND_RED);
				cout << " Wybrałeś złą opcję! Spróbuj ponownie." << endl << endl;
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			}
		} 
		while (true);
	}

	// Trzeci warunek: Użytkownik wybrał walutę USD.
	if (UsersCurrency == 3) {
		do {
			cout << " Na jaką walutę chcesz przeliczyć podaną kwotę w USD?" << endl << endl;
				SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED);
				cout << " [1] ";
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "- Złoty" << endl;
					SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED);
					cout << " [2] ";
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << "- Euro" << endl;
						SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED);
						cout << " [3] ";
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
						cout << "- Anuluj" << endl << endl;
							cout << " Wybierz: ";
							SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED);
							cin >> CurrencySelection;
							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);

			// Pierwszy warunek: Użytkownik wybrał konwersję USD -> PLN.
			if (CurrencySelection == 1) {
				system("cls");
				UsersAmount = UsersAmount * 4.20;
				cout << " Twoja liczba po przeliczeniu z USD na PLN wynosi: ";
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED);
				cout << UsersAmount << " PLN" << endl;
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				UsersCurrency = 1;
				return;
			}

			// Drugi warunek: Użytkownik wybrał konwersję USD -> EUR.
			else if (CurrencySelection == 2) {
				system("cls");
				UsersAmount = UsersAmount * 0.90;
				cout << " Twoja liczba po przeliczeniu z USD na EUR wynosi: ";
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED);
				cout << UsersAmount << " EUR" << endl;
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				UsersCurrency = 2;
				return;
			}

			// Trzeci warunek: Użytkownik anulował wykonywanie akcji.
			else if (CurrencySelection == 3) {
				system("cls");
				break;
			}

			// Blokada: Użytkownik wybrał złą opcję w menu.
			else {
				system("cls");
				SetConsoleTextAttribute(hOut, FOREGROUND_RED);
				cout << " Wybrałeś złą opcję! Spróbuj ponownie." << endl << endl;
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			}
		} 
		while (true);
	}
}

// Funkcja odpowiedzialna za rozmienianie podanej przez użytkownika kwoty.
void Exchange(int& UsersAmount, int& UsersCurrency) {
		
	// Zmienna odpowiedzialna za przeliczanie podanej przez użytkownika kwoty nie ingerując w zmienną odpowiedzialną za przechowywanie kwoty użytkownika.
	int UsersAmountConst = UsersAmount;

	// Pierwszy warunek odpowiedzialny za rozmienianie kwoty PLN.
	if (UsersCurrency == 1) {
		cout << " Twoją kwotę pieniędzy: ";
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED);
		cout << UsersAmount << " PLN" << endl << endl;
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		cout << " Można rozmienić na:" << endl;

		int Banknotes10 = UsersAmountConst / 10;
		UsersAmountConst %= 10;
		int Coins5 = UsersAmountConst / 5;
		UsersAmountConst %= 5;
		int Coins2 = UsersAmountConst / 2;
		UsersAmountConst %= 2;
		int Coins1 = UsersAmountConst;


		if (Banknotes10 > 0) {
			cout << " " << Banknotes10 << " banknotów 10";
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED);
			cout << " PLN" << endl;
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		}
		if (Coins5 > 0) {
			cout << " " << Coins5 << " monet 5";
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED);
			cout << " PLN" << endl;
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		}
		if (Coins2 > 0) {
			cout << " " << Coins2 << " monet 2";
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED);
			cout << " PLN" << endl;
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		}
		if (Coins1 > 0) {
			cout << " " << Coins1 << " monet 1";
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED);
			cout << " PLN" << endl;
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		}
		cout << endl;
		cout << " Aby powrócić do menu głównego naciśnij jakikolwiek klawisz... ";
		system("PAUSE > 0");
		system("cls");
	}

	// Drugi warunek odpowiedzialny za rozmienianie kwoty EUR.
	if (UsersCurrency == 2) {
		cout << " Twoją kwotę pieniędzy: ";
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED);
		cout << UsersAmount << " EUR" << endl << endl;
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		cout << " Można rozmienić na:" << endl;

		int Banknotes10 = UsersAmountConst / 10;
		UsersAmountConst %= 10;
		int Coins5 = UsersAmountConst / 5;
		UsersAmountConst %= 5;
		int Coins2 = UsersAmountConst / 2;
		UsersAmountConst %= 2;
		int Coins1 = UsersAmountConst;


		if (Banknotes10 > 0) {
			cout << " " << Banknotes10 << " banknotów 10";
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED);
			cout << " EUR" << endl;
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		}
		if (Coins5 > 0) {
			cout << " " << Coins5 << " monet 5";
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED);
			cout << " EUR" << endl;
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		}
		if (Coins2 > 0) {
			cout << " " << Coins2 << " monet 2";
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED);
			cout << " EUR" << endl;
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		}
		if (Coins1 > 0) {
			cout << " " << Coins1 << " monet 1";
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED);
			cout << " EUR" << endl << endl;
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		}
		cout << endl;
		cout << " Aby powrócić do menu głównego naciśnij jakikolwiek klawisz... ";
		system("PAUSE > 0");
		system("cls");
	}

	// Trzeci warunek odpowiedzialny za rozmienianie kwoty USD.
	if (UsersCurrency == 3) {

		cout << " Twoją kwotę pieniędzy: ";
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED);
		cout << UsersAmount << " USD" << endl << endl;
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		cout << " Można rozmienić na:" << endl;

		int Banknotes10 = UsersAmountConst / 10;
		UsersAmountConst %= 10;
		int Coins5 = UsersAmountConst / 5;
		UsersAmountConst %= 5;
		int Coins2 = UsersAmountConst / 2;
		UsersAmountConst %= 2;
		int Coins1 = UsersAmountConst;


		if (Banknotes10 > 0) {
			cout << " " << Banknotes10 << " banknotów 10";
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED);
			cout << " USD" << endl;
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		}
		if (Coins5 > 0) {
			cout << " " << Coins5 << " monet 5";
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED);
			cout << " USD" << endl;
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		}
		if (Coins2 > 0) {
			cout << " " << Coins2 << " monet 2";
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED);
			cout << " USD" << endl;
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		}
		if (Coins1 > 0) {
			cout << " " << Coins1 << " monet 1";
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED);
			cout << " USD" << endl << endl;
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		}
		cout << endl;
		cout << " Aby powrócić do menu głównego naciśnij jakikolwiek klawisz... ";
		system("PAUSE > 0");
		system("cls");
	}
}

int main() {


	// Wyświetlanie polskich znaków.
	setlocale(LC_CTYPE, "Polish");

	

	// Zmienna przechowująca podaną przez użytkownika kwotę.
	int UsersAmount = 0;

	// Zmienna przechowująca podaną przez użytkownika walutę.
	int UsersCurrency = 0;

	// Zmienna odpowiedzialna za otwieranie podanej przez użytkownika pozycji menu.
	int MenuSelection = 0;

	// Kod ten maksymalizuje okno konsoli do pełnej wielkości ekranu. Pozwala to na lepszą widoczność i wygodne korzystanie z aplikacji.
	HWND console = GetConsoleWindow();
	ShowWindow(console, SW_MAXIMIZE);

	// Pobieranie uchwytu (handle) do standardowego urządzenia wyjściowego, które w tym przypadku oznacza ekran konsoli.
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	// Ekran powitalny.
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED);
	cout << endl << endl;
	cout << " ########   ##        #######  ######## ##    ##          ##    ######## ##     ## ########   #######           ##    ########   #######  ##          ###    ########  " << endl;
	cout << "      ##    ## #     ##     ##    ##     ##  ##          ##     ##       ##     ## ##     ## ##     ##         ##     ##     ## ##     ## ##         ## ##   ##     ## " << endl;
	cout << "     ##     ###      ##     ##    ##      ####          ##      ##       ##     ## ##     ## ##     ##        ##      ##     ## ##     ## ##        ##   ##  ##     ## " << endl;
	cout << "    ##      ##       ##     ##    ##       ##          ##       ######   ##     ## ########  ##     ##       ##       ##     ## ##     ## ##       ##     ## ########  " << endl;
	cout << "   ##      ###       ##     ##    ##       ##         ##        ##       ##     ## ##   ##   ##     ##      ##        ##     ## ##     ## ##       ######### ##   ##   " << endl;
	cout << "  ##      # ##       ##     ##    ##       ##        ##         ##       ##     ## ##    ##  ##     ##     ##         ##     ## ##     ## ##       ##     ## ##    ##  " << endl;
	cout << " ########   ########  #######     ##       ##       ##          ########  #######  ##     ##  #######     ##          ########   #######  ######## ##     ## ##     ## " << endl << endl;
	cout << " ______________________________________________________________________________________________________________________________________________________________________" << endl << endl << endl;
	cout << " Witaj! Program, z którego właśnie próbujesz skorzystać służy do rozmieniania oraz przeliczania na inną walutę wprowadzonej przez Ciebie kwoty." << endl;
	cout << " Życzymy miłej zabawy!" << endl << endl;
	cout << " Naciśnij jakikolwiek klawisz... ";
	system("PAUSE > 0");
	system("cls");
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);

	// Instrukcja do...while odpowiedzialna za wprowadzenie odpowiedniej kwoty.
	cout << " Przede wszystkim.. Żeby program zadziałał wprowadź kwotę składającą się z maksymalnie sześciu cyfr." << endl;
	do {
		cout << " Wprowadź kwotę: ";
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED);
		cin >> UsersAmount;
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);

		// Warunek: Użytkownik wprowadził liczbę z zakresu 1 - 999999. Przechodzi dalej.
		if (UsersAmount >= 1 && UsersAmount <= 999999) {
			system("cls");
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
			cout << " Wprowadziłeś prawidłową kwotę!" << endl << endl;
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			break;
		}

		// Blokada: Użytkownik wprowadził błędną liczbę.
		else {
			system("cls");
			SetConsoleTextAttribute(hOut, FOREGROUND_RED);
			cout << " Wprowadziłeś błędną kwotę! Spróbuj ponownie." << endl << endl;
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		}
	} 
	while (true);

	// Instrukcja do...while odpowiedzialna za wybranie przez użytkownika interesującej go waluty.
	
	cout << " Teraz wybierz walutę." << endl << endl;
	do {
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED);
		cout << " [1] ";
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		cout << "- Złoty" << endl;
			SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED);
			cout << " [2] ";
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "- Euro" << endl;
				SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED);
				cout << " [3] ";
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "- Dolar" << endl << endl;
					cout << " Wybierz: ";
					SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED);
					cin >> UsersCurrency;
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);

		// Warunek pierwszy: Użytkownik wybrał PLN.
		if (UsersCurrency == 1) {
			system("cls");
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
			cout << " Wybrałeś PLN. Idziemy dalej!" << endl << endl;
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			break;
		}

		// Warunek drugi: Użytkownik wybrał EUR.
		if (UsersCurrency == 2) {
			system("cls");
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
			cout << " Wybrałeś EUR. Idziemy dalej!" << endl << endl;
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			break;
		}

		// Warunek pierwszy: Użytkownik wybrał USD.
		if (UsersCurrency == 3) {
			system("cls");
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
			cout << " Wybrałeś USD. Idziemy dalej!" << endl << endl;
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			break;
		}

		// Blokada: Użytkownik wprowadził błędną opcję.
		else {
			system("cls");
			SetConsoleTextAttribute(hOut, FOREGROUND_RED);
			cout << " Wybrałeś złą opcję! Spróbuj ponownie." << endl << endl;
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		}
	} 
	while (true);

	// Instrukcja do...while odpowiedzialna za wyświetlenie obecnego salda użytkownika oraz zawartości menu.
	do {
		cout << " Twoje obecne saldo: ";

		// Warunek pierwszy: Wyświetla się obecne saldo użytkownika oraz wybrana przez niego waluta.
		if (UsersCurrency == 1) {
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED);
			cout << UsersAmount << " PLN" << endl;
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		}

		// Warunek drugi: Wyświetla się obecne saldo użytkownika oraz wybrana przez niego waluta.
		if (UsersCurrency == 2) {
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED);
			cout << UsersAmount << " EUR" << endl;
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		}

		// Warunek trzeci: Wyświetla się obecne saldo użytkownika oraz wybrana przez niego waluta.
		if (UsersCurrency == 3) {
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED);
			cout << UsersAmount << " USD" << endl;
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		}

		// Wyświetlenie zawartości menu.
		cout << endl;
		cout << " ------------------------------ " << endl;
		cout << " |            ";
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED);
		cout << "MENU";
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		cout << "            | " << endl;
		cout << " ------------------------------ " << endl << endl;
			SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED);
			cout << " [1] ";
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << "- Wprowadź nową liczbę." << endl;
				SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED);
				cout << " [2] ";
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "- Przelicz na inną walutę." << endl;
					SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED);
					cout << " [3] ";
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << "- Rozmień na drobne." << endl;
						SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED);
						cout << " [4] ";
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
						cout << "- Zakończ program." << endl << endl;
							cout << " Wybierz opcję, która Cię interesuje: ";
							SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED);
							cin >> MenuSelection;
							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);

		// Instrukcja warunkowa switch odpowiedzialna za wyświetlanie poszczególnych pozycji menu.
		switch (MenuSelection) {

			// Warunek pierwszy: Ponowne wprowadzenie przez użytkownika interesującej go kwoty pieniędzy. Następnie ponownie musi wybrać walutę.
			case 1:
				system("cls");
				cout << " Ponownie wprowadź kwotę składającą się z maksymalnie sześciu cyfr." << endl << endl;
				do {
					cout << " Wprowadź kwotę: ";
					SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED);
					cin >> UsersAmount;
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);

					// Warunek: Użytkownik wprowadził liczbę z zakresu 1 - 999999. Przechodzi dalej.
					if (UsersAmount >= 1 && UsersAmount <= 999999) {
						system("cls");
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
						cout << " Wprowadziłeś prawidłową kwotę! Możemy przejść dalej." << endl << endl;
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
						break;
					}

					// Blokada: Użytkownik wprowadził błędną liczbę.
					else {
						system("cls");
						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						cout << " Wprowadziłeś błędną kwotę! Spróbuj ponownie." << endl << endl;
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					}
				} 
				while (true);

				cout << " W jakiej walucie jest podana kwota?" << endl << endl;
				cout << " Teraz wybierz walutę." << endl << endl;
				do {
					SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED);
					cout << " [1] ";
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					cout << "- Złoty" << endl;
						SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED);
						cout << " [2] ";
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
						cout << "- Euro" << endl;
							SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED);
							cout << " [3] ";
							SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
							cout << "- Dolar" << endl << endl;
								cout << " Wybierz opcję spośród podanych: ";
								SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED);
								cin >> UsersCurrency;
								SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);

					// Warunek pierwszy: Użytkownik wybrał PLN.
					if (UsersCurrency == 1) {
						system("cls");
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
						cout << " Wybrałeś PLN. Idziemy dalej!" << endl;
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
						break;
					}

					// Warunek drugi: Użytkownik wybrał EUR.
					if (UsersCurrency == 2) {
						system("cls");
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
						cout << " Wybrałeś EUR. Idziemy dalej!" << endl;
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
						break;
					}

					// Warunek drugi: Użytkownik wybrał USD.
					if (UsersCurrency == 3) {
						system("cls");
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
						cout << " Wybrałeś USD. Idziemy dalej!" << endl;
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
						break;
					}

					// Blokada: Użytkownik wprowadził błędną opcję.
					else {
						system("cls");
						SetConsoleTextAttribute(hOut, FOREGROUND_RED);
						cout << " Wybrałeś złą opcję! Spróbuj ponownie." << endl << endl;
						SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					}
				} 
				while (true);
				break;

			// Drugi warunek: Wywołanie funkcji odpowiedzialnej za przeliczenie kwoty na inną walutę [ CurrencyToCurrency() ].
			case 2:
				system("cls");
				cout << " Twoje obecne saldo: ";

				// Warunek pierwszy: Wyświetla się obecne saldo użytkownika oraz wybrana przez niego waluta.
				if (UsersCurrency == 1) {
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED);
					cout << UsersAmount << " PLN" << endl;
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				}

				// Warunek drugi: Wyświetla się obecne saldo użytkownika oraz wybrana przez niego waluta.
				if (UsersCurrency == 2) {
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED);
					cout << UsersAmount << " EUR" << endl;
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				}

				// Warunek trzeci: Wyświetla się obecne saldo użytkownika oraz wybrana przez niego waluta.
				if (UsersCurrency == 3) {
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED);
					cout << UsersAmount << " USD" << endl;
					SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				}
				cout << endl;
				cout << " ------------------------------ " << endl;
				cout << " |           ";
				SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "KANTOR";
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "           | " << endl;
				cout << " ------------------------------ " << endl << endl;
				CurrencyToCurrency(UsersAmount, UsersCurrency);
				break;

			// Trzeci warunek: Wywołanie funkcji odpowiedzialnej za rozmienienie kwoty na drobne [ Exchange() ].
			case 3:
				system("cls");
				cout << " ------------------------------ " << endl;
				cout << " |       ";
				SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "ROZMIENIARKA";
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				cout << "         | " << endl;
				cout << " ------------------------------ " << endl << endl;
				Exchange(UsersAmount, UsersCurrency);
				break;
			
			// Czwarty warunek: Wyświetlenie okna pożegnalnego i zakończenie działania programu.
			case 4:
				system("cls");
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_RED);
				cout << endl << endl;
				cout << " ######## ##     ## ##     ##                     #######  " << endl;
				cout << "    ##    ##     ##  ##   ##                ##   ##     ## " << endl;
				cout << "    ##    ##     ##   ## ##               ##            ## " << endl;
				cout << "    ##    #########    ###              ##        #######  " << endl;
				cout << "    ##    ##     ##   ## ##               ##            ## " << endl;
				cout << "    ##    ##     ##  ##   ##                ##   ##     ## " << endl;
				cout << "    ##    ##     ## ##     ##                     #######  " << endl << endl << endl;
				cout << " Dziękuję za skorzystanie z mojego programu! Zapraszam ponownie! =)" << endl;
				cout << " Twórca: Filip Lisowski" << endl << endl << endl << endl << endl << endl << endl << endl;
				cout << " Naciśnij jakikolwiek przycisk aby zakończyć działanie programu...";
				system("pause > 0");
				system("cls");
				return 0;

			// Blokada: Użytkownik wprowadził błędną opcję
			default:
				system("cls");
				SetConsoleTextAttribute(hOut, FOREGROUND_RED);
				cout << " Wybrałeś złą opcję! Spróbuj ponownie." << endl << endl;
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			}
		} 
		while (MenuSelection != 4);
	return 0;
}
