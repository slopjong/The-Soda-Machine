#include "amountnotfulfilled.h"
#include "sodamachine.h"

StateInterface *AmountNotFulfilled::m_instance = NULL;
SodaMachine * AmountNotFulfilled::m_soda_machine = NULL;

AmountNotFulfilled::AmountNotFulfilled(QObject *parent) :
    QObject(parent)
{
    setObjectName("AmountNotFulfilled");
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
}

void AmountNotFulfilled::exit()
{
    qDebug() << "Exit" << this->objectName();
}
