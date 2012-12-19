#include "amountnotfulfilled.h"
#include "sodamachine.h"
#include "await.h"
#include "poweredon.h"

StateInterface *AmountNotFulfilled::m_instance = NULL;
SodaMachine * AmountNotFulfilled::m_soda_machine = NULL;

AmountNotFulfilled::AmountNotFulfilled(QObject *parent) :
    QObject(parent),
    m_signals_connected(false),
    m_next_state(0)
{
    setObjectName("AmountNotFulfilled");
}

void AmountNotFulfilled::disconnect_signals()
{
    m_soda_machine->disconnect(this, SLOT(enter()));
    m_soda_machine->disconnect(this, SLOT(abort()));
    m_signals_connected = false;
}

void AmountNotFulfilled::abort()
{
    m_soda_machine->refund_full();
    m_next_state = Await::instance();
    exit();
}

StateInterface *AmountNotFulfilled::instance(SodaMachine *soda_machine)
{
    if(soda_machine && !m_soda_machine)
        m_soda_machine = soda_machine;

    if(!m_instance)
        m_instance = new AmountNotFulfilled;

    return m_instance;
}

void AmountNotFulfilled::enter()
{
    qDebug() << "Entered" << this->objectName();

    m_soda_machine->set_new_state(this);

    if(!m_signals_connected)
    {
        // the next two signals make this state re-entrant
        connect(m_soda_machine, SIGNAL(cash_inserted_050()), SLOT(enter()));
        connect(m_soda_machine, SIGNAL(cash_inserted_100()), SLOT(enter()));
        connect(m_soda_machine, SIGNAL(abort()), SLOT(abort()));

        m_signals_connected = true;
    }

    int cash = m_soda_machine->amount();
    int price = m_soda_machine->price();

    if( cash >= price )
    {
        m_soda_machine->refund_exchange();
        m_next_state = PoweredOn::instance();
        exit();
    }
}

void AmountNotFulfilled::exit()
{
    qDebug() << "Exit" << this->objectName();
    disconnect_signals();
    m_next_state->enter();
}
