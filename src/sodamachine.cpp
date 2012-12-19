#include "sodamachine.h"
#include "ui_sodamachine.h"
#include "QDebug"
#include <QApplication>

// our states
#include "state.h"
#include "await.h"
#include "amountnotfulfilled.h"
#include "nosoda.h"
#include "poweredon.h"

SodaMachine::SodaMachine(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SodaMachine),
    m_amount(0),
    m_bottles(3),
    m_price(150),
    m_current_state(0)
{
    ui->setupUi(this);

    // events triggered by the user
    connect(ui->bAbort, SIGNAL(clicked()), SLOT(slot_abort()));
    connect(ui->b050_inserted, SIGNAL(clicked()), SLOT(slot_cash_inserted_050()));
    connect(ui->b100_inserted, SIGNAL(clicked()), SLOT(slot_cash_inserted_100()));

    // initialize the states
    Await::instance(this);
    NoSoda::instance(this);
    PoweredOn::instance(this);
    AmountNotFulfilled::instance(this);

    // the machine has now completely booted
    PoweredOn::instance()->enter();
}

SodaMachine::~SodaMachine()
{
    delete ui;
}

void SodaMachine::set_new_state(StateInterface *state)
{
    m_current_state = state;

    // a Qt interface has no object name, so we print
    // its address instead, we could use qApp.findChild
    // and blow up the business logic to get the actual name
    // or alternatively populate a name map when the states
    // are initialized
    qDebug() << "New state:" << state;
}

void SodaMachine::slot_cash_inserted_050()
{
    m_amount += 50;
    qDebug() << "50 cents inserted";
    emit cash_inserted_050();
}

void SodaMachine::slot_cash_inserted_100()
{
    m_amount += 100;
    qDebug() << "1 euro inserted";
    emit cash_inserted_100();
}

void SodaMachine::slot_abort()
{
    qDebug() << "Aborted";
    emit abort();
}
