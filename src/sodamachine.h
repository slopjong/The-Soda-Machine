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

    void set_new_state(StateInterface *state);

    StateInterface * current_state() { return m_current_state; }
    bool is_empty() { return m_bottles == 0; }
    int price() { return m_price; }
    int amount() { return m_amount; }


public slots:

    // ------------------------------------
    // state transition actions
    // ------------------------------------

    void refund_exchange();
    void refund_full();

    void throw_out_a_soda_bottle() { m_bottles--; }

signals:
    void cash_inserted_050();
    void cash_inserted_100();
    void abort();

private slots:

    // the user interactions
    void slot_cash_inserted_050();
    void slot_cash_inserted_100();
    void slot_abort();

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
