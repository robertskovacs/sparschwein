#include <iostream>

using namespace std;

class Sparschwein {
    public:
        int cent1, cent5, cent10;

        void print();
        void leeren();
        void einwerfen(int acent1, int acent5, int acent10);
        int inhalt() const;

        Sparschwein(int acent1=0, int acent5=0, int acent10=0) {
            einwerfen(acent1, acent5, acent10);
        }

        friend bool operator==(const Sparschwein& s1, const Sparschwein& s2) {
            return s1.inhalt() == s2.inhalt();
        }

        friend bool operator!=(const Sparschwein& s1, const Sparschwein& s2) {
            return s1.inhalt() != s2.inhalt();
        }

        friend bool operator>(const Sparschwein& s1, const Sparschwein& s2) {
            return s1.inhalt() > s2.inhalt();
        }

        friend bool operator<(const Sparschwein& s1, const Sparschwein& s2) {
            return s1.inhalt() < s2.inhalt();
        }

};

int Sparschwein::inhalt() const{
    int total = cent1+cent5*5+cent10*10;
    return total;
}

void Sparschwein::einwerfen(int acent1, int acent5, int acent10) {
    cent1 = acent1;
    cent5 = acent5;
    cent10 = acent10;
}

void Sparschwein::print() {
        cout << cent1 << "*1Cent + " << cent5 << "*5Cent + " << cent10 << "*10Cent = " << cent1+cent5*5+cent10*10 << "Cent\n";
}

void Sparschwein::leeren() {
    cent1 = 0;
    cent5 = 0;
    cent10 = 0;
}

int main() {
    Sparschwein a; // erzeugt ein leeres Sparschwein
    cout << "Sparschwein a - leer nach Erzeugung:\n";
    a.print();

    a.einwerfen(0, 2, 4);
    cout << "Sparschwein a - nach Einwurf:\n";
    a.print();

    cout << "Sparschwein b - erzeugt mit Einzern:\n";
    Sparschwein b=10; // erzeugt ein Sparschwein mit 10 Eincentmünzen als Inhalt
    b.print();

    cout << "Sparschwein c - mit verschiedene Muenzen:\n";
    Sparschwein c(2,3,4); // erzeugt ein Sparschwein mit 2 Eincent-, 3 Fünfcent- und 4 Zehncentmünzen als Inhalt
    c.print();

    c.leeren();
    cout << "Sparschwein c - nach leeren:\n";
    c.print();

    if(a==b)
        cout << "Die Summe in Sparschwein a und b sind gleich\n";
    else
        cout << "Die Summe in Sparschwein a und b sind nicht gleich\n";

    if(a<c)
        cout << "Die Summe in Sparschwein a weniger als in c\n";
    else
        cout << "Die Summe in Sparschwein a mehr als in c\n";

    return 0;
}
