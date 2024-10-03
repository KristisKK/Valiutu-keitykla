#include <iostream>
#include <iomanip>
using namespace std;

// Konvertavimas is euru i kita valiuta funkcija
double convertFromEUR(int currency_type, double currency_value) {
    switch (currency_type) {
        case 1: return 0.8593 * currency_value;  // GBP
        case 2: return 1.0713 * currency_value;    // USD
        case 3: return 88.8260 * currency_value; // INR
        default: return 0;
    }
}

// Valiutu konvertavimo i eurus funkcija
double convertToEUR(int currency_type, double currency_value) {
    switch (currency_type) {
        case 1: return currency_value / 0.8593;  // GBP
        case 2: return currency_value / 1.0713;    // USD
        case 3: return currency_value /88.8260 ; // INR
        default: return 0;
    }
}

// Funkcija valiutos pirkimui
double buyCurrency(int currency_type, double currency_value) {
    switch (currency_type) {
        case 1: return currency_value / 0.8450;  // GBP
        case 2: return currency_value / 1.0547;  // USD
        case 3: return currency_value / 85.2614;  // INR
        default: return 0;
    }
}

// Funkcija valiutos pardavimui
double sellCurrency(int currency_type, double currency_value) {
    switch (currency_type) {
        case 1: return currency_value / 0.9060;  // GBP
        case 2: return currency_value / 1.1309;  // USD
        case 3: return currency_value / 92.8334;  // INR
        default: return 0;
    }
}

// valiutos pasirinkimas ir atvaizdavimas funkcija
string getCurrencyName(int currency_type) {
    switch (currency_type) {
        case 1: return "GBP";
        case 2: return "USD";
        case 3: return "INR";
        default: return "";
    }
}

int main() {
    cout << "1. Valiutos kurso palyginimas su kita valiuta \n";
    cout << "2. Galimybe isigyti valiutos \n";
    cout << "3. galimybe parduoti valiuta \n";
    int menu_option;
    cout << "irasykite jus dominancios opcijos numeri ";
    cin >> menu_option;

    int currency_type;
    double currency_value, result;
    string currency_name;

    switch (menu_option) {
        case 1: {
            cout << "Pasirinkite kokiu budu norite keisti valiuta: \n";
            cout << "1. EUR -> Kita valiuta \n";
            cout << "2. Kita valiuta -> EUR \n";
            int change_option;
            cin >> change_option;

            cout << "pasirinkite valiuta: \n1. GBP \n2. USD \n3. INR\n";
            cin >> currency_type;
            currency_name = getCurrencyName(currency_type);

            cout << "irasykite suma (" << (change_option == 1 ? "EUR" : currency_name) << "): ";
            cin >> currency_value;

            if (change_option == 1) {
                result = convertFromEUR(currency_type, currency_value);
                cout << fixed << setprecision(2) << currency_value << " EUR -> "
                     << fixed << setprecision(2) << result << " " << currency_name << endl;
            } else {
                result = convertToEUR(currency_type, currency_value);
                cout << fixed << setprecision(2) << currency_value << " " << currency_name << " -> "
                     << fixed << setprecision(2) << result << " EUR" << endl;
            }
            break;
        }
        case 2: {
            cout << "Pasirinkite kokia valiuta norite isigyti: \n1. GBP \n2. USD \n3. INR\n";
            cin >> currency_type;
            currency_name = getCurrencyName(currency_type);

            cout << "irasykite suma kuria norite isigyti (" << currency_name << "): ";
            cin >> currency_value;
            result = buyCurrency(currency_type, currency_value);

            cout << "Sveikiname, isigijote: " << fixed << setprecision(2) << currency_value << " " << currency_name
                 << " uz " << fixed << setprecision(2) << result << " EUR" << endl;
            break;
        }
        case 3: {
            cout << "Pasirinkite kokia valiuta norite parduoti: \n1. GBP \n2. USD \n3. INR\n";
            cin >> currency_type;
            currency_name = getCurrencyName(currency_type);

            cout << "irasykite suma kuria norite parduoti (" << currency_name << "): ";
            cin >> currency_value;
            result = sellCurrency(currency_type, currency_value);

            cout << "Sveikiname, pardavete: " << fixed << setprecision(2) << currency_value << " " << currency_name
                 << " uz " << fixed << setprecision(2) << result << " EUR" << endl;
            break;
        }
        default:
            cout << "Neteisingas pasirinkimas. Bandykite dar karta." << endl;
            break;
    }
    return 0;
}
