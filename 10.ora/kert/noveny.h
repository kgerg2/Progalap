#pragma once

class Noveny {
protected:
    int eresi_ido;
    Noveny(int ido) : eresi_ido(ido) {}

public:
    int eresiIdo() const { return eresi_ido; }
};

class Haszon : public Noveny {
protected:
    Haszon(int ido) : Noveny(ido) {}
};

class Virag : public Noveny {
protected:
    Virag(int ido) : Noveny(ido) {}
};

class Burgonya : public Haszon {
private:
    Burgonya() : Haszon(3) {}
    static Burgonya *elem;

public:
    static Burgonya *getBurgonya() {
        if (elem == nullptr)
            elem = new Burgonya();
        return elem;
    }
};

Burgonya* Burgonya::elem = nullptr;
