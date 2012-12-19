#include "await.h"
#include "sodamachine.h"
#include "amountnotfulfilled.h"

StateInterface * Await::m_instance = NULL;
SodaMachine * Await::m_soda_machine = NULL;

Await::Await(QObject *parent) :
    QObject(parent)
{
    setObjectName("Await");
}

StateInterface *Await::instance(SodaMachine *soda_machine)
{
    if(soda_machine && !m_soda_machine)
        m_soda_machine = soda_machine;

    if(!m_instance)
        m_instance = new Await;

    return m_instance;
}

void Await::enter()
{
    qDebug() << "Entered" << this->objectName();

    m_soda_machine->set_new_state(this);

    connect(m_soda_machine, SIGNAL(cash_inserted_050()), SLOT(exit()));
    connect(m_soda_machine, SIGNAL(cash_inserted_100()), SLOT(exit()));
}

void Await::exit()
{
    qDebug() << "Exit" << this->objectName();
    m_soda_machine->disconnect(this, SLOT(exit()));
    AmountNotFulfilled::instance()->enter();
}
