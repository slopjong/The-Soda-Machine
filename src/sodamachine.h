#ifndef SODAMACHINE_H
#define SODAMACHINE_H

#include <QDebug>

#include <QMainWindow>

namespace Ui {
class SodaMachine;
}

class StateInterface;

class SodaMachine : public QMainWindow
{
    Q_OBJECT

    //friend class AmountNotFulfilled;


public:
    explicit SodaMachine(QWidget *parent = 0);
    ~SodaMachine();

    void set_new_state(StateInterface *state)
    {
        m_current_state = state;
    }

    StateInterface * current_state()
    {
        return m_current_state;
    }


    // ------------------------------------
    // state transition actions
    // ------------------------------------

    void refund_exchange()
    {
        qDebug() << "Return"
                 << (m_amount-m_price)
                 << " cents";
        m_amount = 0;
    }

signals:
    void cash_inserted_050();
    void cash_inserted_100();
    void abort();

private slots:

    // the user interactions
    void slot_cash_inserted_050();
    void slot_cash_inserted_100();
    void slot_abort();

    // internal states
    bool is_empty() { return m_bottles == 0; }

    // actions
    void throw_out_a_soda_bottle() { m_bottles--; }

private:
    Ui::SodaMachine *ui;

    // the whole amount the user has inserted, unit is in cents
    int m_amount;

    // initial amount of bottles
    int m_bottles;

    // a soda bottle costs 150 cents
    int m_price;

    StateInterface *m_current_state;
};

#endif // SODAMACHINE_H
