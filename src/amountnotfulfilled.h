#ifndef AMOUNTNOTFULFILLED_H
#define AMOUNTNOTFULFILLED_H

#include <QObject>
#include "state.h"

class AmountNotFulfilled : public QObject, public StateInterface
{
    Q_OBJECT
    Q_INTERFACES(StateInterface)

public slots:

    void enter();
    void exit();

public:

    static StateInterface *instance(SodaMachine *soda_machine = 0);

private:

    explicit AmountNotFulfilled(QObject *parent = 0);
    void disconnect_signals();

    static StateInterface *m_instance;
    static SodaMachine *m_soda_machine;

    // flag which is true if this states is listening
    // to 'cash inserted' and 'abort' signals
    bool m_signals_connected;
    StateInterface *m_next_state;

private slots:

    void abort();

};

#endif // AMOUNTNOTFULFILLED_H
