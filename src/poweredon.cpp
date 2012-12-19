#include "poweredon.h"
#include "sodamachine.h"

StateInterface *PoweredOn::m_instance = NULL;
SodaMachine * PoweredOn::m_soda_machine = NULL;

PoweredOn::PoweredOn(QObject *parent) :
    QObject(parent)
{
    setObjectName("PoweredOn");
}

StateInterface *PoweredOn::instance(SodaMachine *soda_machine)
{
    if(soda_machine && !m_soda_machine)
        m_soda_machine = soda_machine;

    if(!m_instance)
        m_instance = new PoweredOn;

    return m_instance;
}

void PoweredOn::enter()
{
    qDebug() << "Entered" << this->objectName();

    m_soda_machine->set_new_state(this);
}

void PoweredOn::exit()
{
    qDebug() << "Exit" << this->objectName();
}
