#include <iostream>
#include <string>
#include <vector>

void objectClass() {
    /* Típus: az adat 'kategóriája', amely meghatározza az adattal végezhető műveleteket
     * típusspecifikáció, típusimplementáció
     * 
     * Objektum: a feladat megoldásának egy részéért felelős egység
     * tartalmazza a részhez tartozó adatokat (adattagok)
     * és az ezekkel kapcsolatos műveleteket (metódusok).
     *
     * Osztály: egy objektum szerkezetének és viselkedésének mintája, azaz:
     * - felsorolja az adattagokat (szerkezet)
     * - megadja az elvégezhető műveleteket (metódusok)
     * Az osztály alapján hozzuk létre az objektumokat, azaz példányosítjuk őket.
     * pl: std::string
     *
     * Az osztály tartalmazza a belőle példányosított objektumok reprezentációját és
     * a velük végezhető műveletek implementációit
     * -> az osztály lényegében az objektum típusa
     */
    
    std::string str; // <típus> <változónév>
    
    /* Objektum tagjainak elérése:
     * <objektumnév>.<adattagnév>
     * <objektumnév>.<metódusnév>(<paraméterek>)
     */
    
    std::cout << str.size() << std::endl;
    str.append("alma");
    std::cout << str << std::endl;
    
    /* Objektum példányosítása a konstruktor segítségével történik,
     * ami inicializálja az objektum adattagjait (azok konstruktoraival)
     *
     * Alapértelmezett (default)/üres konstruktor: paraméter nélküli konstruktor,
     * minden adattagot az üres konstruktorral inicializál (ha léteznek)
     * ez hívódik meg az egyszerű változódeklarációnál
     *
     * Konstruktoroknak paraméterük is lehet, valamint tetszés szerint
     * inicializálhatják az adattagokat, sőt tetszőleges kódot végrehajthatnak
     * A konstuktorok neve mindig megegyezik az osztály nevével
     * 
     * Konstruktor meghívása kétféleképpen történhet:
     * - a változó deklarációjánál, inicializálás közben
     * pl: <típus> <változónév>(<paraméterek>);
     * - önmagában, kifejezésként
     * pl: <típus>(<paraméterek>)
     */
    
    std::string fiveA(5, 'a');
    std::cout << fiveA << std::endl;
    std::cout << std::string(10, 'c') << std::endl;
}

/* Egyéni osztály definiálása:
 * class <osztálynév> { ... }; (pontosvessző!)
 *
 * Az osztály törzsében adjuk meg az adattagokat, a konstruktorokat és a metódusokat
 * - Adattagok megadása az egyszerű változódeklaráció mintájára
 *
 * - Konstruktorok definiálása:
 * <osztálynév>(<paraméterek>) : <inicializációs lista> { ... }
 * Az inicializációs listában tudjuk megadni, hogy miként szeretnénk inicializálni az adattagokat.
 * Ennek szintaxisa:
 * <adattagnév>(<paraméterek>)
 * Ez az adott adattag típusának megfelelő paraméterekkel ellátott konstruktorával inicializálja
 * az adattagot. Alapértelmezés szerint a default konstruktor hívódik meg.
 *
 * Ha nem adunk meg konstruktort, a fordító automatikusan generál egy üres konstruktort
 *
 * - Metódusok definiálása a globális függvények mintájára:
 * <visszatérési típus> <metódusnév>(<paraméterek>) { ... }
 * Metódusokon belül az adattagokra egyszerűen a nevükkel hivatkozhatunk,
 * mint sima változók esetén.
 *
 * A metódusoknak van egy implicit 'this' paramétere, mely egy pointer arra az objektumra,
 * amelyre a metódust meghívták, pl:
 * str.append("alma") esetén az append metóduson belül this == &str
 * 
 * Egy metódus lehet 'const', melyet a paraméterlistát záró zárójel után kell írni;
 * ez jelzi a fordítónak, hogy a metódus nem módosítja az objektum adattagjait,
 * és így a metódust const objektumokra is meg lehet hívni
 *
 * Láthatósági jelzések: megadják, hogy az egyes osztálytagokat a kód melyik részéből érhetjük el
 * - public: bárhonnan
 * - private: csak az osztálydefiníción belül
 * - protected: a leszármazott osztályokban (később lesz róla szó)
 * Megjegyzés: az objektum a saját adattagjait mindig eléri
 */

class Rectangle {
private:
    int width, height; // két int típusú adattag

public:
    Rectangle() {} // üres konstruktor
    Rectangle(int w, int h) : width(w), height(h) {}
    
    int getWidth() const {
        return width;
    }
    
    int getHeight() const {
        return height;
    }
    
    void setSize(int w, int h) {
        width = w;
        height = h;
    }
    
    int area() const {
        return width * height;
    }
};

void rectangleTest() {
    Rectangle r;
    std::cout << r.getWidth() << ',' << r.getHeight() << std::endl;
    
    Rectangle r2(3, 4);
    std::cout << r2.area() << std::endl;
}

/* Referenciák:
 * Lehetőségünk van egy változót referenciaként definiálni; ekkor a változó ugyanarra az adatra
 * fog hivatkozni, mint amivel inicializáltuk (kötelező inicializálni őket)
 * Ezt követően a referenciával végzett műveletek pontosan ugyanolyanok lesznek, mintha azokat
 * az eredeti változóval végeztük volna
 * A referencia egy 'alias' lesz az eredeti változóra, mivel ugyanazt az adatot manipulálják
 *
 * Szintaxis:
 * <típus> & <változónév> = <érték>;
 * Egy referenciát csak egy másik változóval inicializálhatunk (vagy egy olyan adattal, mely
 * perzisztens, önálló memóriaterülettel rendelkezik - összefoglaló nevükön lvalue)
 *
 * Konstans referencia: ugyanolyan mint a referencia, de a hivatkozott memóriaterületet
 * nem módosíthatjuk a referencián keresztül (csak az eredeti változóval)
 *
 * Szintaxis:
 * const <típus> & <változónév> = <érték>;
 * Fontos különbség a referenciához képest, hogy konstans referenciákat nemcsak változóval
 * (lvalue-val) inicializálhatunk, hanem gyakorlatilag tetszőleges kifejezéssel,
 * így olyanokkal is, amelyeknek nincs perzisztens memóriaterülete
 * (pl. literálok, kifejezések), összefoglaló nevükön rvalue
 *
 * Paraméterátadás módjai:
 * - érték szerinti: a függvénynek átadott argumentum kiértékelődik, majd az értéke átmásolódik
 * a függvényparaméterbe
 * - referencia szerinti: a paraméter ugyanarra az adatra hivatkozik, mint az átadott argumentum
 * így, lehetőségünk van az átadott változó értéke módosítani a függvényből
 * (kivéve konstans referenciánál)
 *
 * Általános, legtöbb esetben működő tipp:
 * Primitív típusokat érték szerint, objektumokat referencia szerint adjunk át
 */

void byValue(int x) {
    x = 1;
}

void byReference(int &x) {
    x = 1;
}

void byConstReference(const Rectangle &r) {
//  r = Rectangle(1, 1);
//  r.setSize(310, 2);
    std::cout << r.area() << std::endl;
}

void paramTest() {
    int x = 2;
    std::cout << x << std::endl;
    byValue(x);
    std::cout << x << std::endl;
    byReference(x);
    std::cout << x << std::endl;
//  byReference(2);
    
    Rectangle r(2, 3);
    byConstReference(r);
    byConstReference(Rectangle(5, 3));
}

/* C++-ban lehetőség van az operátorok túlterhelésére
 * Az operátorokat speciális nevű függvényként adjuk meg, általában:
 * operator <szimbólum> (<paraméterek>) alakban
 * Ennek általában két módja van:
 * - Külön függvényként definiáljuk (<< és >> operátornál gyakran alkalmazzák)
 * - Ha az operátor egy objektumhoz kötődik, akkor definiálhatjuk az operátort metódusként is,
 * ekkor az első operandus lesz a 'this' paraméter
 * 
 * A felüldefinálás módja és lehetőségei operátoronként eltérő.
 *
 * A kiíró és beolvasó operátort gyakran friend függvénnyel adják meg. Ha egy függvényt
 * osztálydefiníció belsejében deklarálunk, és a 'friend' módosítóval látjuk el, akkor a függvény
 * nem az osztály metódusa lesz, hanem egy önálló függvény, ami hozzáfér az adott osztály
 * objektumainak minden tagjához (private és protected).
 */

std::ostream& operator<<(std::ostream &out, const Rectangle &r) {
    return out << "w: " << r.getWidth() << ", h: " << r.getHeight();
}

class Point {
private:
    int x, y;

public:
    Point operator+(const Point &p) const {
        return Point(x + p.x, y + p.y);
    }
    
    friend std::ostream& operator<<(std::ostream &out, const Point &p) {
        return out << '(' << p.x << ',' << p.y << ')';
    }
    
    friend std::istream& operator>>(std::istream &in, Point &p) {
        return in >> p.x >> p.y;
    }
};

void pointTest() {
    Point p;
    std::cout << "Adja meg a pont koordinatait: ";
    std::cin >> p;
    std::cout << p;
}

int main() {
    objectClass(); std::cout << std::endl;
    rectangleTest(); std::cout << std::endl;
    paramTest(); std::cout << std::endl;
    pointTest(); std::cout << std::endl;
    return 0;
}
