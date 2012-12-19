#include "nosoda.h"
#include "sodamachine.h"

StateInterface * NoSoda::m_instance = NULL;
SodaMachine * NoSoda::m_soda_machine = NULL;

NoSoda::NoSoda(QObject *parent) :
    QObject(parent)
{
    setObjectName("NoSoda");
}

StateInterface *NoSoda::instance(SodaMachine *soda_machine)
{
    if(soda_machine && !m_soda_machine)
        m_soda_machine = soda_machine;

    if(!m_instance)
        m_instance = new NoSoda;

    return m_instance;
}

void NoSoda::enter()
{
    qDebug() << "Entered" << this->objectName();

    m_soda_machine->set_new_state(this);

    // REQ-NOTE
    // we assume that the maintainer powers the machine off
    // before refilling it, if the requirements change these
    // connections must be released when exiting the state
    connect(m_soda_machine, SIGNAL(cash_inserted_050()), m_soda_machine, SLOT(refund_full()));
    connect(m_soda_machine, SIGNAL(cash_inserted_100()), m_soda_machine, SLOT(refund_full()));
}

void NoSoda::exit()
{
    qDebug() << "Exit" << this->objectName();
}
