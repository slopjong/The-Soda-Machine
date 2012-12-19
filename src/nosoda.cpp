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
}

void NoSoda::exit()
{
    qDebug() << "Exit" << this->objectName();
}
