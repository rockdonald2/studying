#ifndef PROJEKTEK_LISTAELEM_H
#define PROJEKTEK_LISTAELEM_H

#include <string>

// string alaptipusú lista
typedef std::string ElemTipus;

struct ListaElem {
    // információsmező
    ElemTipus info;
    // kapcsolattartó mező a következő listaelemre
    ListaElem* kov = nullptr;
};

#endif //PROJEKTEK_LISTAELEM_H
