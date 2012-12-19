#include "await.h"
#include "sodamachine.h"

StateInterface * Await::m_instance = NULL;
SodaMachine * Await::m_soda_machine = NULL;

Await::Await(QObject *parent) :
    QObject(parent)
{
}

StateInterface *Await::instance(SodaMachine *soda_machine)
{
    if(soda_machine && !m_soda_machine)
        m_soda_machine = soda_machine;

    if(!m_instance)
        m_instance = new Await;

    return m_instance;
}
