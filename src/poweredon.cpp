#include "poweredon.h"
#include "sodamachine.h"

StateInterface *PoweredOn::m_instance = NULL;
SodaMachine * PoweredOn::m_soda_machine = NULL;

PoweredOn::PoweredOn(QObject *parent) :
    QObject(parent)
{
}

StateInterface *PoweredOn::instance(SodaMachine *soda_machine)
{
    if(soda_machine && !m_soda_machine)
        m_soda_machine = soda_machine;

    if(!m_instance)
        m_instance = new PoweredOn;

    return m_instance;
}
