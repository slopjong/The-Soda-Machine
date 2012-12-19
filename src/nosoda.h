#ifndef NOSODA_H
#define NOSODA_H

#include <QObject>
#include "state.h"

class NoSoda : public QObject, public StateInterface
{
    Q_OBJECT
    Q_INTERFACES(StateInterface)

public:

    void enter();
    void exit();

    static StateInterface *instance(SodaMachine *soda_machine = 0);

private:

    static StateInterface *m_instance;
    static SodaMachine *m_soda_machine;
    explicit NoSoda(QObject *parent = 0);
};

#endif // NOSODA_H
