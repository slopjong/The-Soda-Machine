#include "nosoda.h"
#include "sodamachine.h"

StateInterface * NoSoda::m_instance = NULL;
SodaMachine * NoSoda::m_soda_machine = NULL;

NoSoda::NoSoda(QObject *parent) :
    QObject(parent)
{
}

StateInterface *NoSoda::instance(SodaMachine *soda_machine)
{
    if(soda_machine && !m_soda_machine)
        m_soda_machine = soda_machine;

    if(!m_instance)
        m_instance = new NoSoda;

    return m_instance;
}
